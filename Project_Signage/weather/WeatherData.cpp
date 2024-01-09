/*
 * Definition file for Class WeatherData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <iostream>
#include <string>
#include <vector>
#include "Request2.h"
#include "nlohmann/json.hpp"
#include "WeatherData.h"

using json = nlohmann::json;

/*!
  * Default constructor for class WeatherData
  *
  */
WeatherData::WeatherData() {}

/*!
  * Constructor for class WeatherData
  *
  */
WeatherData::WeatherData(Position pos, std::vector<std::string> desc, std::vector<APIReq*> APIs) {
	
	WeatherData::cityPos = pos;
	
	WeatherData::weatherDesc = desc;
	
	WeatherData::APIs = APIs;
}


/*!
  * Destructor for class WeatherData
  *
  */
WeatherData::~WeatherData() {}

/*!
  * Getter for city Position
  *
  */
Position WeatherData::getCityPos() const {
	return WeatherData::cityPos;
}

/*!
  * Getter for weather description
  *
  */
std::vector<std::string> WeatherData::getWeatherDesc() const {
	return WeatherData::weatherDesc;
}

/*!
  * Getter for Weather APIs
  *
  */
const std::vector<APIReq*>& WeatherData::getAPIs() const {
	return WeatherData::APIs;
}

/*!
  * Getter for current weather
  *
  */
Weather WeatherData::getCurrentWeather() const {
	return WeatherData::currentWeather;
}

/*!
  * Setter for city Position
  *
  */
void WeatherData::setCityPos(Position pos) {
	WeatherData::cityPos = pos;
}

/*!
  *	 Setter for weather description
  *
  */
void WeatherData::setWeatherDesc(std::vector<std::string> desc) {
	WeatherData::weatherDesc = desc;
}

/*!
  * Setter for Weather APIs
  *
  */
void WeatherData::setAPIs(std::vector<APIReq*> APIs) {
	WeatherData::APIs = APIs;
}


/*!
  * Setter for current weather
  *
  */
void WeatherData::setCurrentWeather(Weather weather) {
	WeatherData::currentWeather = weather;
}

/*
  * Method to compare two WeatherData objects
  *
  */
bool WeatherData::isEqual(const WeatherData& other) {
	return (WeatherData::cityPos.isEqual(other.cityPos) && WeatherData::weatherDesc == other.weatherDesc && WeatherData::APIs == other.APIs);
}

/*!
  * Method to get weather data from APIs
  *
  */
void WeatherData::getWeatherFromAPI() {

	std::vector<APIReq>::size_type size = WeatherData::APIs.size();

	std::vector<APIReq>::size_type index = 0;

	bool done = false;

	if (!APIs.empty()) {

		while ((index < size) && (!done)) {

			APIReq* urlReq = WeatherData::APIs[index];

			std::cout << urlReq->getAPIUrl() << std::endl;

			std::string dataFectchWeather = WeatherData::getWeatherString(urlReq->getAPIUrl());

			if (dataFectchWeather != "") {

				done = true;


				urlReq->getProcessWeatherData()->processWeatherString(dataFectchWeather);

				WeatherData::currentWeather = urlReq->getProcessWeatherData()->returnResult();

				


			}	

			index++;

		}
	
	
	
	}

}

/*!
  * Method to fecth the weather string trough the API
  *
  */
std::string WeatherData::getWeatherString(std::string url) {

	std::string weatherString;

	Request2 request(url);

	if (request.Execute()) {

		weatherString = request.result();

	}

	return	weatherString;
}

/*!
  * Method to get the city position from the API
  *
  */
void WeatherData::setCityPosition(std::string url) {

	Request2 request(url);

	if (request.Execute()) {

		std::string result = request.result();

		if (result != "") {

			auto pos = json::parse(result);

			if (pos.is_discarded()) {

				std::cerr << "Parse JSON error" << std::endl;

			}
			else {

				json object = pos;

				json cityPos = pos[0];

				double lat = cityPos["lat"];

				double lon = cityPos["lon"];

				Position NewPos(lat, lon);

				WeatherData::setCityPos(NewPos);

			}
		}

	}

}

/*!
  * Method to get the city position
   *
    */
Position WeatherData::getCityPosition() const {

	return WeatherData::cityPos;

}