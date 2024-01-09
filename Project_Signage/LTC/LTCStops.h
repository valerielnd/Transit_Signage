
/*
 * Header file for Class LTCStops
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <vector>
#include "BusStop.h"


#ifndef LTCSTOP_H_
#define LTCSTOP_H_

 /*!
   * This class represent a BusStop at Western
   *
   */
class LTCStops {

private:

	std::vector<BusStop> westernStops;

public:
	
	LTCStops();

	LTCStops(std::vector<BusStop> stops);

	~LTCStops();

	void setWesternStops(std::vector<BusStop> westernStops);

	std::vector<BusStop>& getWesternStops();

	bool addBusStop(BusStop busStop);

	bool removeBusStop(BusStop busStop);

	BusStop& getBusStop(std::string busStopID);

	bool findBusStop(BusStop busStop);
};

#endif // !LTCSTOP_H_