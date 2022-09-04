#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>

#define MAX_PLAYERS 10

using namespace std;

/*
	Class representing an N-sided die
*/
class Dice
{
private:
	int numSides;

public:
	// Perform a single roll of the die
	int roll(int ns)
	{
		srand(time(0));
		int d1 = (rand() % ns) + 1; // takes remainder of random number and amount of sides and adds 1 to that
		return d1;
	}
};

/*
	Class representing a Game Player
*/
class Player
{
private:
	string name;
	int score;
	bool out;

public:
	Player(string p_name, int p_score)
	{
		name = p_name;
		score = p_score;
	}

	// Getter : Player Name
	string getName()
	{
		return name;
	}

	// Getter : Score
	int getScore()
	{
		return score;
	}

	// Increases the player's score by a specified value
	void addToScore(int val)
	{
		score = val + score; // adds specified value and the score found earlier
	}
};

/*
	Abstract class DiceGame
*/
class DiceGame
{

protected:
	// std::vector<Player *> players;
	Player *players[MAX_PLAYERS];
	Dice *dice;
	int playerCount, numDice;
	// Player p[MAX_PLAYERS];

public:
	//	Pure virtual function
	virtual void play() = 0;

	void initPlayers()
	{
		string p_name;
		int p_score;

		// cout << "Number of players: ";
		// cin >> playerCount;

		for (int i = 0; i < playerCount; i++)
		{
			cout << "Enter player " << i + 1 << "'s name: ";
			cin >> p_name;

			cout << "Enter player " << i + 1 << "'s score: ";
			cin >> p_score;

			//Player player(p_name, p_score);

			// cout << player.getName() << endl;
			players[i] = new Player(p_name,p_score);
		}

		// cout << "Player 1 - " << players[1]->getName() << endl;
		// cout << players[1]->getName() << endl;
	}

	void displayScores()
	{
		for (int j = 0; j < playerCount; j++)
		{
			cout << players[j]->getName() << ": " << players[j]->getScore() << endl;
		}
	}
};

class KnockOut : public DiceGame
{
public:
	void play()
	{
		int n;
		int ns;
		
		cout << "Number of players: ";
		cin >> playerCount;

		this->initPlayers();

		cout << "how many dice: ";
		cin >> n;

		cout << "how many sides: ";
		cin >> ns;

		Dice roll_n;
		int knockOut_num = 0;
		for(int i=0;i < n;i++){
			knockOut_num = roll_n.roll(ns)+knockOut_num;
		}
		cout << "the knock out number is: " << knockOut_num << endl;
		int score1 = 0;

	}
};

int main(void)
{
	KnockOut Knock;
	Knock.play();
	
	// Dice test;
	// cout << test.roll(6) << endl;

	return 0;
}