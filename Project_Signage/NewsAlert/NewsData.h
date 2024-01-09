/*
 * Header file for Class NewsData
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 3, 2023
 */


#include <string>
#include <vector>
#include "NewsArticle.h"
#include "URLReq.h"

#ifndef NEWSDATA_H_
#define  NEWSDATA_H_

 /*!
   * This class is used to store the news articles and the news APIs
   *
   */
class NewsData {

private:

	std::vector<NewsArticle> appNews;

	std::vector<URLReq*> newsAPIs;

public:

	NewsData();

	~NewsData();

	NewsData(std::vector<URLReq*> APIs, std::vector<NewsArticle> articles);

	const std::vector<NewsArticle>& getNewsArticles() const;

	const std::vector<URLReq*>& getNewsAPIs() const;

	bool addArticle(NewsArticle article);

	bool removeArticle(NewsArticle article);

	bool findArticle(NewsArticle article);

	std::vector<NewsArticle>::iterator getArticlePosition(NewsArticle article);

	void setNewsArticle(std::vector<NewsArticle> articles);

	void setNewsAPIs(std::vector<URLReq*> APIs);

	void pullNewsData();

	std::string getNewsString(std::string);

	void printNewsArticles() const;


};
#endif /* NEWSDATA_H_ */
