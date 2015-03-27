//Author: Steven Dewey 
//Description: This application manages the inventory of a car lot, this is done by using a car class to manage all the differnt cars in the system 
//test case #1: I enter 2 and all the current inventory is displayed and I am routed back to the main screen
//test case #2: I enter 5 and am prompted to enter the name of a car to paint, if the car is in the system then I choose what color and then that color is updated, and the price goes up by 1000
//test case #3 I enter 7 and I am prompted for the name of the file I want to save and then the current inventory is saved to the file. 

#include <iostream>
#include <string>
#include <ctime> 
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include "Player.h"

using namespace std;
//function to check if the user entered a string when they should have entered an int
void check_cin(int& userInput)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        userInput = 0;
    }
}

int main()
{
	vector<Player*> allPlayers;
	vector<Player*> playersWaiting;
	bool keepLooping = true;
	//looping function to display menu
	while (keepLooping)
	{
		int userInput;
		cout << "\n\n Please select one of these options: " << endl;
		cout << "1 - Show Players " << endl;
		cout << "2 - Add Player " << endl;
		cout << "3 - Add To Line-up " << endl;
		cout << "4 - Show Line-up " << endl;
		cout << "5 - Fight " << endl;
		cout << "6 - Quit Program " << endl;
		cin >> userInput;
		check_cin(userInput);
		//if user inputs a 1 then display all the inventory with a for loop
		if (userInput == 1)
		{
			
		}
		//if the user inputs 2 then simply display the current balance 
		else if (userInput== 2)
		{
			
		}
		//if use inputs three then allow user to buy a car if the car is not already in the inventory and if buying the car will not make the balance less than 0
		else if (userInput== 3)
		{
			
		}
		//function to sell a the car the user inputs to sell if the car they input is in the system. 
		else if (userInput== 4)
		{
			
		}
		//function to pain the car if the car the user inputs is in the system 
		else if (userInput== 5)
		{
			
		}
		//exit the program
		else if (userInput== 6)
		{
			cout << "\n\nGOODBYE!\n\n" << endl;
			keepLooping = false;
		}
		else
		{
			cout << "Invalid Input. Please Try Again." << endl;
		}
		if (userInput == 0)
		{
			cout << "Invalid Input. Please Try Again." << endl;
		}

	}
	
	system("pause");
	return 0;
}