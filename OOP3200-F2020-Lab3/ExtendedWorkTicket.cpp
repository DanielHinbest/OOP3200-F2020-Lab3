#include "ExtendedWorkTicket.h"

ExtendedWorkTicket::ExtendedWorkTicket()
{
	
}

//Parameterized constructor of ExtendedWorkTicket
ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day,
	const int year, const string& description, const bool isOpen)
{
	
}

bool ExtendedWorkTicket::IsOpen() const
{
	return isOpen;
}
