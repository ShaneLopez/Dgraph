#include <iHstream>
using namespace std;
#include "stack.h"
#include "dgraph.h"

int main(int argc,char ** argv)
{
	dgraph graph;
	slist adj;
	stack list;
	char vertex;
	char cur;
	int visnum = 1;

	graph.filltable();
	graph.displaygraph();
	cout << "A" << endl;
	graph.visit(visnum,'A');
	visnum++;
	adj = graph.findadjacency('A');
	if(!graph.ismarked('A'))
	{
		while(!adj.isEmpty())
		{
			adj.deleteRear(vertex);
			list.push(vertex);
		}
	}
	cout << "===Stack===" << endl;
	list.displayAll();
	while(!list.isEmpty())
	{
		list.pop(cur);
		if(!graph.ismarked(cur))
		{
			cout << cur << endl;
			graph.visit(visnum,cur);
			visnum++;
			cout << "visited " << cur << endl;
			adj = graph.findadjacency(cur);
			while(!adj.isEmpty())
        		{	
                		adj.deleteRear(vertex);
                		list.push(vertex);
        		}
			cout << "===Stack===" << endl;
        		list.displayAll();
		}
		else
		{
			cout << "Skipping " << cur << endl;
		}
	}
	graph.displaygraph();
	return 0;
}
