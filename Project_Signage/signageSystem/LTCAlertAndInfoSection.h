/*! \file LTCAlertAndInfoSection.h
 * 
 * Header file for Class TCAlertAndInfoSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 12, 2023
 */

#include <Wt/WContainerWidget.h>
#include <Wt/WApplication.h>
#include <Wt/WLabel.h>
#include <Wt/WTimer.h>
#include <Wt/WTable.h>
#include "../LTC/LTCInfo.h"
#include "../LTC/LTCAlert.h"
#include "../NewsAlert/NewsData.h"

#ifndef LTHALINFO_H
#define LTHALINFO_H

 /*! \class LTCAlertAndInfoSection
  * 
  *  \brief This class is used to display the LTC alerts and information.
  *		It is also used to display the news alerts.
  *
  *  This class is used to create the section on the web page where the LTC alerts and information are displayed.
  *  It also creates the section where the news alerts are displayed. Each category of information are shown in rotation every 30 seconds
  *  
  *  
  */
class LTCAlertAndInfoSection : public Wt::WContainerWidget {

private:

	Wt::WContainerWidget* LTCAlAndInfSection;

	Wt::WLabel* LTCAlerts;

	std::string fleetInfo;

	std::string stopInfo;

	std::string phoneInfo;

	std::string emailInfo;

	std::string addressInfo;

	Wt::WLabel* NewsAlerts;

	Wt::WTimer timer;

	std::vector<NewsArticle> newsArticles;

	std::vector<Passenger> passengers;


public:

	LTCAlertAndInfoSection(LTCInfo info, NewsData nInfo);

	~LTCAlertAndInfoSection();

	void createLTCAccessbility();

	void createLTCContactInfo();

	void createNewsAlerts();

	void updateNewsData(NewsData& nInfo);

	void createLTCFares();

	

};

#endif // !LTHALINFO_H
