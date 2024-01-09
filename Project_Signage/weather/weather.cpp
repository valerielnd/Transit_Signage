/*
 * Definition file for Class weather
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <iostream>
#include "Weather.h"

 /*!
   * Default constructor for the weather class
   *
   */
Weather::Weather() {}


/*!
  * Constructor for the weather class
  *
  */
Weather::Weather(double value, double feel, std::string unit, std::string desc) {

	Weather::weatherValue = value;

	Weather::feelLike = feel;

	Weather::weatherUnit = unit;
	
	Weather::weatherDescription = desc;

}

/*!
  * Destructor for the weather class
  *
  */
Weather::~Weather() {}


/*!
  * Getter for the weather value
  *
  */
double Weather::getWeatherValue() const {

	return Weather::weatherValue;

}

/*!
  * Getter for the weather feel
  *
  */
double Weather::getWeatherFeel() const {

	return Weather::feelLike;

}

/*!
  * Getter for the weather unit
  *
  */
std::string Weather::getWeatherUnit() const{
	
	return Weather::weatherUnit;

}


/*!
  * Getter for the weather description
  *
  */
std::string  Weather::getWeatherDesc() const {

	return Weather::weatherDescription;

}

/*!
  * Setter for the weather value
  *
  */
void  Weather::setWeatherValue(double value) {

	Weather::weatherValue = value;

}

/*!
  * Setter for the weather feel
  *
  */
void  Weather::setWeatherFeel(double feel) {

	Weather::feelLike = feel;

}

/*!
  * Setter for the weather unit
   *
    */
void  Weather::setWeatherUnit(std::string unit) {

	Weather::weatherUnit = unit;
}


/*!
  * Setter for the weather description
  *
  */
void Weather::setWeatherDesc(std::string desc) {

	Weather::weatherDescription = desc;
}

/*!
  * Method to compare two weather objects
   *
    */
bool Weather::isEqual(const Weather& other) const {

	return (this->weatherValue == other.weatherValue && this->weatherUnit == other.weatherUnit);

}

/*!
  * Method to print the weather object
  *
  */
void Weather::printWeather() const {

	std::cout << "Weather value: " << Weather::weatherValue << " " << Weather::weatherUnit << std::endl;

	std::cout << "Weather description: " << Weather::weatherDescription << std::endl;

	std::cout << "Feels like: " << Weather::feelLike << " " << Weather::weatherUnit << std::endl;

}

