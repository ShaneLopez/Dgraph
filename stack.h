
/*INSTRUCTION:
Stack class - header file template (by Yoshii) based on Notes-1
You must complete the ** parts and then complete stack.cpp*/

// =======================================================

// HW1P1
// Your name: **
// Compiler:  g++ 
// File type: headher file stack.h

//=======================================================

#include <vector>
using namespace std;

//const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef char el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        vector<el_t> el;       // el is  an array of el_t's
        int      top;           // top is index to the top of stack

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL: provide variable to hold the top element in the stack without popping the top element
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

        // ************ add good comments for each function *****
	//PURPOSE: returns true if the stack is empty and returns false if the stack is full
      	bool isEmpty();
	//PURPOSE: returns true if the stack is full and false if the stack si empty
      	bool isFull();
	//PURPOSE: will display all items currently in the stack
        void displayAll();
	//PURPOSE: will delete all items currently in the stack
        void clearIt();
        
  };  

// Note: semicolon is needed at the end of the header file

