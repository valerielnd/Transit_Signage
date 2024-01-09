/*! \file LTCData.cpp
* 
 * Definition file for Class LTCData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>
#include <regex>
#include <ctime>
#include "LTCData.h"
#include "Schedule.h"
#include "../NewsAlert/Request2.h"
#include "../LTC/LTCAlert.h"
#include "Wt/WString.h"
#include "Wt/WTime.h"





   /*! \brief Constructor for the class LTCData
   * 
   *  This constructor is used to initialize the LTCData object. It takes in no parameters.
   *  It initializes the attributes of the class LTCData to their default values
   *
   */
LTCData::LTCData() {

	westernStopList = {"NATSCI","ALUMHAL1","ALUMHAL2","UNIVHOS1","DELAHALL","UNIVRIC1","UNIVRIC2" };

	services = new std::vector<Service>();

	busTrips = new std::map<int, Bus>();

	serviceTrips = new std::map<int, Service>();

	appLTC = LTCStops();

	LTCTxtFiles = std::vector<std::string>();

	urlLTC = "";

	LTCBuses = std::vector<Bus>();

	alertCounter = 0;


}

/*! \brief Constructor for the class LTCData
  * 
   * Constructor for the class LTCData. It takes in a vector of strings and a string.
   * The vector of strings is the list of the txt files that are used to get the data from LTC stops.
   * The string is the url of the LTC Data website.
   * @param files is a vector of strings that contains the names of the txt files
   * @param url is a string that contains the url of the LTC Data website
   * 
   */
LTCData::LTCData(std::vector<std::string> files, std::string url) {

	this->LTCTxtFiles = files;

	this->urlLTC = url;

	westernStopList = { "NATSCI","ALUMHAL1","ALUMHAL2","UNIVHOS1","DELAHALL","UNIVRIC1","UNIVRIC2" };

	services = new std::vector<Service>();

	busTrips = new std::map<int, Bus>();

	serviceTrips = new std::map<int, Service>();

	appLTC = LTCStops();

	LTCBuses = std::vector<Bus>();


}

/*! \brief Destructor for the class LTCData
 * 
  * Destructor for the class LTCData
  *
  */
LTCData::~LTCData() {


}

/*! \brief Reads a txt file and returns a vector of strings
 * 
  * This methods is used to read the txt files and return a vector of strings for each line of the txt file
  * It is used to read LTC static files
  * @param fileName is a string that contains the name of the txt file
  * @return a vector of strings that contains the lines of the txt file
  *
  */
std::vector<std::string> LTCData::readFile(std::string fileName) {

	std::ifstream file(fileName);

	std::vector<std::string> lines;

	std::string line;

	while (std::getline(file, line)) {

		lines.push_back(line);

	}

	return lines;


}

/*! \brief process the txt stop files and create a vector of BusStop objects
*   
* This method is used to parse the data from the txt files and return a vector of BusStop objects
* @param list is a vector of strings that contains the list of the stops
* @param info is a vector of strings that contains the information of the stops
*
*/
void LTCData::processStopFile(const std::vector<std::string>& list, const std::vector<std::string>& info) {


	for (size_t i = 0; i < list.size(); i++) {

		std::string stopID = list[i];


		for (size_t j = 1; j < info.size(); j++) {

			std::string stopInfo = info[j];

			if (stopInfo.find(stopID) != std::string::npos) {


				std::size_t firstComma = stopInfo.find(',');

				std::size_t secondComma = stopInfo.find(',', firstComma + 1);

				std::size_t thirdComma = stopInfo.find(',', secondComma + 1);

				std::size_t fifthComma = stopInfo.find(',', thirdComma + 1);

				std::size_t sixthComma = stopInfo.find(',', fifthComma + 1);

				std::size_t seventhComma = stopInfo.find(',', sixthComma + 1);

				try {

					std::string stopCode = stopInfo.substr(firstComma + 1, secondComma - firstComma - 1);

					int realStopCode = std::stoi(stopCode);

					std::string stopName = stopInfo.substr(secondComma + 1, thirdComma - secondComma - 1);

					std::string stopLat = stopInfo.substr(fifthComma + 1, sixthComma - fifthComma - 1);

					double realLat = std::stod(stopLat);

					std::string stopLon = stopInfo.substr(sixthComma + 1, seventhComma - sixthComma - 1);

					double realLon = std::stod(stopLon);



					BusStop busStop(stopName, stopID, realStopCode, realLat, realLon);

					appLTC.getWesternStops().push_back(busStop);

					

				}
				catch (std::invalid_argument& e) {

					std::cout << "Invalid argument: " << e.what() << std::endl;

				}
				catch (const std::out_of_range& e) {
					
				}



				




			}

		}


	}

	

}


