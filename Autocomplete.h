#pragma once
#include <string>
#include <vector>
#include <unordered_map>
typedef std::vector<std::string> SuggestVec;
class Autocomplete
{
public:

	struct PrefixNode {
		std::unordered_map<wchar_t, PrefixNode*> childrens;
		bool endOfWord;

		PrefixNode()
		{
			endOfWord = false;
		}
		~PrefixNode() {
			for (auto iter = childrens.begin(); iter != childrens.end(); iter++)
			{
				delete iter->second;
			}
		};
	};
	Autocomplete();
	~Autocomplete();
private:
	PrefixNode * root;
	int k;
	//bool is_last_node(PrefixNode * pter);

public:
	void instert(const std::string & word);
	///? Vector>TO DO ::rETURN
	void suggest(const std::string  & word);
	void change(const int size);
	int get_k()const { return k; };
	//Change name
	void vecAdd( std::string & word, PrefixNode * pNext, SuggestVec &  vec,int &count);

};

