/*! \file Bus.cpp
 * 
 * Definition file for Class Bus
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include "Bus.h"

 /*! \brief This is the default constructor for the Bus class
   * 
   * Constructor for Bus class that takes in no parameters.
   *
   */
Bus::Bus() {

	 occupancyStatus = {
	   { 0, "images/not_crowded.png" },
	   { 1, "images/not_crowded.png" },
	   { 2, "images/some_crowding.png" },
	   { 3, "images/crowded.png" }
	};
	
	 //initialize all the variables
	 busNumber = "";
	 busRoute = "";
	 busOccupancy = 0;
	 busCongestion = "";
	 busStopName = "";
	 stopID = 0;
	 busPosition = Position();
	 busSchedule = Schedule();
	 busServices = std::map<int, Service>();
	 services = std::vector<Service>();
	 TripIDs = std::vector<int>();
	 showPosition = -1;
	 
			
}


/*! \brief Constructor for Bus class. 
 *
  * This constructor takes in the bus number and the bus route.
  *  @param busNumber The bus number.
  *  @param busRoute The bus route.
  *
  */
Bus::Bus(std::string busNumber, std::string busRoute) {
	this->busNumber = busNumber;
	this->busRoute = busRoute;
	occupancyStatus = {
	   { 0, "images/not_crowded.png" },
	   { 1, "images/not_crowded.png" },
	   { 2, "images/some_crowding.png" },
	   { 3, "images/crowded.png" }
	};
	
	busOccupancy = 0;
	busCongestion = "";
	busStopName = "";
	stopID = 0;
	busPosition = Position();
	busSchedule = Schedule();
	busServices = std::map<int, Service>();
	services = std::vector<Service>();
	TripIDs = std::vector<int>();
	showPosition = -1;
}

/*! \brief Destructor for Bus class.
* 
* Destructor for Bus class.
*/
Bus::~Bus() {}

/*! \brief Getter for bus number.
  *
  *  This method returns the bus number.
  *  @return The bus number.
  */
std::string Bus::getBusNumber() {
	return busNumber;
}

/*! \brief Getter for bus stop ID
  * 
  * This method returns the bus stop ID trough which the bus is passing.
  * @return The bus stop ID.
  *
  */
int Bus::getStopID() {
	return stopID;
}

/*! \brief Getter for bus stop name.
  * 
  * This method returns the bus stop name trough which the bus is passing.
  * @return	the bus stop name.
  *
  */
std::string Bus::getBusStopName() {
	return busStopName;
}

/*! \brief Getter for bus route.
  * 
  *  This method returns the bus route such as "Natural Science via Dundas"
  *	 @return The bus route.
  */
std::string Bus::getBusRoute() {
	return busRoute;
}

/*! \brief Getter for bus occupancy.
  * 
  *	This method returns the bus occupancy in integer format.
  * To convert the integer to information, GTFS occupancy status is used.
  * @return The bus occupancy.
  */
int Bus::getBusOccupancy() {
	return busOccupancy;
}

/*! \brief Getter for bus congestion.
  *
  * This method returns the bus position in terms of latitude and longitude.
  * @return The bus position.
  */
Position Bus::getBusPosition() {
	return busPosition;
}

/*! \brief Getter for bus schedule.
  * 
  * This method returns the bus schedule comprised of trips done by the bus and stop times for each trip
  *	@return The bus schedule.
  */
Schedule& Bus::getBusSchedule() {
	return this->busSchedule;
}

/*! \brief Getter for bus trips
  *  
  *  This methode get the list of trips for the bus
  *  @return the bus set of trips
  */
std::vector<int> Bus::getTripIDs() {
	return TripIDs;
}

/*! \brief Getter for bus congestion level
  * 
  * This method get Congestion level that is affecting a bus
  * To convert the string code to information, GTFS congestion status is used.
  * @return The bus congestion level.
  * 
  */
std::string Bus::getBusCongestion() {
	return busCongestion;
}

/*! \brief Method to get the occupancy status.
  * 
  * This method is used to convert the occupancy status from integer to information
  * @param the occupancy status in integer format.
  *	@return the occupancy status in string format.
  */
std::string Bus::getOccupancyStatus(int occupancy) {

	if (occupancyStatus.find(occupancy) != occupancyStatus.end()) {
		
		return occupancyStatus[occupancy];
	}

	return "";
}


