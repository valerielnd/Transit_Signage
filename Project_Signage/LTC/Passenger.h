/*
 * Header file for Class Passenger
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 4, 2023
 */

#include <string>


#ifndef PASSENGER_H

#define PASSENGER_H

 /*!
   * This class represents a Passenger object.
   *
   */
class Passenger {

private:

	std::string passengerType;

	double busFare;

public:

	Passenger(std::string passengerType, double busFare);

	~Passenger();
	
	Passenger(const Passenger& other);

	std::string getPassengerType();

	double getBusFare();

	void setPassengerType(std::string passengerType);

	void setBusFare(double busFare);

	bool operator==(const Passenger& passenger);

	Passenger& operator=(const Passenger& other);


};

#endif // !PASSENGER_H