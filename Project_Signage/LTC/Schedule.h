
/*
 * Header file for Class Schedule
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 5, 2023
 */

#include <string>
#include <vector>
#include <map>
#include "Wt/WTime.h"

#ifndef SCHEDULE_H

#define SCHEDULE_H

 /*!
   * TThis class is used to store the schedule of a bus stop
   *
   */
class Schedule{

private:

	std::string busNumber;

	std::vector<int> tripIDs;

	std::string busStopName;

	std::map<int, Wt::WTime> stopTimes;


public:
		Schedule();

		Schedule(std::string busNumber, std::vector<int> tripIDs, std::string busStopName);

		~Schedule();

		std::string getBusNumber();

		std::vector<int> getTripIDs();

		std::string getBusStopName();

		std::map<int, Wt::WTime> getStopTimes();

		void setBusNumber(std::string busNumber);

		void setTripIDs(std::vector<int> tripIDs);

		void setBusStopName(std::string busStopName);

		void setStopTimes(std::map<int, Wt::WTime> stopTimes);

		bool addStopTime(int tripID, Wt::WTime stopTime);

		bool updateStopTime(int tripID, Wt::WTime stopTime);

		bool removeStopTime(int tripID);

		void sortStopTimes();
};

#endif // !SCHEDULE_H
