/*! \file LTCAlertAndInfoSection.cpp
 * Definition file for Class TCAlertAndInfoSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 12, 2023
 */

#include "LTCAlertAndInfoSection.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WTable.h>
#include <Wt/WTableRow.h>
#include <Wt/WText.h>
#include <chrono>
#include <cmath>


 /*! \brief Constructor of the class LTCAlertAndInfoSection.
  * 
  * Constructor for the class LTCAlertAndInfoSection
  * It initializes the member of the class and creates the section container
  * @param info the LTCInfo object
  * @param nInfo the NewsData object
  *
  */
LTCAlertAndInfoSection::LTCAlertAndInfoSection(LTCInfo info, NewsData nInfo) {
	
	this->fleetInfo = info.getFleetInfo();

	this->stopInfo = info.getStopInfo();

	this->phoneInfo = info.getLTCPhone();

	this->emailInfo = info.getLTCEmail();

	this->addressInfo = info.getLTCAddress();

	this->newsArticles = nInfo.getNewsArticles();

	this->passengers = info.getBusPassengers();

	Wt::WApplication::instance()->styleSheet().addRule(".LTCAlertAndInf", "height: 10%; width: 100%;");

	LTCAlAndInfSection = this->addWidget(std::make_unique<Wt::WContainerWidget>());

	LTCAlAndInfSection->addStyleClass("container-fluid px-2 fixed-bottom mb-2");

	LTCAlAndInfSection->setHeight(Wt::WLength(10, Wt::LengthUnit::ViewportHeight));

	LTCAlAndInfSection->setStyleClass("LTCAlertAndInf");

	LTCAlertAndInfoSection::createLTCFares();

}

LTCAlertAndInfoSection::~LTCAlertAndInfoSection() {}

/*! \brief This method is used to create the LTC accessibility part of the section.
 * 
 * This methods creates the LTC accessibility part of the section of the web page
 * It creates the container for the section and adds the title and the info
 *
 */
void LTCAlertAndInfoSection::createLTCAccessbility() {

	/* Create the container for LTC accessibility info */
	auto infoCtn = std::make_unique<Wt::WContainerWidget>();

	Wt::WApplication::instance()->styleSheet().addRule(".infoCtn", "background-color: #E5FFED");

	infoCtn->addStyleClass("container-fluid px-2 fixed-bottom mb-2");

	infoCtn->setStyleClass("infoCtn");

	infoCtn->setHeight(Wt::WLength(12, Wt::LengthUnit::ViewportHeight));


	/* Create the the row to add LTC accessibility info */
	Wt::WApplication::instance()->styleSheet().addRule(".infoRow", "text-align: center");

	auto infoRow = std::make_unique<Wt::WContainerWidget>();

	infoRow->addStyleClass("row");

	infoRow->setStyleClass("infoRow");

	Wt::WImage* AccLogo = infoRow->addWidget(std::make_unique<Wt::WImage>("images/wheelchair-solid.svg"));

	Wt::WApplication::instance()->styleSheet().addRule(".tempImage", "width:16px; height:16px;");

	AccLogo->addStyleClass("fa-solid fa-wheelchair");

	AccLogo->setStyleClass("tempImage");

	/* Create the title text */
	auto headertext = infoRow->addWidget(std::make_unique<Wt::WLabel>("Accessibility at London Transit"));

	Wt::WApplication::instance()->styleSheet().addRule(".headertext", "color: black; font: Copperplate; font-weight:bold; font-size:15px; text-align: center; padding: 3px; ");

	headertext-> setStyleClass("headertext");


	/* Create the row to add the LTC fleet info */
	auto fleetRow = std::make_unique<Wt::WContainerWidget>();

	fleetRow->addStyleClass("row");

	fleetRow->setStyleClass("infoRow");

	auto LTCAccessibility = fleetRow->addWidget(std::make_unique<Wt::WLabel>(fleetInfo));

	Wt::WApplication::instance()->styleSheet().addRule(".accInfo", "color: #2776b0; font: Copperplate; font-weight:bold; font-size:12px; text-align: center; padding: 3px; ");

	LTCAccessibility->setStyleClass("accInfo");


	/* Create the row to add the LTC stop info */
	auto infoStopRow = std::make_unique<Wt::WContainerWidget>();

	auto LTCstopAccessibility = infoStopRow->addWidget(std::make_unique<Wt::WLabel>(stopInfo));

	infoStopRow->addStyleClass("row mx-2");

	Wt::WApplication::instance()->styleSheet().addRule(".accStopInfo", "color: #2776b0; font: Copperplate; font-weight:bold; font-size:12px; text-align: center; padding: 3px; ");

	LTCstopAccessibility->setStyleClass("accStopInfo");

	
	/* Add the rows container inside the accessibility container */
	infoCtn->addWidget(std::move(infoRow));

	infoCtn->addWidget(std::move(fleetRow));

	infoCtn->addWidget(std::move(infoStopRow));


	/* Clear the section container before adding the new content */
	LTCAlAndInfSection->clear();


	/* Add the conatct container inside the section container  to show it on the page*/
	LTCAlAndInfSection->addWidget(std::move(infoCtn));




}





