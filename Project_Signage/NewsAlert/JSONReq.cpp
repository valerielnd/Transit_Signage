/*
 * Definition file for Class JSONReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 8, 2023
 */

#include <string>
#include "JSONReq.h"
#include "ProcessJSON.h"

 /*!
   * Constructor for JSONReq class
   *
   */
JSONReq::JSONReq() {
	
	JSONReq::returnType = "JSON";

	JSONReq::getNews = new ProcessJSON();
}

/*!
  * Constructor for JSONReq class. It takes in a string url and sets it to the urlString variable.
  *
  */
JSONReq::JSONReq(std::string url) {

	JSONReq::urlString = url;

	JSONReq::returnType = "JSON";

	JSONReq::getNews = new ProcessJSON();
}

/*!
  * Destructor for JSONReq class
  *
  */
JSONReq::~JSONReq() {
	
	if(JSONReq::getNews){
		
		delete JSONReq::getNews;
	}
}

/*!
  * This method returns the urlString variable
  *
  */
const std::string& JSONReq::getStringUrl() const {

	return JSONReq::urlString;

}

/*!
  * This method returns the returnType variable
   *
    */
const std::string& JSONReq::getType() const {

	return JSONReq::returnType;



}

/*!
  * This method sets the urlString variable to the string passed in
  *
  */
void JSONReq::setStringUrl(std::string str) {

	JSONReq::urlString = str;

}

/*!
 * This method returns the getNews variable
*
*/
ProcessData* JSONReq::getProcessData() const {

	return JSONReq::getNews;

}


