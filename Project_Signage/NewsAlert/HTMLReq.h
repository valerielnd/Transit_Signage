/*
 * Header file Game.h
 * @author Irmene-Valerie Leonard
 * Created on: Feb 6, 2023
 */
#include <string>
#include "URLReq.h"

#ifndef HTMLREQ_H_
#define  HTMLREQ_H_


class HTMLReq : public URLReq {

private:

    std::string urlString;

    std::string returnType;

    ProcessData* getNews;


public:

    HTMLReq();

    HTMLReq(std::string url);

    virtual ~HTMLReq();

    virtual const std::string& getStringUrl() const;

    virtual void setStringUrl(std::string str);

    virtual const std::string& getType() const;

    virtual ProcessData* getProcessData() const;

};

#endif
