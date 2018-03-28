using namespace std;
#include "hw3p3.h"

struct Gvertex
{
	char name;
	int mark;
	int vis;
	int degree;
	slist adj;
};

class dgraph : slist
{
protected:
	Gvertex Gtable[20];
public:
	dgraph();
	int displaygraph();
	int filltable();
	int findoutdegree(char index);
	slist findadjacency(char index);
	void visit(int visnum,char vertex);
	bool ismarked(char vertex);	
};
