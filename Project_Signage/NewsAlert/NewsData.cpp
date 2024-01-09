/*
 * Definition file for Class NewsData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 3, 2023
 */


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Request2.h"
#include "gumbo.h"
#include "NewsData.h"

 /*!
   * Constructor for the class NewsData
   *
   */
NewsData::NewsData() {
	
	appNews = std::vector<NewsArticle>();

	newsAPIs = std::vector<URLReq*>();
	
}


/*!
  * Destructor for the class NewsData
  *
  */
NewsData::~NewsData() {}



/*!
  * Constructor for the class NewsData. Takes in a vector of NewsArticle and a vector of URLReq
  *
  */
NewsData::NewsData(std::vector<URLReq*> APIs, std::vector<NewsArticle> articles) {

	NewsData::appNews = articles;

	NewsData::newsAPIs = APIs;


}

/*!
  * This method is used to get the news articles
   *
    */
const std::vector<NewsArticle>& NewsData::getNewsArticles() const {

	return NewsData::appNews;

}

/*!
  * This method is used to get the news APIs
  *
  */
const std::vector<URLReq*>& NewsData::getNewsAPIs() const {

	return NewsData::newsAPIs;

}



/*!
  * This method is used to add a news article to the vector of news articles
  *
  */
bool NewsData::addArticle(NewsArticle article) {

	std::vector<std::string>::size_type size = NewsData::appNews.size();

	if (!NewsData::findArticle(article) && size < 6) {

		NewsData::appNews.push_back(article);

		return true;

	}

	return false;

}

/*!
  * This method is used to remove a news article from the vector of news articles
  *
  */
bool NewsData::removeArticle(NewsArticle article) {

	std::vector<NewsArticle>::iterator position = NewsData::getArticlePosition(article);


	if (position != NewsData::appNews.end()) {

		NewsData::appNews.erase(position);


		return true;

	}

	return false;

}

/*!
  * This method is used to find a news article in the vector of news articles
  *
  */
bool NewsData::findArticle(NewsArticle article) {

	auto it = std::find(NewsData::appNews.begin(), NewsData::appNews.end(), article);

	if (it != NewsData::appNews.end()) {

		return true;

	}
	return false;
}

/*!
  * This method is used to get the position of a news article in the vector of news articles
  *
  */
std::vector<NewsArticle>::iterator NewsData::getArticlePosition(NewsArticle article) {

	auto it = std::find(NewsData::appNews.begin(), NewsData::appNews.end(), article);

	return it;


}

/*!
  * This method is used to set the news articles
  *
  */
void NewsData::setNewsArticle(std::vector<NewsArticle> articles) {

	if (NewsData::appNews.size() > 0){

		NewsData::appNews.clear();

	}

	if (articles.size() > 6) {

		std::vector<NewsArticle> fArticles(articles.end() - 5, articles.end());

		articles = fArticles;

	}
	NewsData::appNews = articles;

	articles.clear();

}

/*!
  * This method is used to set the news APIs
  *
  */
void NewsData::setNewsAPIs(std::vector<URLReq*> APIs) {

	NewsData::newsAPIs = APIs;

}

/*!
  * This method is used to pull the news data from the APIs
  *
  */
void NewsData::pullNewsData() {

	std::string NewsInfo;

	std::vector<URLReq>::size_type size = NewsData::newsAPIs.size();

	std::vector<URLReq>::size_type index = 0;

	bool done = false;

	if (size > 0) {


		while ((index < size) && (!done)) {

			URLReq* url = NewsData::newsAPIs[index];

			std::string dataFetchNews = NewsData::getNewsString(url->getStringUrl());

			if (dataFetchNews != "") {

				done = true;

				url->getProcessData()->processString(dataFetchNews);

				std::vector<NewsArticle> newArticles = url->getProcessData()->returnResult();


				this->setNewsArticle(newArticles);

			}
			index++;

		}

	}

}


/*!
  * This method is used to fecth the news data from the APIs
  *
  */
std::string NewsData::getNewsString(std::string url) {

	Request2 dataReq(url);

	std::string content;

	if (dataReq.Execute()) {

	
		content = dataReq.result();


	}
	return content;
}

/*!
  * This method is used to print the news articles
  *
  */
void NewsData::printNewsArticles() const {

	if (!NewsData::appNews.empty()) {
	
		for (std::vector<NewsArticle>::size_type i = 0; i < NewsData::appNews.size(); i++) {
		
			NewsData::appNews[i].printNewsData();
		
		}
		
	
	
	}

}