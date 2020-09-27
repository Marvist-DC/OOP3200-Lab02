/*
 * File Name: WorkTicket.h
 * Date: September 27, 2020
 * Duy Tan Vu			- 100750366
 * Domenic Catalano		- 100556614
 * Header file for WorkTicket class
 */

#pragma once

#ifndef __WORKTICKET__
#define __WORKTICKET__

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <string>			// String data type
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include <sstream>			// string stream

using namespace std;

/**** CLASS DECLARATION ****/

class WorkTicket
{

public:

	/* Default Constructor */
	WorkTicket() : objWorkTicketNumber(0), objClientID(""), objDay(1), objMonth(1), objYear(2000), objIssueDescription("") {}

	/* Parameterized Constructor */
	WorkTicket(int workTicketNumber, string clientID, int day, int month, int year, string issueDescription);

	/* Copy Constructor*/
	WorkTicket(const WorkTicket& ticket_2);

	/* Operator Overloads */

	operator string();

	// Overload operator to compare two WorkTicket objects
	bool operator==(const WorkTicket& other_ticket) const;

	// Overload operator to assign a WorkTicket to another WorkTicket
	WorkTicket operator=(const WorkTicket &new_work_ticket);

	// Overload operators for retrieving class information and to output/display class information
	friend ostream& operator<<(ostream& out, const WorkTicket& work_ticket);
	friend istream& operator>>(istream& in, WorkTicket& work_ticket);

	/* Accessors */
	int GetWorkTicketNumber() const { return objWorkTicketNumber; }
	string GetClientID() const { return objClientID; }
	string GetDate() const;
	string GetIssueDescription() const { return objIssueDescription; }
	void ShowWorkTicket() const;

	/* Mutators */
	void SetWorkTicketNumber(int workTicketNumber) { objWorkTicketNumber = workTicketNumber; }
	void SetClientID(string clientID);
	void SetDate(int day, int month, int year);
	void SetIssueDescription(string issue);
	bool SetWorkTicket(int workTicketNumber, string clientID, int day, int month, int year, string issue);

	// Private Attributes
private:
	int objWorkTicketNumber;		// Work ticket number
	string objClientID;				// Client ID
	int objDay;						// Date of creation
	int objMonth;					// Month of creation
	int objYear;					// Year of creation
	string objIssueDescription;		// Description of the issue
};

#endif /* defined (__WORKTICKET__) */

