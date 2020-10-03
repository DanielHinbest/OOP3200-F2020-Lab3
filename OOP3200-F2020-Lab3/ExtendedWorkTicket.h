/* Program Name: OOP 3200 - Lab 3 - Inheritance
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: October 4, 2020
 * Description: A child class of the WorkTicket parent class that allows the opening and closing of tickets
 */
#pragma once

#ifndef _EXTENDED_WORK_TICKET_H
#define _EXTENDED_WORK_TICKET_H

#include "WorkTicket.h"
#include <string>

class ExtendedWorkTicket : public WorkTicket
{
private:
	// Attribute of the ExtendedWorkTicket to set its open status
	bool isOpen = true;

public:
	//Default constructor - Calls the WorkTicket and sets the isOpen value
	ExtendedWorkTicket()
	{
		WorkTicket();
		isOpen = true;
	}

	//Parameterized constructor - sets the parameters from the parent class and the isOpen parameter
	//Initializes all the inherited attributes
	ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, const bool my_isOpen);

	//Accessor for isOpen
	bool IsOpen() const;

	//Mutator to close the ticket
	void CloseTicket();

	//Mutator to set the work ticket
	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, const bool my_isOpen);

	//Overrides ShowWorkTicket
	void ShowWorkTicket() const override;

	//Overload << operator
	friend ostream& operator << (ostream& out, const ExtendedWorkTicket& ticket);


};

//Parameterized constructor of ExtendedWorkTicket
ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day,
	const int year, const string& description, const bool my_isOpen)
{
	SetTicketNumber(ticket_number);
	SetClientId(client_id);
	SetDate(day, month, year);
	SetDescription(description);
	isOpen = my_isOpen;
}

//Accessor to return the isOpen attribute
bool ExtendedWorkTicket::IsOpen() const
{
	return isOpen;
}

//Function override that calls the parent function and outputs whether it's open or closed
void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();

	if (isOpen == true)

		cout << "Ticket:        OPEN" << endl;
	else

		cout << "Ticket:        CLOSED" << endl;
}

//Mutator that closes the work ticket
void ExtendedWorkTicket::CloseTicket()
{
	isOpen = false;
}

//Function overload that checks if the input is valid and will set the work ticket if it is valid
bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year,
	const string& description, const bool my_isOpen)
{
	bool valid = true;
	if (my_isOpen != true)
	{
		valid = false;
	}
	else
	{
		WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description);
		isOpen = my_isOpen;
	}
	return valid;
}
// Overloaded input operator for ExtendedWorkTicket
ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
	string valid;

	if (ticket.isOpen == true)
	{
		valid = "OPEN";
	}
	else
	{
		valid = "CLOSED";
	}

	out << (WorkTicket)ticket
		<< "Ticket:        " << valid << std::endl;

	return out;
}
//end of overload
#endif

