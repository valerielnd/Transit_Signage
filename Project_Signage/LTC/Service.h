/*
 * Header file for Class Service
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <vector>

#ifndef SERVICE_H
#define SERVICE_H

/*!
* This class represent a Service for a LTC Bus
*
*/
class Service {

private:

	int serviceID;

	std::vector<bool> serviceDays;

public:
	Service();

	Service(int serviceID, std::vector<bool> serviceDays);

	~Service();

	void setServiceID(int serviceID);

	int getServiceID() const;

	void setServiceDays(std::vector<bool> serviceDays);

	std::vector<bool>& getServiceDays();

	bool addServiceDay(int serviceDay, bool status);

	bool findServiceDay(int serviceDay);
	


};

#endif // !SERVICE_H