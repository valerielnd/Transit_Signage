/*
 * Header file for Class Position
 * @author Irmene-Valerie Leonard
 * @author Nguyen Albert An
 * @author IYuan Jiaqi
 * @author  Bkkourh Oby
 * @author Sarkar Aaron
 * Created on: March 1, 2023
 */

#ifndef POSITION_H_
#define POSITION_H_

 /*!
   * This class represent a posThis class represent a position in the map with a latitude and a longitude
   *
   */
class Position {

private:
	double posLat;

	double posLon;

public:

	Position();

	Position(double lat, double lon);

	~Position();

	double getLat() const;

	double getLon() const;

	void setLat(double lat);

	void setLon(double lon);

	bool isEqual(const Position& other);

	void printPosition() const;


};
#endif // !POSITION_H_
