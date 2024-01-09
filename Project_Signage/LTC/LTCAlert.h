/*! \file LTCAlert.h
* 
 * Header file for Class LTCAlert
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <string>

#ifndef LTCALERT_H
#define LTCALERT_H

 /*!
   * This class is used to store the information of the alerts about Buses
   *
   */
class LTCAlert{

private:

	std::string alertID;

	std::string alertBusNumber;

	std::string alerText;

	std::string alertDate;

	std::string alertStopID;

	std::string alertCause;

	std::string alertEffect;


public:
	LTCAlert();

	LTCAlert(std::string alertID, std::string alertBusNumber,  std::string alertDate, std::string alertStopID, std::string alertCause, std::string alertEffect, std::string alerText);

	~LTCAlert();

	std::string getAlertID();

	std::string getAlertBusNumber();

	std::string getAlerText();

	std::string getAlertDate();

	std::string getAlertStopID();

	std::string getAlertCause();

	std::string getAlertEffect();

	void setAlertID(std::string alertID);

	void setAlertBusNumber(std::string alertBusNumber);

	void setAlerText(std::string alerText);

	void setAlertDate(std::string alertDate);

	void setAlertStopID(std::string alertStopID);

	void setAlertCause(std::string alertCause);

	void setAlertEffect(std::string alertEffect);

	bool operator==(const LTCAlert& other) const;
};

#endif // LTCALERT_H
