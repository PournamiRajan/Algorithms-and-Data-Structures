#include "City.h"

/*
 * Overloaded input operator
 */
istream& operator >>(istream& ins, City& city)
{
	string lat,longi;
	getline(ins, city.name, ',');
	getline(ins, city.state, ',');
    ins>>city.coordinate;
    return ins;
}
/*
 * Overloaded output operator
 */
ostream& operator <<(ostream& outs, const City& city)
{
	return outs;
}

/*
 * Getters
 */
string City::getname() const
{
	return name;
}

string City::getstate() const
{
	return state;
}

Coordinate City::getcoordinate() const
{
	return coordinate;
}
/*
 * Destructor
 */
City::~City()
{

}
