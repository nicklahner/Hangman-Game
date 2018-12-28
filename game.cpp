#include<stdio.h>
#include<string>
#include"game.h"
#include<cctype>


int Game_t::toString()
{
	int spaces = 0;	
	for(int i = 0; i < 40; i++)
	{
		cout << endl;
	}
	cout << "    ------------" << endl;
	cout << "    |";
	if(this->head)
	{
		cout << "       |" << endl;
	}
	else
	{
		cout << endl;
	}
	cout << "    | ";
	if(this -> head)
	{
		cout <<"      O";
	}
	cout << endl;
	cout << "    | ";
	if(this -> body)
	{
		if(this ->leftArm)
		{	
			if(this->rightArm)
			{
				cout << "     /|\\";
			}
			else
			{
				cout << "     /|";
			}
		}
		else
		{
			cout << "      |";
		}
	}
	cout << endl;
	cout << "    | " ;
	if(this->leftLeg)
	{
		if(this -> rightLeg)
		{
			cout << "     / \\";				
		}
		else
		{
			cout << "     /";
		}
	}
	cout << endl;
	cout << "    | " << endl;	
	cout << "    | " << endl;
	cout << "----------------" << endl;

	cout << endl << endl ;
	cout << "    Word Size is: " << this->word.size() << endl;
	cout  << endl;
	cout << "  ";

	bool space = true;	
	for(size_t i = 0; i < this->word.size(); i++)
	{
		space = true;
		for(size_t j = 0; j < this->letters.size(); j++)
		{
			if(word[i] == letters[j])
			{
				char letter = word[i];
				letter = toupper(letter);
				cout << " " <<  letter;
				space = false;
			}	
		}
		if(space)
		{
			cout << " _";
			spaces++;
		}
	}
	cout << endl;
	cout << " Letters entered: ";

	for(size_t i = 0; i < letters.size(); i++)
	{
		cout << letters[i] << ", ";		
	}
	cout << endl;	
	//output correctly entered letters here
	//output incorrecly entered letters here

	return spaces;
}

string getWord()
{
	
	cout << "Please enter a word: " << endl;
	string retval;
	cin >> retval;
	return retval;
	
}

bool Game_t::promptUser()
{
	cout << endl;
	cout << "Please enter a letter: " << endl;
	string userGuess; 
	char guess;	
	cin >> userGuess; 
	if(userGuess.size() > 1)
	{
		cout << "You have entered more than one letter." << endl;
		this->promptUser();		
	}	
	else
	{
		guess = userGuess[0];
	}


	//char guess;
	//cin >> guess;
	

	cout << "You have entered a letter, which is: " << guess << endl;
	if(letters.size() == 0)
	{
		this -> letters.push_back(guess);
	}
	else{	
		for(size_t i = 0; i < letters.size(); i++)
		{
			if(guess == letters[i])
			{
				cout << "You have already entered that letter" << endl; 
				return false;
			}
		}
		this -> letters.push_back(guess);	
	}
	for(size_t i = 0; i < word.size(); i++)
	{
		if(guess == word[i])
		{
			return true;	
		}	
	}	
	if(this->head == false)
	{
		this -> head = true;
		return false;	
	}
	if(this->body == false)
	{
		this->body = true;
		return false;
	}
	if(this->leftArm == false)
	{
		leftArm = true;
		return false;
	}
	if(this->rightArm == false)
	{
		rightArm = true;
		return false;
	}		
	if(this->leftLeg == false)
	{
		this->leftLeg = true;
		return false;
	}
	
	if(this->rightLeg == false)
	{
		rightLeg = true;
		return false;
	}
	return false;
}


Game_t::Game_t() : letters(0)
{
	this -> head = false;
	this -> leftArm = false;
	this -> rightArm = false;
	this -> body = false;
	this -> rightLeg = false;
	this -> leftLeg = false;
	this -> word = getWord();
}

bool Game_t::getRightLeg()
{
	return this ->rightLeg;
}

int main(int argc, char** argv)
{
	Game_t game = Game_t();
	game.toString();	

	int res = 0;
	while(!game.getRightLeg() )
	{
  		game.promptUser();
	    res = game.toString();
		if(res == 0) break;
	}
	if(res > 0)	
	{
		cout << endl << endl << endl << endl;
		cout << "        GAME OVER" << endl;
		cout << endl << endl << endl << endl;
	}
	else
	{	
		cout << endl << endl << endl << endl;
		cout << "        YOU HAVE WON" << endl;	
		cout << endl << endl << endl << endl;
	}
	
	return 0;
}
