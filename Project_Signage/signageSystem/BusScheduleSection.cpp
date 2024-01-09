/*! \file BusScheduleSection.cpp
*
 * Definition file for Class BusScheduleSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 20, 2023
 */

#include <cstdlib>
#include <algorithm>
#include <Wt/WText.h>
#include <Wt/WApplication.h>
#include <Wt/WString.h>
#include <Wt/WTableRow.h>
#include <Wt/WLabel.h>
#include <Wt/WImage.h>
#include <Wt/WDate.h>
#include "BusScheduleSection.h"


/*! \brief Constructor for BusScheduleSection.
*   
*  This constructor will create the bus schedule section and display the bus schedule
*  @param stop is the bus stop for the current signage
*  @param dateTime is the current date and time
*  @param services is the list of services for the trips going by that signage
*
* 
*/
BusScheduleSection::BusScheduleSection(BusStop& stop, Wt::WDateTime* dateTime, std::map<int, Service>& services) : bStop(stop), busDateTime(dateTime), tripsServices(services) {

	bStop = stop;

	busDateTime = dateTime;

	busesGroup = 0;

	groupShowed = 0;

	tripsServices = services;

	ltcAlerts = new std::vector<LTCAlert>(3);

	Wt::WApplication::instance()->styleSheet().addRule(".busSchedule", "height: 48%; width:40%");

	busScheduleCtn = this->addWidget(std::make_unique<Wt::WContainerWidget>());

	busScheduleCtn->addStyleClass("container-fluid px-2");

	busScheduleCtn->addStyleClass("busSchedule");

	busScheduleCtn->setHeight(Wt::WLength(48, Wt::LengthUnit::ViewportHeight));
	
	
	alertCtn = this->addWidget(std::make_unique<Wt::WContainerWidget>());

	alertCtn->addStyleClass("container border border-2");

	alertCtn->setHeight(Wt::WLength(20, Wt::LengthUnit::ViewportHeight));
	
	
	schedCtn = busScheduleCtn->addWidget(std::make_unique<Wt::WContainerWidget>());

	schedCtn->addStyleClass("container");


	if (stop.getBusList().size() > 0) {

		createDisplayedBus();

		createScheduleToShow();
		
		firstShow = true;

		displaySchedule();
		
	}
	
}

/*! \brief Destructor for BusScheduleSection.
* 
*  This destructor will delete the bus schedule section
*/
BusScheduleSection::~BusScheduleSection() {
}

/*! \brief This method sets the datetime used by this section.
* 
*   This method is used to set the datetime to the current datetime in the system
*   @param dateTime is the current datetime in the system
*/
void BusScheduleSection::setDateTime(Wt::WDateTime* dateTime) {

  busDateTime = dateTime;


}

/*! \brief This method is used to divide the buses to show in groups of 5.
* 
*	This method divides the buses to show in groups of 5 since they will be shown in rotation in the web page
*   
* 
*/
void BusScheduleSection::createDisplayedBus() {

	auto result = std::div(bStop.getBusList().size(), MAX_BUS);

	int numRotation = result.quot;

	int remainderBus = result.rem;

	int first = 0;

	if (numRotation <= 0) {

		std::map<int, int> busMap;
	
		busMap.insert(std::pair<int, int>(first, bStop.getBusList().size() -1));
	
	}
	else {
	
		for (int i = 0; i < numRotation; i++) {

			std::map<int, int> busMap;

			busMap.insert(std::pair<int, int>(first, first + (MAX_BUS - 1)));

			displayedBus.push_back(busMap);

			first += MAX_BUS;

		}

		if (remainderBus > 0) {

			std::map<int, int> busMap;

			busMap.insert(std::pair<int, int>(first, bStop.getBusList().size() - 1));

			displayedBus.push_back(busMap);

		}
	
	}

}

