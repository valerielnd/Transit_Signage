/*! \file BusStop.cpp
* 
 * Definition file for Class BusStop
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <algorithm>
#include <iostream>
#include "BusStop.h"



  /*! \brief construcotr for BusStop
   * 
   * This method to construct a BusStop object
   * It initializes all the variables to their default values
   *
   */
BusStop::BusStop() {
	this->busStopName = "";
	this->busStopID = "";
	this->busStopCode = 0;
	this->busStopLat = 0;
	this->busStopLong = 0;	
	busList = std::vector<Bus>();
	alertList = std::vector<LTCAlert>();
	busStopAlert = LTCAlert();
	busStopInfo = LTCInfo();

}

/*! \brief Constructor for BusStop
   * . 
   * 
   * It takes in a string for the name of the bus stop and a string for the ID of the bus stop
   * @param busStopName is a string that represents the name of the bus stop
   * @param busStopID is a string that represents the ID of the bus stop
   *
   *
   */
BusStop::BusStop(std::string busStopName, std::string busStopID) {
	this->busStopName = busStopName;
	this->busStopID = busStopID;
	this->busStopCode = 0;
	this->busStopLat = 0;
	this->busStopLong = 0;
	busList = std::vector<Bus>();
	alertList = std::vector<LTCAlert>();
	busStopAlert = LTCAlert();
	busStopInfo = LTCInfo();

	//initialize all variables

	
}

/*! \brief  Constructor for BusStop
*   
*  It takes in a string for the name of the bus stop, a string for the ID of the bus stop, 
*  an int for the code of the bus stop, a double for the latitude of the bus stop, and a double 
*  for the longitude of the bus stop
*  @param busStopName is a string that represents the name of the bus stop
*  @param busStopID is a string that represents the ID of the bus stop
*  @param busStopCode is an int that represents the code of the bus stop
*  @param busStopLat is a double that represents the latitude of the bus stop
*  @param busStopLong is a double that represents the longitude of the bus stop
*  
*/
BusStop::BusStop(std::string stopName, std::string stopID, int stopCode, double stopLat, double stopLon) {
	this->busStopName = stopName;
	this->busStopID = stopID;
	this->busStopCode = stopCode;
	this->busStopLat = stopLat;
	this->busStopLong = stopLon;
	busList = std::vector<Bus>();
	alertList = std::vector<LTCAlert>();
	busStopAlert = LTCAlert();
	busStopInfo = LTCInfo();
	
}

/*! \brief Constructor for BusStop
* 
*  Constructor for BusStop
*/
BusStop::~BusStop() {
	
}


/*! \brief This method is used to set the name of the bus stop
*
* This method is used to set the name of the bus stop such as "Natural Science"
* @param busStopName is a string that represents the name of the bus stop
*
*/
void BusStop::setBusStopName(std::string busStopName) {
	this->busStopName = busStopName;
}

/*! \brief This method is used to set the ID of the bus stop
* 
*  This method is used to set the ID of the bus stop such as "NATSCI"
* @param busStopID is a string that represents the ID of the bus stop
*
*/
void BusStop::setBusStopID(std::string busStopID) {
	this->busStopID = busStopID;
}


/*! \brief This method is used to set the alert of the bus stop
 * 
 * This method is used to set the Alert of the bus stop
 * @param	busStopAlert is an LTCAlert object that represents the alert of the bus stop
 *
 */
void BusStop::setBusStopAlert(LTCAlert busStopAlert) {
	this->busStopAlert = busStopAlert;
}


/*! \brief This method is used to set the info of the bus stop
 * 
 * This method is used to set the info of the bus stop. 
 * The informartion include LTC accessibility and LTC contact information
 * @param busStopInfo is an LTCInfo object that represents the info of the bus stop
 *
 */
void BusStop::setBusStopInfo(LTCInfo busStopInfo) {

	this->busStopInfo = busStopInfo;
	
}


/*! \brief This method is used to set the list of buses at the bus stop
* 
 * This method is used to set the list of buses at the bus stop
 * @param busStoList is a vector of Bus objects that represents the list of buses at the bus stop
 */
void BusStop::setBusList(std::vector<Bus> busList) {
	this->busList = busList;
}

/*! \brief This method is used to set the list of alerts of the bus stop
 * 
 * This method is used to set the list of alerts of the bus stop
 * @param alertList is a vector of LTCAlert objects that represents the list of alerts of the bus stop
 */
void BusStop::setAlertList(std::vector<LTCAlert> alertList) {

	this->alertList = alertList;
}

/*! \brief This method is used to get the ID of the bus stop
 *  
 * This method is used to get the ID of the bus stop
 * @return busStopID is a string that represents the ID of the bus stop
 *
 */
