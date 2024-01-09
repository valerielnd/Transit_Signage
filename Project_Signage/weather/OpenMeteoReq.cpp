/*
 * Definition file for Class OpenMeteoReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 2, 2023
 */


#include <iostream>
#include <string>
#include "OpenMeteoReq.h"
#include "ProcessOpenMeteo.h"


 /*!
  * This is the default constructor for the OpenMeteoReq class.
  *
  */
OpenMeteoReq::OpenMeteoReq() {

	OpenMeteoReq::APIType = "OpenMeteo";

	OpenMeteoReq::processWeatherData = new ProcessOpenMeteo();

}

/*!
  *   This is the constructor for the OpenMeteoReq class.
  *
  */
OpenMeteoReq::OpenMeteoReq(std::string url) {
	OpenMeteoReq::APIUrl = url;
	OpenMeteoReq::APIType = "OpenMeteo";
	OpenMeteoReq::processWeatherData = new ProcessOpenMeteo();
}

/*!
 * This is the destructor for the OpenMeteoReq class.
 *
 */
OpenMeteoReq::~OpenMeteoReq() {}


/*!
 * This method returns the API URL for the OpenMeteoReq class.
 *
 */
const std::string& OpenMeteoReq::getAPIUrl() const {
	return OpenMeteoReq::APIUrl;
}

/*!
 * This method sets the API URL for the OpenMeteoReq class.
 *
 */
void OpenMeteoReq::setAPIUrl(std::string str) {
	OpenMeteoReq::APIUrl = str;
}

/*!
 * This method set the API type for the OpenMeteoReq class.
 *
 */
void OpenMeteoReq::setAPIType(std::string str) {
	OpenMeteoReq::APIUrl = str;
}

/*!
 * This method returns the API type for the OpenMeteoReq class.
 *
 */
const std::string& OpenMeteoReq::getAPIType() const {
	return OpenMeteoReq::APIType;
}

/*!
 * This method returns the ProcessWeatherData object for the OpenMeteoReq class. 
 * 
 */
ProcessWeatherData* OpenMeteoReq::getProcessWeatherData() const {
	return OpenMeteoReq::processWeatherData;
}


