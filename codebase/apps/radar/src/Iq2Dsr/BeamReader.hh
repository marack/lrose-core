// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/////////////////////////////////////////////////////////////
// BeamReader.hh
//
// Mike Dixon, RAP, NCAR
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// August 2007
//
///////////////////////////////////////////////////////////////

#ifndef BeamReader_hh
#define BeamReader_hh

#include <pthread.h>
#include <string>
#include <vector>
#include <deque>
#include <radar/IwrfTsInfo.hh>
#include <radar/IwrfTsPulse.hh>
#include <radar/IwrfTsReader.hh>
#include <radar/AtmosAtten.hh>
#include "ArrayDeque.hh"
#include "Params.hh"
#include "Args.hh"
#include "Beam.hh"
#include "MomentsMgr.hh"
using namespace std;

////////////////////////
// This class

class BeamReader {
  
public:

  // scan mode for determining PPI vs RHI operations
  
  typedef enum {
    SCAN_TYPE_UNKNOWN,
    SCAN_TYPE_PPI,
    SCAN_TYPE_RHI
  } scan_type_t;
  
  // constructor
  
  BeamReader(const string &prog_name,
             const Params &params,
             const Args &args,
             deque<Beam *> &beamRecyclePool,
             pthread_mutex_t &beamRecyclePoolMutex,
             vector<const MomentsMgr *> &momentsMgrArray);
  
  // destructor
  
  ~BeamReader();

  // constructor OK?

  bool constructorOK;

  // get the next beam
  // returns Beam object pointer on success, NULL on failure
  // caller must free beam
  
  Beam *getNextBeam();

  // if end of vol is encountered in time series, the _endOfVol flag
  // will be set. Similarly for end of sweep.
  // the flags are cleared when a new beam is created.

  bool getEndOfSweepFlag() const { return _endOfSweepFlag; }
  bool getEndOfVolFlag() const { return _endOfVolFlag; }
    
  // get ops info

  const IwrfTsInfo &getOpsInfo() const { return _pulseReader->getOpsInfo(); }
  bool isOpsInfoNew() const { return _pulseReader->isOpsInfoNew(); }
  scan_type_t getScanType() const { return _scanType; }

protected:
  
private:

  string _progName;
  const Params &_params;
  const Args &_args;

  // beam pool - so that beam objects can be recycled

  deque<Beam *> &_beamRecyclePool;
  pthread_mutex_t &_beamRecyclePoolMutex;
  
  // moments manager

  vector<const MomentsMgr *> _momentsMgrArray;
  const MomentsMgr *_momentsMgr;
  int _mgrIndex;
  int _missMgrCount;

  // Pulse reader
  
  IwrfTsReader *_pulseReader;

  // end of sweep and vol flags
  
  bool _endOfSweepFlag;
  bool _endOfVolFlag;

  // active pulse queue
  
  si64 _pulseSeqNum;
  si64 _prevPulseSeqNum;
  IwrfTsPulse *_prevPulse;
  deque<IwrfTsPulse *> _pulseQueue;
  deque<IwrfTsPulse *> _pulseCache;
  int _pulseCount;
  int _pulseCountSinceStatus;
  
  // pulse queue for interpolating antenna angles
  
  deque<IwrfTsPulse *> _interpQueue;
  bool _interpReady; // angles have been interpolated and are ready for use
  bool _interpOverflow;
  double _prevAzInterp, _prevElInterp;
  
  // Pulse recycle pool.
  // The pulse pool holds previously used pulse objects, 
  // so that they may be re-used. This saves continual allocation
  // and de-allocation of memory.
  
  deque<IwrfTsPulse *> _pulseRecyclePool;

  // phase coding
  
  static const int _maxTrips = 4;
  static const int _maxBins = 3092;
  static const int _maxGates = _maxBins * _maxTrips;
  static const int _nSamplesSz = 64;

  IwrfTsPulse::burst_phase_t _burstPhases;
  
