#pragma once

#ifndef POSITION_H_
#define POSITION_H_


class Position
{
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
