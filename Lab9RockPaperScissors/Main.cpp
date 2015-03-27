//Author: Steven Dewey 
//Description: This application simulates playing rock, paper, scissors in a really fun way. 
//test case #1: I enter 2 and enter in a new player, I enter 2 again and enter the same name and am told the player already exists. 
//test case #2: I enter 2 and enter in a new player, I enter 1 and the name of that person is displayed along with all zero's because the player has not played in any games yet. 
//test case #3: I enter 2 and enter a new player, I do it again so I now have 2 players, I enter both players into the line up by pressing 3 and entering the players names, I then enter 5 and the players battle, each player is randomely assigned either rock paper or scissors and a winner is determined or a draw is declared. 

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
//fuction to find a player. 
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
//function to show players, with a bool to check on if the function is called as part of case 1 or 4. 
void showPlayers(vector<Player*> players, bool lineUp){
	for (int i = 0; i < players.size(); i++)
		{
			cout << players[i]->toString() << endl;
		}
		if (players.size() == 0)
		{
			if (lineUp)
			{
				cout << "\nNo Players Are Currently in the Line-up. Try Selecting Option 3 From the Menu to Add More Players to the Line-up" << endl;
			}
			else
			{
				cout << "\nNo Players Are Currently in the System. Try Selecting Option 2 From the Menu to Add More Players." << endl;
			}
			
		}
}
//function to add a new player. 
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
//function to add a player from the all player vector to the line-up vector.
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
//function to fight with the two players in the front of the line-up vector, removing the two players at the front each time. 
void fight(vector<Player*>& playersWaiting) {
	if (playersWaiting.size() == 0)
	{
		cout << "\nError, No Players are Waiting to Play. A Minimum of 2 Players in the Line-up is Required to Play. Try Selecting Menu Option #3 to Add Players to the Line-up." << endl;
	}
	else if (playersWaiting.size() == 1)
	{
		cout << "\nError, Only 1 Player is Waiting to Play. A Minimum of 2 Players in the Line-up is Required to Play. Try Selecting Menu Option #3 to Add Players to the Line-up." << endl;
	}
	else if (playersWaiting[0] == playersWaiting[1])
	{
		cout << "\nThe Player Named " << playersWaiting[0]->getName() << " Was Lined-up to Play Themself, The Result was a Draw." << endl;
		playersWaiting[0]->setDraws(1);
		playersWaiting.erase.begin();
		playersWaiting.erase.begin();
	}
	else
	{
		//play rock paper scissors!!
		cout << "\n" << "Fight Initiated Between " << playersWaiting[0]->getName() << " and " << playersWaiting[1]->getName() << "!" << endl;
		string player1 = playersWaiting[0]->getRPSThrow();
		cout << "\n" << playersWaiting[0]->getName() << " Throws " << player1 << "!" << endl;
		string player2 = playersWaiting[1]->getRPSThrow();
		cout << playersWaiting[1]->getName() << " Throws " << player2 << "!" << endl;
		if ( (player1 == "Rock" && player2 == "Scissors") || (player1 == "Scissors" && player2 == "Paper") || (player1 == "Paper" && player2 == "Rock") )
		{
			playersWaiting[0]->setWins(1);
			playersWaiting[1]->setLosses(1);
			cout << "\n" << playersWaiting[0]->getName() << " is the Winner!" << endl;
		}
		else if ( (player2 == "Rock" && player1 == "Scissors") || (player2 == "Scissors" && player1 == "Paper") || (player2 == "Paper" && player1 == "Rock") )
		{
			playersWaiting[1]->setWins(1);
			playersWaiting[0]->setLosses(1);
			cout << "\n" << playersWaiting[1]->getName() << " is the Winner!" << endl;
		}
		else if (player1 == player2)
		{
			playersWaiting[0]->setDraws(1);
			playersWaiting[1]->setDraws(1);
			cout << "\nIt was a Draw!" << endl;
		}
		//remove the players that just played. 
		playersWaiting.erase.begin();
		playersWaiting.erase.begin();
	}
}
//start main function
int main()
{
	//declare variables necessary for this scope.
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
			showPlayers(allPlayers, false);
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
			showPlayers(playersWaiting, true);
		}
		//This will take the first two players pointed to in the vector of players waiting to compete (the two that have been waiting the longest) and will have them compete. 
		else if (userInput== 5)
		{
			fight(playersWaiting);
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