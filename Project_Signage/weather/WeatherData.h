/*
 * Header file for Class WeatherData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include<vector>
#include<string>
#include "Weather.h"
#include "Position.h"
#include "APIReq.h"

#ifndef WEATHERDATA_H_

#define WEATHERDATA_H_


 /*!
   * This class is used to store the weather data of London city
   *
   */
class WeatherData {

private: 

    Position cityPos;

    std::vector<std::string> weatherDesc;

    std::vector<APIReq*> APIs;

    Weather currentWeather;

public:

    WeatherData();

    WeatherData(Position pos, std::vector<std::string> desc, std::vector<APIReq*> APIs);

    ~WeatherData();

    Position getCityPos() const;

    std::vector<std::string> getWeatherDesc() const;

    const std::vector<APIReq*>& getAPIs() const;

    Weather getCurrentWeather() const;

    void setCityPos(Position pos);

    void setWeatherDesc(std::vector<std::string> desc);

    void setAPIs(std::vector<APIReq*> APIs);

    void setCurrentWeather(Weather weather);

    bool isEqual(const WeatherData& other);

    void getWeatherFromAPI();

    std::string getWeatherString(std::string url);

    void setCityPosition(std::string url);

    Position getCityPosition() const;




};

#endif // !WEATHERDATA_H_