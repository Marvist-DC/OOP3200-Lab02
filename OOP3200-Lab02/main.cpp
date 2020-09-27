/*
 * File Name: main.cpp
 * Program Name: OOP3200 - Lab 2: Class Operators and Data Type Conversions
 * Date: September 27, 2020
 * Description: This is a modified version of lab 1 with the addition of
				 operators and data type conversions
 * Authors: Duy Tan Vu          - 100750366
 *          Domenic Catalano    - 100556614
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
	// Program banner
	cout << "================" << endl
		<< "WorkTicket Class" << endl
		<< "================" << endl;

	// VARRIABLE DECLARATIONS & ARRAY
	WorkTicket workTicketObject[3];
	string clientID;
	int ticketNumber;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	string issue;
	bool result;		// Flag of the SetWorkTicket() function

	// CONSTANT DECLARATIONS
	const int MIN_TICKET_NUMBER = 1;
	const int MIN_DAY = 1;
	const int MAX_DAY = 31;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;
	const int MIN_YEAR = 2000;
	const int MAX_YEAR = 2099;

	// Try-catch block to catch an exception
	// Try-catch block to display error message
	try
	{
		// For loop will interate 3 times to fill array
		for (int i = 0; i < 3; ++i)
		{
			// Prompt for ticket number
			cout << "\nPlease enter a Work Ticket Number [" << i + 1 << "]: ";
			ticketNumber = ConsoleInput::ReadInteger(MIN_TICKET_NUMBER);

			// Prompt for client ID
			cout << "Please enter a Client ID Number [" << i + 1 << "]: ";
			cin >> clientID;

			// Prompt for day ticket created
			cout << "Please enter ticket day [" << i + 1 << "]: ";
			ticketDay = ConsoleInput::ReadInteger(MIN_DAY, MAX_DAY);

			// Prompt for month ticket created
			cout << "Please enter ticket month [" << i + 1 << "]: ";
			ticketMonth = ConsoleInput::ReadInteger(MIN_MONTH, MAX_MONTH);

			// Prompt for year ticket created
			cout << "Please enter ticket year [" << i + 1 << "]: ";
			ticketYear = ConsoleInput::ReadInteger(MIN_YEAR, MAX_YEAR);

			// Prompt for description of the issue
			cout << "Please enter your issue description [" << i + 1 << "]: ";
			cin >> issue;

			// If all parameters are valid, return true and display a message. Otherwise return false
			result = workTicketObject[i].SetWorkTicket(ticketNumber, clientID, ticketDay, ticketMonth, ticketYear, issue);
			if (!result)
			{
				cout << "Data is invalid, please try again.";
			}
			else
			{
				cout << "Data was successfully entered.\n";
			}
		}

		// Output summary of the data to the user
		cout << "\n== Data Summary ==\n";
		for (int i = 0; i < 3; ++i)
		{
			workTicketObject[i].ShowWorkTicket();
		}

	}
	// Display exception if invalid data was entered
	catch (const exception & e)
	{
		// Show error message
		cerr << e.what();
	}

	// End of the program
	cout << endl << endl;
	return 0;
}