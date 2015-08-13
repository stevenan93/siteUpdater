//Steven An 2015
#include <iostream>
#include "linkedList.h"
using namespace std;

int main()
{
	linkedList<int> *link = new linkedList<int>;
	link->insertIntoList(22);
	link->insertIntoList(11);
	link->insertIntoList(1);
	link->insertIntoList(2);
	for(int i = 0; i < link->getNumItems(); i++)
	{
		cout << link->getItemAtIndex(i) << endl;
	}
	return 0;
}