/*! \brief This method is used to create the LTC contact part of the section.
 *
 * This methods creates the LTC contact part of the section of the web page
 * It creates the container for the contact info and adds the title and the info
 * It is used to show LTC phone, address and email
 */
void LTCAlertAndInfoSection::createLTCContactInfo() {


	/* Create the container for LTC contact info */
	auto contactCtn = std::make_unique<Wt::WContainerWidget>();

	Wt::WApplication::instance()->styleSheet().addRule(".contactCtn", "background-color: #E5FFED");

	contactCtn->addStyleClass("container-fluid fixed-bottom px-2 mb-2");

	contactCtn->setStyleClass("faresCtn");

	contactCtn->setHeight(Wt::WLength(12, Wt::LengthUnit::ViewportHeight));


	
	/* Create the header row to add the title */
	auto HeaderRow = std::make_unique<Wt::WContainerWidget>();

	HeaderRow->addStyleClass("row text-center");

	HeaderRow->setStyleClass("infoRow");

	auto LTContactHeader = HeaderRow->addWidget(std::make_unique<Wt::WLabel>("LTC Contact Information"));

	Wt::WApplication::instance()->styleSheet().addRule(".header", "font: Copperplate; font-weight:bold; font-size:12px; ");

	LTContactHeader->setStyleClass("header");

	Wt::WApplication::instance()->styleSheet().addRule(".infoRow", "text-align: center;");
	

	/* Create the row to add the LTC Phone number */
	auto phoneRow = std::make_unique<Wt::WContainerWidget>();

	phoneRow->addStyleClass("row gy-0");

	phoneRow->setStyleClass("infoRow");

	Wt::WApplication::instance()->styleSheet().addRule(".phoneLogo", "width:12px; height:12px;");

	Wt::WImage* phoneLogo = phoneRow->addWidget(std::make_unique<Wt::WImage>("images/square-phone-flip-solid.svg"));

	phoneLogo->addStyleClass("fa-solid fa-square-phone-flip");

	phoneLogo->setStyleClass("phoneLogo");

	auto LTCContactPhone = phoneRow->addWidget(std::make_unique<Wt::WLabel>(phoneInfo));

	Wt::WApplication::instance()->styleSheet().addRule(".phone", "color: #2776b0; font: Copperplate; font-weight:bold; font-size:12px; text-align: center; ");

	LTCContactPhone->setStyleClass("phone");


	/* Create the row to add the LTC Email */
	auto emailRow = std::make_unique<Wt::WContainerWidget>();

	emailRow->addStyleClass("row gy-0");

	emailRow->setStyleClass("infoRow");

	Wt::WApplication::instance()->styleSheet().addRule(".emailLogo", "width:12px; height:12px;");

	Wt::WImage* emailLogo = emailRow->addWidget(std::make_unique<Wt::WImage>("images/envelope-circle-check-solid.svg"));

	emailLogo->addStyleClass("fa-solid fa-envelope-circle-check");

	emailLogo->setStyleClass("emailLogo");

	auto LTCContactEmail = emailRow->addWidget(std::make_unique<Wt::WLabel>(emailInfo));

	Wt::WApplication::instance()->styleSheet().addRule(".email", "color: #2776b0; font: Copperplate; font-weight:bold; font-size:12px; text-align: center;  ");

	LTCContactEmail->setStyleClass("email");



	/* Create the row to add the LTC Address */
	auto addessRow = std::make_unique<Wt::WContainerWidget>();

	addessRow->addStyleClass("row gy-0");

	addessRow->setStyleClass("infoRow");

	Wt::WApplication::instance()->styleSheet().addRule(".addressLogo", "width:12px; height:12px;");

	Wt::WImage* adLogo = addessRow->addWidget(std::make_unique<Wt::WImage>("images/map-location-dot-solid.svg"));

	adLogo->addStyleClass("fa-solid fa-map-location-dot");

	adLogo->setStyleClass("addressLogo");

	auto LTCContactAddress = addessRow->addWidget(std::make_unique<Wt::WLabel>(addressInfo));

	Wt::WApplication::instance()->styleSheet().addRule(".address", "color: #2776b0; font: Copperplate; font-weight:bold; font-size:12px; text-align: center; ");

	LTCContactAddress->setStyleClass("address");

	
	/* Add the rows container inside the contact container */
	contactCtn->addWidget(std::move(HeaderRow)); 

	contactCtn->addWidget(std::move(phoneRow));

	contactCtn->addWidget(std::move(emailRow));

	contactCtn->addWidget(std::move(addessRow));

	/* Clear the main container */
	LTCAlAndInfSection->clear();

	/* Add the conatct container inside the section container  to show it on the page*/
	LTCAlAndInfSection->addWidget(std::move(contactCtn));


}

