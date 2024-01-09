/*
 * Defintion file for Class OpenWeatherReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 3, 2023
 */


#include <iostream>
#include <string>
#include "ProcessOpenWeather.h"
#include "OpenWeatherReq.h"

 /*!
   *  Default constructor for the class OpenWeatherReq
   *
   */
OpenWeatherReq::OpenWeatherReq() {

	OpenWeatherReq::APIType = "OpenWeather";

	OpenWeatherReq::processWeatherData = new ProcessOpenWeather();

}

/*!
  *  Constructor for the class OpenWeatherReq
  *
  */
OpenWeatherReq::OpenWeatherReq(std::string url) {
	OpenWeatherReq::APIUrl = url;
	OpenWeatherReq::APIType = "OpenWeather";
	OpenWeatherReq::processWeatherData = new ProcessOpenWeather();
}

/*!
  * Destructor for the class OpenWeatherReq
  *
  */
OpenWeatherReq::~OpenWeatherReq() {
	
	
	if (OpenWeatherReq::processWeatherData) {
	
		delete OpenWeatherReq::processWeatherData;
	}
}

/*!
  * Getter for the APIUrl
  *
  */
const std::string& OpenWeatherReq::getAPIUrl() const {
	return OpenWeatherReq::APIUrl;
}

/*!
  * Setter for the APIUrl
  *
  */
void OpenWeatherReq::setAPIUrl(std::string str) {
	OpenWeatherReq::APIUrl = str;
}

/*!
  * Getter for the APIType
  *
  */
const std::string& OpenWeatherReq::getAPIType() const {
	return OpenWeatherReq::APIType;
}

/*!
  * Setter for the APIType
  *
  */
void OpenWeatherReq::setAPIType(std::string str) {
	OpenWeatherReq::APIType = str;
}

/*!
  * This method returns the ProcessWeatherData object for the OpenMeteoReq class. 
  *
  */
ProcessWeatherData* OpenWeatherReq::getProcessWeatherData() const {
	return OpenWeatherReq::processWeatherData;
}

