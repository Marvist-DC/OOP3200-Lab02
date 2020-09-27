/*
 * File Name: MyConsoleInput.cpp
 * Date: September 20, 2020
 * Duy Tan Vu          - 100750366
 * Domenic Catalano    - 100556614
 * This is the header of functions used to validate numbers
 * These two functions are allowed to use for OOP3200 - Lab 01
 * Reference: DC Connect OOP3200 materials on Week 01 Content
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>		 // numeric_limits
#include <cfloat>		 // for limits of a double DBL_MIN and DBL_MAX
#include <sstream>		 // for create a stream to throw an error
#include <stdexcept>	 // exception handling

#include "MyconsoleInput.h"

using namespace std;

// ReadDouble function definition
double ConsoleInput::ReadDouble(const double MIN, const double MAX)
{

	double validNumber = 0.0;	// holds the user input
	stringstream errorMessage;	// an error message string stream 
	cin >> validNumber;			// try to get input

	// remove any remaining characters from the buffer.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// if user input fails...
	if (cin.fail())
	{
		cin.clear();	// Reset the fail() state of the cin object.
		cin.sync();		// clear the buffer

		// Store the error to a string stream
		errorMessage << "* Invalid input. Please try again and enter a numeric value.\n";

		// Throw an exception if input is not numeric

		throw invalid_argument(errorMessage.str());

		// Try again by calling the function again (recursion)
		validNumber = ReadDouble(MIN, MAX);
	}
	else if (validNumber < MIN || validNumber > MAX)// if value is outside range...
	{
		// Store the error to a string stream
		errorMessage << " * Invalid input. Please try again and enter a value between "
			<< MIN << " and " << MAX << ".\n";

		// Throw an exception if input is not numeric
		throw invalid_argument(errorMessage.str());
		// Try again by call the function again (recursion)
		validNumber = ReadDouble(MIN, MAX);
	}

	return validNumber; // returns a valid value to the calling function.
}

// ReadInteger function definition
int ConsoleInput::ReadInteger(const int MIN, const int MAX)
{

	double validNumber = 0.0; // holds the user input
	stringstream errorMessage;		// Store the error to a string stream
	validNumber = ConsoleInput::ReadDouble(MIN, MAX); // Get user input as a double

	// if(abs(validNumber - (int) validNumber) > 0.00000001) // Alternative
	if (validNumber > (int)validNumber)      // If user input is not a whole number
	{
		// report the problem to the user.
		errorMessage << " * Invalid input. Please try again and enter whole number.\n";
		throw invalid_argument(errorMessage.str());
		validNumber = ReadInteger(MIN, MAX); // try again using recursion.
	}
	return (int)validNumber; // returns a valid value to the calling function.
}
