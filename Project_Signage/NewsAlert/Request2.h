/*
 * Header file Request.h
 * @author Irmene-Valerie Leonard
 * Created on: Feb 6, 2023
 */
# include <string>

#ifndef REQUEST2_H_
#define REQUEST2_H_

 /*
  * This class presents C++ API for making web requests
  */
class Request2 {

private:

	/* String variable containing the URL to fetch*/
	std::string URLrequest;

	/* String variable containing data fetch trough a web request*/
	std::string curlBuffer;

	/* Libcurl scallback function to recieve and save data from the web request*/
	static size_t WriteMemoryCallback(char* data, size_t size, int nmemb, std::string* buffer);

public:

	/* Contructor to create a web request object*/
	Request2(std::string urlReq);

	/* Method to execute the request and retrieve the document from the URL provided on construction*/
	bool Execute();

	/*Method to return a string object containing the JSON data retrieved on executing the request*/
	std::string result();

	/* Destructor of objects of the class*/
	~Request2();
};

#endif /* REQUEST_H_ */

