/*
 * Header file for Class APIReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi 
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <string>
#include"ProcessWeatherData.h"

#ifndef APIREQ_H_H
#define APIREQ_H_H

 /*!
  * This class represents a request to the weather APIs
  * It is an abstract class
  */
class APIReq {


protected:

	std::string APIUrl;  /**< API URL */

	std::string APIType;  /**< API Type */

	ProcessWeatherData* processWeatherData; /**< A pointer to an instance of processWeatherData to called to process the data once fetched */

public:

	virtual ~APIReq() {};

	virtual const std::string& getAPIUrl() const = 0;

	virtual void setAPIUrl(std::string str) = 0;

	virtual const std::string& getAPIType() const = 0;

	virtual void setAPIType(std::string str) = 0;

	virtual ProcessWeatherData* getProcessWeatherData() const = 0;




};


#endif // !APIREQ_H_H
