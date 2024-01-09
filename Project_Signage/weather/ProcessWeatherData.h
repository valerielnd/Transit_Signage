
/*
 * Header file for Class ProcessWeatherData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <string>
#include "Weather.h"

#ifndef PROCESSWEATHERDATA_H_
#define PROCESSWEATHERDATA_H_

 /*!
  * This class is an abstract class that is used to process the weather data
  *
  */
class ProcessWeatherData {

public:

	virtual ~ProcessWeatherData() {};

	virtual void processWeatherString(std::string str) = 0;

	virtual Weather returnResult() const = 0;

protected:

	Weather weather;


};






#endif // PROCESSWEATHERDATA_H_
