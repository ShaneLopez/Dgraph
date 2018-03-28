
//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A
//Make sure all if-then-else are commented describing which case it is
//Make sure all local variables are described fully

// ====================================================

//HW3P1 llist
//Your name: Shane Lopez
//Complier:  gcc
//File type: .cpp

//=====================================================
#include <iostream>
using namespace std;
#include"llist.h" 

llist::llist()
{
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

//Purpose:clear the linked list(called automatically 
llist::~llist()
{  
	cout << "Calling the llist destructor" << endl;
	el_t old;
	while(!isEmpty())
	{
		deleteFront(old);
	}
}

//Purpose:returns true or false depending on if the list is empty or not
bool llist::isEmpty()
{
	if(Front == NULL && Rear == NULL)
	{
		return true;
	}
	return false;
}

//Purpose:Display the entire list if list is empty prints "[empty]"
void llist::displayAll()
{
	Node* p;//the current node being printed
	p = Front;
	// list not empty
	if(!isEmpty())
	{
		while(p != NULL)
		{
			cout << '[' << p->Elem << ']' << endl;
			p = p->Next;
		}
	}
	//list is empty
	else
	{
		cout << "[ empty ]" << endl;
	}
}
//Purpose:Add an element to the rear of the list
void llist::addRear(el_t NewNum)
{
	//The list is not empty
	//will create a node after rear and turn that node into rear
	if(!isEmpty())
	{
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = NewNum;
		Rear->Next = NULL;
		Count++;
	}
	//This is the first node being added to the list
	//Set front and rear to the new node and assign NewNum to the node
	else
	{	
		Front = new Node;
		Rear = Front;
		Front->Next = Rear;
		Rear->Next = NULL;
		Rear->Elem = NewNum;
		Count++;	
	}
}

//Purpose:delete the front node in the list
void llist::deleteFront(el_t& OldNum)
{
	//case if the list is not empty and this is not the first node in the list
	if(!isEmpty() && Front != Rear)
	{
		OldNum = Front->Elem;
		Node *Second; //node right after first for front to reassign to
		Second = Front->Next;
		delete Front;
		Front = Second;
		Count--;
	}
	//case if the list is empty throw an underflow exception
	else if(isEmpty())
	{
		throw Underflow();
	}
	//case if this is the first node in the list
	else if(Front == Rear)
	{
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}
}

//Purpose:Add a node in front of the front node
void llist::addFront(el_t NewNum)
{
	//case the list is not empty
	if(!isEmpty())
	{
		Node *x;
		x = new Node;
		x->Next = Front;
		Front = x;
		Front->Elem = NewNum;
		Count++;
	}
	//case the list is empty
	else
	{
		Front = new Node;
		Rear = Front;
		Front->Next = Rear;
		Front->Elem = NewNum;
		Count++;
	}
}

//Purpose:delete the rear node and reassign the rear node to the second to last node
void llist::deleteRear(el_t& OldNum)
{
	//case the list is not empty and this is not the only node in the list
	if(!isEmpty() && Front != Rear)
	{
		OldNum = Rear->Elem;
		Node* p = Front;
		while(p->Next != Rear)
		{			
			p = p->Next;
		}
		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
	//case the list is empty throw underflow
	else if(isEmpty())
	{
		throw Underflow();
	}
	//case this is the last node in the list
	else if(Front == Rear)
	{
		OldNum = Rear->Elem;
                delete Rear;
                Front = NULL;
                Rear = NULL;
                Count--;
	}
}

//Purpose:Delete a specified node in the list 
void llist::deleteIth(int I, el_t& OldNum)
{
	//case I is the last node in the list
	if(I == Count)
        {
        	el_t temp;
                deleteRear(temp);
                OldNum = temp;	
        }
	//case I is the first node in the list
       	else if(I == 1)
     	{
           	el_t temp;
                deleteFront(temp);
                OldNum = temp;
       	}
	//case I is somewhere in the list but is not the first or last
	else if(I <= Count && I >= 1)
	{
		Node* f = Front;
		Node* s = f->Next;
		for(int k = 1;k < I - 1;k++)
		{
			f = s;
			s = f->Next;
		}
		f->Next = s->Next;
		OldNum = s->Elem;
		delete s;
		Count--;
	}
	//case I is greater than count or less than 1
	else if(I > Count || I < 1)
	{
		throw OutOfRange();
	}
}

//Purpose:adds a node to a specified location in the list
void llist::addbeforeIth(int I, el_t newNum)
{
	//case I is somewhere in the list
	if(I <= Count + 1 && I >= 1)
	{
		Node* p = new Node;
		p->Elem = newNum;
		Node* cur = Front;
		//case I is the end node in the list
		if(I == Count + 1)
                {
                        addRear(newNum);
                }
		//case I is the begining node in the list
                else if(I == 1)
                {
                        addFront(newNum);
                }
		//case I is somewhere in the list not first or last
		else if(I > 1 && I <= Count)
		{
			int k;
			for(k = 1;k < I - 1;k++)
			{
				cur = cur->Next;
			}
			cout << k << endl;
			p->Next = cur->Next;
			cur->Next = p;
			Count++;
		}
	}
	//case I is greater than count or less than 1
	else if(I > Count + 1 || I < 1)
	{
		throw OutOfRange();
	}
}
