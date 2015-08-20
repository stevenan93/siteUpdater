//Steven An 2015
#include <iostream>
#include <fstream>
#include <string>
#include <cstring> //for strcmp, strcat
#include <cstdlib> //for atoi
#include "linkedList.h"
#include "node.h"
#include <stdio.h>
#include <time.h>
using namespace std;

string FILE_NAME = "music.html";

struct video
{
	string url, title, caption; 
};

void displayItems(linkedList<string> *ptr, bool lines);
void erase(linkedList<string> *ptr, int begin, int end);
void siteUpdater(linkedList<string> *ptr);
linkedList<string>* loadFileIntoList();
void displayCommands();
void outputToFile(linkedList<string> *ptr);
void outputToFile(linkedList<string> *ptr, string customFileName);
void backUpFile(linkedList<string> *ptr);
void addSong(linkedList<string> *ptr, video vid);

int main()
{
	linkedList<string> *list = loadFileIntoList();
	if(list)
	{
		backUpFile(list);
		siteUpdater(list);
	}
	delete list;
	return 0;
}

void addSong(linkedList<string> *list, video vid)
{
	int songSection = 41;
	time_t curTime;
	struct tm *timeInfo;
	time( &curTime );
	
	list->insertAtIndex("<br><br><br>", songSection);
	list->insertAtIndex(" ", songSection);
	list->insertAtIndex("</li>", songSection);
	list->insertAtIndex(vid.caption, songSection);
	list->insertAtIndex("</strong><br>", songSection);
	list->insertAtIndex(" : " + vid.title, songSection);
	list->insertAtIndex(ctime( &curTime), songSection);
	list->insertAtIndex("<br><strong>", songSection);
	list->insertAtIndex("\" frameborder=\"0\" allowfullscreen></iframe>", songSection);
	list->insertAtIndex(vid.url, songSection);
	list->insertAtIndex("<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/", songSection);
	list->insertAtIndex("<li>", songSection);
	list->insertAtIndex(" ", songSection);
	list->insertAtIndex(" ", songSection);

}

void outputToFile(linkedList<string> *ptr, string str)
{
	ofstream output(str.c_str());
	for(int i = 1; i <= ptr->getNumItems(); i++)
	{
		output << ptr->getItemAtIndex(i) << endl;
	}
	cout << "written to " << str;
	cout << " (" << ptr->getNumItems() << " lines)\n";
}


void outputToFile(linkedList<string> *ptr)
{
	ofstream output(FILE_NAME.c_str());
	for(int i = 1; i <= ptr->getNumItems(); i++)
	{
		output << ptr->getItemAtIndex(i) << endl;
	}
	cout << "written to " << FILE_NAME;
	cout << " (" << ptr->getNumItems() << " lines)\n";
}


void backUpFile(linkedList<string> *ptr)
{
	 string backupName = FILE_NAME;
	 backupName.append(".backup");
	 ifstream  src(FILE_NAME.c_str(), ios::binary);
     ofstream  dst(backupName.c_str(), ios::binary);
     dst << src.rdbuf();
     cout << FILE_NAME << " backed up to: " << backupName << endl;
}

linkedList<string>* loadFileIntoList()
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
		cout << FILE_NAME << " loaded (" << link->getNumItems();
		cout << " items)\n";
		return link;
	}
	else
	{
		cout << FILE_NAME << " not found\n";
		return NULL;
	}
}

void displayCommands()
{
	cout << "----Site Updater by Steven An----\n" << 
		"(D)isplay loaded file\n" << 
		"(T)oggle line numbers\n" <<
		"(A)dd song to song page\n" << 
		"(R)emove lines in range\n" <<
		"(W)rite to file\n" <<
	    "(Q)uit site updater\n";
}

void siteUpdater(linkedList<string> *ptr)
{
	string input = " ";
	bool lines = true;
	displayCommands();
	while(strcmp(input.c_str(), "Q"))
	{
		cout << "Enter in a command: ";
		getline(cin, input);
		if(!strcmp(input.c_str(), "M"))
		{
			displayCommands();
		}
		if(!strcmp(input.c_str(), "D"))
		{
			displayItems(ptr, lines);
		}
		if(!strcmp(input.c_str(), "T"))
		{
			if(lines)
			{
				lines = false;
				cout << "Line numbers: OFF\n";
			}
			else
			{
				lines = true;
				cout << "Line numbers: ON\n";
			}
		}
		if(!strcmp(input.c_str(), "A"))
		{
			video newVideo;
			cout << "please enter the title: ";
			getline(cin, newVideo.title);
			cout << "please enter a caption: ";
			getline(cin, newVideo.caption);
			cout << "please enter the youtube code: ";
			getline(cin, newVideo.url);
			addSong(ptr, newVideo);
		}
		if(!strcmp(input.c_str(), "W"))
		{
			outputToFile(ptr);
		}
		if(!strcmp(input.c_str(), "R"))
		{
			string begin, end;
			cout << "starting line: ";
			getline(cin, begin);
			int b = atoi(begin.c_str());
			cout << "ending line: ";
			getline(cin, end);
			int e = atoi(end.c_str());
			ptr->removeFromList(b, e);
			cout << "deleted " << e - b + 1 << " lines\n";
		}

	}
}

void displayItems(linkedList<string> *ptr, bool lines)
{
	cout << "Displaying file: " << FILE_NAME << '(' << ptr->getNumItems() << " lines)" << endl;
	for(int i = 0; i < 70; i++)
		cout << '-';
	cout << endl;
	
	for(int i = 1; i <= ptr->getNumItems(); i++)
	{
		if(lines)
		{
			if(i < 10)
				cout << ' ';
			cout << i << " : ";
		}
		cout << ptr->getItemAtIndex(i) << endl;
	}
	
	for(int i = 0; i < 70; i++)
		cout << '-';
	cout << endl;
}

void erase(linkedList<string> *ptr, int begin, int end)
{
	if(end < begin || begin <= 0 || end > ptr->getNumItems())
	{
		cout << "Out of range\n";
	}
	else
	{
		for(int i = begin; i <= end; i++)
		{
			ptr->removeFromList(i);
			ptr->insertAtIndex(" ", i);
		}
	}
}
