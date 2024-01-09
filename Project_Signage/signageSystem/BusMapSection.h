/*! \file BusMapSection.h
* 
 * Header file for Class BusMapSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 20, 2023
 */

#include <Wt/WContainerWidget.h>
#include "../LTC/Bus.h"

#ifndef BUSMAP_H

#define BUSMAP_H


 /*! \class BusMapSection
  * 
  * \brief This class is used to display the map with the current buses postion on the signage
  * 
  *  This class is used to display the map with the current buses postion on the signage
  *  It is a container widget that contains a google map
  *  It uses the buses coordinates to display their positions
  *
  */
class BusMapSection : public Wt::WContainerWidget {

private:

	

	Wt::WGoogleMap* map;

	std::vector<Bus> busesOnMap;

	double stopLat;

	double stopLong;

public:

	BusMapSection();

	~BusMapSection();

	void setbusesOnMap(std::vector<Bus> buses);

	void addMarkers();

	void setStopPosition(double lat, double longt);

};

#endif // !BUSMAP_H