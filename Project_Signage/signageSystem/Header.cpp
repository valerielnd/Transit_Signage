/*! \file Header.cpp
 * 
 * Definition file for Class Header
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WImage.h>
#include <Wt/WApplication.h>
#include <Wt/WLength.h>
#include <cmath>
#include "Header.h"



 /*! \brief Constructor for the class Header.
 *  
 *  This method contstruct a header object and set the logo, slogan, bus stop name and weather information
 *  @param stop the bus stop
 *  @param info the weather information
 *  @param lFile the file name of the logo
 *  @param sFile the file name of the slogan
 * 
 */
Header::Header(BusStop& stop, WeatherData& info, std::string lFile, std::string sFile) : bStop(stop), wInfo(info) {

	logoFile = lFile;

	sloganFile = sFile;

	stopName = bStop.getBusStopName();

	temperatureImgs = new std::map<std::string, std::string>{
    {"Clear sky", "images/sun-solid.svg"},
    {"few clouds", "images/cloud-sun-fill.svg"},
    {"mist","images/cloud-haze.svg"},
    {"shower rain","images/cloud-drizzle-fill.svg"},
    {"rain","images/cloud-sun-rain-solid.svg"},
    {"snow","images/snow2.svg"},
    {"Thunderstorm", "images/cloud-bolt-solid.svg"},
    {"scattered clouds","images/cloud-solid.svg"},
    {"broken clouds","images/clouds_fill.svg"},
	};

	createHeader();

}

/*! \brief This constructor is used to create a copy of the header.
 *
 *  This method creatse a copy of an existing header.
 *  @param other the header to copy
 *  
 *
 */
Header::Header(const Header& other)
    : bStop(other.bStop), wInfo(other.wInfo), logoFile(other.logoFile),
      sloganFile(other.sloganFile), stopName(other.stopName),
      temperatureImgs(new std::map<std::string, std::string>(*other.temperatureImgs))
{
    createHeader();
}



/*! \brief Destructor for the class Header
 *
 *   This method is used to destroy the header object
 *   It will be called automatically when an instance of the header class is destroyed
 *   
 */
Header::~Header() {
	
	delete temperatureImgs;
}




/*! \brief This method is used to create the header of the page
 *
 *  This method is used to create the header section of the page.
 *  It displays the BusStop name, the weather information and the logo of the company.
 *  
 */
