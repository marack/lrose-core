/**
 * @file  AzGradientFilter.hh
 * @brief Azimuth gradient filter
 * @class AzGradientFilter
 * @brief Azimuth gradient filter
 */
#ifndef AZGRADIENTFILTER_H
#define AZGRADIENTFILTER_H

#include <string>
#include <vector>

class RayData1;
class RayLoopData;
class AzGradientStateSpecialData;
class RadxRay;
class RayxData;

class AzGradientFilter
{
public:
  /**
   * Constructor, no members
   */
  AzGradientFilter(void);

  /**
   * Destructor
   */
  ~AzGradientFilter(void);
  
  /**
   * Peform filter on inputs, output into last arg
   * @param[in] state  The state object
   * @param[in] v  Value to add to input data at each point prior to filtering
   * @param[in] name  Field name
   * @param[out] output  Pointer to output that is updated 
   * @return true if successful
   */
  bool filter(const AzGradientStateSpecialData &state, double v,
	      const RayxData &rdata,
	      const std::string &name, const RayData1 &rdata1,
	      RayLoopData *output);
    
private:
  const AzGradientStateSpecialData *_state;

  bool _setAdjacentRays(const RayData1 &rdata1, const RadxRay **lray0,
		       const RadxRay **lray1) const;
  bool _veryFirstRay(const RayData1 &rdata1, const RadxRay **lray0,
		     const RadxRay **lray1) const;
  bool _veryLastRay(const RayData1 &rdata1,
		    const RadxRay **lray0,
		    const RadxRay **lray1) const;
  bool _setPreviousRayWhenNewSweep(int oldSweep, int sweep,
				   const RadxRay **lray0,
				   const RadxRay **lray1) const;
  bool _setNextRayWhenEndSweep(int sweep, int nextSweep,
			       const RadxRay **lray0,
			       const RadxRay **lray1) const;
};

#endif