std::string BusStop::getBusStopName() {
	return busStopName;
}


/*! \brief This method is used to get the code of the bus stop
 * 
 * This method is used to get the Alert of the bus stop
 * @return busStopAlert is an LTCAlert object
 *
 */
std::string BusStop::getBusStopID() {
	return busStopID;
}


/*! \brief This method is used to get the info of the bus stop
 * 
 * This method is used to get the info of the bus stop
 * @return busStopInfo is an LTCInfo object
 *
 */
LTCAlert BusStop::getBusStopAlert() {
	return busStopAlert;
}


/*! \brief This method is used to get the list of buses at the bus stop
* 
 * This method is used to get the list of buses at the bus stop
 * @return busList is a vector of Bus objects 
 *
 */
LTCInfo BusStop::getBusStopInfo() {
	
	return this->busStopInfo;
}


/*! \brief This method is used to get the list of buses at the bus stop
* 
 * This method is used to get the list of buses at the bus stop
 * @return busList is a vector of Bus objects 
 *
 */
std::vector<Bus>& BusStop::getBusList() {
	return busList;
}


/*! \brief This method is used to get the list of alerts of the bus stop
 * 
 * This method is used to get the list of alerts of the bus stop
 * @return alertList is a vector of LTCAlert objects
 *
 */
std::vector<LTCAlert>& BusStop::getAlertList() {

	return alertList;

}

/*! \brief Adds a bus to the list of buses at the bus stop
* 
 * This method is used to add a bus to the list of buses at the bus stop
 * @param bus is a Bus object that represents the bus to be added to the list of buses at the bus stop
 * @return true if the bus is added to the list of buses at the bus stop
 *
 */
bool BusStop::addBus(Bus bus) {
	
	if (!this->findBus(bus)) {
		
		busList.push_back(bus);

		return true;
	}
	return false;
}


/*! \brief Removes a bus from the list of buses at the bus stop
* 
 * This method is used to remove a bus from the list of buses at the bus stop
 * @param bus is a Bus object that represents the bus to be removed from the list of buses at the bus stop
 * @return true if the bus is removed from the list of buses at the bus stop
 */
bool BusStop::removeBus(Bus bus) {

	if (this->findBus(bus)) {
		
		busList.erase(std::remove(busList.begin(), busList.end(), bus), busList.end());
		
		return true;
	}
	return false;
}


/*! \brief Gets a bus in the list of buses at the bus stop
* 
 * This method is used to get a bus from the list of buses at the bus stop
 *  @param  busToFind is a Bus object that represents the bus to be found in the list of buses at the bus stop
 *  @return	the bus if the bus is found in the list of buses at the bus stop
 *	
 */
Bus& BusStop::getBus(Bus busToFind) {

	for (size_t i = 0; i < BusStop::busList.size(); i++) {
		
		Bus bus = BusStop::busList[i];

		if (bus == busToFind) {
			
			return BusStop::busList[i];
		}
		
	}

	throw std::runtime_error("Requested bus not found at the bus stop");
	
}


/*! \brief get a bus in the list of buses at the bus stop
*    
*  This method is used to get a bus from the list of buses at the bus stop and returns it
*  @param busNum is a string that represents the number of the bus to be found
*  @param tripID is an integer that represents the trip ID of the bus to be found
*/
Bus& BusStop::getBus(std::string busNum, int tripID) {

	for (size_t i = 0; i < BusStop::busList.size(); i++) {

		Bus bus = BusStop::busList[i];

		std::vector<int> TripIDs = bus.getTripIDs();

		auto it = std::find(TripIDs.begin(), TripIDs.end(), tripID);


		if (it != TripIDs.end()) {

			std::string busNumber = bus.getBusNumber();

			if (busNum == busNumber) {

				return BusStop::busList[i];

			}
		}

	}

	throw std::runtime_error("Requested bus not found at the bus stop");

}

/*! \brief Finds a bus in the list of buses at the bus stop
* 
* This method is used to get a bus from the list of buses at the bus stop based on the bus number and route
* @param busNumber is a string that represents the number of the bus to be found in the list of buses at the bus stop
* @param busRoute is a string that represents the route of the bus to be found in the list of buses at the bus stop
* @return true if the bus is found in the list of buses at the bus stop
*/
bool BusStop::findBus(std::string busNumber, std::string busRoute) {

	Bus busToFind(busNumber, busRoute);	

	for (size_t i = 0; i < BusStop::busList.size(); i++) {

		Bus bus = BusStop::busList[i];

		if (bus == busToFind) {

			return true;
		}

	}
	return false;

}


