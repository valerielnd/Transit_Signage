/*
 * Header file for Class OpenWeatherReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 3, 2023
 */

#include "APIReq.h"

#ifndef OPENWEATHER_H_

#define OPENWEATHER_H_

 /*!
   * This class implements the class of APIReq. It is used to create an OpenWeatherReq object.
   *
   */
class OpenWeatherReq : public APIReq {

public:

	OpenWeatherReq();

	OpenWeatherReq(std::string url);

	virtual ~OpenWeatherReq();

	virtual const std::string& getAPIUrl() const ;

	virtual void setAPIUrl(std::string str);

	virtual const std::string& getAPIType() const ;

	virtual void setAPIType(std::string str) ;

	virtual ProcessWeatherData* getProcessWeatherData() const ;
};
#endif // !OPENWEATHER_H_
