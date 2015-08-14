//Steven An 2015
#include <iostream>
#include <fstream>
#include <string>
#include "linkedList.h"
using namespace std;

void displayItems(linkedList<string> *ptr);

int main()
{
	string fileName = "projects.html"; 
	string line;
	linkedList<string> *link = new linkedList<string>;
	ifstream myFile (fileName.c_str());
	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			link->insertIntoList(line);
		}
	}
	else
	{
		cout << fileName << " not found\n";
	}
	displayItems(link);
	return 0;
}


void displayItems(linkedList<string> *ptr)
{
	for(int i = 0; i < ptr->getNumItems(); i++)
	{
		cout << ptr->getItemAtIndex(i) << endl;
	}
}
