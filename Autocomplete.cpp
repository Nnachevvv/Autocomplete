#include "Autocomplete.h"

#include <iostream>

Autocomplete::Autocomplete()
{
		root = new PrefixNode();
		k = 10;
}


Autocomplete::~Autocomplete()
{
	delete root;
}


void Autocomplete::instert(const std::string & word)
{
	PrefixNode * pNext = root;
	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i];
		if (pNext->childrens.find(word[i]) == pNext->childrens.end())
		{
			pNext->childrens[index] = new PrefixNode();
		}
		pNext = pNext->childrens[index];
	}
	pNext->endOfWord = true;
	//delete pNext;
}

void Autocomplete::suggest(const std::string & word)
{
	SuggestVec vec;
	int count = 0;
	PrefixNode * pNext = root;
	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i];
		if (pNext->childrens.find(word[i]) == pNext->childrens.end())
		{
			throw std::logic_error("No type of word in dictionary.");
		}
		pNext = pNext->childrens[index];
	}
	std::string other_words = word;
	vecAdd(other_words, pNext, vec,count);
	for (auto i = vec.begin(); i != vec.end(); i++)
	{
		std::cout << *i<<std::endl;
	}
	
	
}

void Autocomplete::change(const int size)
{
	this->k = size;
}

void Autocomplete::vecAdd(std::string & word, PrefixNode * pNext, SuggestVec & vec,int &count)
{
	if (pNext->endOfWord)
	{
		vec.push_back(word);
		count++;
	}
	
	for (auto i = pNext->childrens.begin(); i != pNext->childrens.end(); i++)
	{
		if (i->second)
		{
			if (count >= k)
			{
				return;
			}
			word.push_back(i->first);
			vecAdd(word, i->second, vec,count);
			word.pop_back();
		}
	}
}
