/*! \file BusSection.h
 * 
 * Header file for Class BusSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 20, 2023
 */

#include <Wt/WContainerWidget.h>
#include "../LTC/BusStop.h"
#include "BusScheduleSection.h"
#include "BusMapSection.h"

#ifndef BUSSECTION_H_

#define BUSSECTION_H_

 /*! \class BusSection
  * 
  * \brief This class is used to display the bus schedule and bus map on the signage. 
  *
  *  This class is used to create the section on the web page where the bus schedule and bus map are displayed.
  *	 The bus schedules are shown in rotation every 30 seconds and the positions of the bus in the shedule are shown on the map
  */

class BusSection : public Wt::WContainerWidget {

private :

	BusScheduleSection* busScheduleSection;

	BusMapSection* busMapSection;


public:

	BusSection(BusStop& stop, Wt::WDateTime* dateTime, std::map<int, Service>& services, std::vector<LTCAlert> alerts);

	~BusSection();

	BusScheduleSection* getBuSchuduleSection() ;

	void setDateTime(Wt::WDateTime* dateTime);

	void setBusScheduleInfo(bool result);

	bool setBusShownMap();

	void setStopPosition(double lat, double longt);

	
};
#endif // !BUSSECTION_H_
