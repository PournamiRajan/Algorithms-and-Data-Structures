/*
 * Calculator.h
 *
 *  Created on: Apr 8, 2018
 *      Author: pournami
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include <iostream>
using namespace std;

class Calculator {
public:
	Calculator(string exp); //Constructor
	virtual ~Calculator(); //Destructor

	double expression() throw (string); //Expression
	double term() throw(string); //Term
	double factor() throw(string); //Factor

	void getNum(double &num); // string to decimal conversion

private:
	string s;
	int index;

};

#endif /* CALCULATOR_H_ */
