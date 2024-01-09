/*
 * Definiiton file for Class Passenger
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 4, 2023
 */

#include "Passenger.h"

 /*!
   * Constructor for Class Passenger
   *
   */
Passenger::Passenger(std::string passengerType, double busFare) {
	this->passengerType = passengerType;
	this->busFare = busFare;
}


/*!
  * Destructor for Class Passenger
  *
  */
Passenger::~Passenger() {}

Passenger::Passenger(const Passenger& other) {
    passengerType = other.passengerType;
    busFare = other.busFare;
}


/*!
  * Getter for passengerType
  *
  */
std::string Passenger::getPassengerType() {
	return passengerType;
}


/*!
  * Getter for busFare
  *
  */
double Passenger::getBusFare() {
	return busFare;
}


/*!
  * Setter for passengerType
  *
  */
void Passenger::setPassengerType(std::string passengerType) {
	this->passengerType = passengerType;
}


/*!
  * Setter for busFare
  *
  */
void Passenger::setBusFare(double busFare) {
	this->busFare = busFare;
}

/*!
  * Overloaded operator for comparing two Passenger objects
  *
  */
bool Passenger::operator==(const Passenger& passenger) {
	return this->passengerType == passenger.passengerType && this->busFare == passenger.busFare;
}

/*!
  * Overloaded operator for assigning one Passenger object to another
  *
  */
Passenger& Passenger::operator=(const Passenger& other) {
	if (this != &other) {
		passengerType = other.passengerType;
		busFare = other.busFare;
	}
	return *this;
}