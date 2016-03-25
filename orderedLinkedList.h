//Oniel Toledo   Assignment 12   CS202                                                                                                                                              
//The following header file contains class definitions for the derived orderedLinkedList                                                                                          
//class as well as the template functions for the class, there will be no non-template                                                                                              
//functions so there will be no separate implementation files to be created                                                                                                         
//the function its non-pure virtual functions from the abstract class linkedListType.h                                                                                              
//search function looks for an item in the list if found will return true                                                                                                           
//insert function inserts a new node to the list at the beginning of the list                                                                                                       
//insertLast function will insert a new node and value at the end of the list                                                                                                       
//deleteNode will delete a passed item it it exists in the list                                                                                                                     
//sortedMerge simply calls sMerge
//sMerge will merge two lists into a new linkedList and set the current class object
//to point to that linked list

//header gaurds
#ifndef H_ORDERED
#define H_ORDERED

#include<iostream>
#include "linkedListType.h"
using namespace std;

template<class myType>
class orderedLinkedList: public linkedListType<myType>{
 public:
  bool search(const myType&);
  void insert(const myType&);
  void insertLast(const myType&);
  void deleteNode(const myType&);
  void sortedMerge(const linkedListType<myType>&, const linkedListType<myType>&);
 private:
  nodeType<myType>* sMerge(nodeType<myType>* , nodeType<myType>*);
 protected:
  using linkedListType<myType>::count;
  using linkedListType<myType>::first;
  using linkedListType<myType>::last;
};

//function to search for the passed item in the class list 
template<class myType>
bool orderedLinkedList<myType>::search(const myType& searchItem){
  bool found = false;
  nodeType<myType> *current;//pointer used to go through the list
  
  current = first;//start at the top of the list
  while(current!=NULL && !found)//loop until item is found or end is reached
    if(current->info >=searchItem)
      found = true;
    else
      current = current->link;
  if(found)
    found = (current->info == searchItem);
  return found;
}


//function to insert a new node to the list(if it doesn't already exist in the list), since
//the list is ordered the new node will have to be insrted in order
template<class myType>
void orderedLinkedList<myType>::insert(const myType& item){
  nodeType<myType> *current;
  nodeType<myType> *trailCurrent;
  nodeType<myType> * newNode;
  bool found;
  
  if(search(item)==true)//run the search function, if the list already has that item don't insert it
    cout << "The item to be inserted is alread in the list." << endl;
  else{
    
    newNode = new nodeType<myType>;
    newNode->info = item;//create a new node list add item and set link to null(in case it is last)
    newNode->link = NULL;
    
    if(first == NULL){//case1- no list, create the list with this single value
      first = newNode;
      last = newNode;
      count++;
    }
    else{
      current = first;
      found = false;
      //loop until the value is found or the end of the list is reached.
      while(current != NULL && !found)
	if(current->info >= item)
	  found = true;//if found exit loop
	else{
	  trailCurrent = current;
	  current = current->link;
	}
      
      if(current == first){
	newNode->link = first;
	first = newNode;
	count++;
      }
      else{
	trailCurrent->link = newNode;
	newNode->link = current;
	
	if(current ==NULL)
	  last = newNode;	
	count++;
      }
    }
  }
}

//insert last function calls the insrt function to perform insrt function
template<class myType>
void orderedLinkedList<myType>::insertLast(const myType& item){
  insert(item);
}

//function to delete a passed item
template<class myType>
void orderedLinkedList<myType>::deleteNode(const myType& deleteItem){
  nodeType<myType> *current;
  nodeType<myType> *trailCurrent;
  bool found;
  
  if(first == NULL)//if there is no list error msg
    cout << "Cannot delete from an empty list." << endl;
  else{
    current = first;
    found = false;
    //loop until either the end of the list is reached or the item is found
    //will start from the first pointer info cell, it that is not the item
    //set current to the link of that node which will point to the next list
    //loops until found, or link is NULL
    while(current != NULL && !found)
      if(current->info >= deleteItem)
	found = true;
      else{
	trailCurrent = current;
	current = current->link;
      }
    if(current == NULL)//if NULL was reached the list does not contained deleteItem
      cout << "The item to be deleted is not in the list." << endl;
    else//if the item does have it...
      if(current->info == deleteItem){
	if(first == current){//if it is the first node, set first node to the second node,
	  first = first->link;
	  if(first =NULL)
	    last = NULL;
	  delete current;//and delete, check to make sure the first node is not the only one
	}
	else{
	  trailCurrent->link = current->link;
	  
	  if(current ==last)
	    last = trailCurrent;
	  
	  delete current;
	}
	count--;
      }
      else
	cout << "The item to be deleted is not in the list." << endl;
  }
}

//function that calls upon the sMerge function, which merges the 2 passed lists recursively
template<class myType>
void orderedLinkedList<myType>::sortedMerge(const linkedListType<myType>& list1, const linkedListType<myType>& list2){
  //sMerge will (if the lists aren't already NULL) create a new linked list and while store the data of the two lists in order,
  //the result of this function will the pointer to the head of this new function, which 'first' of the current function will 
  //be equal to
  first = sMerge(list1.firstPtr(), list2.firstPtr());
}


//recusive function that merges two sorted lists
template<class myType>
nodeType<myType>* orderedLinkedList<myType>::sMerge(nodeType<myType>* a, nodeType<myType>* b){
  nodeType<myType> *newNode;
  //two possible cases either both are NULL or they aren't
  //case1---both lists are empty
  if(a == NULL && b == NULL)//if both are null return null
    return NULL;
  else{
    //create a new linked list that will store merged lists
    newNode = new nodeType<myType>;
    //case2---one of the lists is empty, insert the other lists information and recurse
    if((a==NULL && b!=NULL) ||(a!=NULL && b==NULL)){//if either a or b is NULL
      
      if(b==NULL){
	newNode->info = a->info;
	count++;
	newNode->link = sMerge(a->link, NULL);
      }
      else
	if(a==NULL){
	  newNode->info = b->info;
	  count++;
	  newNode->link = sMerge(NULL, b->link);
	}
    }//case3---if both lists have information, compare the lists for the smallest number
    else{//insrt that number in the new created newNode list and recurse for other possible
      if(a->info <= b->info){//data sets
	newNode->info = a->info;
	count++;
	newNode->link = sMerge(a->link, b);
      }
      else
	if(a->info > b->info){
	  newNode->info = b->info;
	  count++;
	  newNode->link = sMerge(a, b->link);
	}
    }
    
    return newNode;//return the head of the newNode
  }
}

#endif
