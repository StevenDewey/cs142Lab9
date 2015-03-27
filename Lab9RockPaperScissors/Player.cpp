//WARNING: It is expressly forbidden to modify any part of this document, including its name
#include "Player.h"
using namespace std;

//---------------------------------------------------------------------------------------
Player::Player(string name_in)
{
	name = name_in;
	//color = color_in;
	//price = price_in;
}
Player::~Player(){}
//---------------------------------------------------------------------------------------
string Player::getRPSThrow()
{
	string theThrow;
	return theThrow;
}
double Player::getWinRecord()
{
	double record;
	return record;
}
//---------------------------------------------------------------------------------------
string Player::toString()
{
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Number of Wins: " << numberOfWins << endl;
	ss << "Number of Losses: " << numberOfLosses << endl;
	ss << "Number of Draws: " << numberOfDraws << endl;
	return ss.str();
}
//---------------------------------------------------------------------------------------
