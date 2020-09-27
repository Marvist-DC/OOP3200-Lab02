/*
 * File Name: WorkTicket.cpp
 * Date: September 27, 2020
 * Duy Tan Vu			- 100750366
 * Domenic Catalano		- 100556614
 * WorkTicket class definition
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

// Copy constuctor definition
WorkTicket::WorkTicket(const WorkTicket& ticket_2)
{
	objWorkTicketNumber = ticket_2.objWorkTicketNumber;
	objClientID = ticket_2.objClientID;
	objDay = ticket_2.objDay;
	objMonth = ticket_2.objMonth;
	objYear = ticket_2.objYear;
	objIssueDescription = ticket_2.objIssueDescription;

	cout << "\nA WorkTicket object was COPIED.\n";
}

WorkTicket::operator string()
{
	stringstream converted_ticket;
	converted_ticket << "Work Ticket #" << objWorkTicketNumber << " - "
					 << objClientID << " (" << objDay << "/" << objMonth 
					 << "/" << objYear << "): " << objIssueDescription;
	return converted_ticket.str();
}

// == operator for WorkTicket comparison
bool WorkTicket::operator==(const WorkTicket& other_ticket) const
{
	return((GetWorkTicketNumber() == other_ticket.GetWorkTicketNumber()) && (GetClientID() == other_ticket.GetClientID())
		&& (GetDate() == other_ticket.GetDate()) && (GetIssueDescription() == other_ticket.GetIssueDescription()));
}

// = operator to assign a WorkTicket to another WorkTicket
WorkTicket WorkTicket::operator=(const WorkTicket &new_work_ticket)
{
	
	objWorkTicketNumber = new_work_ticket.objWorkTicketNumber;
	objClientID = new_work_ticket.objClientID;
	objDay = new_work_ticket.objDay;
	objMonth = new_work_ticket.objMonth;
	objYear = new_work_ticket.objYear;
	objIssueDescription = new_work_ticket.objIssueDescription;
	cout << "\nA WorkTicket Object was ASSIGNED.\n";
	return *this;
}

// << operator to displays all objects attributes neatly on the console
ostream& operator<<(ostream& out, const WorkTicket& work_ticket)
{
	work_ticket.ShowWorkTicket();
	return out;
}

// >> operator allow user to enter all of the attributes of a WorkTicket object
istream& operator>>(istream& in, WorkTicket& work_ticket)
{
	in >> work_ticket.objWorkTicketNumber;
	in >> work_ticket.objClientID;
	in >> work_ticket.objDay;
	in >> work_ticket.objMonth;
	in >> work_ticket.objYear;
	in >> work_ticket.objIssueDescription;

	return in;
}


/* Accessor definition */

// Gets the date from the users input
string WorkTicket::GetDate() const
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
