/*
 * File Name: main.cpp
 * Program Name: OOP3200 - Lab 2: Class Operators and Data Type Conversions
 * Date: September 27, 2020
 * Description: This is a modified version of lab 1 with the addition of
				 operators and data type conversions
 * Authors:	 Duy Tan Vu          - 100750366
 *			 Domenic Catalano    - 100556614
 * OOP3200 - Lab 02: Class Operators and Data Type Conversions
 */

#include "WorkTicket.h"
#include "MyConsoleInput.h"	// ConsoleInput::ReadInteger()

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <string>			// String data type
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include <sstream>			// string stream

using namespace std;

int main()
{
	// Declared object for purpose of 'existing object'
	WorkTicket ticket1(1001, "1002", 27, 11, 2020, "test");		// Declared object for purpose of 'existing object'
	WorkTicket userTicket;										// Object to hold user input

	// Copy constructor used to declare a new object based on an existing one
	WorkTicket ticket2(ticket1);

	// Typecasting an object as a string to output to the console
	string ticketAsString = string(ticket1);
	cout << ticketAsString;

	// User input attributes for an object
	cout << "\nEnter attributes for a ticket: ";
	cin >> userTicket;

	// Test if the two objects are equal
	if (ticket1 == userTicket)
	{
		cout << "The two tickets match!";
	}
	else
	{
		cout << "The two tickets do NOT match!";
	}

	// Assigning an object to another existing object
	ticket1 = userTicket;


	// Output an object using cout
	userTicket.ShowWorkTicket();

	// End of the program
	cout << endl << endl;
	return 0;
}