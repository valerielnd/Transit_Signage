/*
 * Definition file for Class NewsArticle
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 5, 2023
 */


#include <string>
#include <iostream>
#include "NewsArticle.h"


 /*!
   * Constructor of the NewsArticle class
   *
   */
NewsArticle::NewsArticle() {
	
	NewsArticle::newsInfo = "";

	NewsArticle::newsDate = "";
	
};


/*!
  * Destructor of the NewsArticle class
  *
  */
NewsArticle::~NewsArticle() {};

/*!
  * Constructor of the NewsArticle class. It takes two parameters. The first parameter is the news data and the second parameter is the news date.
  *
  */
NewsArticle::NewsArticle(std::string data, std::string date) {

	NewsArticle::newsInfo = data;

	NewsArticle::newsDate = date;
}

/*!
  * This method returns the news info
  *
  */
const std::string& NewsArticle::getNewsData() const{

	return NewsArticle::newsInfo;


}

/*!
  * This method returns the news date
   *
    */
const std::string& NewsArticle::getNewsDate() const{

	return NewsArticle::newsDate;


}

/*!
  * This method sets the news data
  *
  */
void NewsArticle::setNewsData(std::string data) {


	NewsArticle::newsInfo = data;


}

/*!
  * This method sets the news date
  *
  */
void NewsArticle::setNewsDate(std::string date) {


	NewsArticle::newsDate = date;


}

/*!
  * This method prints the news data
  *
  */
void NewsArticle::printNewsData() const {

	if (NewsArticle::newsDate != "" && NewsArticle::newsInfo != "") {

		std::cout << NewsArticle::newsDate << ": " << NewsArticle::newsInfo << std::endl;
	}
	else {
	
		std::cout << "Error empty news article" << std::endl;
	}

}

/*!
  * This method compares two news articles
  *
  */
bool NewsArticle::operator==(const NewsArticle& other) const {
	// compare the relevant data members of the NewsArticle class
	return (this->newsInfo == other.newsInfo && this->newsDate == other.newsDate);
}