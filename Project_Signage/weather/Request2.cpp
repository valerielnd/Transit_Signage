/*
 * Definition file Request.cpp
 * @author Irmene-Valerie Leonard
 * Created on: Feb 6, 2023
 */

#include <curl/curl.h>
#include <iostream>
#include "Request2.h"

 /*
  * Contructor to create a web request object
  * @urlReq the the URL to fetch
  * @buffer the data fetch trough a web request
  */
Request2::Request2(std::string urlReq) {

	/*initialize all member data */
	Request2::URLrequest = urlReq;

	Request2::curlBuffer = "";
}


/*
 * Libcurl callback function to recieve and save data from the web request
 * @data Pointer that points to the delivered data
 * @size this variable is always equal to 1
 * @nmemb the size of that data
 * @return the size of data received
 */
size_t Request2::WriteMemoryCallback(char* data, size_t size, int nmemb, std::string* buffer) {

	/* Initialize the amount of data received to 0*/
	size_t sizeDataRecieved = 0;

	/* Save the data fetch in the string buffer*/
	if (buffer != NULL) {

		buffer->append(data, size * nmemb);

		sizeDataRecieved = size * nmemb;
	}

	/* Return the size of the data received*/
	return sizeDataRecieved;

}

/*
 * Method to execute the request and retrieve the document from the URL provided on construction
 * @return true on success or false on failure
 */
bool Request2::Execute() {

	/* Define the variables needed to execute the curl request*/
	CURL* curl_handle;

	CURLcode result;

	/* Set up the program environment that libcurl needs*/
	curl_global_init(CURL_GLOBAL_ALL);

	/* Initialize the curl session */
	curl_handle = curl_easy_init();

	/* If the curl session was properly initialize*/
	if (curl_handle) {

		/* specify URL to get */
		curl_easy_setopt(curl_handle, CURLOPT_URL, URLrequest.c_str());

		/* Set the User - Agent header */
		curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "MyApplication/1.0");

		/* Send all data to the writeback function  */
		curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

		/* Pass the string curlBuffer to the callback function */
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &curlBuffer);

		/* Performs the request*/
		result = curl_easy_perform(curl_handle);

		/* End the libcurl easy handle*/
		curl_easy_cleanup(curl_handle);

		/* If the request was successful, return true*/
		if (result == CURLE_OK) {

			return true;
		}


	}
	/* If the curl session was not initialize, print an error message*/
	else {

		std::cout << "The curl session was not properly initialize" << std::endl;
	}

	/* If the request was not successful, return false*/
	return false;

}

/*
 * Method to return a string object containing the JSON data retrieved on executing the request
 * @The string object containing the JSON data or an empty string if no data was fetch
 */
std::string Request2::result() {

	return Request2::curlBuffer;
}

/*
 * Destructor of objects of the class Request
 */
Request2::~Request2() {

	/* Global libcurl cleanup*/
	curl_global_cleanup();

}
