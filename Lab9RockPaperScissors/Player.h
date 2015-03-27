//Author: Steven Dewey
//Description: Declaring the Player class and all variables and functions that make up the class.

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
		 * Returns the Randomize the selection of choosing rock, paper or scissors, and return the chosen "throw."
		 * 
		 * Return:
		 *		The name of the throw
		 */
		string getRPSThrow();
		//---------------------------------------------------------------------------------------
		/* 
		 * getName
		 * 
		 * Returns the name of the Player.
		 * 
		 * Return:
		 *		The name of the Player
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
		 *		double
		 */
		double getWinRecord();
		//---------------------------------------------------------------------------------------
		/* 
		 * toString
		 * 
		 * This function returns a string that has all of the information about the player (including his/her win record).
		 * 
		 * Return:
		 *		A data string about this player
		 */
		string toString();
		//---------------------------------------------------------------------------------------
};