/*! \brief This method is used to create the LTC news alerts part of the section.
 *
 *  This methods creates the LTC news alerts part of the section of the web page
 *  It creates the container for the news alerts and adds the title and the news alerts
 *  It is used to show the news alerts from Western or the News API
 */
void LTCAlertAndInfoSection::createNewsAlerts() {

	/* If News alerts were fetched*/
	if (!this->newsArticles.empty()) {


		/* Create the container for LTC news alerts */
		auto newsCtn = std::make_unique<Wt::WContainerWidget>();

		Wt::WApplication::instance()->styleSheet().addRule(".newsCtn", "background-color: #E5FFED");

		newsCtn->addStyleClass("container-fluid px-2 fixed-bottom mb-2");

		newsCtn->setStyleClass("newsCtn");

		newsCtn->setHeight(Wt::WLength(12, Wt::LengthUnit::ViewportHeight));



	
		/* Create the header row to add the title */
		Wt::WApplication::instance()->styleSheet().addRule(".newsHeaderRow", "margin-bottom: 10px; text-align: center;");

		auto newsHeaderRow = std::make_unique<Wt::WContainerWidget>();

		newsHeaderRow->addStyleClass("row mx-2");

		newsHeaderRow->setStyleClass("newsHeaderRow");

		Wt::WApplication::instance()->styleSheet().addRule(".newsHeader", "color: purple; font: Copperplate; font-weight:bold; font-size:18px; text-align: center; padding: 3px; ");

		auto LTCNewsHeader = newsHeaderRow->addWidget(std::make_unique<Wt::WLabel>("News Alerts"));

		LTCNewsHeader->setStyleClass("newsHeader");



		/* Create the row to add the news alerts */

		Wt::WApplication::instance()->styleSheet().addRule(".newsRow", "background-color: white; ");

		auto newsRow = std::make_unique<Wt::WContainerWidget>();

		newsRow->addStyleClass("row mx-2 g-0");

		newsRow->setStyleClass("newsRow");


		/* Create the table where the news alerts will be inserted*/
		auto newsTable = newsRow->addWidget(std::make_unique<Wt::WTable>());
	
		Wt::WApplication::instance()->styleSheet().addRule(".newsText", "color: black; font: Copperplate; font-weight:bold; font-size:15px; text-align: center; padding: 3px; ");
		
		int columnCounter = 0;

		newsTable->clear();

		int newsCounter = 0;

		while (newsCounter < 1) {

			std::string newsText = newsArticles[newsCounter].getNewsData();

			std::string newsDate = newsArticles[newsCounter].getNewsDate();

			Wt::WText* rowText = newsTable->elementAt(newsCounter, columnCounter)->addNew<Wt::WText>(newsDate + ": " + newsText);

			rowText->setStyleClass("newsText");

			newsCounter++;
		
		}

		NewsArticle shownArticle = newsArticles[0];

		newsArticles.erase(newsArticles.begin());

		newsArticles.push_back(shownArticle);	

		newsTable->addStyleClass("table table-default table-borderless table-sm table-striped");



		/* Add the rows container inside the news container */
		newsCtn->addWidget(std::move(newsHeaderRow));

		newsCtn->addWidget(std::move(newsRow));

	
		/* Clear the main container */
		LTCAlAndInfSection->clear();


		/* Add the news container inside the section container  to show it on the page*/
		LTCAlAndInfSection->addWidget(std::move(newsCtn));


	}


}


