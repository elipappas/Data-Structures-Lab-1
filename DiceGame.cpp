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
class Dice{
	private:
		int numSides;

	public:
		// Perform a single roll of the die	
		int roll(int ns) {
			srand(time(0));
			int d1 = (rand() % ns) +1; //takes remainder of random number and amount of sides and adds 1 to that
			return d1;
		}

};

/*
	Class representing a Game Player
*/
class Player{
	private:
		string name;
		int score;
	public:
		Player(string p_name, int p_score) {
			name = p_name;
			score = p_score;
		}

		// Getter : Player Name
		string getName() {
			return name;
		}
		// Getter : Score
		int getScore() {
			return score;
		}
		// Increases the player's score by a specified value
		void addToScore(int val){	
			score = val + score; //adds specified value and the score found earlier
		}
};

/*
	Abstract class DiceGame
*/
class DiceGame{
		
	protected:
		Player *players[MAX_PLAYERS];
		Dice *dice;
		int numPlayers, numDice;
		
	public:
		//	Pure virtual function	
		virtual void play() = 0;
		void initPlayers(){
			map<string,int> player_map;
			string p_name;
			int p_score;
			for(int i = 0;i < numPlayers; i++) {
				cout << "enter the player's name: " << endl;
				cin >> p_name;
				cout << "enter the player's score: " << endl;
				cin >> p_score;
				Player p1(p_name,p_score);
				players[i] -> getName();
				players[i+1] -> getScore();
			}
			
		}
		void displayScores(){
			for(int j = 0;j < numPlayers;j++){
				cout << players[j] << ": " << players[j+1] << endl;
			}
		}
};
class knockOut: public DiceGame{
	public:
		void game(){
			int n;
			int ns;
			cout << "how many dice: " << endl;
			cin >> n;
			cout << "how many sides: " << endl;
			cin >> ns;
			Dice roll_n;
			int knockOut_num = roll_n.roll(ns);
			cout << "the knock out number is: " << knockOut_num << endl;
			int score1 = 0;
		}
		
};

int main() {
	// Base class pointer
	Dice test;
	cout << test.roll(6)<<endl;
	return 0;
}