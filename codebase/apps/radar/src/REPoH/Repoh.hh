/**
 * @file Repoh.hh 
 * @class Repoh
 */

#ifndef REPOH_H
#define REPOH_H

#include "Parms.hh"
#include <FiltAlgVirtVol/Algorithm.hh>

class VolumeData;

class Repoh
{
public:
  Repoh(void);

  /**
   * Constructor
   * @param[in] parmFileName  Name of file with parameters
   * @param[in] cleanExit  Method to call for exiting program
   */
  Repoh(const Parms &parms, void cleanExit(int));

  /**
   * Destructor
   */
  virtual ~Repoh (void);

  /**
   * True if object is well formed
   */
  inline bool ok(void) const {return _ok;}

  /**
   * @return reference to the parameters
   */
  inline const Parms &getParms(void) const {return _parms;}

  /**
   * @return a pointer to the Algorithm object
   */
  inline const Algorithm *getAlgorithm(void) const {return _alg;}
  

  // /**
  //  * Run the Repoh algorithm on a volume
  //  * @param[in] inputs  Input data
  //  * @param[out] outputs Output data
  //  * @return true for success, false for error 
  //  */
  bool run(VolumeData *inputs);

protected:
private:

  bool _ok;            /**< True if object well formed */
  Parms _parms;   /**< Parameters */
  Algorithm *_alg;     /**< Algorithm pointer, pointer due to threading */
};

#endif