/*! \brief This method is used to create the schedule to show on the web page
* 
*	This methods creates the schedule to show on the web page by getting the buses to show and the current time
*   It will show schedule for bus that match the current time and is no more than 2 hours from the current time
*/
void BusScheduleSection::createScheduleToShow() {

	if (busesGroup > static_cast<int>(displayedBus.size())) {
	
		busesGroup = 0;
	
	}

	groupShowed = busesGroup;

	int groupToshow = groupShowed;

	Wt::WTime timeSchedule = busDateTime->time();


	if (groupToshow < static_cast<int>(displayedBus.size())) {

		int first;

		int last;
	
		std::map<int, int> elementToShow = displayedBus.at(groupToshow);

		for (const auto& kvp : elementToShow) {
			
			first = kvp.first;
			
			last = kvp.second;
		}


		if (displayedBus.size() > 0) {

			for (int i = first; i <= last; i++) {

				Bus busToshow = bStop.getBusList().at(i);

				Schedule busSchedule = busToshow.getBusSchedule();

				if (busSchedule.getStopTimes().size() > 0) {

					std::map<int, Wt::WTime> stopTimes = busSchedule.getStopTimes();

					std::vector<std::pair<int, Wt::WTime>> sortedStopTimes = sortSchedule(stopTimes);

					auto it = std::find_if(sortedStopTimes.begin(), sortedStopTimes.end(),
						[&](const std::pair<int, Wt::WTime>& stopTime) {
							return stopTime.second > timeSchedule && stopTime.second < timeSchedule.addSecs(7200);
						});

					int firstIndex = -1;

					if (it != sortedStopTimes.end()) {
						firstIndex = std::distance(sortedStopTimes.begin(), it);
					}
					
					busToshow.setShowPosition(firstIndex);

					bStop.getBusList().at(i).setShowPosition(firstIndex);
				}




			}



		}
	
	}	
	busesGroup++;
}

