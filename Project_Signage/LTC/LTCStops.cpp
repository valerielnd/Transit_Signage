/*
 * Definition file for Class LTCStops
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <algorithm>
#include "LTCStops.h"

 /*!
   *  Constructor for the class LTCStops
   *
   */
LTCStops::LTCStops() {

	westernStops = std::vector<BusStop>();
}


/*!
   *  Constructor for the class LTCStops
   *
   */
LTCStops::LTCStops(std::vector<BusStop> stops) {

	this->westernStops = stops;

}

/*!
  * Destructor for the class LTCStops
  *
  */
LTCStops::~LTCStops() {}


/*!
  * Setter for the vector of BusStop
  *
  */
void LTCStops::setWesternStops(std::vector<BusStop> westernStops) {
	this->westernStops = westernStops;
}

/*!
  * Getter for the vector of BusStop
  *
  */
std::vector<BusStop>& LTCStops::getWesternStops() {
	return westernStops;
}


/*!
  * Add a BusStop to the vector of BusStop
  *
  */
bool LTCStops::addBusStop(BusStop busStop) {

	if (!this->findBusStop(busStop)) {

		westernStops.push_back(busStop);

		return true;
	}

	return false;
}


/*!
  * Remove a BusStop from the vector of BusStop
  *
  */
bool LTCStops::removeBusStop(BusStop busStop) {

	if (this->findBusStop(busStop)) {

		westernStops.erase(std::remove(westernStops.begin(), westernStops.end(), busStop), westernStops.end());
	}

	return false;
}

/*!
  * Get a BusStop from the vector of BusStop
  *
  */
BusStop& LTCStops::getBusStop(std::string busStopID) {

	

	for (size_t i = 0; i < westernStops.size(); i++) {

		BusStop busToReturn = westernStops[i];

		if (busToReturn.getBusStopID() == busStopID) {

			return westernStops[i];
		}
	}

	throw std::runtime_error("Element not found");
}

/*!
  * Find a BusStop from the vector of BusStop
   *
    */
bool LTCStops::findBusStop(BusStop busStop) {

	auto found_bus_stop = std::find(westernStops.begin(), westernStops.end(), busStop);

	if (found_bus_stop != westernStops.end()) {

		return true;
	}
	

	return false;
}