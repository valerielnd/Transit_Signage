/*
 * Header file Game.h
 * @author Irmene-Valerie Leonard
 * Created on: Feb 6, 2023
 */
#include <string>
#include "ProcessData.h"

#ifndef URLREQ_H_
#define  URLREQ_H_

class URLReq {

public:
 
    virtual ~URLReq() {}

    virtual const std::string& getStringUrl() const = 0;
    
    virtual void setStringUrl(std::string str) = 0;

    virtual const std::string& getType() const = 0;

    virtual ProcessData* getProcessData() const = 0;
    

protected:
    
    std::string urlString;
    
    std::string returnType;

    ProcessData* getNews;
};
#endif
