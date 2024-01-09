/*! \file AppView.cpp
 * 
 * Definition file for Class AppView
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <thread>
#include <Wt/WTimer.h>
#include <Wt/WText.h>
#include "AppView.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>


 
 /*! \brief Constructor of the AppView class
    * 
    * This method creates the AppView object
    * @param env The environment of the application
    * @param busStopPos The position of the bus stop in the vector of bus stops
    * @param weatherInfo The weather information
    * @param newsInfo The news information
    * @param LTCDets The LTC information
    * 
    */
AppView::AppView(const Wt::WEnvironment& env, int busStopPos, WeatherData& weatherInfo, NewsData& newsInfo, LTCData& LTCDets) : Wt::WApplication(env) {

    this->wInfo = weatherInfo;

    this->nInfo = newsInfo;

    this->LTCAppInfo = LTCDets;

    BusStop& bus = LTCAppInfo.getAppLTC().getWesternStops()[busStopPos];

    BusStop bus1 = LTCAppInfo.getAppLTC().getWesternStops()[busStopPos];

    std::map<int, Service>& services = LTCAppInfo.getserviceTrips();
    
    timerCounter = 1;

    newsCounter = 0;

    styleSheet = new Wt::WCssStyleSheet();

    auto theme = std::make_shared<Wt::WBootstrapTheme>();

    theme->setVersion(Wt::BootstrapVersion::v3);

    wApp->setTheme(theme);

    wApp->useStyleSheet("https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css");

    wApp->useStyleSheet("https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css");


    appName = "Transit Titans";

    setTitle(appName);


    pageHeader = root()->addNew<Header>(bus, wInfo, "logo.png", "slogan.png");

   dtSection = root()->addNew<DateTimeSection>();

   dateTime = dtSection->getDateTime();

   LTCInfo info = bus.getBusStopInfo();
   
   std::vector<LTCAlert> alerts(3);

   alerts   = LTCAppInfo.fecthAlertToShow();

   busSection = root()->addNew<BusSection>(bus,dateTime,services, alerts);

   ltcSection = root()->addNew<LTCAlertAndInfoSection>(info, newsInfo);



    Wt::WApplication::instance()->styleSheet().addRule(".rootStyle", "height: 100%; width: 100%; background-color: 2F4F4F");

    root()->setStyleClass("rootStyle");

    root()->addStyleClass("container-fluid");

    root()->setHeight(Wt::WLength(100, Wt::LengthUnit::ViewportHeight));

    setTimer();

}

/*! \brief Destructor of the AppView class
    * 
    * This method destructs the AppView object
    *
    */
AppView::~AppView() {

	delete styleSheet;

}

/*! \brief This method sets the timer for updating the system
* 
* This class sets the system timer to update the app every 30 seconds
*
*/
void AppView::setTimer() {

    timer.setInterval(std::chrono::seconds(30));
    timer.timeout().connect(this, &AppView::updateApp);
    timer.start();

}

/*! \brief This method updates the system once the timer is triggered
* 
* This method updates the system once the timer is triggered every 30 seconds
*
*/
void AppView::updateApp() {

    

    std::thread updateTimeThread(&AppView::updateTimeInSystem, this);

    

    if (timerCounter % 4 == 0) {

     

       updateBusSchedule();

       ltcSection->createLTCFares();

       wInfo.getWeatherFromAPI();

       pageHeader->updateWeatherInfo(wInfo);


       

   }
    else if (timerCounter % 3 == 0) {

        
        updateBusSchedule();

        
        ltcSection->createNewsAlerts();

        newsCounter++;

        
    
    }
    else if (timerCounter % 2 == 0) {

       

        updateBusSchedule();

        ltcSection->createLTCContactInfo();

        

    }
   else {
        
        
        updateBusSchedule();
       

       ltcSection->createLTCAccessbility();



       if (newsCounter > 5) {
       
           nInfo.pullNewsData();

           ltcSection->updateNewsData(nInfo);

           newsCounter = 0;
       
       
       }

       
      

   }

    timerCounter++;
   

    updateTimeThread.join();

  
 
}

/*! \brief This method returns the time in the system
* 
*  This method returns the time and date in the system when needed by other classes
*  @return dateTime - the time dans date in the system
*/
Wt::WDateTime* AppView::getTime() {

    return dateTime;

}

/*! \brief This method updates the time in the system
* 
*  This method updates the time and date in the system
*  The update is done using a thread
*/
void AppView::updateTimeInSystem() {

    timeMtx.lock();

    dtSection->updateTime();

    dateTime = dtSection->getDateTime();

    busSection->setDateTime(dateTime);

    timeMtx.unlock();

}

/*! \brief This method updates the bus schedule
* 
*  This method updates the bus schedule in the system
*  It updates the bus schedule of each buses and the map of the buses
*/
void AppView::updateBusSchedule() {

    updateTimeInSystem();

    schedMtx.lock();

    bool done = LTCAppInfo.getRealTimeData();

    busSection->setBusScheduleInfo(done);
 
    busSection->getBuSchuduleSection()->createScheduleToShow();

    busSection->getBuSchuduleSection()->displaySchedule();

    busSection->setBusShownMap();

    schedMtx.unlock();


}
