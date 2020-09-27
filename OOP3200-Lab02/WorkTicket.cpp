/*
 * File Name: WorkTicket.cpp
 * Date: September 27, 2020
 * Duy Tan Vu			- 100750366
 * Domenic Catalano		- 100556614
 */

#include "WorkTicket.h"

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <string>			// String data type
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include <sstream>			// string stream

using namespace std;

/**** CLASS DEFINITION ****/


/* Parameterized Constructor definition */
WorkTicket::WorkTicket(int workTicketNumber, string clientID, int day, int month, int year, string issue)
{
	SetWorkTicketNumber(workTicketNumber);
	SetClientID(clientID);
	SetDate(day, month, year);
	SetIssueDescription(issue);
}

//// Copy constuctor definition
//WorkTicket::WorkTicket(const WorkTicket& ticket_2)
//{
//	SetWorkTicketNumber(ticket_2.GetWorkTicketNumber());
//	SetClientID(ticket_2.GetClientID());
//	SetDate(ticket_2.GetDate());
//	SetIssueDescription(ticket_2.GetIssueDescription());
//}

//// == operator for WorkTicket comparison
//bool WorkTicket::operator==(const WorkTicket& other_ticket) const
//{
//	return((GetWorkTicketNumber() == other_ticket.GetWorkTicketNumber()) && (GetClientID() == other_ticket.GetClientID())
//		&& (GetDate() == other_ticket.GetDate()) && (GetIssueDescription() == other_ticket.GetIssueDescription()));
//}

/* Accessor definition */

// Gets the date from the users input
string WorkTicket::GetDate(int objDay, int objMonth, int objYear) const
{
	// Create a string stream to display the date ticket was created
	stringstream dateReturn;
	dateReturn << objDay << "/" << objMonth << "/" << objYear;
	return dateReturn.str();
}

void WorkTicket::ShowWorkTicket() const
{
	// Display data using iomanip to format the text
	cout << setw(15) << "\nWork Ticket Number: " << objWorkTicketNumber << endl
		<< setw(15) << "Client ID: " << objClientID << endl
		<< setw(15) << "Ticket Date: " << objDay << "/" << objMonth << "/" << objYear << endl
		<< setw(15) << "Issue: " << objIssueDescription << endl;
}

/* Mutators definition*/

// Sets the date to each variable according to user input
void WorkTicket::SetDate(int day, int month, int year)
{
	// Assign day, month and year to object's attributes
	objDay = day;
	objMonth = month;
	objYear = year;
}

// Sets the client ID according to the users input and validates it
void WorkTicket::SetClientID(string clientID)
{
	// Constant of minimum string length required
	const int MIN_STRING_LENGTH = 1;

	// If client ID string is less than 1 then throw an exception
	if (clientID.length() < MIN_STRING_LENGTH)
	{
		stringstream errorMessage;
		errorMessage << "Please enter more than " << MIN_STRING_LENGTH << " characters.";
		throw invalid_argument(errorMessage.str());
	}
	objClientID = clientID;
}

// Sets the issue description according to the users input and validates it
void WorkTicket::SetIssueDescription(string issue)
{
	// Constant of minimum string length required
	const int MIN_STRING_LENGTH = 1;

	// If issue string is less than 1 then throw an exception
	if (issue.length() < MIN_STRING_LENGTH)
	{
		stringstream errorMessage;
		errorMessage << "Please enter more than " << MIN_STRING_LENGTH << " characters.";
		throw invalid_argument(errorMessage.str());
	}
	objIssueDescription = issue;
}

// If all validation checks through, the data will be accepted into this method
bool WorkTicket::SetWorkTicket(int workTicketNumber, string clientID, int day, int month, int year, string issue)
{
	SetWorkTicketNumber(workTicketNumber);
	SetDate(day, month, year);
	SetClientID(clientID);
	SetIssueDescription(issue);

	return true;
}
