/*! \file LTCData.h
* 
 * Header file for Class LTCData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */
#include "LTCStops.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

#ifndef LTCDATA_H_
#define LTCDATA_H_

/*! \class LTCData
* 
*  \brief This class reprents all the LTC data of the APP
* 
* This class reprents all the LTC data of the APP
* It is used to fetch the data from the LTC files and website
*
*/
class LTCData{

private:

		std::vector<std::string> westernStopList;

		LTCStops appLTC;

		std::vector<std::string> LTCTxtFiles;

		std::string urlLTC;

		std::vector<Bus> LTCBuses;

		std::vector<Service>* services;

		std::map<int, Bus>* busTrips;

		std::map<int, Service>* serviceTrips;
		
		int alertCounter;


public:

	LTCData();

	LTCData(std::vector<std::string> files, std::string url);
	
	~LTCData();

	LTCStops& getAppLTC();

	std::vector<std::string> readFile(std::string fileName);

	void processStopFile(const std::vector<std::string>& list, const std::vector<std::string>& info);

	void processServiceFile(const std::vector<std::string>& servicesLine);

	json parseLFilesData(std::string data);

	std::vector<std::string> getLTCTxtFiles();

	std::string getUrlLTC();

	void setUrlLTC(std::string url);

	void setLTCTxtFiles(std::vector<std::string> files);

	void setAppLTC(LTCStops appLTC);

	void setWesternStopList(std::vector<std::string> westernStopList);

	const std::vector<std::string>& getWesternStopList() const;

	void createStopsLTCInfo();

	void createLTCStops();

	void createLTCBus();

	void createServiceDays();

	bool findBus(Bus bus) const;

	Bus& getBus(std::string busNumber, std::string route);

	void addScheduleToBus();

	void sortBusSchedule(std::map<int, Wt::WTime> stopTimes);

	std::string fixLTCJSON(std::string& content);

	bool getRealTimeData();

	bool getVehiclePosition();

	void getLTCAlerts(std::vector<LTCAlert>& alerts);

	json parseLTCRealTimeData(const std::string& ltcString);

	std::string convertTimeStamp(std::time_t stamp);

	std::string convertTodate(std::time_t stamp);
	
	bool isStringInVector(const std::string& str);

	std::map<int, Service>& getserviceTrips();
	
	std::vector<LTCAlert> fecthAlertToShow();
};

#endif // !LTCDATA_H_