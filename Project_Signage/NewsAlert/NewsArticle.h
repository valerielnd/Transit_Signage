/*
 * Header file for Class NewsArticle
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 5, 2023
 */


# include <string>

#ifndef NEWSARTICLE_H_
#define  NEWSARTICLE_H_

 /*!
   * This class is used to create a news article object
   *
   */
class NewsArticle {

private: 

	std::string newsInfo;
	std::string newsDate;
	

public:

	NewsArticle();

	~NewsArticle();

	NewsArticle(std::string data, std::string date);

	const std::string& getNewsData() const;

	const std::string& getNewsDate() const;

	void setNewsData(std::string data);

	void setNewsDate(std::string date);

	void printNewsData() const;

	bool operator==(const NewsArticle& other) const;

};

#endif /* NEWSARTICLE_H_ */
