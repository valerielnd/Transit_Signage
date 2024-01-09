/*! \file DateTimeSection.cpp
 * 
 * Definition file for Class DateAndTimeSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include "DateTimeSection.h"

 /*! \brief Constructor for the DateTimeSection class.
   *  This class is used to display the date and time on the signage.
   *
   *  This constructor construct the section on the web page where the date and time are displayed.
   *  It is used to create the main container for this section and the row that will contain the date and time.
   */
DateTimeSection::DateTimeSection() {
    
    /* Create the main container for the time and date */ 
    auto timeAndDateCtn = std::make_unique<Wt::WContainerWidget>();

    Wt::WApplication::instance()->styleSheet().addRule(".timeAndDate", "height: 5%;");

    timeAndDateCtn->addStyleClass("container-fluid py-2 px-2");

    timeAndDateCtn->setHeight(Wt::WLength(5, Wt::LengthUnit::ViewportHeight));

    timeAndDateCtn->setStyleClass("pageHeader");


    /* Create the row that will contain the date and time */
    auto timeAndDateRow = std::make_unique<Wt::WContainerWidget>();

    timeAndDateRow->addStyleClass("row bg-primary bg-gradient mx-2");

    auto dateCol = std::make_unique<Wt::WContainerWidget>();

    dateCol->addStyleClass("col p-1");

   
    /*Get the current date with the time*/
    this->dateTime = new Wt::WDateTime(Wt::WDateTime::currentDateTime());

    int seconds = dateTime->time().second();

    dateTime->setTime(Wt::WDateTime::currentDateTime().addSecs(-(14400 + seconds)).time());

    
    /* Create the date and time labels */
    Wt::WApplication::instance()->styleSheet().addRule(".dateS", "font:Papyrus; color:white; font-size: 16px; font-weight:bold;");

    dateLabel = dateCol->addWidget(std::make_unique<Wt::WLabel>(dateTime->toString("ddd MMM d")));

    dateLabel->setStyleClass("dateS");

    auto timeCol = std::make_unique<Wt::WContainerWidget>();

    timeCol->addStyleClass("col p-1 text-end me-2");

    Wt::WApplication::instance()->styleSheet().addRule(".time", "font:Papyrus; color:white; font-size: 16px; font-weight:bold;");

    timeLabel = timeCol->addWidget(std::make_unique<Wt::WLabel>(dateTime->toString("hh:mm AP")));

    timeLabel->setStyleClass("time");


    /* Add the date and time labels to the row */
    timeAndDateRow->addWidget(std::move(dateCol));

    timeAndDateRow->addWidget(std::move(timeCol));


    /* Add the row to the main container */
    timeAndDateCtn->addWidget(std::move(timeAndDateRow));

    /* Add the time and date container container in this section container to show it on the page*/
    addWidget(std::move(timeAndDateCtn));

   
}

/*! \brief Destructor for the DateTimeSection class
  *
  *  This destructor is used to delete the date and time object.
  */
DateTimeSection::~DateTimeSection() {

    //delete this->dateTime;
}

/*! \brief This method is used to update the time and date on the signage.
  *
  *  This method is used to update the time and date on the signage every 30 seconds.
  *  It gets called by the App main class.
  */
void DateTimeSection::updateTime() {

    /* Get the previous date wtih the time*/
    Wt::WDate previousDate = this->dateTime->date();

    int seconds = dateTime->time().second();

    /* Update the time */
    dateTime->setTime(Wt::WDateTime::currentDateTime().addSecs(-(14400 + seconds)).time());

    timeLabel->setText(dateTime->toString("hh:mm AP"));

    /* Update the date */
    Wt::WDate newDate = dateTime->date();

    if (newDate.daysTo(previousDate) == 1) {

        dateLabel->setText(dateTime->toString("ddd MMM d"));

    }

    this->refresh();
}


/*! \brief This method is used to get the date and time object.
*
*  This method is used to get the date and time object.
*  This is used to propagate the same time and date object to the other sections.
*/
Wt::WDateTime* DateTimeSection::getDateTime() const {

    return dateTime;


}


	
