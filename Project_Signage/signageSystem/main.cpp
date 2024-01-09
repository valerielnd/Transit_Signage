/*! \file main.cpp
 * Definition file for main class of the Signage System
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */
 
#include <iostream>
#include <vector>
#include <Wt/WServer.h>
#include "../weather/APIReq.h"
#include "../weather/ProcessWeatherData.h"
#include "../weather/WeatherData.h"
#include "../NewsAlert/NewsArticle.h"
#include "../NewsAlert/NewsData.h"
#include "../NewsAlert/JSONReq.h"
#include "../weather/Weather.h"
#include "../weather/APIReq.h"
#include "../weather/OpenMeteoReq.h"
#include "../weather/OpenWeatherReq.h"
#include "../weather/Position.h"
#include "../LTC/LTCData.h"
#include "SignageSystem.h"
#include "AppView.h"



 /*! \brief This method is used to create an application for each Bus stop at Western
   * 
   * Method to create an application for each Bus stop at Western
   * @param env The environment of the application
   * @param str The name of the Bus stop
   *
   */
template <typename T>
std::unique_ptr<Wt::WApplication> createApplication3(const Wt::WEnvironment& env, std::string str)
{
 
    return std::make_unique<T>(env, str);
}

/*! \brief This is the main method for the Signage System
  * 
  * The main method for the Signage System
  * It creates a WT:WApplication for each Bus stop at Western
  * 
  * 
  *
  */
int main(int argc, char** argv) {

	SignageSystem westernSys;

	/* Create The app LTC Data*/
	
	westernSys.createLTCData();

	LTCData newLTC = westernSys.getLTCData();

	
	/* Create The app Weather Data*/

	westernSys.createWeatherData();

	WeatherData newWeather = westernSys.getWeatherData();


	/* Create The app news Data*/

	westernSys.createNewsData();

	NewsData newNews = westernSys.getNewsData();

    try {
        Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);

        server.addEntryPoint(Wt::EntryPointType::Application, [&](const Wt::WEnvironment& env) {
            //BusStop arg1 = newLTC.getAppLTC().getWesternStops()[0];
            int arg1 = 0;
            WeatherData arg2 = newWeather;
            NewsData arg3 = newNews;
            LTCData arg4 = newLTC;
        return std::make_unique<AppView>(env, arg1,arg2,arg3, arg4); }, "/natsci");

        server.addEntryPoint(Wt::EntryPointType::Application, [&](const Wt::WEnvironment& env) {
            //BusStop arg1 = newLTC.getAppLTC().getWesternStops()[1];
            int arg1 = 1;
            WeatherData arg2 = newWeather;
            NewsData arg3 = newNews;
            LTCData arg4 = newLTC;
        return std::make_unique<AppView>(env, arg1, arg2, arg3, arg4); }, "/alumhal1");


        server.run();

    }
    catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }


}