/*! \brief process the txt service files and create a vector of services
  * 
  * This method is used to parse the data from the calendar.txt files and return a vector of Service objects
  * @param servicesLine is a vector of strings that contains the list of the services
  *
  */
void LTCData::processServiceFile(const std::vector<std::string>& servicesLine) {


	for (size_t i = 1; i < servicesLine.size(); i++) {

		std::string line = servicesLine[i];

		std::stringstream sLine(line);

		std::string field;

		std::vector<std::string> fields;

		while (std::getline(sLine, field, ',')) {

			fields.push_back(field);
		}

		
		int id = std::stoi(fields[0]);

		
		std::vector<bool> availability;

		for (std::size_t i = 1; i < fields.size() - 2; i++) {

			int val = std::stoi(fields[i]);

			availability.push_back(val == 1);
		}

		Service newService(id, availability);

		services->push_back(newService);



	}


}


/*! \brief Parses string data and returns a json object
  * 
  * This method is used to parse the data from the txt files and return a Json Object
  * @param data is a string that contains the data to be parsed
  *
  */
json LTCData::parseLFilesData(std::string data) {

	json j = json::parse(data);

	return j;

}

/*! \brief Creates the LTCInfo object
  * 
  * This method is used the create the data for the LTCInfo object
  * The information are about LTC's fleet and stops accessibility and the fare for each passenger type
  *
  */
void LTCData::createStopsLTCInfo() {

	LTCInfo appLTCInfo;

	Passenger adult("Adult", 3.0);

	appLTCInfo.addPassenger(adult);

	Passenger Student("Student", 3.0);

	appLTCInfo.addPassenger(Student);

	Passenger Senior("Senior", 3.0);

	appLTCInfo.addPassenger(Senior);

	Passenger Child("Child (12 years and under)", 0.0);

	appLTCInfo.addPassenger(Child);

	appLTCInfo.setFleetInfo("Fleet - 100% low-floor accessible. Customers requiring the use of the kneeling feature or the ramp should request same at time of boarding.");

	appLTCInfo.setStopInfo("Stop - 100% accessible (with the exception of locations without a connecting sidewalk)");

	appLTCInfo.setLTCAddress("450 Highbury Avenue North, N5W 5L2");

	appLTCInfo.setLTCPhone("519-451-1347");

	appLTCInfo.setLTCEmail("ltc@londontransit.ca");



	if (this->getAppLTC().getWesternStops().size() > 0) {



		for (size_t i = 0; i < this->getAppLTC().getWesternStops().size(); i++) {



			this->getAppLTC().getWesternStops()[i].setBusStopInfo(appLTCInfo);



		}

	}




}


/*! \brief Getter method for the BusStops
* 
  * Getter method for the BusStops of the APP
  *  @return the vector of BusStops
  *
  */
LTCStops& LTCData::getAppLTC() {

	return this->appLTC;

}

/*! \brief Getter method for the LTC static text files
  * 
  * Getter method for the vector of strings of the txt files
  * @return the vector of strings of the txt files
  *
  */
std::vector<std::string> LTCData::getLTCTxtFiles() {

	return this->LTCTxtFiles;
}

/*! \brief Getter method for the url of the LTC
*  
* Getter method for the url of the LTC
* @return the url of the LTC
*
*/
std::string LTCData::getUrlLTC() {

	return this->urlLTC;
}

