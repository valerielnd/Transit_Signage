
/*
 * Header file Game.h
 * @author Irmene-Valerie Leonard
 * Created on: Feb 6, 2023
 */
#include <string>
#include <vector>
#include "ProcessData.h"
#include "NewsArticle.h"

#ifndef PROCESSHTML_H_
#define PROCESSHTML_H_

class  ProcessHTML : public ProcessData {

private:

    std::vector<NewsArticle> result;


public:

    ProcessHTML();

    virtual ~ProcessHTML();

    virtual void processString(std::string str);

    virtual std::vector<NewsArticle> returnResult();

};

#endif

