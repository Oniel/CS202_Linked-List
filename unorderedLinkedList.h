//Oniel Toledo   Assignment 12   CS202
//The following header file contains class definitions for the derived unorderedLinkedList
//class as well as the template functions for the class, there will be no non-template 
//functions so there will be no separate implementation files to be created
//the function its non-pure virtual functions from the abstract class linkedListType.h
//search function looks for an item in the list if found will return true
//insert function inserts a new node to the list at the beginning of the list
//insertLast function will insert a new node and value at the end of the list
//deleteNode will delete a passed item it it exists in the list


//header gaurds
#ifndef H_UNORDERED
#define H_UNORDERED

#include<iostream>
#include "linkedListType.h"
using namespace std;

template<class myType>
class unorderedLinkedList: public linkedListType<myType>{
 public:
  bool search(const myType&) const;
  void insert(const myType&);
  void insertLast(const myType&);
  void deleteNode(const myType&);
 protected:
  using linkedListType<myType>::count;
  using linkedListType<myType>::first;
  using linkedListType<myType>::last;
};

//function to search for the passed item in the class list
template<class myType>
bool unorderedLinkedList<myType>::search(const myType& item) const{
  bool found = false;
  nodeType<myType> *current;//created current pointer to go throught the list
 
  current = first;//start at the top(head) of the list
  //loop until either the item is found or the end of the list is reached
  while(current!=NULL && !found)
    if(current->info == item)
      return true;//stop loop and return true if found
    else//else current will be set to link which will point to next link(if not NULL)
      current = current->link;
  return false;//if function did not find 'item' return false
}

//insert new node at the beginning of the function
template<class myType>
void unorderedLinkedList<myType>::insert(const myType& newVal){
  nodeType<myType> *newNode;
  newNode = new nodeType<myType>;

  newNode->info = newVal;//create new list and store value
  newNode->link = first;//new node will be in front of the list
  first = newNode;
  count++;
  if(last == NULL)
    last = newNode;
}

//insertes new node at the end of the function
template<class myType>
void unorderedLinkedList<myType>::insertLast(const myType& newVal){
  nodeType<myType> * newNode;//create new pointer and list
  newNode = new nodeType<myType>;

  newNode->info = newVal;//store the value and set link to NULL since it will be the last list
  newNode->link = NULL;
  
  if(first == NULL){//if the list is empty, this will be the only node
    first = newNode;
    last = newNode;
    count++;
  }
  else{//find the last link and set that to the newNode list
    last->link = newNode;
    last = newNode;
    count ++;
  }
}

//will delete a node from the list, if it exists
template<class myType>
void unorderedLinkedList<myType>::deleteNode(const myType& deleteItem){
  nodeType<myType> *current;
  nodeType<myType> *trailCurrent;
  bool found;
  
  //case 1
  if(first==NULL)//if no list exists no need to search return error msg
    cout << "Cannot delete from an empty list." << endl << endl;
  else{
    //case 2
    if(first->info==deleteItem){//if item to delete is the first one
      current = first;
      first = first->link;//set first to second node
      count--;

      if(first == NULL)
	last = NULL;
      delete current;//delete the first node
    }
    else{//for all other cases...
      found = false;
      trailCurrent = first;
      current = first->link;
      while(current !=NULL && !found){//loop until the item is found or the end
	if(current->info != deleteItem){//of the list is reached
	  trailCurrent = current;
	  current = current->link;
	}
	else
	  found = true;
      }
      if(found){//if the item is found set trailCurrent link to point to the node after the node where
	trailCurrent->link = current->link;//the item is located  (before: a->b->c now a->c)
	count--;
	if(last == current)
	  last = trailCurrent;
	delete current;//delete the node with the deleteItem, 
      }
      else//the item is not in the list
	cout << "The item to be deleted is not in the list." << endl;
    }
  }
}

#endif