/*! \brief Setter for the url of the LTC
  *  
  * This method is used to set the url of the LTC
  * @param url is a string that contains the url of the LTC
  *
  */
void LTCData::setUrlLTC(std::string url) {

	this->urlLTC = url;

}

/*! \brief Setter method for the vector of strings of the txt files
  * 
  * Setter method for the vector of strings of the txt files
  * @param files is a vector of strings that contains the list of the txt files
  *
  */
void LTCData::setLTCTxtFiles(std::vector<std::string> files) {

	this->LTCTxtFiles = files;
}

/*! \brief Setter method for the BusStops
  * 
  * Setter method for the BusStops of the APP
  * @param appLTC is a LTCStops object that contains the list of BusStops
  *
  */
void LTCData::setAppLTC(LTCStops appLTC) {

	this->appLTC = appLTC;

}

/*! \brief Setter method for the list of stops at Western
  * 
  * Setter method for the list of BusStops at Western
  * @param westernStopList is a vector of strings that contains the list of BusStops at Western
  *
  */
void LTCData::setWesternStopList(std::vector<std::string> westernStopList) {

	this->westernStopList = westernStopList;
}



/*! \brief Getter method for the list of stops at Western
  *
  * Getter method for the vector of list of BusStops at Western
  * @return the vector of strings that contains the list of BusStops at Western
  *
  */
const std::vector<std::string>& LTCData::getWesternStopList() const {

	return this->westernStopList;


}

/*! \brief thie method creates the LTCStops
  *
  * This method is used to create the LTCStops object that contain the list of bus stops
  *
  */
void LTCData::createLTCStops() {

	if (this->LTCTxtFiles.size() > 0) {

		std::vector<std::string> stopsInfo = readFile(LTCTxtFiles[0]);

		processStopFile(westernStopList, stopsInfo);


	}
}

/*! \brief Creates the service days for the buses
  * 
  * This method is used to create the serviceDays for the buses
  *
  */
void LTCData::createServiceDays() {

	if (this->LTCTxtFiles.size() > 0) {

		std::vector<std::string> calendarInfo = readFile(LTCTxtFiles[5]);

		processServiceFile(calendarInfo);



	}


}



/*! \brief Creates the bus that will pass trough the stop
*  
* This method is used to read the stop text file and create the bus that will pass trough that stop
* @param stopFile - the name of the stop file that contain the stops information about the buses and their trips
*/
void LTCData::createLTCBus() {

	std::vector<std::string> tripLines = readFile(LTCTxtFiles[3]);

	for (size_t i = 1; i < tripLines.size(); i++) {

		std::string routeID = tripLines[i].substr(0, tripLines[i].find(','));

		std::string line = tripLines[i];

		std::size_t firstComma = line.find(',');

		std::size_t secondComma = line.find(',', firstComma + 1);

		std::size_t thirdComma = line.find(',', secondComma + 1);

		std::size_t fourthComma = line.find(',', thirdComma + 1);

		std::size_t fifthComma = line.find(',', fourthComma + 1);

		std::size_t sixthComma = line.find(',', fifthComma + 1);

		std::string serviceID = line.substr(firstComma + 1, secondComma - firstComma - 1);

		int realServiceID = std::stoi(serviceID);

		std::string tripID = line.substr(secondComma + 1, thirdComma - secondComma - 1);

		int realTripID = std::stoi(tripID);

		std::string tripHeadsign = line.substr(thirdComma + 1, fourthComma - thirdComma - 1);

		std::string directionID = line.substr(fifthComma + 1, sixthComma - fifthComma - 1);

		Bus newBus(routeID, tripHeadsign);

		Schedule newSchedule;

		newBus.setBusSchedule(newSchedule);

		busTrips->insert(std::pair<int, Bus>(realTripID, newBus));

		size_t size = 0;

		bool found = false;

		while (size < services->size() && not found) {

			Service service = (*services)[size];

			if (service.getServiceID() == realServiceID) {

				serviceTrips->insert(std::pair<int, Service>(realTripID, service));

				found = true;


			}

			size++;
		}


	}
	
}


