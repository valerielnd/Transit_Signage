/*! \file Header.h
 * 
 * Header file for Class Header
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */
#include <Wt/WContainerWidget.h>
#include "../weather/WeatherData.h"
#include "../LTC/BusStop.h"

#ifndef HEADER_H
#define HEADER_H


 /*! \class Header
   * 
   * \brief This class is used to create the header of the page.
   *    It displays the BusStop name, the weather information and the logo of the company.
   * 
   *  This class is used to create the header section of the page. 
   *  It displays the BusStop name, the weather information and the logo of the company.
   *  It will also be used to update the weather information displayed
   *
   */
class Header : public Wt::WContainerWidget {

private:

    BusStop& bStop;
    WeatherData& wInfo;
    std::string logoFile;
    std::string sloganFile;
    std::string stopName;
    std::map<std::string, std::string>* temperatureImgs;
	Wt::WText* textTemp;
    Wt::WImage* tempImage;
    void createHeader();

  
public:

    Header(BusStop& stop, WeatherData& info, std::string lFile, std::string sFile);

    ~Header();

    Header(const Header& other);

    void setLogoFile(std::string file);

    void setSloganFile(std::string file);

    void setBusStop(BusStop& stop);

    void setWeatherInfo(WeatherData& info);

    void updateWeatherInfo(WeatherData& info);


};

#endif // !HEADER_H
