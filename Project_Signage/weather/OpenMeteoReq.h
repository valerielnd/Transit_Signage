/*
 * Header file for Class OpenMeteoReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 2, 2023
 */

#include "APIReq.h"

#ifndef OPENMETEO_H_
#define OPENMETEO_H_

 /*!
  * This class represent a request to the OpenMeteo API. 
  *  It implements the APIReq class.
  *
  */
class OpenMeteoReq : public APIReq {

public:
	OpenMeteoReq();

	OpenMeteoReq(std::string url);

	virtual ~OpenMeteoReq();

	virtual const std::string& getAPIUrl() const ;

	virtual void setAPIUrl(std::string str);

	virtual const std::string& getAPIType() const ;

	virtual void setAPIType(std::string str);

	virtual ProcessWeatherData* getProcessWeatherData() const;
};

#endif // !OPENMETEO_H_