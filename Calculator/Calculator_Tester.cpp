/*
 * Calculator_Tester.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: pournami
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Calculator.h"
using namespace std;
/*
 * To perform the user input operation
 * @param expression : User input expression to execute
 */
double perform_operation(string expression);

int main()
{
	while(1)
	{
		cout << "Expression? ";
		string line;
		cin >> line;
		try
		{
			if(line == ".") break; //End of execution
			if(line[line.length()-1] != '=') throw string("Equal to(=) expected at end"); // = missing at end
			double result = perform_operation(line);
			cout << "\n result = " << result << endl<<endl;
		}
		catch (string& msg)
		{
			cout << endl << "***** " << msg << endl;
		}
	}
	cout << "Done!" << endl;
	return 0;
}

double perform_operation(string line)
{
	Calculator calc(line); // Creating calculator object
	return calc.expression(); // calling expression function

}