  // beam identification

  si64 _beamCount;
  int _midIndex, _startIndex, _endIndex;
  si64 _prevBeamPulseSeqNum; // pulse after center of beam
  vector<const IwrfTsPulse *> _beamPulses;

  // beam properties

  scan_type_t _scanType;
  int _nGates;
  int _nSamples;

  double _az;
  double _el;

  double _prt;
  double _meanPrf;
  double _pulseWidthUs;

  // pulse-to-pulse HV alternating mode

  bool _isAlternating;
  bool _startsOnHoriz;

  // staggered PRT and dual PRT

  bool _isStaggeredPrt;
  bool _startsOnPrtShort;

  double _prtShort;
  double _prtLong;
  
  int _nGatesPrtShort;
  int _nGatesPrtLong;
  
  bool _isDualPrt;
  bool _isDualReady;

  int _dualPrtIndexStart;
  int _dualPrtIndexEnd;

  // beam location/rate in azimuth - PPI mode

  int _azIndex;
  int _prevAzIndex;

  // beam location/rate in elevation - RHI mode
  
  int _elIndex;
  int _prevElIndex;

  // antenna rate

  bool _azRateInitialized;
  double _prevTimeForAzRate;
  double _prevAzForRate;
  double _progressiveAzRate;
  double _beamAzRate;
  bool _rotationClockwise;
  
  bool _elRateInitialized;
  double _prevTimeForElRate;
  double _prevElForRate;
  double _progressiveElRate;
  double _beamElRate;
  bool _rotationUpwards;
  
  // index the beams

  bool _indexTheBeams;
  double _indexedResolution;
  double _beamAngleDeg;

  // window 90% factors
  // this is the fraction of the window width, centered, which
  // accounts for 90 percent of the power

  double _windowFactorRect;
  double _windowFactorVonhann;
  double _windowFactorBlackman;
  double _windowFactorBlackmanNuttall;

  // atmospheric attenuation

  AtmosAtten _atmosAtten;

  // private functions
  
  int _initializeQueue();

  int _readDualPrtBeam();
  int _readNonIndexedBeam();
  int _readIndexedBeam();

  int _findPrevIndexedBeam();
  int _findNextIndexedBeam();
  int _finalizeNonIndexedBeam();
  int _checkStartConditions();
  void _constrainPulsesToWithinDwell();

  IwrfTsPulse *_getNextPulse();
  IwrfTsPulse *_readNextPulse();
  IwrfTsPulse *_doReadNextPulse();
  IwrfTsPulse *_readNextPulseWithInterp();
  IwrfTsPulse *_pushOntoInterpQueue();
  IwrfTsPulse *_popFromInterpQueue();

  bool _beamOk();
  void _addPulseToQueue(IwrfTsPulse *pulse);
  void _cacheLatestPulse();

  void _clearPulseQueue();
  void _recyclePulses();
  void _addPulseToRecyclePool(IwrfTsPulse *pulse);
  IwrfTsPulse *_getPulseFromRecyclePool();

  void _interpAzAngles();
  void _interpElevAngles();

  void _initPpiMode();
  void _initRhiMode();

  void _setPrt();

  int _findBeamCenterPpi();
  int _findBeamCenterRhi();

  int _computeMinNGates();
  int _computeNSamplesIndexed();
  int _computeNSamplesEffective(int nSamples);

  void _checkIsAlternating();
  void _checkAlternatingStartsOnH();
  void _checkIsStaggeredPrt();
  void _checkStaggeredStartsOnShort();

  double _conditionAz(double az);
  double _conditionEl(double el);

  void _computeProgressiveAzRate(const IwrfTsPulse *pulse);
  void _computeProgressiveElRate(const IwrfTsPulse *pulse);

  void _computeBeamAzRate(int endIndex, int nSamples);
  void _computeBeamElRate(int endIndex, int nSamples);

  void _checkQueueStatus();
  void _computeWindowFactors();

};

#endif
