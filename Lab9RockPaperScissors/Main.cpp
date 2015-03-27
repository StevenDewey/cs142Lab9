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
int findPlayer(vector<Player*>& allPlayers, string newName){
	if (allPlayers.size() == 0)
		{
			return -1;
		}
	for (int i = 0; i < allPlayers.size(); i++)
	{
		if (newName == allPlayers[i]->getName())
		{
			return i;
		}
	}
	return -1;
}

void showPlayers(vector<Player*> players){
	for (int i = 0; i < players.size(); i++)
		{
			cout << players[i]->toString() << endl;
		}
		if (players.size() == 0)
		{
			cout << "\nNo Players Are Currently in the System. Try Selecting Option 2 From the Menu to Add More Players." << endl;
		}
}
void addPlayer(vector<Player*>& allPlayers){
	string newName;
		cout << "\nNew Player Name: " << endl;
		cin.sync();
		getline(cin, newName);
		if (findPlayer(allPlayers, newName) >=0)
		{
			cout << "\nError, Player Named " << newName << " is Already in System. Please Try Again." << endl;
		}
		else
		{
			allPlayers.push_back(new Player(newName));
			cout << "\nPlayer Named " << newName << " Has Been Added to System." << endl;
		}
}
void addPlayerToLineUp(vector<Player*>& allPlayers, vector<Player*>& playersWaiting){
	string playerName;
		cout << "Player Name: " << endl;
		cin.sync();
		getline(cin, playerName);
		int index = findPlayer(allPlayers, playerName);
		if (index >=0)
		{
			playersWaiting.push_back(allPlayers[index]);
			cout << "\nPlayer Named " << playerName << " Has Been Added to the Line-Up." << endl;
		}
		else
		{
			cout << "\nError, Player Named " << playerName << " is Not in System. Please Try Again." << endl;
		}
}

int main()
{
	srand ( (unsigned int)time(0) ); 
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
		//if user inputs a 1 then display all the players with a for loop
		if (userInput == 1)
		{
			showPlayers(allPlayers);
		}
		//if the user inputs 2 then add a new player 
		else if (userInput== 2)
		{
			addPlayer(allPlayers);
		}
		//This will prompt the user for a name.  You must verify that this Player is pointed to in the vector that points to all players.  If so, you will add a * (pointer) to the same Player in the vector of players waiting to compete.
		else if (userInput== 3)
		{
			addPlayerToLineUp(allPlayers, playersWaiting);
		}
		//This will show all of the players waiting to compete.
		else if (userInput== 4)
		{
			showPlayers(playersWaiting);
		}
		//This will take the first two players pointed to in the vector of players waiting to compete (the two that have been waiting the longest) and will have them compete. 
		else if (userInput== 5)
		{
			if (playersWaiting.size() == 0)
			{
				cout << "\nError, No Players are Waiting to Play. A Minimum of 2 Players in the Line-up is Required to Play. Try Selecting Menu Option #3 to Add Players to the Line-up." << endl;
			}
			else if (playersWaiting.size() == 1)
			{
				cout << "\nError, Only 1 Player is Waiting to Play. A Minimum of 2 Players in the Line-up is Required to Play. Try Selecting Menu Option #3 to Add Players to the Line-up." << endl;
			}
			else
			{
				string player1 = playersWaiting[0]->getRPSThrow();
				string player2 = playersWaiting[1]->getRPSThrow();
				if ( (player1 == "Rock" && player2 == "Scissors") || (player1 == "Scissors" && player2 == "Paper") || (player1 == "Paper" && player2 == "Rock") )
				{
					playersWaiting[0]->setWins(1);
					playersWaiting[1]->setLosses(1);
				}
				else if ( (player2 == "Rock" && player1 == "Scissors") || (player2 == "Scissors" && player1 == "Paper") || (player2 == "Paper" && player1 == "Rock") )
				{
					playersWaiting[1]->setWins(1);
					playersWaiting[0]->setLosses(1);
				}
				else if (player1 == player2)
				{
					playersWaiting[0]->setDraws(1);
					playersWaiting[1]->setDraws(1);
				}
			}
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