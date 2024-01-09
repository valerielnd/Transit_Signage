/*
 * Header file for Class ProcessWeather
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 9, 2023
 */


#include <string>
#include <iostream>
#include<map>
#include "ProcessWeatherData.h"
#include "Weather.h"

#ifndef PROCESSOPEN_H_

#define PROCESSOPEN_H_

 /*!
   * This class is used is used to process the weather data from OpenWeatherMap API
   * It implements the abstract class ProcessWeatherData
   *
   */
class ProcessOpenWeather : public ProcessWeatherData {


public:

	ProcessOpenWeather();

	~ProcessOpenWeather();

	virtual void processWeatherString(std::string str);

	virtual Weather returnResult() const ;



};

#endif // !PROCESSOPEN_H_
