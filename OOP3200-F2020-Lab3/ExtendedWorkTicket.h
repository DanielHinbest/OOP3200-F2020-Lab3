/* Program Name: OOP 3200 - Lab 3 - Inheritance
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: October 4, 2020
 * Description:
 */
#pragma once

#ifndef _EXTENDED_WORK_TICKET_H
#define _EXTENDED_WORK_TICKET_H

#include "WorkTicket.h"
#include <string>

class ExtendedWorkTicket : public WorkTicket
{
private:
	bool isOpen = true;

public:
	ExtendedWorkTicket()
	{
		WorkTicket();
		isOpen = true;
	}

	ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, const bool my_isOpen);

	//Accessor for isOpen
	bool IsOpen() const;
	void CloseTicket();

	//Mutator to set the work ticket
	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, const bool my_isOpen);

	//Overrides ShowWorkTicket
	void ShowWorkTicket() const override;

	//Overload << operator
	friend ostream& operator << (ostream& out, const ExtendedWorkTicket& ticket);


};
/* Program Name: OOP 3200 - Lab 3 - Inheritance
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: October 4, 2020
 * Description:
 */

#include "ExtendedWorkTicket.h"

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

bool ExtendedWorkTicket::IsOpen() const
{
	return isOpen;
}

void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();

	if (isOpen == true)

		cout << "\nTicket: OPEN" << endl;
	else

		cout << "\nTicket: CLOSED" << endl;
}

void ExtendedWorkTicket::CloseTicket()
{
	isOpen = false;
}

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

ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
	string valid;

	if (ticket.isOpen == true)
	{
		valid = "Open";
	}
	else
	{
		valid = "Closed";
	}

	out << (WorkTicket)ticket
		<< "Open:" << valid << std::endl;

	return out;
}

#endif

