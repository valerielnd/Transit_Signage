/*! \file LTCAlert.cpp
* 
 * Definiiton file for Class LTCAlert
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include "LTCAlert.h"

 /*! \brief Construtor for the class LTCAlert
   * 
   * This method is used to create an object of type LTCAlert
   * It will initialize the attributes of the class to the default values
   * 
   *
   */
LTCAlert::LTCAlert() {

	alertID = "";
	alertBusNumber = "";
	alerText = "";
	alertDate = "";
	alertStopID = "";
	alertCause = "";
	alertEffect = "";


}

/*! \brief Construtor for the class LTCAlert
  * 
  *  This method is used to create an object of type LTCAlert
  *  It will initialize the attributes of the class to the values passed as parameters
  *  @param alertID 
  *  @param alertBusNumber the bus number for the alert
  *  @param alertDate the date for the alert
  *  @param alertStopID the stop ID for the alert
  *  @param alertCause the cause for the alert
  *  @param alertEffect the effect for the alert
  *  @param alerText the text for the alert
  *
  */
LTCAlert::LTCAlert(std::string alertID,  std::string alertBusNumber, std::string alertDate, std::string alertStopID, std::string alertCause, std::string alertEffect, std::string alerText){

	this->alertID = alertID;
	this->alertBusNumber = alertBusNumber;
	this->alertDate = alertDate;
	this->alertStopID = alertStopID;
	this->alertCause = alertCause;
	this->alertEffect = alertEffect;
	this->alerText = alerText;
}

/*! \brief Destructor for the class LTCAlert
*  
*  This method is used to destroy an object of type LTCAlert
* 
*
*/
LTCAlert::~LTCAlert() {}


/*! \brief Getter for the alertID
  * 
  * This method is used to get the alertID
  *  @return alertID
  *
  */
std::string LTCAlert::getAlertID() {

	return alertID;
}

/*! \brief Getter for the alertBusNumber
  * 
  *  This method is used to get the alertBusNumber
  *  @return alertBusNumber
  *
  */
std::string LTCAlert::getAlertBusNumber() {
	return alertBusNumber;
}

/*! \brief Getter for the alerText
  * 
  * This method is used to get the alerText
  *  @return alerText
  *
  */
std::string LTCAlert::getAlerText() {
	return alerText;
}

/*! \brief Getter for the alertDate
  * 
  *  This method is used to get the alertDate
  *  @return alertDate
  *
  */
std::string LTCAlert::getAlertDate() {
	return alertDate;
}

/*! \brief Getter for the alertStopID
  * 
  *  This method is used to get the alertStopID
  *  @return alertStopID
  *
  */
std::string LTCAlert::getAlertStopID() {
	return alertStopID;
}

/*! \brief Getter for the alertCause
  * 
  *  This method is used to get the alertCause
  *  @return alertCause
   *
    */
std::string LTCAlert::getAlertCause() {
	return alertCause;
}

/*! \bref Getter for the alertEffect
  * 
  *  This method is used to get the alertEffect
  *  @return alertEffect the effect of the alert
  *
  */
std::string LTCAlert::getAlertEffect() {
	return alertEffect;
}


/*! \brief Setter for the alertID
* 
  * Setter for the alertID
  * @param alertID the ID for the alert
  */
void LTCAlert::setAlertID(std::string alertID) {

	this->alertID = alertID;
}

/*! \brief Setter for the alertBusNumber
* 
  * Setter for the alertBusNumber
  * @param alertBusNumber
  */
void LTCAlert::setAlertBusNumber(std::string alertBusNumber) {
	this->alertBusNumber = alertBusNumber;
}

/*! \brief Setter for the alerText
* 
  * Setter for the alerText
   * @param alerText the text for the alert
    */
void LTCAlert::setAlerText(std::string alerText) {
	this->alerText = alerText;
}

/*! \brief Setter for the alertDate
* 
  * Setter for the alertDate
  *  @param alertDate the date for the alert
  *
  */
void LTCAlert::setAlertDate(std::string alertDate) {
	this->alertDate = alertDate;
}

/*! \brief Setter for the alertStopID
* 
  * Setter for the alertStopID
  * @param alertStopID the stop ID for the alert
  */
void LTCAlert::setAlertStopID(std::string alertStopID) {
	this->alertStopID = alertStopID;
}

/*! \brief Setter for the alertCause
* 
  * Setter for the alertCause
  * @param alertCause the cause for the alert
  */ 
void LTCAlert::setAlertCause(std::string alertCause) {
	this->alertCause = alertCause;
}


/*! \brief Setter for the alertEffect
* 
* Setter for the alertEffect
* @param alertEffect the effect of the alert
*/
void LTCAlert::setAlertEffect(std::string alertEffect) {
	this->alertEffect = alertEffect;
}

/*! \brief Overloaded operator ==
*  
*  This method is used to compare two objects of type LTCAlert
*  @param other the other object to compare to
*  @return true if the two objects are equal, false otherwise
*/
bool LTCAlert::operator==(const LTCAlert& other) const {
	return (alertID == other.alertID &&
		alertBusNumber == other.alertBusNumber &&
		alertDate == other.alertDate &&
		alertStopID == other.alertStopID &&
		alertCause == other.alertCause &&
		alertEffect == other.alertEffect &&
		alerText == other.alerText);
}

