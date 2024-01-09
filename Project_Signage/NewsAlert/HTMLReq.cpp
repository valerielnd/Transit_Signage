#include <string>
#include "HTMLReq.h"
#include "ProcessHTML.h"


HTMLReq::HTMLReq() {
	
	HTMLReq::returnType = "HTML";
	
	HTMLReq::getNews = new ProcessHTML();
}

HTMLReq::HTMLReq(std::string url) {

	HTMLReq::urlString = url;

	HTMLReq::returnType = "HTML";

	HTMLReq::getNews = new ProcessHTML();
}

HTMLReq::~HTMLReq() {
	
	if(HTMLReq::getNews){
		
		delete HTMLReq::getNews;
	}
	
}

const std::string& HTMLReq::getStringUrl() const {

	return HTMLReq::urlString;

}

const std::string& HTMLReq::getType() const {

	return HTMLReq::returnType;



}

void HTMLReq::setStringUrl(std::string str) {

	HTMLReq::urlString = str;

}

ProcessData* HTMLReq::getProcessData() const {

	return HTMLReq::getNews;

}