/*! \brief Method to get the position from which to start getting a stop time to show.
  * 
  * This method is used in the bus schedule section to get which stop time to show depending on the current time
  * @return the position from which to start getting a stop time to show.
  */
int Bus::getShowPosition() {

	return showPosition;
}

/*! \brief Getter for bus services.
  *
  *  Method to get the set of services associated with a bus trip
  *  @return the bus set of services
  */
std::map<int, Service> Bus::getBusServices() {


	return busServices;

}

/*! \brief Setter for the bus number
  * 
  *	This method is used to set the bus number.
  * @param busNumber The bus number.
  *
  */
void Bus::setBusNumber(std::string busNumber) {
	this->busNumber = busNumber;
}

/*! \brief Setter for the bus stop ID
  * 
  * This method is used to set the bus stop ID.
  * @param stopID The bus stop ID.
  *
  */
void Bus::setStopID(int stopID) {
	this->stopID = stopID;
}


/*! \brief Setter for the bus stop name
  * 
  * This method is used to set the bus stop name.
  * @param busStopName The bus stop name.
  *
  */
void Bus::setBusStopName(std::string busStopName) {
	this->busStopName = busStopName;
}


/*! \brief Setter for the bus route
  * 
  * This method is used to set the bus route.
  *	 @param busRoute The bus route.
  *
  */
void Bus::setBusRoute(std::string busRoute) {
	this->busRoute = busRoute;
}


/*! \brief Setter for the bus occupancy
  * 
  *  This method is used to set the bus occupancy.
  *  @param busOccupancy The bus occupancy.
  */
void Bus::setBusOccupancy(int busOccupancy) {
	this->busOccupancy = busOccupancy;
}

/*! \brief Setter for the bus position
  * 
  *	 This method is used to set the bus position.
  *  @param busPosition The bus position.
  *
  */
void Bus::setBusPosition(Position busPosition) {
	this->busPosition = busPosition;
}

/*! \brief Setter for the bus schedule
  *
  * This method is used to set the bus schedule.
  *	 @param busSchedule The bus schedule.
  *
  */
void Bus::setBusSchedule(Schedule busSchedule) {
	this->busSchedule = busSchedule;
}

/*! \brief Setter for the bus trips
  * 
  *  This method set the list of trips for the bus
  *  @param the bus set of trips
  */
void Bus::setTripIDs(std::vector<int> TripIDs) {
	this->TripIDs = TripIDs;
}

/*! \brief Setter for the bus congestion level
  * 
  *  This method set the list of services for the bus
  *  @param the bus congestion level
  *
  */
void Bus::setBusCongestion(std::string busCongestion) {
	this->busCongestion = busCongestion;
}

/*! \brief Setter for the bus show position
*  
*  This method set the show position for the bus which is the position for wich the stop time is shown
*  @param the bus show position
*
*/
void Bus::setShowPosition(int showPosition) {

	this->showPosition = showPosition;
}


/*! \brief Setter for bus services.
  * 
  *	This method set the set of services associated with the  bus trips
  * @param the bus set of services
  *
  */
void Bus::setBusServices(std::map<int, Service> busServices) {

	this->busServices = busServices;
}


/*! \brief Method to add a trip ID to the vector of trip IDs.
  * 
  *  This method is used to add a trip ID to the vector of trip IDs.
  *  @param tripID The trip ID to add.
  *
  */
bool Bus::addTripID(int tripID) {
	TripIDs.push_back(tripID);
	return true;
}

/*! \brief Method to remove a trip ID from the vector of trip IDs.
  *	 
  *  This method is used to remove a trip ID from the vector of trip IDs.
  *  @param tripID The trip ID to remove.
  *
  */
bool Bus::removeTripID(int tripID) {
	for (std::size_t i = 0; i < TripIDs.size(); i++) {
		if (TripIDs[i] == tripID) {
			TripIDs.erase(TripIDs.begin() + i);
			return true;
		}
	}
	return false;
}

/*! \brief Method to add a service to the map of services.
  * 
  *  This method is used to add a service to the map of services.
  *  @param trip The trip ID.
  *  @param service The service to add.
  *
  */
bool Bus::addBusService(int trip, Service service) {


	busServices.insert(std::pair<int, Service>(trip, service));
	
	return true;


}


/*! \brief This is an overloaded operator for equality.
  * 
  * Overloaded operator for equality.
  * @param other The other bus to compare to.
  *
  */
bool Bus::operator==(const Bus& other) const {

	return this->busNumber == other.busNumber && this->busRoute == other.busRoute;
}

