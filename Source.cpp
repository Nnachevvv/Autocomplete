#include "Autocomplete.h"
#include <iostream>
#include <fstream>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
using namespace std;


int main()
{
	Autocomplete * autocomp = new Autocomplete();

	std::cout << "Enter file name"<<std::endl;
	string line;
	std::cin >> line;
	ifstream myfile(line);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//std::cout << line<<std::endl;
			autocomp->instert(line);
		}
		myfile.close();
	}

	
		do{
		std::cout << " Enter | quit | suggest | insert | change " << std::endl;
		std::cin >> line;
		if (line=="suggest")
		{
			std::cout << "Enter prefix to suggest a word" << std::endl;
			std::cin >> line;
			autocomp->suggest(line);
			std::cout << "---------------------------------------------------"<<std::endl;
		}
		else if (line == "insert")
		{
			std::cout << "Enter word to insert in dictonary" << std::endl;
			std::cin >> line;
			autocomp->instert(line);
		}
		else if(line=="change")
		{
			std::cout << "Enter number to change k." << std::endl;
			int k;
			std::cin >> k;
			autocomp->change(k);
		}
		} while (line != "quit");

	delete autocomp;
	myfile.clear();
	myfile.close();
	return 0;
}
