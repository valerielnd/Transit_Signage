/*! \file DateTimeSection.h
 * 
 * Header file for Class DateAndTimeSection
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <Wt/WDate.h>
#include <Wt/WTime.h>
#include <Wt/WLocale.h>
#include <Wt/WTimer.h>
#include <Wt/WLabel.h>
#include <Wt/WDateTime.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WApplication.h>

#ifndef DATETIME_H_
#define DATETIME_H_

 /*! \brief This class is used to display the date and time on the signage
  *
  *  This class is used to create the section on the web page where the date and time are displayed.
  *  The time and date displayed are updated every 30 seconds.
  *  
  */
class DateTimeSection : public Wt::WContainerWidget {

private:

    Wt::WDateTime* dateTime;

    Wt::WLabel* dateLabel;

    Wt::WLabel* timeLabel;


public:

    DateTimeSection();

    ~DateTimeSection();

    void updateTime();

    Wt::WDateTime* getDateTime() const;


};

#endif // !DATETIME_H_