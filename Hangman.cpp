// Hangman
// IGL Incorrect Guess List
// CGL Correct Guess List

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

NumberOfGuesses(std::string tence, int i)
{
	if (i > 1)
	{
		std::cout<<"You ";
		std::cout<<tence;
		std::cout<<i;
		std::cout<<" Guesses left"<<std::endl;
	}
	else
	{
		std::cout<<"You "; 
		std::cout<<tence;
		std::cout<<"1 Guess left"<<std::endl;
	}
}

game(std::string word)
{
	std::string IGL, CGL;
	char guess;
	bool GuessedLetter;
	int LettersGuessed = 0;
	int Guesses = 10;
	int letters;
	while (true)
	{
		GuessedLetter = false;
		do
			{
			std::cout<<"Hangman!"<<std::endl;
			for(int i = 0; i < word.length(); i++)
			{
				if (CGL.find(word.at(i)) != std::string::npos)
				{
					std::cout<<word.at(i);
					std::cout<<" ";
				}
				else
					std::cout<<"_ ";
			}
			std::cout<<std::endl;
			std::cout<<"Incorrect Letters you have guessed: ";
			std::cout<<IGL;
			std::cout<<std::endl;
			NumberOfGuesses("have ", Guesses);
			std::cout<<"What letter do you guess?: ";
			std::cin>>guess;
			if (IGL.find(guess) != std::string::npos || CGL.find(guess) != std::string::npos) // if the guessed letter is in the CGL or the IGL 
			{
				std::cout<<"You've already guessed this letter. ";
				std::cin.ignore();
				std::cin.get();
				system("cls");
			}
		}while(IGL.find(guess) != std::string::npos || CGL.find(guess) != std::string::npos);
		for(int i = 0; i < word.length(); i++)
		{
			if (guess == word.at(i))
			{
				GuessedLetter = true;
				CGL += guess;
				LettersGuessed += 1;
			}
		}
		if (GuessedLetter == false)
		{
			Guesses -= 1;
			if (!(IGL == ""))
				IGL += ", ";
			IGL += guess;
		}
		if (word.length() == LettersGuessed)
		{
			system("cls");
			std::cout<<"You won"<<std::endl;
			std::cout<<"The word was ";
			std::cout<<word<<std::endl;
			NumberOfGuesses("had ", Guesses);
			std::cin.ignore();
			std::cin.get();
			return 0;
		}
		if (Guesses == 0)
		{
			system("cls");
			std::cout<<"You loss"<<std::endl;
			std::cout<<"The word was ";
			std::cout<<word<<std::endl;
			std::cin.ignore();
			std::cin.get();
			return 0;
		}
		system("cls");
	}
}

unsigned long long rand64(int seed)
{
	seed = seed * 6364136223846793005 + 1442695040888963407;
	return seed;
}

int main()
{
	srand(time(0));
	int players;
	std::string rword;
	while(true)
	{
		system("cls");
		do
		{
			std::cout<<"Would you like to play one player or two player? (1, 2): ";
			std::cin>>players;
			if (players < 0 || players > 3)
			{
				system("cls");
			}
		}while(!(players > 0 && players < 3));
		if (players == 1)
		{
			std::ifstream read;
			read.open("words.txt");
		
			for(int i = 0; i < rand64(time(0)) % 58110; i++)
			{
				getline(read, rword);
			}	
		    read.close();
		}
		else
		{
			std::cout<<"What will the word for the other player be?: "; 
			std::cin>>rword;
		}
		system("cls");
		game(rword);
	}
}

