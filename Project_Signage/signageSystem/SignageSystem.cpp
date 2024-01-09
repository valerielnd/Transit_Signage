/*! \file SignageSystem.cpp
* 
 * Definition file for Class SignageSystem
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include "SignageSystem.h"
#include "../weather/APIReq.h"
#include "../NewsAlert/URLReq.h"
#include "../weather/OpenMeteoReq.h"
#include "../weather/OpenWeatherReq.h"
#include "../NewsAlert/JSONReq.h"
#include "../NewsAlert/HTMLReq.h"

 /*! \brief Constructor for SignageSystem
 * 
  * This method construct the SignageSystem
  * It initializes all the variables to their default values
  */
SignageSystem::SignageSystem() {
	
	createNewsUrl();

	createWeatherUrl();

	createLTCFiles();

}

/*! \brief Destructor for SignageSystem
 * 
 * Destructor for SignageSystem
 *
 */
SignageSystem::~SignageSystem() {}


/*! \brief This method is used to create the news urls 
 * 
 * This method creates the urls to connect to the Western News Website and the News API
 * 
 *
 */
void SignageSystem::createWeatherUrl() {

	std::string openWeather = "https://api.openweathermap.org/data/2.5/weather?lat=42.9832406&lon=-81.243372&units=metric&appid=4f2b6b9258463b4ef2e0c27bc9ee5183";

	APIReq* openWAPI = new OpenWeatherReq(openWeather);

	weatherAPIs.push_back(openWAPI);

	std::string openMeteo = "https://api.open-meteo.com/v1/forecast?latitude=42.9832406&longitude=-81.243372&current_weather=true";

	APIReq* openMAPI = new OpenMeteoReq(openMeteo);

	weatherAPIs.push_back(openMAPI);
}

/*! \brief This method is used to create the news urls 
 * 
 * This method creates the urls to connect to the Western News Website and the News API
 * 
 *
 */
void SignageSystem::createNewsUrl() {
	
	std::string westernSite = "https://news.westernu.ca/campus/";
	
	URLReq* westernURL = new HTMLReq(westernSite);

	newsAPIs.push_back(westernURL);

	std::string APINews = "https://newsapi.org/v2/top-headlines?country=ca&category=general&pageSize=5&apiKey=5675f3f6a72d4ec78d0f2189de86afd7";

	URLReq* newsAPIURL = new JSONReq(APINews);

	newsAPIs.push_back(newsAPIURL);
}

/*! \brief This method is used to create the LTC text files
 * 
 * This method creates the vector of LTC text files
 * Those files are the static file with bus, stops, trips information
 * They contain LTC pre-planned schedule for the buses
 *
 */
void SignageSystem::createLTCFiles() {

	std::vector<std::string> files = { "ltcFiles/stops.txt", "ltcFiles/stop_times.txt","ltcFiles/routes.txt","ltcFiles/trips.txt", "ltcFiles/natsci.txt", "ltcFiles/calendar.txt"};

	LTCFiles = files;

}

/*! \brief Sets the LTC text files
 * 
 * This method sets the LTC text files
 * @param files is the vector of LTC text files
 *
 */
void SignageSystem::setLTCFiles(std::vector<std::string> files) {
	this->LTCFiles = files;
}

/*! \brief Sets the news APIs
 * 
 * This method sets the news APIs
 * @param APIs is the vector of news APIs
 *
 */
void SignageSystem::setNewsAPIs(std::vector<URLReq*> APIs) {
	this->newsAPIs = APIs;
}



/*! \brief Sets the weather APIs
* 
 * This method sets the weather APIs
 * @param APIs is the vector of weather APIs
 *
 */
void SignageSystem::setWeatherAPIs(std::vector<APIReq*> APIs) {
	this->weatherAPIs = APIs;
}


/*! \brief This method is used to create the news data needed in the system
 * 
 * This method creates the news data
 * The data is based on the information retrieve from the news APIs
 *
 */
void SignageSystem::createNewsData() {

	if (newsAPIs.size() > 0) {
		
		newsAppData.setNewsAPIs(newsAPIs);

		newsAppData.pullNewsData();
	}

}


/*! \brief This method is used to create the weather data needed in the system
 * 
 * This method creates the weather data 
 *  The data is based on the information retrieve from the weather APIs
 * 
 */
void SignageSystem::createWeatherData() {

	if (weatherAPIs.size() > 0) {
		
		weatherAppData.setAPIs(weatherAPIs);

		weatherAppData.getWeatherFromAPI();
	}

}

/*! \brief This method is used to create the LTC data needed in the system
 * 
 * This method creates the LTC data
 * It creates the LTC stops, the stops information, the service days, the buses, the trips and the schedule for the buses
 *
 */
void SignageSystem::createLTCData() {

	LTCAppData.setLTCTxtFiles(LTCFiles);

	LTCAppData.createLTCStops();

	LTCAppData.createStopsLTCInfo();

	LTCAppData.createServiceDays();

	LTCAppData.createLTCBus();

	LTCAppData.addScheduleToBus();

	LTCAppData.getRealTimeData();

	LTCAppData.getVehiclePosition();


}


/*! \brief Getter for the LTC data
 * 
 * This method returns the LTC data
 * @return the LTCData object
 *
 */
LTCData SignageSystem::getLTCData() const {

	return LTCAppData;


}

/*! \brief Getter for the news data
 * 
 * This method returns the news data
 * @return the NewsData object
 * 
 */
NewsData SignageSystem::getNewsData() const {

	return newsAppData;

}

/*! \brief Getter for the weather data
 * 
 * This method returns the weather data 
 * @return the WeatherData object
 * 
 */
WeatherData SignageSystem::getWeatherData() const {

	return weatherAppData;

}