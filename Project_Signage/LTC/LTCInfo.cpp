/*
 * Defintion file for Class LTCInfo
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 7, 2023
 */

#include <algorithm>
#include "LTCInfo.h"

 /*!
   * Constructor for the class LTCInfo
   *
   */
LTCInfo::LTCInfo() {
	LTCPhone = "";
	LTCEmail = "";
	LTCAddress = "";

}

/*!
  * Constructor for the class LTCInfo
  *
  */
LTCInfo::LTCInfo(std::string LTCPhone, std::string LTCEmail, std::string LTCAddress) {
	this->LTCPhone = LTCPhone;
	this->LTCEmail = LTCEmail;
	this->LTCAddress = LTCAddress;
}

LTCInfo::LTCInfo(const LTCInfo& other) {
    this->busPassengers = other.busPassengers;
    this->fleetInfo = other.fleetInfo;
    this->stopInfo = other.stopInfo;
    this->LTCPhone = other.LTCPhone;
    this->LTCEmail = other.LTCEmail;
    this->LTCAddress = other.LTCAddress;
}

/*!
  * Getter for the busPassengers
  *
  */
std::vector<Passenger> LTCInfo::getBusPassengers() {
	return busPassengers;
}

/*!
  * Getter for the fleetInfo
   *
    */
std::string LTCInfo::getFleetInfo() {
	return fleetInfo;
}


/*!
  * Getter for the stopInfo
  *
  */
std::string LTCInfo::getStopInfo() {
	return this->stopInfo;
}

/*!
  * Getter for the LTCPhone
   *
    */
std::string LTCInfo::getLTCPhone() {
	return LTCPhone;
}


/*!
  * Getter for the LTCEmail
   *
    */
std::string LTCInfo::getLTCEmail() {
	return LTCEmail;
}


/*!
  * Getter for the LTCAddress
  *
  */
std::string LTCInfo::getLTCAddress() {
	return LTCAddress;
}

/*!
  * Setter for the busPassengers
  *
  */
void LTCInfo::setBusPassengers(std::vector<Passenger> busPassengers) {
	this->busPassengers = busPassengers;
}


/*!
  * Setter for the fleetInfo
   *
    */
void LTCInfo::setFleetInfo(std::string fleetInfo) {
	this->fleetInfo = fleetInfo;
}


/*!
  * Setter for the stopInfo
   *
    */
void LTCInfo::setStopInfo(std::string stopInfo) {
	this->stopInfo = stopInfo;
}


/*!
  * Setter for the LTCPhone
  *
  */
void LTCInfo::setLTCPhone(std::string LTCPhone) {
	this->LTCPhone = LTCPhone;
}


/*!
  * Setter for the LTCEmail
  *
  */
void LTCInfo::setLTCEmail(std::string LTCEmail) {
	this->LTCEmail = LTCEmail;
}


/*!
  * Setter for the LTCAddress
  *
  */
void LTCInfo::setLTCAddress(std::string LTCAddress) {
	this->LTCAddress = LTCAddress;
}


/*!
  * Adds a passenger to the busPassengers vector
  *
  */
bool LTCInfo::addPassenger(Passenger passenger) {

	if (!findPassenger(passenger)) {
		
		busPassengers.push_back(passenger);
		
		return true;
	}
	return false;
}


/*!
  * Removes a passenger from the busPassengers vector
  *
  */
bool LTCInfo::removePassenger(Passenger passenger) {
	
	if (findPassenger(passenger)) {
		
		busPassengers.erase(std::remove(busPassengers.begin(), busPassengers.end(), passenger), busPassengers.end());
		
		return true;
	}
	return false;
}

/*!
  * Updates a passenger in the busPassengers vector
  *
  */

bool LTCInfo::updatePassenger(Passenger passenger) {

	if (findPassenger(passenger)) {
		busPassengers.erase(std::remove(busPassengers.begin(), busPassengers.end(), passenger), busPassengers.end());
		busPassengers.push_back(passenger);
		return true;
	}
	return false;
}


/*!
  * Finds a passenger in the busPassengers vector
  *
  */
bool LTCInfo::findPassenger(Passenger passenger) {
	auto found_passenger = std::find(LTCInfo::busPassengers.begin(), LTCInfo::busPassengers.end(), passenger);

	if(found_passenger != LTCInfo::busPassengers.end()) {
		return true;
	}
	return false;
}

/*!
  * Overloaded assignment operator
  *
  */
LTCInfo& LTCInfo::operator=(const LTCInfo& other) {
	if (this != &other) {
		
		busPassengers = other.busPassengers;
		fleetInfo = other.fleetInfo;
		stopInfo = other.stopInfo;
		LTCPhone = other.LTCPhone;
		LTCEmail = other.LTCEmail;
		LTCAddress = other.LTCAddress;
	}
	return *this;
}