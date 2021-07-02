// Hang Man Decoder
#include <iostream>
#include <fstream>
#include <cassert>

#define POSSIBLE_WORD_COUNT 58110

int main()
{
	std::string word, answer, IGL, CGL;
	uint32_t count;
	while (true)
	{
		std::cout<<"What letters are in the word so far?: ";
		std::cin>>word;
		std::cout<<"What letters have you guessed?: ";
		std::cin>>IGL;
		for (int i = 0; i < word.length(); i++)
		{
			if (word.at(i) != '_')
			{
				CGL += word.at(i);
			}
		}
		std::ifstream read("words.txt"); // Constructor opens and closes file automatically
		assert(read.is_open());

		for(uint32_t i = 0; i < POSSIBLE_WORD_COUNT; i++)
//		for(float i = 0; i < POSSIBLE_WORD_COUNT; i++)
		{
			count = 0;
			std::getline(read, answer);
//			for(float j = 0; j < answer.length(); j++)
			for(uint32_t j = 0; j < answer.length(); j++)
			{
				if (answer.length() != word.length() || IGL.find(answer.at(j)) != std::string::npos || CGL.find(answer.at(j)) != std::string::npos && word.at(j) == '_')
				{
					break;
				}
				else if (word.at(j) == answer.at(j) || word.at(j) == '_')
				{
					count++;
				}
			}
			if (count == word.length())
			{
				std::cout<<answer<<std::endl;
			}
		}
		std::cout<<"Done!!";
		std::cin.ignore();
		std::cin.get();
		system("cls");
	}
}