/*! \brief Finds a bus in the list of buses at the bus stop
* 
 * This method is used to find a bus in the list of buses at the bus stop using the bus to find
 * @param bus is a Bus object that represents the bus to be found in the list of buses at the bus stop
 * @return true if the bus is found in the list of buses at the bus stop
 */
bool BusStop::findBus(Bus bus) {
	auto found_bus = std::find(BusStop::busList.begin(), BusStop::busList.end(), bus);

	if (found_bus != BusStop::busList.end()) {
		return true;
	}

	return false;
}


/*! \brief Overloads the == operator for BusStop objects
* 
 * This method is used to overload the == operator for BusStop objects
 * @param other is a BusStop object that represents the other BusStop object to be compared to the current BusStop object
 * @return true if the bus stop IDs of the two BusStop objects are equal
 *
 */
bool BusStop::operator==(const BusStop& other) const {

	return this->busStopID == other.busStopID;
}


/*! \brief Gets the bus stop code
* 
 * This method is used to get the bus stop code sudh as "1222"
 * @return an int that represents the code of the bus stop
 *
 */
int BusStop::getStopCode() {

	return this->busStopCode;


}


/*! \brief Sets the bus stop code
* 
 * This method is used to set the bus stop code
 * @param busStopCode is an int that represents the code of the bus stop
 *
 */
void BusStop::setBusStopCode(int busStopCode) {

	this->busStopCode = busStopCode;

}


/*! \brief Sets the bus latitude position
* 
 * This method is used to set the latitude of the bus stop
 * @param busStopLat is a double that represents the latitude of the bus stop
 */
void BusStop::setBusStopLat(double busStopLat) {

	this->busStopLat = busStopLat;

}


/*! \bried Sets the bus longitude position
* 
 * This method is used to set the longitude of the bus stop
 * @param busStopLong is a double that represents the longitude of the bus stop
 *
 */
void BusStop::setBusStopLong(double busStopLong) {

	this->busStopLong = busStopLong;

}


/*! \brief Gets the bus latitude position
* 
 * This method is used to get the latitude of the bus stop
 * @return a double that represents the latitude of the bus stop
 *
 */
double BusStop::getBusStopLat() {

	return this->busStopLat;

}


/*! \brief Gets the bus longitude position
* 
 * This method is used to get the longitude of the bus stop
 * @return a double that represents the longitude of the bus stop
 *
 */
double BusStop::getBusStopLong() {

	return this->busStopLong;

}


/*! \brief Finds an alert in the list of alerts of the bus stop
 * 
 * This method is used to find an alert in the list of alerts
 * @param alert is a LTCAlert object that represents the alert to be found
 * @retunr true if the alert is found in the list of alerts of the bus stop
 *
 */
bool BusStop::findAlert(LTCAlert alert) {

	auto found_alert = std::find(BusStop::alertList.begin(), BusStop::alertList.end(), alert);

	if (found_alert != BusStop::alertList.end()) {
		return true;
	}

	return false;


}


/*! \brief Adds an alert to the list of alerts of the bus stop
* 
* This method is used to add an alert to the list of alerts of the bus stop
* @param alert is a LTCAlert object that represents the alert to be added to the list of alerts of the bus stop
* @return true if the alert is added to the list of alerts of the bus stop
*/
bool BusStop::addAlert(LTCAlert alert) {

	if (!this->findAlert(alert)) {

		alertList.push_back(alert);

		return true;
	}
	return false;

}


/*! \brief Removes an alert from the list of alerts of the bus stop
* 
 * This method is used to remove an alert from the list of alerts of the bus stop
 * @param alert is a LTCAlert object that represents the alert to be removed from the list of alerts of the bus stop
 * @return true if the alert is removed from the list of alerts of the bus stop
 */
bool BusStop::removeAlert(LTCAlert alert) {

	if (this->findAlert(alert)) {

		alertList.erase(std::remove(alertList.begin(), alertList.end(), alert), alertList.end());

		return true;
	}
	return false;

}


/*! \brief Gets an alert from the list of alerts of the bus stop
* 
 * This method is used to get an alert from the list of alerts of the bus stop
 * @param alertToFind is a LTCAlert object that represents the alert to be found in the list of alerts of the bus stop
 * @return a LTCAlert object that represents the alert found in the list of alerts of the bus stop
 */
LTCAlert& BusStop::getAlert(LTCAlert alertToFind) {

	for (size_t i = 0; i < BusStop::alertList.size(); i++) {

		LTCAlert alert = BusStop::alertList[i];

		if (alert.getAlertID() == alertToFind.getAlertID()) {

			return BusStop::alertList[i];
		}

	}
	throw std::runtime_error("Requested bus not found at the bus stop");

}
