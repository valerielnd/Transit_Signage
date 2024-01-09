#include <iostream>
#include "Position.h"


Position::Position() {}

Position::Position(double lat, double lon) {
// Initialize the private variables
	posLat = lat;
	posLon = lon;

}

Position::~Position() {}

double Position::getLat() const {
	return posLat;
}

double Position::getLon() const {
	return posLon;
}

void Position::setLat(double lat) {
	posLat = lat;
}

void Position::setLon(double lon) {
	posLon = lon;
}

bool Position::isEqual(const Position& other) {
	return (posLat == other.posLat && posLon == other.posLon);
}

void Position::printPosition() const {
	std::cout << "Latitude: " << posLat << std::endl;
	std::cout << "Longitude: " << posLon << std::endl;
}