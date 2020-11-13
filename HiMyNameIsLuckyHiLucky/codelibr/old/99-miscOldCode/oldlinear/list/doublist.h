// ***********************************************************
// *                                                         *
// *  doublist.h                                             *
// *                                                         *
// *  Implementation for a list class, implemented via       *
// *        doubly-linked memory                             *
// *                                                         *
// *  Written 5/97 by Jason Zych                             *
// *                                                         *
// *********************************************************** 

#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <iostream.h>
#include "asserts.h"

template <class Etype>
class ListNode
{
private:

   friend class List<Etype>; 
  
   // ListNode Constructor
   ListNode() { next = NULL; }

   Etype element;
   ListNode* next;
   ListNode* prev; 
};



template <class Etype>
class List
{
public:

 // *** Allocation/Deallocation

   // List 
   //    - default constructor
   //    - creates an empty list
   List();
 
 
   // List 
   //    - copy constructor
   //    - parameters : origVal - a previously allocated List object 
   //    - initializes the list to be a copy of origVal 
   List(const List& origVal);


   // ~List
   //    - destructor 
   //    - deallocates all dynamically allocated memory inside the list 
   virtual ~List();


 // *** Mass Update

   // Clear
   //    - deletes all values from list, resulting in an empty list 
   void Clear(); 

   
   // operator=
   //    - parameters: origVal - a previously allocated List object
   //    - return value: reference to the List object
   //    - sets the the list to be a copy of origVal
   List& operator= (const List& origVal);


 // *** Singular Update

   // InsertAfter
   //    - parameters : newElem - an element of the list's type, to be inserted
   //    - inserts newElem after current position in list
   void InsertAfter(Etype newElem); 


   // InsertBefore
   //    - parameters : newElem - an element of the list's type, to be inserted
   //    - inserts newElem before current position in list
   void InsertBefore(Etype newElem); 


   // Remove
   //    - removes the element at the current postition of the list
   void Remove();


   // Update
   //    - parameters : updateElem - an element of the list's type
   //    - replaces the value at the current position with updateElem 
   void Update(Etype updateElem); 


 // *** Traversal

   // Head
   //    - makes the first position in the list the current position 
   void Head();

   
   // Tail
   //    - makes the last position in the list the current position 
   void Tail();


   // operator++
   //    - moves the current position one forward in the list  
   List& operator++ (int);


   // operator--
   //    - moves the current position one backward in the list
   List& operator-- (int); 

 // *** Information Access 

   // Retrieve
   //    - returns the element at the current list position
   Etype Retrieve() const; 

   
   // Find 
   //    - parameters : queryElem - an element of the list's type, 
   //                       to be searched for
   //    - return value : a boolean yes or no
   //    - searches list for queryElem...if found, make that position the current
   //         position and return 1; otherwise, return 0 
   int Find(Etype queryElem); 


   // Length
   //    - return value : an integer representing the list's length 
   //    - returns the length of the list 
   int Length() const; 

// *** Output

   // Print
   //    - writes the individual elements of the list to the output
   //         stream object, and then returns that output stream object
   void Print() const;


protected:

   ListNode<Etype> *head,        // points to first node of list
                   *current,     // points to node at current list position
                   *tail;        // points to last node of list

   int size;          // number of nodes in list

};


#endif 

   

