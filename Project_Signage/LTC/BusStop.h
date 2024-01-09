/*! \file BusStop.h
 * Header file for Class BusStop
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <vector>
#include <string>
#include "Bus.h"
#include "LTCAlert.h"
#include "LTCInfo.h"


#ifndef BUSSTOP_H_
#define BUSSTOP_H_

 /*! \class BusStop
   * 
   * \brief Class BusStop
   * 
   *  This class is used to create a BusStop object that represents LTC bus stops at Western
   *  It contains a vector of Bus objects, a vector of LTCAlert objects, a LTCAlert object, 
   *  a LTCInfo object, a string for the bus stop name, a string for the bus stop ID, 
   *  a double for the bus stop latitude, a double for the bus stop longitude, and an int for the bus stop code
   *
   *
   */
class BusStop {

private:

	std::vector<Bus> busList;
	
	std::string busStopName;

	std::string busStopID;

	int busStopCode;

	std::vector<LTCAlert> alertList;

	LTCAlert busStopAlert;

	LTCInfo busStopInfo;

	double busStopLat;

	double busStopLong;


public:

	BusStop();

	BusStop(std::string busStopName, std::string busStopID);

	BusStop(std::string stopName, std::string stopID, int stopCode, double stopLat, double stopLon);

	~BusStop();

	void setBusStopName(std::string busStopName);

	void setBusStopID(std::string busStopID);

	void setBusStopAlert(LTCAlert busStopAlert);

	void setBusStopInfo(LTCInfo busStopInfo);

	void setBusList(std::vector<Bus> busList);

	void setAlertList(std::vector<LTCAlert> alertList);

	std::string getBusStopName();

	std::string getBusStopID();

	LTCAlert getBusStopAlert();

	LTCInfo getBusStopInfo();

	std::vector<Bus>& getBusList();

	std::vector<LTCAlert>& getAlertList();

	bool addBus(Bus bus);

	bool removeBus(Bus bus);

	Bus& getBus(Bus busToFind);

	Bus& getBus(std::string, int tripID);

	bool findBus(std::string busNumber, std::string busRoute);

	bool findBus(Bus bus);

	bool operator==(const BusStop& other) const;

	int getStopCode();

	void setBusStopCode(int busStopCode);

	double getBusStopLat();

	void setBusStopLat(double busStopLat);

	double getBusStopLong();

	void setBusStopLong(double busStopLong);

	bool findAlert(LTCAlert alert);

	bool addAlert(LTCAlert alert);

	bool removeAlert(LTCAlert alert);

	LTCAlert& getAlert(LTCAlert alertToFind);




};

#endif // !BUSSTOP_H_
