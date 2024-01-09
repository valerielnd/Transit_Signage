/*
 * Definition file for Class ProcessWeather
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 9, 2023
 */

#include <iostream>
#include <string>
#include "ProcessOpenWeather.h"
#include "Weather.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

ProcessOpenWeather::ProcessOpenWeather() {}

ProcessOpenWeather::~ProcessOpenWeather() {}

/*!
 * Constructor for the class ProcessOpenWeather
 *
 */
void ProcessOpenWeather::processWeatherString(std::string str) {

	auto jObj = json::parse(str, nullptr, false);

	if (jObj.is_discarded()) {

		std::cerr << "Parse JSON error" << std::endl;
	}
	else {

		json object = jObj;

		std::string currentDesc = object["weather"][0]["description"];

		double currentTemp = object["main"]["temp"];

		double feelLike = object["main"]["feels_like"];

		ProcessOpenWeather::weather.setWeatherDesc(currentDesc);

		ProcessOpenWeather::weather.setWeatherValue(currentTemp);

		ProcessOpenWeather::weather.setWeatherFeel(feelLike);

		ProcessOpenWeather::weather.setWeatherUnit("C");



	}

	
}

/*!
  * This method returns the weather object
  *
  */
Weather ProcessOpenWeather::returnResult() const {

	return ProcessOpenWeather::weather;

}



