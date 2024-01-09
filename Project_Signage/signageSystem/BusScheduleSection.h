/*! \file BusScheduleSection.h
 * 
 * Header file for Class BusScheduleSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 20, 2023
 */

#include <vector>
#include <map>
#include <Wt/WContainerWidget.h>
#include <Wt/WTable.h>
#include <Wt/WDateTime.h>
#include "../LTC/BusStop.h"

#ifndef BUSSCHEDULE_H

#define BUSSCHEDULE_H

 /*! \class BusScheduleSection
  * \brief This class is used to display the bus schedule on the signage
 * 
 *  This class is used to display the bus schedule on the signage along with the route, occupancy level,
 *  congestion and their next two estimated arrival if available.
 *  It will also display the LTC alerts if there is any.
 *	
 *
 */
class BusScheduleSection : public Wt::WContainerWidget {

private:

	const int MAX_BUS = 3;

	Wt::WTable* busScheduleTable;

	Wt::WContainerWidget* infoCtn;
	
	BusStop bStop;

	Wt::WDateTime* busDateTime;

	Wt::WLabel* infoLabel;

	std::vector<std::map<int,int>> displayedBus;

	int busesGroup;

	int groupShowed;

	std::vector<Bus> busesShown;

	std::map<int, Service>& tripsServices;

	Wt::WContainerWidget* busScheduleCtn;
	
	Wt::WContainerWidget* schedCtn;
	
	Wt::WContainerWidget* alertCtn;

	std::vector<LTCAlert>* ltcAlerts;
	
	bool firstShow;

public:

	BusScheduleSection(BusStop& stop, Wt::WDateTime* dateTime, std::map<int, Service>& services);

	~BusScheduleSection();

	void createScheduleSection();

	void setDateTime(Wt::WDateTime* dateTime);

	void createDisplayedBus();

	void createScheduleToShow();

	void displaySchedule();

	void displayLTCAlerts();

	bool compareTime(const Wt::WTime& t1, const Wt::WTime& t2);

	std::vector<std::pair<int, Wt::WTime>> sortSchedule(std::map<int, Wt::WTime> schedule);

	int getNumberOfBus(int first, int last);

	void setInfoLabel(bool isRealTime);

	std::vector<Bus> getBusShown();
	
	void setAlerts(std::vector<LTCAlert> alerts);
};

#endif // !BUSSCHEDULE_H