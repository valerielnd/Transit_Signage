/*
 * Definition file for Class Service
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include "Service.h"

/*!
 *  Default Constructor for the class Service
 *
 */
Service::Service() {

	serviceID = 0;

	for (int i = 0; i < 7; i++) {
		serviceDays.push_back(0);
	}


}

/*!
 *  Constructor for the class Service
 *  @param serviceID the ID of the service
 *  @param serviceDays the days of the service
 *
 */
Service::Service(int serviceID, std::vector<bool> serviceDays) {

	this->serviceID = serviceID;

	this->serviceDays = serviceDays;
}

/*!
 * Destructor for the class Service
 *
 */
Service::~Service() {

	for (int i = 0; i < 7; i++) {
		serviceDays.push_back(0);
	}

}


/*!
 * Setter for the serviceID
 * @param serviceID the ID of the service
 *
 */
void Service::setServiceID(int serviceID) {

	this->serviceID = serviceID;
}

/*!
 * Getter for the serviceID
 * @return the ID of the service
 *
 */
int Service::getServiceID() const {

	
	return serviceID;
}

/*!
 * Setter for the serviceDays
 * @param serviceDays the days of the service
 *
 */
void Service::setServiceDays(std::vector<bool> serviceDays) {


	this->serviceDays = serviceDays;
}


/*!
 * Getter for the serviceDays
 * @return the days of the service
 *
 */
std::vector<bool>& Service::getServiceDays() {


	return serviceDays;
}

/*!
 * Add a serviceDay to the serviceDays
 * @param serviceDay the day of the service
 * @return true if the serviceDay was added, false otherwise
 *
 */
bool Service::addServiceDay(int serviceDay, bool status) {

	if (serviceDay < 0 || serviceDay > 6) {

		return false;
	}
	else {
	
		if (serviceDays.size() == 7) {
		
			serviceDays[serviceDay] = status;

			return true;
		
		}
	
	}

	return false;
}


/*!
 * Find a serviceDay in the serviceDays
 * @param serviceDay the day of the service
 * @return true if the serviceDay was found, false otherwise
 *
 */
bool Service::findServiceDay(int serviceDay) {

	if (serviceDay < 0 || serviceDay > 6) {

		return false;
	}
	else {
	
		if (serviceDays.size() == 7) {

			bool status = serviceDays[serviceDay];

			return status;

		}
	
	}
	
	return false;
}
