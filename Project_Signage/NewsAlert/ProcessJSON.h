/*
 * Header file for Class ProcessJSON
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 10, 2023
 */


#include <string>
#include <vector>
#include "ProcessData.h"
#include "NewsArticle.h"

#ifndef PROCESSJSON_H_
#define PROCESSJSON_H_

 /*!
   * This class is used to process the News Data coming from API in JSON format
   * It implements the abstract class ProcessData
   */
class ProcessJSON : public ProcessData {

private:

    std::vector<NewsArticle> result;


public:

    ProcessJSON();

    virtual ~ProcessJSON();

    virtual void processString(std::string str);

    virtual std::vector<NewsArticle> returnResult();

};

#endif
