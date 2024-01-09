/*
 * Definition file for Class AppView
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 1, 2023
 */

#include <iostream>
#include "Position.h"

 /*!
   *  Default constructor for class Position
   *
   */
Position::Position() {

	posLat = 0;
	posLon = 0;
}

/*!
  * Constructor for class Position
  *
  */
Position::Position(double lat, double lon) {

	posLat = lat;
	posLon = lon;

}

/*!
  * Destructor for class Position
  *
  */
Position::~Position() {}

/*!
  * Getter for the latitude of the position
  *
  */
double Position::getLat() const {
	return posLat;
}


/*!
  * Getter for the longitude of the position
   *
    */
double Position::getLon() const {
	return posLon;
}


/*!
  * Setter for the latitude of the position
  *
  */
void Position::setLat(double lat) {
	posLat = lat;
}

/*!
  * Setter for the longitude of the position
  *
  */
void Position::setLon(double lon) {
	posLon = lon;
}

/*!
  * Compare two positions
  *
  */
bool Position::isEqual(const Position& other) {
	return (posLat == other.posLat && posLon == other.posLon);
}


/*!
  * Print the position
  *
  */
void Position::printPosition() const {
	std::cout << "Latitude: " << posLat << std::endl;
	std::cout << "Longitude: " << posLon << std::endl;
}