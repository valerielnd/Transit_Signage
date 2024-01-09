/*! \file SignageSyste.h
* 
 * Header file for Class SignageSystem
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include "../LTC/LTCData.h"
#include "../NewsAlert/NewsData.h"
#include "../weather/WeatherData.h"
#include "../weather/APIReq.h"
#include "../NewsAlert/URLReq.h"
#include <iostream>
#include <string>
#include <vector>



#ifndef SYGNAGESYSTEM_H_
#define SYGNAGESYSTEM_H_

 /*! \class SignageSystem
 *   
 * \brief This class represents the Signage System being built
 * 
  * This class represents the Signage System being built. 
  * It is responsible for creating the data for view classes
  *
  */
class SignageSystem {

private:

	LTCData LTCAppData;
	
	NewsData newsAppData;
	
	WeatherData weatherAppData;
	
	std::vector<std::string> LTCFiles;
	
	std::vector<URLReq*> newsAPIs;
	
	std::vector<APIReq*> weatherAPIs;

	void createWeatherUrl();

	void createNewsUrl();

	void createLTCFiles();

public:

	SignageSystem();

	~SignageSystem();

	void setLTCFiles(std::vector<std::string> files);

	void setNewsAPIs(std::vector<URLReq*> APIs);

	void setWeatherAPIs(std::vector<APIReq*> APIs);

	void createLTCData();

	void createNewsData();

	void createWeatherData();

	LTCData getLTCData() const;

	NewsData getNewsData() const;

	WeatherData getWeatherData() const;

	



};

#endif // !SYGNAGESYSTEM_H_