/*! \brief Finds a bus in the list of buses at the bus stop
* 
* This method is used to find a bus in the list of buses at the bus stop
* @param bus is a Bus object that represents the bus to be found in the list of buses at the bus stop
* @return true if the bus is found in the list of buses at the bus stop, false otherwise
*/
bool LTCData::findBus(Bus bus) const {


	if (LTCBuses.size() == 0) {

		return false;

	}

	else {

		for (size_t i = 0; i < LTCBuses.size(); i++) {

			if (bus == LTCBuses[i]) {

				return true;

			}
		}
		return false;
	}



}


/*! \brief get a bus from list of buses at the bus stop
*  
*  This method is used to get a bus from the list of buses at the bus stop
*  @param busNumber is a string that represents the bus number
*  @param route is a string that represents the route of the bus
*/
Bus& LTCData::getBus(std::string busNumber, std::string route) {

	if (LTCBuses.size() != 0) {

		for (size_t i = 0; i < LTCBuses.size(); i++) {

			if (LTCBuses[i].getBusNumber() == busNumber && LTCBuses[i].getBusRoute() == route) {

				return LTCBuses[i];

			}
		}
	}
	throw std::runtime_error("Element not found");



}

/*! \brief Sets the buses schedule
*   
*  This method retrieves the buses schedule from LTC static file and sets the buses schedule
*/
void LTCData::addScheduleToBus() {

	std::vector<std::string> tripLines = readFile(LTCTxtFiles[4]);

	for (size_t i = 1; i < tripLines.size(); i++) {

		std::string tripID = tripLines[i].substr(0, tripLines[i].find(','));

		if (busTrips->find(std::stoi(tripID)) != busTrips->end()) {

			Bus bus = busTrips->operator[](std::stoi(tripID));

			std::string line = tripLines[i];

			std::size_t firstComma = line.find(',');

			std::size_t secondComma = line.find(',', firstComma + 1);

			

			std::size_t thirdComma = line.find(',', secondComma + 1);

			std::size_t fourthComma = line.find(',', thirdComma + 1);

			

			std::string arrivalTime = line.substr(firstComma + 1, secondComma - firstComma - 1);

			Wt::WString timeString(arrivalTime);

			Wt::WTime time = Wt::WTime::fromString(timeString, "hh:mm:ss");

			std::string departureTime = line.substr(secondComma + 1, thirdComma - secondComma - 1);

			std::string stopID = line.substr(thirdComma + 1, fourthComma - thirdComma - 1);

			if (appLTC.getWesternStops().size() > 0) {

				if (appLTC.getBusStop(stopID).findBus(bus.getBusNumber(), bus.getBusRoute())) {

					try {

						appLTC.getBusStop(stopID).getBus(bus).addTripID(std::stoi(tripID));

						appLTC.getBusStop(stopID).getBus(bus).getBusSchedule().addStopTime(std::stoi(tripID), time);

						
					}
					catch (std::runtime_error& e) {

						

					}

				}
				else {

					bus.setBusStopName(stopID);

					bus.addTripID(std::stoi(tripID));

					bus.getBusSchedule().addStopTime(std::stoi(tripID), time);

					bus.getBusSchedule().setBusNumber(bus.getBusNumber());

					bus.getBusSchedule().setBusStopName(stopID);


					appLTC.getBusStop(stopID).addBus(bus);
				}


			}
		}


	}




}

/*! \brief This method sorts the bus schedule 
* 
*  This method sorts the bus schedule in ascending order
*  @param stopTimes is a map that represents the bus schedule
*/
void LTCData::sortBusSchedule(std::map<int, Wt::WTime> stopTimes) {

	std::vector<std::pair<int, Wt::WTime>> stopTimesVector;
	for (const auto& stopTime : stopTimes) {
		stopTimesVector.emplace_back(stopTime);
	}

	
	std::sort(stopTimesVector.begin(), stopTimesVector.end(), [](const auto& a, const auto& b) {
		return a.second < b.second;
		});

	
	std::map<int, Wt::WTime> sortedStopTimes;
	for (const auto& stopTime : stopTimesVector) {
		sortedStopTimes.emplace(stopTime);
	}

}

