/*! \file AppView.h
* 
 * Header file for Class AppView
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <string>
#include <mutex>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WBootstrapTheme.h>
#include <Wt/WApplication.h>
#include "Header.h"
#include "../NewsAlert/NewsData.h"
#include"../LTC/BusStop.h"
#include "../LTC/LTCData.h"
#include "DateTimeSection.h"
#include "LTCAlertAndInfoSection.h"
#include "BusSection.h"


#ifndef APPVIEW_H
#define APPVIEW_H


 /*! \class AppView
 * 
 *   \brief Class that represents the main view class of the application
*    This class represents  the main view of the application
*    It is responsible for displaying the header, date and time, weather, news and ltc information
*/
class AppView : public Wt::WApplication{

private:


    std::string appName;

    Wt::WCssStyleSheet* styleSheet;

    WeatherData wInfo;

    NewsData nInfo;

    LTCData LTCAppInfo;

    Header* pageHeader;

    DateTimeSection* dtSection;

    LTCAlertAndInfoSection* ltcSection;

    BusSection* busSection;

    std::string testText;

    Wt::WTimer timer;

    Wt::WContainerWidget* resultDtSection;

    int timerCounter;

    int newsCounter;

    Wt::WDateTime* dateTime;

    std::mutex timeMtx;

    std::mutex schedMtx;

   

public:

    AppView(const Wt::WEnvironment& env, int busStopPos, WeatherData& weatherInfo, NewsData& newsInfo, LTCData& LTCDets);

    ~AppView();

    void setTimer();

    void updateApp();

    Wt::WDateTime* getTime();

    void updateTimeInSystem();

    void updateBusSchedule();


};

#endif // !APPVIEW_H