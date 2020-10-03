#pragma once

#ifndef _EXTENDED_WORK_TICKET_H
#define _EXTENDED_WORK_TICKET_H

#include "WorkTicket.h"
#include <string>

class ExtendedWorkTicket: public WorkTicket
{
private:
	bool isOpen = true;

public:
	ExtendedWorkTicket();
	
	ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, const bool isOpen);

	//Accessor for isOpen
	bool IsOpen() const;
};

#endif