/*! \brief This method fixes the broken JSON TripUpdates.json file fetch from LTC API
* 
*  This method fixes the broken JSON TripUpdates.json file fetch from LTC API
*  This file contain the real time information about the bus stop times
*  @param content is a string that represents the broken JSON file
*/
std::string LTCData::fixLTCJSON(std::string& content) {

	if (content != "") {

		std::regex pattern("\\},\\s*\\{\"id\":");


		std::string newContent = std::regex_replace(content, pattern, "}},{\"id\":");

		std::string end_str = "}]}";

		if (newContent.substr(newContent.length() - end_str.length()) == end_str) {
			newContent = newContent.substr(0, newContent.length() - end_str.length()) + "}}]}";
		}

		return newContent;
	}

	return "";

}


/* \brief This method fetch	the real time data from the LTC API
* 
*  This method fetch the real time data from the LTC API
*  This data contain real-time information about the buses stop times
*  @return true if the data was fetched successfully
*/
bool LTCData::getRealTimeData() {
	bool success = false;

	std::string urlReq = "http://gtfs.ltconline.ca/TripUpdate/TripUpdates.json";

	/* Define a String object to contain the data pulled from the API*/
	std::string content;

	/* Define a request object to fecth data from NHL API*/
	Request2 dataReq(urlReq);

	/* Execute the request and if the return value is true*/
	if (dataReq.Execute()) {

		/* Get the data pulled for the API*/
		content = dataReq.result();

		/*If the data was received from the API*/
		if (content != "") {

			/*Fix the json obtained*/
			//std::string newContent = fixLTCJSON(content);
			std::string newContent = content;

			/*Parse the json data*/
			if (newContent != "") {

				json obj = parseLTCRealTimeData(newContent);


				/*If the json data was parsed correctly*/
				if (obj != NULL) {

					success = true;

					/*Get the timestamp*/
					std::time_t timeStamp = obj["header"]["timestamp"];

					std::string timeString = convertTimeStamp(timeStamp);

					//Wt::WTime timeUpdate = Wt::WTime::fromString(timeString, "hh:mm:ss");

					/*Get the array of entities*/
					json entities = obj["entity"];

					/*Iterate through the entities*/
					for (size_t i = 0; i < entities.size(); i++) {

						/*Get the trip update*/
						json tripUpdate = entities[i]["trip_update"];

						/*Get the trip id*/
						std::string tripID = tripUpdate["trip"]["trip_id"];

						/*Get the stop time update*/
						json stopTimeUpdate = tripUpdate["stop_time_update"];

						for (size_t j = 0; j < stopTimeUpdate.size(); j++) {

							std::string stopID = stopTimeUpdate[j]["stop_id"];

							if (isStringInVector(stopID) && appLTC.getBusStop(stopID).getBusList().size() > 0) {

								Bus bus = busTrips->operator[](std::stoi(tripID));

								std::time_t arrivalTime = std::time_t(-1);

								if (!stopTimeUpdate[j]["arrival"].is_null()) {

									arrivalTime = stopTimeUpdate[j]["arrival"]["time"];

								}
								else if (!stopTimeUpdate[j]["departure"].is_null()) {

									arrivalTime = stopTimeUpdate[j]["departure"]["time"];

								}

								if (arrivalTime != std::time_t(-1)) {

									std::string newtimeString = convertTimeStamp(arrivalTime);

									Wt::WTime newTime = Wt::WTime::fromString(newtimeString, "hh:mm:ss");

									try {

										if (appLTC.getBusStop(stopID).getBus(bus).getBusNumber() != "NA") {


											appLTC.getBusStop(stopID).getBus(bus).getBusSchedule().updateStopTime(std::stoi(tripID), newTime);

										}
									}
									catch (std::exception& e) {

										

									}

								}



							}




						}


					}
				}


			}



		}

	}
	return success;
}

