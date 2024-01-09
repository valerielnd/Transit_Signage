/*! \file BusSection.cpp
 * 
 * Definiton file for Class BusSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 20, 2023
 */

#include "BusSection.h"



/*! \brief Constructor for the class BusSection.
*  
*  This constructor is used toconstruct section on the web page where the bus schedule and bus map are displayed.
*  @param stop is the bus stop for which the bus schedule and bus map are displayed
*  @param dateTime is the curennt date and time 
*/
BusSection::BusSection(BusStop& stop, Wt::WDateTime* dateTime, std::map<int, Service>& services, std::vector<LTCAlert> alerts)  {

	/* Create the container for to hold all the components of the section*/
	auto busSectionCtn = std::make_unique<Wt::WContainerWidget>();

	busSectionCtn->addStyleClass("container-fluid");


	/* Create the row to hold the bus schedule and bus map*/
	auto busSectionRow = std::make_unique<Wt::WContainerWidget>();
	
	busSectionRow->addStyleClass("row bg-light bg-gradient");



	/* Create the column to hold the schedule section*/
	busScheduleSection = busSectionRow->addNew<BusScheduleSection>(stop, dateTime, services);
	
	busScheduleSection->setAlerts(alerts);

	busScheduleSection->addStyleClass("col");



	/* Create the column to hold the map section*/
	busMapSection = busSectionRow->addNew<BusMapSection>();

	setStopPosition(stop.getBusStopLat(), stop.getBusStopLong());

	setBusShownMap();

	busMapSection->addStyleClass("col");



	/* Add the busSectionRow to the BusSection container*/
	busSectionCtn->addWidget(std::move(busSectionRow));

	/* Add the BusSection container to the BusSection widget so that it can appear on the web page*/
	addWidget(std::move(busSectionCtn));


}

/*! \brief Destructor for the class BusSection.
* 
*  This destructor is used to destroy the BusSection object
*/
BusSection::~BusSection() {

}


/*! \brief This function is used to get the BusScheduleSection object.
* 
*  This function is used to get the BusScheduleSection object by the App main class to updated the bus schedule information
*/
BusScheduleSection* BusSection::getBuSchuduleSection() {

	return busScheduleSection;

}


/*! \brief This function is used to set the date and time for the bus schedule.
* 
*  This function is used to set the date and time for the bus schedule.
*  This information is used to select the right stop time to display
*/
void BusSection::setDateTime(Wt::WDateTime* dateTime) {

	busScheduleSection->setDateTime(dateTime);

}


/*! \brief This function is used to set the information label for the bus schedule.
* 
*  This function is used to set the information label for the bus schedule.
*  This information is used to tell the user if the bus schedule is based on real-time information or LTC pre-planned schedule
*/
void BusSection::setBusScheduleInfo(bool result) {

	busScheduleSection->setInfoLabel(result);

}

/*! \brief This function is used to set the bus shown on the map.
* 
*  This function is used to set the list of bus shown on the map base on which bus schedule are displayed.
*/
bool  BusSection::setBusShownMap() {

	if (busScheduleSection->getBusShown().size() >0) {

		busMapSection->setbusesOnMap(busScheduleSection->getBusShown());

		busMapSection->addMarkers();

		return true;

	}

	return false;

}


/*! \brief This function is used to set the position of the bus stop on the map.
* 
*  This function is used to set the position of the bus stop on the map.
*  @param lat is the latitude of the bus position
*  @param longt	is the longitude of the bus position
*/
void BusSection::setStopPosition(double lat, double longt) {

	busMapSection->setStopPosition(lat, longt);

}