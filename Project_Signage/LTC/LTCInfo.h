/*
 * Header file for Class LTCInfo
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 7, 2023
 */

#include <vector>
#include "Passenger.h"

#ifndef LTCINFO_H_
#define	LTCINFO_H_

 /*!
   * ThisThis class is used to store the information of the LTC
   *
   */
class LTCInfo{

private:

	std::vector<Passenger> busPassengers;

	std::string fleetInfo;

	std::string stopInfo;

	std::string LTCPhone;

	std::string LTCEmail;

	std::string LTCAddress;

public:
	LTCInfo();

	LTCInfo(std::string LTCPhone, std::string LTCEmail, std::string LTCAddress);

	std::vector<Passenger> getBusPassengers();
	
	LTCInfo(const LTCInfo& other);

	std::string getFleetInfo();

	std::string getStopInfo();

	std::string getLTCPhone();

	std::string getLTCEmail();

	std::string getLTCAddress();

	void setBusPassengers(std::vector<Passenger> busPassengers);

	void setFleetInfo(std::string fleetInfo);

	void setStopInfo(std::string stopInfo);

	void setLTCPhone(std::string LTCPhone);

	void setLTCEmail(std::string LTCEmail);

	void setLTCAddress(std::string LTCAddress);

	bool addPassenger(Passenger passenger);

	bool removePassenger(Passenger passenger);

	bool updatePassenger(Passenger passenger);

	bool findPassenger(Passenger passenger);

	LTCInfo& operator=(const LTCInfo& other);


};


#endif // !LTCINFO_H_