/*! \brief This method is used to update the news data.
 *
 *  It is used to update the news data from Western or the News API.
 *  It will trigger getNewsData() method from the NewsData class.
 *  @param nInfo is the NewsData object that contains the news data.
 *  
 */
void LTCAlertAndInfoSection::updateNewsData(NewsData& nInfo) {

	if (!nInfo.getNewsArticles().empty()) {
	
		this->newsArticles.clear();

		this->newsArticles = nInfo.getNewsArticles();
	
	
	}

	

}

/*! \brief This method is used to create the LTC fares part of the section.
 * 
 *  This methods creates the LTC fares part of the section of the web page
 *  It creates the container for the fares and adds the title and the fares
 *  It is used to show the fares from the LTC website
 */
void LTCAlertAndInfoSection::createLTCFares() {


	/* Create the container for LTC fares */
	auto faresCtn = std::make_unique<Wt::WContainerWidget>();

	Wt::WApplication::instance()->styleSheet().addRule(".faresCtn","background-color: #E5FFED");

	faresCtn->addStyleClass("container-fluid px-2 fixed-bottom mb-2");

	faresCtn->setStyleClass("faresCtn");

	faresCtn->setHeight(Wt::WLength(12, Wt::LengthUnit::ViewportHeight));



	/* Create the row for LTC fares */
	auto faresCtnRow = std::make_unique<Wt::WContainerWidget>();

	faresCtnRow->addStyleClass("row px-4");

	
	/* Create the first column for LTC fares */
	auto faresCtnCol1 = std::make_unique<Wt::WContainerWidget>();

	faresCtnCol1->addStyleClass("col mx-auto");


	/* Create the second column for LTC fares */
	auto faresCtnCol2 = std::make_unique<Wt::WContainerWidget>();

	faresCtnCol2->addStyleClass("col mx-auto");


	/* Create the header row for title */

	Wt::WApplication::instance()->styleSheet().addRule(".faresHeaderRow", "text-align: center;");

	auto faresHeaderRow = std::make_unique<Wt::WContainerWidget>();

	faresHeaderRow->addStyleClass("row");

	faresHeaderRow->setStyleClass("faresHeaderRow");

	Wt::WApplication::instance()->styleSheet().addRule(".fareHeader", "color:black; font: Copperplate; font-weight:bold; font-size:15px; ");

	auto LTCFaresHeader = faresHeaderRow->addWidget(std::make_unique<Wt::WLabel>("LTC Bus Fares "));
	
	LTCFaresHeader->setStyleClass("fareHeader");

	Wt::WImage* faresLogo = faresHeaderRow->addWidget(std::make_unique<Wt::WImage>("images/sack-dollar-solid.svg"));

	Wt::WApplication::instance()->styleSheet().addRule(".faresImage", "fill:green; color:green; width:20px; height:20px;");

	faresLogo->addStyleClass("fa-solid fa-sack-dollar");

	faresLogo->setStyleClass("faresImage");

	

	/* Create the row where the tables containing the fares information will be added*/
	auto faresRow = std::make_unique<Wt::WContainerWidget>();

	faresRow->addStyleClass("row");



	/* Create the left table where the fares will be inserted*/
	auto faresTable1 = faresCtnCol1->addWidget(std::make_unique<Wt::WTable>());

	Wt::WApplication::instance()->styleSheet().addRule(".faresText", "color: green; font: Copperplate; font-weight:bold; font-size:12px; text-align: center; ");

	//int columnCounter = 0;

	//int rowCounter = 0;

	for (std::size_t i = 0; i < this->passengers.size() - 2; i++) {

		std::string type = passengers[i].getPassengerType();

		double fares = passengers[i].getBusFare();

		Wt::WText* rowText1 = faresTable1->elementAt(i, 0)->addNew<Wt::WText>(type);

		if (fares <= 0) {

			Wt::WText* rowText2 = faresTable1->elementAt(i, 1)->addNew<Wt::WText>("Free");

			rowText2->setStyleClass("faresText");

		}
		else {
		
			Wt::WText* rowText2 = faresTable1->elementAt(i, 1)->addNew<Wt::WText>("$" + std::to_string(static_cast<int>(std::round(fares))) + " CAD");

			rowText2->setStyleClass("faresText");
		
		}
	
		rowText1->setStyleClass("faresText");

	}


	/* Create the right table where the fares will be inserted*/
	auto faresTable2 = faresCtnCol2->addWidget(std::make_unique<Wt::WTable>());

	for (std::size_t i = 0; i < this->passengers.size() - 2; i++) {

		std::string type = passengers[(i+2)].getPassengerType();

		double fares = passengers[(i+2)].getBusFare();

		Wt::WText* rowText1 = faresTable2->elementAt(i, 0)->addNew<Wt::WText>(type);

		if (fares <= 0) {

			Wt::WText* rowText2 = faresTable2->elementAt(i, 1)->addNew<Wt::WText>("Free");

			rowText2->setStyleClass("faresText");

		}
		else {

			Wt::WText* rowText2 = faresTable2->elementAt(i, 1)->addNew<Wt::WText>("$" + std::to_string(static_cast<int>(std::round(fares))) + " CAD");

			rowText2->setStyleClass("faresText");

		}

		rowText1->setStyleClass("faresText");

	}

	/* Style both table using boostrap 5*/
	faresTable1->addStyleClass("table table-sm table-sucess table-borderless");

	faresTable2->addStyleClass("table table-sm table-sucess table-borderless");


	/* Add the header row and the fares row to the fares container*/
	faresCtnRow->addWidget(std::move(faresHeaderRow));

	faresCtnRow->addWidget(std::move(faresCtnCol1));

	faresCtnRow->addWidget(std::move(faresCtnCol2));

	faresCtn->addWidget(std::move(faresCtnRow));
	

	/* Clear the main container */
	LTCAlAndInfSection->clear();

	/* Add the fares container to the main container */
	LTCAlAndInfSection->addWidget(std::move(faresCtn));


}
