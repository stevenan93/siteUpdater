//Steven An 2015
#include <iostream>
#include <fstream>
#include <string>
#include "linkedList.h"
using namespace std;

string FILE_NAME = "projects.html";

void displayItems(linkedList<string> *ptr, bool lines);

int main()
{
	string line;
	linkedList<string> *link = new linkedList<string>;
	ifstream myFile (FILE_NAME.c_str());
	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			link->insertIntoList(line);
		}
	}
	else
	{
		cout << FILE_NAME << " not found\n";
	}
	displayItems(link, true);
	delete link;
	return 0;
}


void displayItems(linkedList<string> *ptr, bool lines)
{
	cout << "Displaying file: " << FILE_NAME << '(' << ptr->getNumItems() << " lines)" << endl;
	for(int i = 0; i < 70; i++)
		cout << '-';
	cout << endl;
	
	for(int i = 0; i < ptr->getNumItems(); i++)
	{
		if(lines)
		{
			if(i < 9)
				cout << ' ';
			cout << i + 1 << " : ";
		}
		cout << ptr->getItemAtIndex(i) << endl;
	}
	
	for(int i = 0; i < 70; i++)
		cout << '-';
	cout << endl;
}

