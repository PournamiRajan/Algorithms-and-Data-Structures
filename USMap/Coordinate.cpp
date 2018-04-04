#include "Coordinate.h"
#include <string>

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;
/*
 * Getters
 */
double Coordinate::getlatitude() const
{
	return latitude;
}
double Coordinate::getlongitude() const
{
	return longitude;
}
/*
 * Overloaded input operator
 */

istream& operator >>(istream& ins, Coordinate& coordinate)
{
   string lat,longi;
   getline(ins, lat, ',');
   getline(ins, longi);
   coordinate.latitude = stod(lat, nullptr);
   coordinate.longitude = stod(longi);
   return ins;
}

Coordinate::~Coordinate()
{

}