void Header::createHeader() {


    /* Create the container for header components */
    auto pageHeaderCtn = std::make_unique<Wt::WContainerWidget>();

    Wt::WApplication::instance()->styleSheet().addRule(".pageHeader", "height: 12%; width: 100%;");

    pageHeaderCtn->addStyleClass("container-fluid");

    pageHeaderCtn->setHeight(Wt::WLength(12, Wt::LengthUnit::ViewportHeight));

    pageHeaderCtn->setStyleClass("pageHeader");



    /* Create the row for the header */
    auto pageHeaderRow = std::make_unique<Wt::WContainerWidget>();

    pageHeaderRow->addStyleClass("row");

    auto pageHeader = std::make_unique<Wt::WContainerWidget>();

    pageHeader->addStyleClass("navbar navbar-expand-lg navbar-dark bg-dark bg-gradient");

  

    /* Create the container for the LTC logo and Bus Name and Number */
    auto headerContainer = std::make_unique<Wt::WContainerWidget>();

    headerContainer->addStyleClass("container-fluid");

    auto logoNavbar = std::make_unique<Wt::WContainerWidget>();

    logoNavbar->addStyleClass("navbar");

    auto logoCtn = std::make_unique<Wt::WContainerWidget>();

    logoCtn->addStyleClass("container");

    auto logoNavBrand = std::make_unique<Wt::WContainerWidget>();

    logoNavBrand->addStyleClass("navbar-brand");

    Wt::WImage* LTCLogo = logoNavBrand->addWidget(std::make_unique<Wt::WImage>("images/LTC_Logo_nobg.png"));

    Wt::WImage* geoLogo = logoNavBrand->addWidget(std::make_unique<Wt::WImage>("images/bus-front-fill.svg"));

    Wt::WApplication::instance()->styleSheet().addRule(".LTCLogo", "width:130px; height:30px;");

    Wt::WApplication::instance()->styleSheet().addRule(".geoLogo", "--fa-beat-fade-opacity: 0.1; --fa-beat-fade-scale: 1.25; fill:green; color:green; width:16px; height:16px;");

    std::unique_ptr<Wt::WText> logoText = std::make_unique<Wt::WText>("<b style='color:white; font:Papyrus; font-style: oblique; font-size: 10px;'> Plan Your Trip</b>");

    logoNavBrand->addWidget(std::move(logoText));

    LTCLogo->addStyleClass("d-inline-block align-text-top");

    LTCLogo->setStyleClass("LTCLogo");

    geoLogo->addStyleClass("fa-solid fa-map-pin fa-beat-fade");

    geoLogo->setStyleClass("geoLogo");

    auto stopInfoNav = std::make_unique<Wt::WContainerWidget>();

    stopInfoNav->addStyleClass("nav navbar-nav");

    Wt::WApplication::instance()->styleSheet().addRule(".stopNav", "position:absolute; left:50%; transform:  translatex(-50%);");

    stopInfoNav->setStyleClass("stopNav");

    Wt::WApplication::instance()->styleSheet().addRule(".StopInfo", "color: #2776b0; font: Copperplate; font-weight:bold; font-size:30px; text-align: center;  ");

    std::unique_ptr<Wt::WText> StopInfo = std::make_unique<Wt::WText>(this->stopName);

    StopInfo->setStyleClass("navbar-text style='color: #2776b0'");

    StopInfo->setStyleClass("StopInfo");


    /* Get the temperature to show */
    double currentTemp = wInfo.getCurrentWeather().getWeatherValue();

    std::string tempDesc = wInfo.getCurrentWeather().getWeatherDesc();

    std::string wImageFile = (*temperatureImgs)[tempDesc];

    /*Get the image for the temperature*/
    if (wImageFile.empty()) {

		wImageFile = "images/cloud-solid.svg";

	}

    /* Create the container for the weather information */
    auto tempInfoNav = std::make_unique<Wt::WContainerWidget>();

    tempInfoNav->addStyleClass("nav navbar-nav navbar-right");

    tempImage = tempInfoNav->addWidget(std::make_unique<Wt::WImage>(wImageFile));

    textTemp = tempInfoNav->addWidget(std::make_unique<Wt::WText>(" "+std::to_string((int)round(currentTemp)) + "<span>&#8451;</span>"));

    Wt::WApplication::instance()->styleSheet().addRule(".tempImage", "fill:white; color:white; width:20px; height:20px;");

    Wt::WApplication::instance()->styleSheet().addRule(".tempInfo", "font:Papyrus; color:white ; font-style: oblique; font-size: 18px;");

    tempImage->addStyleClass("fa-solid fa-snowflake");

    tempImage->setStyleClass("tempImage");

    textTemp->setStyleClass("tempInfo");


    logoCtn->addWidget(std::move(logoNavBrand));

    logoNavbar->addWidget(std::move(logoCtn));

    headerContainer->addWidget(std::move(logoNavbar));

    stopInfoNav->addWidget(std::move(StopInfo));

    headerContainer->addWidget(std::move(stopInfoNav));

    
    headerContainer->addWidget(std::move(tempInfoNav));

    pageHeader->addWidget(std::move(headerContainer));

    pageHeaderRow->addWidget(std::move(pageHeader));

    pageHeaderCtn->addWidget(std::move(pageHeaderRow));

    addWidget(std::move(pageHeaderCtn));

}


/*! \brief This method is used to set the logo file of the header.
 *
 *  This method sets LTC logo file shown at the top of the page.
 *  @param file The file name of the logo image.
 */
void Header::setLogoFile(std::string file) {

    this->logoFile = file;

}


/*! \brief This method is used to set the slogan file of the header
 *
 *  This method sets the slogan log file shown at the top of the page.
 *  @param file The file name of the slogan image.
 */
void Header::setSloganFile(std::string file) {

	this->sloganFile = file;

}


/*! \brief This method is used to set BusStop object of the header
 *
 *  This method sets the BusStop object of the header.
 *  @param stop The BusStop object.
 */
void Header::setBusStop(BusStop& stop) {

    this->bStop = stop;
}

/*! \brief This method is used to set the weather information of the header
  *
  *  This method sets the weather information used to extract the weather information displayed in the header.
  *  @param info The WeatherData object.
  */
void  Header::setWeatherInfo(WeatherData& info) {
 
    this->wInfo = info;

}

/*! \brief This method is used to update the weather information of the header
 * 
 *  This method is used by the App main page to update the weather information displayed in the header.
 *  The weather is updated every 3 minutes.
 *  @param info The WeatherData object.
 */
void Header::updateWeatherInfo(WeatherData& info) {

     double currentTemp = info.getCurrentWeather().getWeatherValue();

    std::string tempDesc = wInfo.getCurrentWeather().getWeatherDesc();

    std::string wImageFile = (*temperatureImgs)[tempDesc];
	
	/*Get the image for the temperature*/
    if (wImageFile.empty()) {

		wImageFile = "images/cloud-solid.svg";

	}
    textTemp->setText(std::to_string((int)round(currentTemp)) + "<span>&#8451;</span>");

    tempImage->setImageLink(wImageFile);

    this->refresh();


}