#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ProcessHTML.h"
#include "NewsArticle.h"
#include "gumbo.h"
#include "Document.h"
#include "Node.h"

ProcessHTML::ProcessHTML() {}

ProcessHTML::~ProcessHTML() {}

void ProcessHTML::processString(std::string str) {

	CDocument doc;

	doc.parse(str.c_str());

	std::vector<std::string> dates;

	std::vector<std::string> articlesTexts;

	CSelection cdates = doc.find("article p span.published");

	CSelection ctext = doc.find("article div.post-content p");

	for (int i = 0; i < 6; i++) {

		
		dates.push_back(cdates.nodeAt(i).text());
	}

	for (int i = 0; i < 6; i++) {


		articlesTexts.push_back(ctext.nodeAt(i).text());
	}
	if (!dates.empty() && !articlesTexts.empty()) {
		for (int i = 1; i < 6; i++) {

			NewsArticle article(articlesTexts[i], dates[i]);

			ProcessHTML::result.push_back(article);


		}
	}
	
}
std::vector<NewsArticle> ProcessHTML::returnResult() {
	
	return ProcessHTML::result;
}

