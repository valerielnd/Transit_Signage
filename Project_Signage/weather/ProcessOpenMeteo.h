
/*
 * Header file for Class ProcessOpenMeteo
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <string>
#include <iostream>
#include<map>
#include "ProcessWeatherData.h"
#include "Weather.h"


#ifndef PROCESSOPENMETEO_H_
#define PROCESSOPENMETEO_H_

 /*!
   * This class is used to process the weather data from OpenMeteo API
   * It implements the abstract class ProcessWeatherData
   *
   */
class ProcessOpenMeteo : public ProcessWeatherData{

private:

	std::map<int, std::string> weatherCode;

public:

		ProcessOpenMeteo();

		~ProcessOpenMeteo();

		virtual void processWeatherString(std::string str);

		virtual Weather returnResult() const;
};

#endif // !PROCESSOPENMETEO_H_