/*! \brief This method is used to display the schedule on the web page
* 
*	This mehod uses the group of buses to show and the current time to display the schedule on the web page
*   It also set the buses which position need to be shown on the map
*/
void BusScheduleSection::displaySchedule() {
	
	std::map<std::string, std::string>  congestionInfo = {
	   { "0", "Runing Smoothly" },
	   { "1", "Runing Smoothly" },
	   { "2", "Stop and Go" },
	   { "3", "Congestion" },
	   { "4", "Severe Congestion" }
	 };
	 

	int groupToshow = groupShowed;

	int row = 1;

	if (busesShown.size() > 0) {
	
		busesShown.clear();
	
	}

	if (groupToshow < static_cast<int>(displayedBus.size())) {

		int first;

		int last;

		std::map<int, int> elementToShow = displayedBus.at(groupToshow);

		for (const auto& kvp : elementToShow) {

			first = kvp.first;

			last = kvp.second;
		}

		int numToShow = getNumberOfBus(first, last);

		if (numToShow > 0) {
			
			schedCtn->clear();

			if (firstShow) {

				infoCtn = busScheduleCtn->insertWidget(0, std::make_unique<Wt::WContainerWidget>());

				infoCtn->addStyleClass("container");

				Wt::WApplication::instance()->styleSheet().addRule(".infoLogo", "width:25px; height:25px;");

				Wt::WImage* infoLogo = infoCtn->addWidget(std::make_unique<Wt::WImage>("images/live.svg"));

				infoLogo->addStyleClass("fa-solid fa-tower-broadcast fa-beat-fade");

				infoLogo->setStyleClass("infoLogo");

				infoLabel = infoCtn->addWidget(std::make_unique<Wt::WLabel>(" LTC Buses Schedule"));

				Wt::WApplication::instance()->styleSheet().addRule(".infoLabel", "font:Papyrus; color:Green; font-size: 20px; font-weight:bold; padding:2px");

				infoLabel->setStyleClass("infoLabel");

				firstShow = false;
			}
			
			

			busScheduleTable = schedCtn->addWidget(std::make_unique<Wt::WTable>());

			busScheduleTable->setHeaderCount(1);

			busScheduleTable->addStyleClass("table table-md table-info table-borderless");

			Wt::WApplication::instance()->styleSheet().addRule(".headerRow", "color: white; font: Copperplate; font-weight: bold; font-size: 15px; text-align: center;");

			Wt::WText* rowTextBus = busScheduleTable->elementAt(0, 0)->addNew<Wt::WText>("Bus");

			rowTextBus->setStyleClass("headerRow");

			busScheduleTable->elementAt(0,1)->addNew<Wt::WText>("Ocuppancy");

			rowTextBus->setStyleClass("headerRow");
			
			Wt::WText* rowCongestion = busScheduleTable->elementAt(0, 2)->addNew<Wt::WText>("Congestion");

			rowCongestion->setStyleClass("headerRow");
			

			Wt::WText* rowTextRoute = busScheduleTable->elementAt(0, 3)->addNew<Wt::WText>("Route");

			rowTextRoute->setStyleClass("headerRow");

			Wt::WText* rowTextArrival = busScheduleTable->elementAt(0, 4)->addNew<Wt::WText>("Estimated Arrival");

			rowTextArrival->setStyleClass("headerRow");

			for (int i = first; i <= last; i++) {

				Bus busToshow = bStop.getBusList().at(i);

				Schedule busSchedule = busToshow.getBusSchedule();

				int firstIndex = busToshow.getShowPosition();

				if (firstIndex >= 0) {

					std::vector<Wt::WTime> nextFourSchedules;

					if (busSchedule.getStopTimes().size() > 0) {

						std::map<int, Wt::WTime> stopTimes = busSchedule.getStopTimes();

						std::vector<std::pair<int, Wt::WTime>> sortedStopTimes = sortSchedule(stopTimes);

						int k = firstIndex;
						
						while (nextFourSchedules.size() < 2 && k < static_cast<int>(sortedStopTimes.size())){

							int key = std::next(sortedStopTimes.begin(), k)->first;

							Service service = tripsServices[key];

							Wt::WDate dateSchedule = busDateTime->date();

							int day = dateSchedule.dayOfWeek();

							if (day > 0) {
							
								bool result = service.findServiceDay(day - 1);

								if (result) {
								
									Wt::WTime value = std::next(sortedStopTimes.begin(), k)->second;

									nextFourSchedules.push_back(value);
									
									busesShown.push_back(busToshow);
								
								}
							
							}
							
							k++;
							
						}

						if (nextFourSchedules.size() > 0) {


							std::sort(nextFourSchedules.begin(), nextFourSchedules.end(), [](const Wt::WTime& a, const Wt::WTime& b) {
								return a < b;
								});


							Wt::WApplication::instance()->styleSheet().addRule(".scheduleText", "color: black; font: Copperplate; font-weight:bold; font-size:15px; text-align: center; padding: 3px; ");

							std::string busNumber = busToshow.getBusNumber();

							Wt::WText* busNum = busScheduleTable->elementAt(row, 0)->addNew<Wt::WText>(busNumber);

							busNum->setStyleClass("scheduleText");

							
							Wt::WApplication::instance()->styleSheet().addRule(".statusImage", "width:25px; height:25px;");
							
							std::int16_t busOccupancy = busToshow.getBusOccupancy();

							std::string statusImage = busToshow.getOccupancyStatus(busOccupancy);

							if (statusImage == "") {

								statusImage = "images/lack.png";

							}

							Wt::WImage* busOcc = busScheduleTable->elementAt(row, 1)->addNew<Wt::WImage>(statusImage);
							
							busOcc->setStyleClass("statusImage");
							
							
							std::string busCongestion = busToshow.getBusCongestion();
							
							std::string congestionStatus = congestionInfo[busCongestion];

							if (congestionStatus == "") {

								congestionStatus = "Unknown";

							}

							busScheduleTable->elementAt(row, 2)->addNew<Wt::WText>(congestionStatus);

							

							std::string busRoute = busToshow.getBusRoute();

							Wt::WText* busRte = busScheduleTable->elementAt(row, 3)->addNew<Wt::WText>(busRoute);

							busRte->setStyleClass("scheduleText");

							
							Wt::WString bSchedule = "";

							for (Wt::WTime key : nextFourSchedules) {

								Wt::WString bTime = key.toString("hh:mm");

								bSchedule = bSchedule + bTime + " ";
							}

							busScheduleTable->elementAt(row, 4)->addNew<Wt::WText>(bSchedule);
							
							row++;
						}
					}

				}
			}

			Wt::WTableRow* firstRow = busScheduleTable->rowAt(0);
			
			firstRow->setStyleClass("table-dark");

		}
		
	}


}

