#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main()
{
    hashClass HashT;
	string name = "";
    

	HashT.AddItem("Paul", "12B Str");
	HashT.AddItem("Kim", "224A Crossroads");
	HashT.AddItem("Emma", "45D Strawberry Bazaar");
	HashT.AddItem("Annie", "3A Lexington alley");
	HashT.AddItem("Sarah", "14A Castle str");
	HashT.AddItem("Pepper", "4C Dickens alley");
	HashT.AddItem("Mike", "6D China Town str");
	HashT.AddItem("Steve", "9D Church Lane");
	HashT.AddItem("Bill", "55C North str");
	HashT.AddItem("Marie", "5 Park Avenue");
	HashT.AddItem("Susan", "9 Mill Lane");
	HashT.AddItem("Joe", "17A Green str");

	//while (name != "quit")
	//{
		//cout << "Enter name for search ";
		//cin >> name;
		//if (name != "quit")
		//{
			//HashT.FindAddress(name);
		//}
	//}
	HashT.PrintItemsInIndex(2);

	while (name != "quit")
	{
		cout << "Enter name for remove ";
		cin >> name;
		if (name != "quit")
		{
			HashT.RemoveItem(name);
		}
	}
	HashT.PrintItemsInIndex(2);

	//HashT.PrintTable();

	//HashT.PrintItemsInIndex(9);
	//HashT.PrintItemsInIndex(8);
}