/*! \brief This method fetch	the real time bus positions from the LTC API
* 
*  This method fetch the real time bus positions from the LTC API
*  This information is used to display the bus positions on the map
*/
bool LTCData::getVehiclePosition() {

	bool success = false;

	std::string urlReq = "http://gtfs.ltconline.ca/Vehicle/VehiclePositions.json";

	/* Define a String object to contain the data pulled from the API*/
	std::string content;

	/* Define a request object to fecth data from NHL API*/
	Request2 dataReq(urlReq);

	/* Execute the request and if the return value is true*/
	if (dataReq.Execute()) {

		/* Get the data pulled for the API*/
		content = dataReq.result();

		/*If the data was received from the API*/
		if (content != "") {

			json obj = parseLTCRealTimeData(content);


			/*If the json data was parsed correctly*/
			if (obj != NULL) {

				success = true;

				/*Get the timestamp*/
				std::time_t timeStamp = obj["header"]["timestamp"];

				std::string timeString = convertTimeStamp(timeStamp);

				//Wt::WTime timeAlertEnd = Wt::WTime::fromString(timeString, "hh:mm:ss");

				/*Get the array of entities*/
				json entities = obj["entity"];

				/*Iterate through the entities*/
				for (size_t i = 0; i < entities.size(); i++) {

					/*Get the trip update*/
					json vehicle = entities[i]["vehicle"];

					/*Get the trip id*/
					std::string tripID = vehicle["trip"]["trip_id"];

					int realtTripID = std::stoi(tripID);

					std::string routeID = vehicle["trip"]["route_id"];

					for (std::size_t j = 0; j < appLTC.getWesternStops().size(); j++) {

						try {

							Bus& foundBus = appLTC.getWesternStops().at(j).getBus(routeID, realtTripID);

							if (foundBus.getBusNumber() != "NA") {

								/*Get the stop time update*/
								json position = vehicle["position"];

								double lat = position["latitude"];

								double lon = position["longitude"];

								Position Pos(lat, lon);

								foundBus.setBusPosition(Pos);

								int congestion = vehicle["congestion_level"];

								std::string realCongestion = std::to_string(congestion);

								foundBus.setBusCongestion(realCongestion);

								int occupancy = vehicle["occupancy_status"];

								foundBus.setBusOccupancy(occupancy);

							}

						}
						catch (std::exception& e) {

							//std::cout << e.what() << std::endl;

						}	
					}


				}


			}

		}

	}
	return success;

}


/*! \brief This method fetch the alerts from the LTC API
*  
*  This method fetch the alerts from the LTC API
*  Those alerts are about detours, delays and stops closed
*/
json LTCData::parseLTCRealTimeData(const std::string& ltcString) {


	/* Convert the JSON data to a JSON object*/
	auto jObj = json::parse(ltcString, nullptr, false);

	/* If an error occured*/
	if (jObj.is_discarded()) {

		std::cerr << "Parse JSON error" << std::endl;

		return NULL;
	}
	else {

		json object = jObj;

		return object;

	}


}


