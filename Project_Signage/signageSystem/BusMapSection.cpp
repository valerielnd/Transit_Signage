/*! \file BusMapSection.cpp
* 
 * Definition file for Class BusMapSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 20, 2023
 */

#include <Wt/WText.h>
#include "BusMapSection.h"
#include <Wt/WGoogleMap.h>
#include <Wt/WLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WTemplate.h>
#include <Wt/WPushButton.h>
#include <Wt/WApplication.h>


/*! \brief Constructor for BusMapSection
* 
*  This method is used to create a BusMapSection object
*  It creates a google map and sets its properties
*  It also sets the style sheet for the map
*/
BusMapSection::BusMapSection() {

    std::string googlekey = "AIzaSyA4slC - A0xd9fgUsYyYKsjb3l5bgj3zW_w";

    Wt::WApplication::instance()->readConfigurationProperty("google_api_key", googlekey);;

    auto layout = setLayout(std::make_unique<Wt::WHBoxLayout>());

    map = layout->addWidget(std::make_unique<Wt::WGoogleMap>(Wt::GoogleMapsVersion::v3));

    Wt::WApplication::instance()->styleSheet().addRule(".mapSection", "height: 68%; width:60%");

    Wt::WGoogleMap::Coordinate center(43.010172, -81.273174);

    map->panTo(center);
   
    map->setCenter(center);
    
    map->setHeight(Wt::WLength(68, Wt::LengthUnit::ViewportHeight));

    map->setStyleClass("mapSection");

    map->zoomOut();


}

/*! \brief Destructor for BusMapSection
* 
*  This method is used to delete a BusMapSection object
*/
BusMapSection::~BusMapSection() {
}


/*! \brief This method is used to set the buses that will be displayed on the map
* 
*  This method is used to set the buses that will be displayed on the map
*  It takes a vector of buses as a parameter
*  @param buses a vector of buses
* 
*/
void BusMapSection::setbusesOnMap(std::vector<Bus> buses) {

	this->busesOnMap = buses;

}

/*! \brief This method is used to add markers to the map
* 
*  This method is used to add markers to the map
*  It takes the buses coordinates and displays them on the map
*/
void BusMapSection::addMarkers() {

    map->clearOverlays();

  
    if (busesOnMap.size() > 0) {

        std::string stop = busesOnMap.at(0).getBusStopName();

        Wt::WString stopNumber = Wt::WString::fromUTF8(stop);

        map->openInfoWindow(Wt::WGoogleMap::Coordinate(stopLat, stopLong),
            stopNumber);

        for (std::size_t i = 0; i < busesOnMap.size(); i++) {

            if (busesOnMap.at(i).getBusPosition().getLat() != 0 && busesOnMap.at(i).getBusPosition().getLon() != 0) {

                Wt::WString busNumber = Wt::WString::fromUTF8((busesOnMap.at(i).getBusNumber()) + " " + busesOnMap.at(i).getBusRoute());

                map->openInfoWindow(Wt::WGoogleMap::Coordinate(busesOnMap.at(i).getBusPosition().getLat(), busesOnMap.at(i).getBusPosition().getLon()), busNumber);

            }

        }

        

	}

}

/*! \brief This method is used to set the stop position
*  
* This method is used to set the stop position
* @param lat the latitude of the stop
* @param longt the longitude of the bus
*/
void  BusMapSection::setStopPosition(double lat, double longt) {

    this->stopLat = lat;

    this->stopLong = longt;

}