/*
 * Definition file for Class ProcessJSON
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <string>
#include <iostream>
#include "ProcessJSON.h"
#include "nlohmann/json.hpp"
#include "NewsArticle.h"

using json = nlohmann::json;

/*!
  * Default Constructor for the class ProcessJSON
  *
  */
ProcessJSON::ProcessJSON() {}

/*!
  * Destructor for the class ProcessJSON
   *
    */
ProcessJSON::~ProcessJSON() {}

void ProcessJSON::processString(std::string str) {

	std::cout << "inside processJson string" << std::endl;

	
	auto jObj = json::parse(str, nullptr, false);

	
	if (jObj.is_discarded()) {

		std::cerr << "Parse JSON error" << std::endl;
	}
	else {

		json object = jObj;
		
		json  articles = object["articles"];

		int numArticles = articles.size();

		for (int i = 0; i < numArticles; i++) {
		
			std::string newsInfo = articles[i]["title"];

			std::string newsDate = articles[i]["publishedAt"];

			int startIndex = 0;
				
			int endIndex = 0;

			char separator = '-';

			std::vector<std::string> dateVec;
			
			for (std::size_t j = 0; j <= newsDate.size(); j++) {

				if (newsDate[j] == separator || j == newsDate.size()) {
					
					endIndex = j;
					
					std::string temp;
					
					temp.append(newsDate, startIndex, endIndex - startIndex);
					
					dateVec.push_back(temp);
					
					startIndex = endIndex + 1;
				}
			}
			std::string newDate;

			if (dateVec.size() > 0) {

				newDate = dateVec[1] + "-" + dateVec[2][0] + dateVec[2][1] + "-" + dateVec[0];

			}

			if (newsInfo != "" && newDate != "") {

				NewsArticle article(newsInfo, newDate);

				ProcessJSON::result.push_back(article);
			
			}
			
		
		}

		

	}

	
}

/*!
  * This method returns the result of the processing of the JSON data
  *
  */
std::vector<NewsArticle> ProcessJSON::returnResult() {
	
	return ProcessJSON::result;
}


