#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>

using namespace std;

class Game_t
{
	public:
		Game_t();
		int toString();
		bool promptUser();	
		
		bool getRightLeg();
		string word;


	private:
		bool head;
		bool body;
		bool rightArm;
		bool leftArm;
		bool leftLeg;
		bool rightLeg;
		vector<char> letters;
		

};

#endif