/*! \brief This function displays the alerts for the bus stop
*
*  This function displays the alerts for the LTC
*  It will show them in group of 3 in rotation
*
*/
void BusScheduleSection::displayLTCAlerts() {

	alertCtn->clear();
	

	/* Create the logo and the title for the alerts */

	Wt::WApplication::instance()->styleSheet().addRule(".alertLogo", "width:25px; height:25px;");

	Wt::WImage* alertLogo = alertCtn->addWidget(std::make_unique<Wt::WImage>("images/info-square-fill.svg"));

	alertLogo->addStyleClass("bi bi-info-square-fill");

	alertLogo->setStyleClass("infoLogo");


	auto alertLabel = alertCtn->addWidget(std::make_unique<Wt::WLabel>(" LTC Alerts"));

	Wt::WApplication::instance()->styleSheet().addRule(".alertLabel", "font:Papyrus; color:red; font-size: 20px; font-weight:bold; padding:2px");

	alertLabel->setStyleClass("alertLabel");


	/* Create the row to add the alerts table */

	Wt::WApplication::instance()->styleSheet().addRule(".alertRow", "max-height: 100%;");

	auto alertRow = std::make_unique<Wt::WContainerWidget>();

	alertRow->addStyleClass("row mx-2 text-center");

	alertRow->setStyleClass("alertRow");


	/* Create the table where the news alerts will be inserted*/
	auto newsTable = alertRow->addWidget(std::make_unique<Wt::WTable>());

	Wt::WApplication::instance()->styleSheet().addRule(".alertText", "color: black; font-weight:bold; font: Copperplate; font-size:10px; text-align: center; padding: 3px; ");

	if (ltcAlerts->size() > 0) {

		Wt::WApplication::instance()->styleSheet().addRule(".alertCtn", "background-color: #fad1d0");

		alertCtn->setStyleClass("alertCtn");

		for (std::size_t i = 0; i < ltcAlerts->size(); i++) {
			
			std::string newsText = (*ltcAlerts)[i].getAlerText();
			
			std::string newsDate = (*ltcAlerts)[i].getAlertDate();
			
			std::string alertStop = (*ltcAlerts)[i].getAlertStopID();

			Wt::WText* rowText = newsTable->elementAt(i, 0)->addNew<Wt::WText>(newsDate + ": " + newsText);
			
			rowText->setStyleClass("alertText");
		}
	}
	else {

		std::string newsText = "No current alerts for this stop";

		Wt::WText* rowText = newsTable->elementAt(0, 0)->addNew<Wt::WText>(newsText);

		Wt::WApplication::instance()->styleSheet().addRule(".newsTextEmpty", "color: black; font: Copperplate; font-weight:bold; font-size:20px; text-align: center; padding: 3px; ");

		rowText->setStyleClass("newsTextEmpty");

		Wt::WApplication::instance()->styleSheet().addRule(".alertCtn", "background-color: white");

		alertCtn->setStyleClass("alertCtn");



	}

	Wt::WApplication::instance()->styleSheet().addRule(".alertTable", "max-height: 100%;");

	newsTable->addStyleClass("table table-default table-borderless table-sm");

	newsTable->addStyleClass("alertTable");


	

	/* Add the rows container inside the news container */
	alertCtn->addWidget(std::move(alertRow));

}



/*! \brief This function compares two wtime objects
*
*  This function compares two wtime objects
*  @param t1 the first time object
*  @param t2 the second time object
*  @return true if t1 is greater than t2
*/
bool BusScheduleSection::compareTime(const Wt::WTime& t1, const Wt::WTime& t2) {

	return t1 > t2;

}

