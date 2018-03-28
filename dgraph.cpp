#include <iostream>
#include <fstream>
using namespace std;
#include "dgraph.h"

dgraph::dgraph()
{
	for(int i = 0;i <= 20; i++)
	{
		Gtable[i].name = ' ';
		Gtable[i].mark = 0;
		Gtable[i].degree = 0;
		Gtable[i].vis = 0;
	}
}

int dgraph::displaygraph()
{
	for(int i = 0; i <= 20; i++)
	{
		if(Gtable[i].name != ' ')
		{
			cout << Gtable[i].name << endl;
			cout << Gtable[i].degree << endl;
			cout << Gtable[i].mark << endl;
			cout << Gtable[i].vis << endl;
			Gtable[i].adj.displayAll();
			cout << "===================" << endl;
		}
	}
}

int dgraph::filltable()
{
	int i = 0;
	char c;
	ifstream din;
	din.open("table.txt");
	while(din >> Gtable[i].name)
	{
		din >> Gtable[i].degree;
		for(int k = 1; k <= Gtable[i].degree; k++)
		{
			din >> c;
			Gtable[i].adj.addRear(c);
		}
		i++;
	}
	din.close();
	return 0;
}

int dgraph::findoutdegree(char in)
{
	for(int i = 0; i <= 20; i++)
	{
		if(Gtable[i].name == in)
		{
			return Gtable[i].degree;
		}
	}
	return -1;
}

slist dgraph::findadjacency(char in)
{
	for(int i = 0; i <= 20; i++)
	{
		if(Gtable[i].name == in)
		{
			return Gtable[i].adj;
		}
	}
}

void dgraph::visit(int visnum,char vertex)
{
	for(int i = 0;i <= 20; i++)
	{
		if(Gtable[i].name == vertex)
		{
			Gtable[i].vis = visnum;
		}
	}
}

bool dgraph::ismarked(char vertex)
{
	for(int i = 0;i <=20; i++)
	{	
		if(Gtable[i].name == vertex)
		{
			if(Gtable[i].mark == 1)
			{
				return true;
			}
			else
			{	
				Gtable[i].mark = 1;
				return false;
			}
		}
	}
}
