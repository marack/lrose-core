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
//////////////////////////////////////////////////////////
// SigmaInterp.cc
//
// This class provides the pressure at any given flight level
// between -10 and 500.
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Sept 1998
//
//////////////////////////////////////////////////////////


#include <mm5/SigmaInterp.hh>
#include <iostream>
#include <cstdio>
#include <toolsa/str.h>
#include <toolsa/mem.h>
using namespace std;

const double SigmaInterp::MissingDouble = -9999.9;

//////////////
// Constructor

SigmaInterp::SigmaInterp ()
  
{
  
}

//////////////
// Destructor

SigmaInterp::~SigmaInterp ()

{

}

////////////////////////////////////////////////////////////////
// set levels
//
// Before calling prepareInterp, you need to set pressure, height
// or flight levels. So you need to call one of the following:
//  * setPressureLevels()
//  * setHeightLevels()
//  * setFlightLevels()

void SigmaInterp::setPressureLevels(int n_levels, const double *pressure)

{
  _pressure.clear();
  for (int i = 0; i < n_levels; i++) {
    _pressure.push_back(pressure[i]);
  }
}

void SigmaInterp::setPressureLevels(const vector<double> pressure)

{
  _pressure.clear();
  for (size_t i = 0; i < pressure.size(); i++) {
    _pressure.push_back(pressure[i]);
  }
}

void SigmaInterp::setHeightLevels(int n_levels, const double *height)
  
{
  _pressure.clear();
  for (int i = 0; i < n_levels; i++) {
    _pressure.push_back(_isa.ht2pres(height[i]));
  }
}

void SigmaInterp::setHeightLevels(const vector<double> height)
  
{
  _pressure.clear();
  for (size_t i = 0; i < height.size(); i++) {
    _pressure.push_back(_isa.ht2pres(height[i]));
  }
}

void SigmaInterp::setFlightLevels(int n_levels, const double *flevel)

{
  _pressure.clear();
  for (int i = 0; i < n_levels; i++) {
    _pressure.push_back(_isa.flevel2pres(flevel[i]));
  }
}

void SigmaInterp::setFlightLevels(const vector<double> flevel)

{
  _pressure.clear();
  for (size_t i = 0; i < flevel.size(); i++) {
    _pressure.push_back(_isa.flevel2pres(flevel[i]));
  }
}

////////////////
// prepareInterp
//
// Loads interpolation info for a sigma pressure profile for
// a given point.
//

void SigmaInterp::prepareInterp(const vector<double> &p_sigma)

{

  // load up interp info
  
  _interpIndex.clear();
  int jstart = 0;
  for (size_t ii = 0; ii < _pressure.size(); ii++) {
    
    SigmaInterp_interp_t intp;
    intp.valid = FALSE;
    double pres = _pressure[ii];
    
    for (size_t j = jstart; j < p_sigma.size() - 1; j++) {
      if (p_sigma[j] >= pres && p_sigma[j+1] <= pres) {
	intp.lowerIsigma = j;
	intp.upperIsigma = j + 1;
	double dp = p_sigma[j] - p_sigma[j+1];
	intp.wtLower = (pres - p_sigma[j+1]) / dp;
	intp.wtUpper = (p_sigma[j] - pres) / dp;
	intp.valid = TRUE;
	jstart = j;
	break;
      }
    } // j

    _interpIndex.push_back(intp);
    
  } // ii

  // load up sigmaNeeded
  
  _sigmaNeeded.clear();
  for (size_t i = 0; i < p_sigma.size(); i++) {
    _sigmaNeeded.push_back(FALSE);
  }
  
  for (size_t ii = 0; ii < _pressure.size(); ii++) {
    SigmaInterp_interp_t &intp = _interpIndex[ii];
    if (intp.valid) {
      _sigmaNeeded[intp.lowerIsigma] = TRUE;
      _sigmaNeeded[intp.upperIsigma] = TRUE;
    }
  }

}

///////////
// doInterp
//
// Interpolate a field from sigma to flight levels.
//
// Passed in is the array for the field column in sigma levels.
//
// If copy_lowest_downwards is true, the lowest non-missing data will
// be copied down to the lowest level.
//
// Fills out vector with interpolated data.

void SigmaInterp::doInterp(const vector<double> &field_sigma,
			   vector<double> &interp_data,
			   bool copy_lowest_downwards)
  
{
  
  int lowestValid = -1;
  interp_data.clear();
  
  for (size_t ii = 0; ii < _pressure.size(); ii++) {
    SigmaInterp_interp_t &intp = _interpIndex[ii];
    double val;
    if (intp.valid) {
      val = (field_sigma[intp.lowerIsigma] * intp.wtLower +
	     field_sigma[intp.upperIsigma] * intp.wtUpper);
      if (lowestValid == -1) {
	lowestValid = ii;
      }
    } else {
      val = MissingDouble;
    }
    interp_data.push_back(val);
  } // ii

  // copy downwards if relevant

  double bottomVal = MissingDouble;
  for (size_t i = 0; i < field_sigma.size(); i++) {
    if (field_sigma[i] != MissingDouble) {
      bottomVal = field_sigma[i];
      break;
    }
  }
  
  if (copy_lowest_downwards) {
    for (int i = lowestValid - 1; i >= 0; i--) {
      interp_data[i] = bottomVal;
    }
  }

}

////////////////////////
// print pressure array

void SigmaInterp::printPressureArray(ostream &out)

{
  out << "----> SigmaInterp: pressure array <----" << endl;
  for (size_t i = 0; i < _pressure.size(); i++) {
    out << "i, pressure: " << i << ", " << _pressure[i] << endl;
  }
}