/*! \brief This function sorts the schedule
*
*  This function sorts the stop times in a schedule in ascending order
*  @param stopTimes the map of stop times
*  @return a vector of sorted stop times
*/
std::vector<std::pair<int, Wt::WTime>> BusScheduleSection::sortSchedule(std::map<int, Wt::WTime> stopTimes) {

	std::vector<std::pair<int, Wt::WTime>> stopTimesVector;
	for (const auto& stopTime : stopTimes) {
		stopTimesVector.emplace_back(stopTime);
	}

	
	std::sort(stopTimesVector.begin(), stopTimesVector.end(), [](const auto& a, const auto& b) {
		return a.second < b.second;
		});

	return stopTimesVector;
}



/*! \brief This function returns the number of buses for which the schedule will be displayed
*
*  This function returns the number of buses for which the schedule is displayed
*  @param first the first bus to display
*  @param last the last bus to display
*/
int BusScheduleSection::getNumberOfBus(int first, int last) {

	int numBus = 0;

	if (first >= 0 && last >= 0) {

		for (int i = first; i <= last; i++) {

			Bus busToshow = bStop.getBusList().at(i);

			Schedule busSchedule = busToshow.getBusSchedule();

			int firstIndex = busToshow.getShowPosition();

			if (firstIndex >= 0) {

				numBus++;

			}
		}
	}
	
	return numBus;


}



/*! \brief This function sets the message info about the schedules that are displayed
*
*  This function sets the message info about the schedules that are displayed.
*  It will let riders know if the schedule is real-time or not
*  @param isRealTime true if the schedule is real-time
*
*/
void BusScheduleSection::setInfoLabel(bool isRealTime) {

	if (infoCtn != nullptr) {

		infoCtn->clear();

		if (isRealTime) {

			Wt::WApplication::instance()->styleSheet().addRule(".infoLogo", "fill:green; color:green; width:25px; height:25px;");

			Wt::WImage* infoLogo = infoCtn->addWidget(std::make_unique<Wt::WImage>("images/live.svg"));

			infoLogo->addStyleClass("fa-solid fa-tower-broadcast fa-beat-fade");

			infoLogo->setStyleClass("infoLogo");

			infoLabel = infoCtn->addWidget(std::make_unique<Wt::WLabel>(" Real-Time Information"));

			Wt::WApplication::instance()->styleSheet().addRule(".infoLabel", "font:Papyrus; color:Green; font-size: 20px; font-weight:bold;");

			infoLabel->setStyleClass("infoLabel");

		}
		else {


			Wt::WApplication::instance()->styleSheet().addRule(".infoLogo", "fill:orange; width:25px; height:25px;");

			Wt::WImage* infoLogo = infoCtn->addWidget(std::make_unique<Wt::WImage>("images/preplaned.svg"));

			infoLogo->addStyleClass("bi-exclamation-octagon");

			infoLogo->setStyleClass("infoLogo");

			infoLabel = infoCtn->addWidget(std::make_unique<Wt::WLabel>(" LTC Pre-Planned Schedule"));

			Wt::WApplication::instance()->styleSheet().addRule(".infoLabel", "font:Papyrus; color:orange; font-size: 20px; font-weight:bold;");

			infoLabel->setStyleClass("infoLabel");
		}
	}

}


/*! \brief This function sets the get the list of bus for which the schedule is displayed
*
*  This function sets the get the list of bus for which the schedule is displayed
*  @return a vector of buses
*/
std::vector<Bus> BusScheduleSection::getBusShown() {

	return busesShown;

}

/*! \brief This function sets the alerts to display
*
*  This function sets the alerts to display
*  @param alerts the vector of alerts
*/
void BusScheduleSection::setAlerts(std::vector<LTCAlert> alerts) {

	if (alerts.size() > 0) {

		*ltcAlerts = alerts;

		displayLTCAlerts();

	}
}