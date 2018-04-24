/*
 * Calculator.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: pournami
 */

#include "Calculator.h"


#define REMOVE_SPACE {while (s[index] == ' ') index++;} // remove space from the beginning of the expression

//Constructor Definition
Calculator::Calculator(string exp)
{
	s = exp;
	index = 0;

}

//Destructor Definition
Calculator::~Calculator() {

}

//Expression Definition: returns a double number
double Calculator::expression() throw(string)
{
	REMOVE_SPACE;
	double num = term(); // Calls term()
	while (s[index] == '+' || s[index] == '-')
	{
		num = (s[index++] == '+')? num + term(): num - term(); // Calls term()
	}
	return num;

}

//Term Definition
double Calculator::term() throw(string)
{
	REMOVE_SPACE;
	double num = factor(); // Calls factor()
	while (s[index] == '*' || s[index] == '/')
	{
		if(s[index] == '*')
		{
			index++;
			num = num * factor(); // Calls factor()
		}
		else if(s[index] == '/')
		{
			index++;
			double divisor = factor(); // Calls factor()
			(divisor != 0)? num = num / divisor : throw string("Division by zero");
		}
		else throw string("Unexpected "+s[index]);
	}
	return num;
}

double Calculator::factor() throw(string)
{
	double num = 0;
	REMOVE_SPACE;

	if (s[index] == '(')
	{
		index++;
		num = expression(); //// Calls expression()
		if (s[index] == ')') {
			index++;
			return num;
		} else throw string("Missing )");
	}
	if (!isdigit(s[index])) throw string("Invalid factor");

	getNum(num);
	return num;
}

void Calculator::getNum(double &num)
{
	string num_string = "";
	while(isdigit(s[index]) || s[index] == '.' || ((s[index] == 'e' || s[index] == 'E') && s[index+1] == '-') || ((s[index] == 'e' || s[index] == 'E')&& s[index+1] == '+'))
	{
		num_string += s[index++];
		if(s[index-1] == 'e' || s[index-1] == 'E') num_string += s[index++];
	}
	num = atof(&num_string[0]);
	return;
}
