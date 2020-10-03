/* Program Name: OOP 3200 - Lab 3 - Inheritance
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: October 4, 2020
 * Description: Another modification of WorkTicket with a child class of the WorkTicket parent class that allows the opening and closing of tickets
 */

#include <iostream>

#include "ExtendedWorkTicket.h"


int main()
{
	//Default ticket1
	ExtendedWorkTicket testTicket1;
	//Parameters for testTicket2
	ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true);

	//Outputs testTicket1 & testTicket2
	std::cout << std::endl << "As Initialized: " << std::endl;
	testTicket1.ShowWorkTicket();
	testTicket2.ShowWorkTicket();


	if (!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 1: " << testTicket1 << std::endl;

	if (!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 2: " << testTicket2 << std::endl;

	//Closes ticket2
	testTicket2.CloseTicket();

	std::cout << std::endl << "After Ticket 2 closed: " << testTicket2 << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}




