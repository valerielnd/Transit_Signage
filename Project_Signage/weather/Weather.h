/*
 * Header file for Class weather
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <vector>
#include <string>

#ifndef WEATHER_H

#define WEATHER_H


 /*!
   * This class is used to store the weather information
   *
   */
class Weather {

private:

    double weatherValue;

    double feelLike;

    std::string weatherUnit;

    std::string weatherDescription;


public :

    Weather();

    Weather(double value, double feel, std::string unit, std::string desc);


    ~Weather();


    double getWeatherValue() const;

    double getWeatherFeel() const;

    std::string getWeatherUnit() const;

    std::string getWeatherDesc() const;

    void setWeatherValue(double value);

    void setWeatherFeel(double feel);

    void setWeatherUnit(std::string unit);

    void setWeatherDesc(std::string unit);

    bool isEqual(const Weather& other) const;

    void printWeather() const;




};

#endif // !WEATHER_H