/*! \brief This method convert a time stamp to a string time
* 
*  This method convert a time stamp to a string time in the format hh:mmm
*  @param stamp The time stamp to convert
*  @return The string time
*/
void LTCData::getLTCAlerts(std::vector<LTCAlert>& alerts) {

	std::string urlReq = "http://gtfs.ltconline.ca/Alert/Alerts.json";

	/* Define a String object to contain the data pulled from the API*/
	std::string content;

	/* Define a request object to fecth data from NHL API*/
	Request2 dataReq(urlReq);

	/* Execute the request and if the return value is true*/
	if (dataReq.Execute()) {

		/* Get the data pulled for the API*/
		content = dataReq.result();

		/*If the data was received from the API*/
		if (content != "") {

			json obj = parseLTCRealTimeData(content);


			/*If the json data was parsed correctly*/
			if (obj != NULL) {

				/*Get the array of entities*/

				json entities = obj["entity"];

				/*Iterate through the entities*/
				for (size_t i = 0; i < entities.size(); i++) {

					/*Get the trip alert*/
					json alert = entities[i]["alert"];

					/*Get the Stop id*/
					std::string alertInformedStop = alert["informed_entity"][0]["stop_id"];

					/*Get the aler id*/
					std::string alertID = entities[i]["id"];

					/*Get the alert period */
					std::time_t alertStart = alert["active_period"][0]["start"];

					std::time_t alertEnd = alert["active_period"][0]["end"];

					std::string timestart = convertTodate(alertStart);

					//Wt::WTime timeAlertStart = Wt::WTime::fromString(timestart, "hh:mm:ss");

					std::string timeEnd = convertTodate(alertEnd);

					//Wt::WTime timeAlertEnd = Wt::WTime::fromString(timeEnd, "hh:mm:ss");

					std::string alertPeriod = timestart + "-" + timeEnd;


					/*Get the route id*/
					std::string alertInformedRoute = alert["informed_entity"][0]["route_id"];

					/*Get the alert*/
					int alertEffect = alert["effect"];

					/*Get the alert cause*/
					int alertCause = alert["cause"];

	
					/* Get the alert text*/
					std::string alerDesc = alert["description_text"]["translation"][0]["text"];

					std::string alertText = alerDesc.substr(0, alerDesc.find(".", alerDesc.find(".") + 1) + 1);

					LTCAlert newAlert(alertID, alertInformedRoute, alertPeriod, alertInformedStop, std::to_string(alertCause), std::to_string(alertEffect), alertText);

					alerts.push_back(newAlert);
						


				}

			}

		}

	}

	

}

/*! \brief This method convert a time stamp to a string time
* 
*  This method convert a time stamp to a string time in the format hh:mmm
*  @param stamp The time stamp to convert
*  @return The string time
*/
std::string LTCData::convertTimeStamp(std::time_t stamp) {

	std::stringstream stime;
    struct tm timeinfo;
    localtime_r(&stamp, &timeinfo);
    stime << std::setfill('0') << std::setw(2) << timeinfo.tm_hour << ":" << std::setw(2) << timeinfo.tm_min << ":" << std::setw(2) << timeinfo.tm_sec;
    std::string result = stime.str();
    return result;

}

/*! \brief This method convert a time stamp to a string date
* 
*  This method convert a time stamp to a string date in the format dd/mm/yyyy
*  @param stamp The time stamp to convert
*  @return The string date
*/
std::string LTCData::convertTodate(std::time_t stamp) {

	std::tm now;
    localtime_r(&stamp, &now); 
	
    std::stringstream date_ss;
    date_ss << std::setfill('0') << std::setw(2) << now.tm_mday << '/'
            << std::setw(2) << (now.tm_mon + 1) << '/' 
            << (now.tm_year + 1900);
    std::string dateStr = date_ss.str();

    return dateStr;

}


/*! \brief this method verify if a string is in a vector of western stop list
* 
*  This method verify if a string is in a vector of western stop list
*  @param str The string to verify
*  @return True if the string is in the vector, false otherwise
*/
bool LTCData::isStringInVector(const std::string& str) {

	for (const auto& element : westernStopList) {
		if (element == str) {
			return true;
		}
	}
	return false;

}

/*! \brief This method return the vector of services associated with a bus trips
* 
*  This method return the vector of services associated with a bus trips
*  @return The vector of services associated with a bus trips
*/
std::map<int, Service>& LTCData::getserviceTrips() {

	return *serviceTrips;

}

/*! \brief this method fetches the LTC alerts
* 
*  This method fetches the LTC alerts
*  @return The vector of alerts to show
*/
std::vector<LTCAlert> LTCData::fecthAlertToShow() {

	std::vector<LTCAlert> alerts;
	
	getLTCAlerts(alerts);

	std::vector<LTCAlert> alertsToShow;

	if (alerts.size() > 0) {

		while (alertsToShow.size() < 3 and alertCounter < static_cast<int>(alerts.size())) {

			if (alerts[alertCounter].getAlerText() != "") {
			
				alertsToShow.push_back(alerts[alertCounter]);
			
			}

			alertCounter++;

		}

	}
	if (alertCounter == static_cast<int>(alerts.size())) {

		alertCounter = 0;

	}
	return alertsToShow;

}