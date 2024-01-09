/*
 * Header file for Class ProcessData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */

#include <string>
#include <vector>
#include "NewsArticle.h"

#ifndef DATA_H_

#define  DATA_H_

 /*!
   * This class is an abstract class that is used to process News data
   *
   */
class ProcessData {

public:

    virtual ~ProcessData() {}

    virtual void processString(std::string str) = 0;

    virtual std::vector<NewsArticle> returnResult() = 0;


};
#endif
