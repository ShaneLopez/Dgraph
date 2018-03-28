/*INSTRUCTION
Look for **.
Update comments, complete exception handling and finish ClearIt to make this complete - Yoshii (CS311)*/

// =========================================================

//HW1P1 stack
//Your name: Shane Lopez
//Complier:  gcc
//File type: .cpp

//================================================================

#include <iostream>
#include <vector>
using namespace std;
#include "stack.h"

//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
	//top = -1; // indicate an empty stack 
}
  
// the stack is empty when top is equal to -1.isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ 
	if (el.size() == 0)
	{ 
		return true;
	} 
	else return false; 
}
    
//the stack is full when top is equal to MAX-1. isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
{ 
	/*if (top == MAX-1 )
	{ 
		return true; 
	}*/
	return false; 
}
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{ 
	if (isFull())
	{ 
		throw Overflow();
	}
    	else 
	{ 
		el.push_back(elem); 
	}
}
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{ 
	if (isEmpty())
	{	
		throw Underflow();
	}
    	else 
	{ 
		elem = el.back();
		el.pop_back();
	}
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{ 
	if (isEmpty())
	{
		throw Underflow();
	}
    	else 
	{ 
		elem = el.back(); 
	} 
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
	if (isEmpty())
	{ 
		cout << "no items currentlly on the stack" << endl;
	}
    	else for (int i=el.size() - 1; i>=0; i--)
      	{ 
		cout << el[i] << endl; 
	}
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
	el_t elem;
	if (!isEmpty())
        {
		while(el.size() > 0)
		{	
			el.pop_back();
		}
	}
}

stack::~stack()
{
	clearIt();
}
