//WARNING: It is expressly forbidden to modify any part of this document, including its name
#include "Player.h"
using namespace std;

//---------------------------------------------------------------------------------------
Player::Player(string name_in)
{
	name = name_in;
	numberOfWins = 0;
	numberOfLosses = 0;
	numberOfDraws = 0;
}
Player::~Player(){}
//---------------------------------------------------------------------------------------
string Player::getRPSThrow()
{
	string theThrow;
	int randomnum = rand() %3 +1;
	if (randomnum == 1)
	{
		theThrow = "Rock";
	}
	else if (randomnum == 2)
	{
		theThrow = "Paper";
	}
	else if (randomnum == 3)
	{
		theThrow = "Scissors";
	}
	
	return theThrow;
}
string Player::getName()
{	
	return name;
}
void Player::setWins(double win)
{	
	numberOfWins += win;
}
void Player::setLosses(double loss)
{	
	numberOfLosses += loss;
}
void Player::setDraws(double draw)
{	
	numberOfDraws += draw;
}
double Player::getWinRecord()
{
	double record;
	double totalGames = (numberOfWins + numberOfLosses + numberOfDraws);
	if (totalGames == 0)
	{
		return 0;
	}
	record = numberOfWins / totalGames;
	return record;
}
//---------------------------------------------------------------------------------------
string Player::toString()
{
	stringstream ss;
	ss << "\nName: " << name << endl;
	ss << "Number of Wins: " << numberOfWins << endl;
	ss << "Number of Losses: " << numberOfLosses << endl;
	ss << "Number of Draws: " << numberOfDraws << endl;
	ss << "Winning Record: " << getWinRecord() << "%" << endl;
	return ss.str();
}
//---------------------------------------------------------------------------------------
