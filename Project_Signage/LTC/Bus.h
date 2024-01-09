/*! \file Bus.h
 * 
 * Header file for Class Bus
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */
 
#include<string>
#include<vector>
#include "Service.h"
#include "Position.h"
#include "Schedule.h"

#ifndef BUS_H_
#define BUS_H_


 /*! \brief This class represents a bus object.
   * 
   * This class represents a bus object. It contains the bus number, 
   * the bus route, the bus occupancy, the bus position, the bus schedule, 
   * the bus congestion, the bus stop name, the stop ID and the trip IDs.
   * 
   */
class Bus {


private:

	std::string busNumber; 

	int stopID; 

	std::string busStopName; 

	std::string busRoute;

	int busOccupancy;

	Position busPosition;

	Schedule busSchedule;

	std::map<int, Service> busServices;

	std::vector<int> TripIDs;

	std::string busCongestion;

	int showPosition; 

	std::map<int, std::string> occupancyStatus;

	std::vector<Service> services;

public:

	Bus();

	Bus(std::string busNumber, std::string busRoute);

	~Bus();

	std::string getBusNumber();

	int getStopID();

	std::string getBusStopName();

	std::string getBusRoute();

	int getBusOccupancy();

	Position getBusPosition();

	Schedule& getBusSchedule();

	std::vector<int> getTripIDs();

	std::string getBusCongestion();

	std::string getOccupancyStatus(int occupancy);

	int getShowPosition(); 

	std::map<int, Service> getBusServices(); 

	void setBusNumber(std::string busNumber);

	void setStopID(int stopID);

	void setBusStopName(std::string busStopName);

	void setBusRoute(std::string busRoute);

	void setBusOccupancy(int busOccupancy);

	void setBusPosition(Position busPosition);

	void setBusSchedule(Schedule busSchedule);

	void setTripIDs(std::vector<int> TripIDs);

	void setBusCongestion(std::string busCongestion);

	void setShowPosition(int showPosition); 
	
	void setBusServices(std::map<int, Service> busServices); 
	
	bool addTripID(int tripID);
	
	bool removeTripID(int tripID);

	bool addBusService(int trip, Service service); 

	bool operator==(const Bus& other) const;

};
#endif // !BUS_H_
