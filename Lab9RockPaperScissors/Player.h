//Author: Steven Dewey
#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Player
{
	private:
		string name;
		double numberOfWins;
		double numberOfLosses;
		double numberOfDraws;

	public:
		//---------------------------------------------------------------------------------------
		/* 
		 * Constructor/Destructor
		 * 
		 * Handles creation and deletion of Player objects.
		 * 
		 * Parameter: name_in
		 *		The name of a new player
		 */
		Player(string name_in);
		virtual ~Player();
		//---------------------------------------------------------------------------------------
		/* 
		 * getName
		 * 
		 * Returns the Randomize the selection of choosing rock, paper or scissors, and return the chosen "throw.".
		 * 
		 * Return:
		 *		The name of the car
		 */
		string getRPSThrow();
		//---------------------------------------------------------------------------------------
		/* 
		 * getName
		 * 
		 * Returns the Randomize the selection of choosing rock, paper or scissors, and return the chosen "throw.".
		 * 
		 * Return:
		 *		The name of the car
		 */
		string getName();
		/* 
		 * setWins
		 * 
		 * Sets the number of wins after a battle has taken place.
		 * 
		 * Return:
		 *		nothing, its void.
		 */
		void Player::setWins(double win);
		/* 
		 * setLosses
		 * 
		 * Sets the number of losses after a battle has taken place.
		 * 
		 * Return:
		 *		nothing, its void.
		 */
		void Player::setLosses(double loss);
		/* 
		 * setDraws
		 * 
		 * Sets the number of draws after a battle has taken place.
		 * 
		 * Return:
		 *		nothing, its void.
		 */
		void Player::setDraws(double draw);
		/* 
		 * getWinRecord
		 * 
		 * Returns the number of wins divided by all matches in which the player has participated.
		 * 
		 * Return:
		 *		string
		 */
		double getWinRecord();
		//---------------------------------------------------------------------------------------
		/* 
		 * toString
		 * 
		 * This function returns a string that has all of the information about the player (including his/her win record).
		 * 
		 * Return:
		 *		A data string about this car
		 */
		string toString();
		//---------------------------------------------------------------------------------------
};