/*
 * Header file for Class JSONReq
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 8, 2023
 */

#include <string>
#include "URLReq.h"

#ifndef JSONREQ_H_
#define  JSONREQ_H_


 /*!
   * This class implements the class of URLReq. It is used to create a JSONReq object.
   *
   */
class JSONReq : public URLReq {

private:
    
    std::string urlString;
    
    std::string returnType;

    ProcessData* getNews;


public:

    JSONReq();

    JSONReq(std::string url);

    virtual ~JSONReq();

    virtual const std::string& getStringUrl() const ;
    
    virtual void setStringUrl(std::string str) ;

    virtual const std::string& getType() const ;

    virtual ProcessData* getProcessData() const;
   
};

#endif
