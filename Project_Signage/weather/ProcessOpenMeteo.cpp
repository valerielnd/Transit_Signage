/*
 * Definition file for Class ProcessOpenMeteo
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <iostream>
#include <string>
#include "Weather.h"
#include "ProcessOpenMeteo.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

/*!
  * Default constructor of the class ProcessOpenMeteo
  *
  */
ProcessOpenMeteo::ProcessOpenMeteo() {

	ProcessOpenMeteo::weatherCode = {

		{0, "Clear sky"},

		{1,"few clouds"},

		{2,"few clouds"},

		{3,"few clouds"},

		{45, "mist"},

		{48, "mist"},

		{51, "shower rain"},

		{53, "shower rain"},

		{55, "shower rain"},

		{61, "rain"},

		{63, "rain"},

		{65, "rain"},

		{66, "rain"},

		{67, "rain"},

		{71, "snow"},

		{73, "snow"},

		{75, "snow"},

		{77, "snow"},

		{95, "Thunderstorm"},

		{96, "Thunderstorm"},

		{99, "Thunderstorm"},


	};

}	

/*!
  * Destructor of the class ProcessOpenMeteo
  *
  */
ProcessOpenMeteo::~ProcessOpenMeteo() {}

/*!
  * This method is used to process the string data fetched from OpenMeteo API
  *
  */
void ProcessOpenMeteo::processWeatherString(std::string str) {

	auto jObj = json::parse(str, nullptr, false);

	
	if (jObj.is_discarded()) {

		std::cerr << "Parse JSON error" << std::endl;
	}
	else {

		json object = jObj;

		int currentcode = object["current_weather"]["weathercode"];

		std::string currentDesc = "";

		if (currentcode) {
		
			currentDesc = ProcessOpenMeteo::weatherCode[currentcode];
		
		}

		double currentTemp = object["current_weather"]["temperature"];


		ProcessOpenMeteo::weather.setWeatherDesc(currentDesc);

		ProcessOpenMeteo::weather.setWeatherValue(currentTemp);

		ProcessOpenMeteo::weather.setWeatherFeel(currentTemp);

		ProcessOpenMeteo::weather.setWeatherUnit("C");
	}
}

/*!
  * This method is used to return the weather object
  *
  */
Weather ProcessOpenMeteo::returnResult() const {

	return ProcessOpenMeteo::weather;

}
