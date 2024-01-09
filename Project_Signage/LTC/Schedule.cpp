/*
 * Definition file for Class Schedule
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 5, 2023
 */

#include <algorithm>
#include "Schedule.h"



 /*!
   * Default Constructor for Schedule class
   *
   */
Schedule::Schedule() {

	busNumber = "";
	tripIDs = {};
	busStopName = "";
	stopTimes = {};

}

/*!
  * Constructor for Schedule class
  *
  */
Schedule::Schedule(std::string busNumber, std::vector<int> tripIDs, std::string busStopName) {
	this->busNumber = busNumber;
	this->tripIDs = tripIDs;
	this->busStopName = busStopName;
	stopTimes = {};
}

/*!
  * Destructor for Schedule class
  *
  */
Schedule::~Schedule() {}

/*!
  * Getter for busNumber
  *
  */
std::string Schedule::getBusNumber() {
	return busNumber;
}

/*!
  * Getter for tripIDs
  *
  */
std::vector<int> Schedule::getTripIDs() {
	return tripIDs;
}

/*!
  * Getter for busStopName
  *
  */
std::string Schedule::getBusStopName() {
	return busStopName;
}

/*!
  * Getter for stopTimes
  *
  */
std::map<int, Wt::WTime> Schedule::getStopTimes() {
	return stopTimes;
}

/*!
  * Setter for busNumber
  *
  */
void Schedule::setBusNumber(std::string busNumber) {
	this->busNumber = busNumber;
}

/*!
  * Setter for tripIDs
   *
    */
void Schedule::setTripIDs(std::vector<int> tripIDs) {
	this->tripIDs = tripIDs;
}


/*!
  * Setter for busStopName
  *
  */
void Schedule::setBusStopName(std::string busStopName) {
	this->busStopName = busStopName;
}


/*!
  * Setter for stopTimes
  *
  */
void Schedule::setStopTimes(std::map<int, Wt::WTime> stopTimes) {
	this->stopTimes = stopTimes;
}


/*!
  * Adds a stop time to the schedule
  *
  */
bool Schedule::addStopTime(int tripID, Wt::WTime stopTime) {
	if (stopTimes.find(tripID) == stopTimes.end()) {
		stopTimes.insert(std::pair<int, Wt::WTime>(tripID, stopTime));
		return true;
	}
	else {
		return false;
	}
}

/*!
  * Updates a stop time in the schedule
  *
  */
bool Schedule::updateStopTime(int tripID, Wt::WTime stopTime) {
	if (stopTimes.find(tripID) != stopTimes.end()) {
		stopTimes[tripID] = stopTime;
		return true;
	}
	else {
		return false;
	}
}

/*!
  * Removes a stop time from the schedule
  *
  */
bool Schedule::removeStopTime(int tripID) {
	if (stopTimes.find(tripID) != stopTimes.end()) {
		stopTimes.erase(tripID);
		return true;
	}
	else {
		return false;
	}
}

void Schedule::sortStopTimes() {

	std::vector<std::pair<int, Wt::WTime>> stopTimesVector;
	for (const auto& stopTime : stopTimes) {
		stopTimesVector.emplace_back(stopTime);
	}

	// sort the vector by the second element (Wt::WTime) in ascending order
	std::sort(stopTimesVector.begin(), stopTimesVector.end(), [](const auto& a, const auto& b) {
		return a.second < b.second;
		});

	// create a new map from the sorted vector
	std::map<int, Wt::WTime> sortedStopTimes;

	for (const auto& stopTime : stopTimesVector) {
		sortedStopTimes.insert(stopTime);
	}

	for (const auto& stopTime : sortedStopTimes) {
		std::cout << stopTime.first << ": " << stopTime.second.hour() << ":" << stopTime.second.minute() << std::endl;
	}

	this->setStopTimes(sortedStopTimes);
}

