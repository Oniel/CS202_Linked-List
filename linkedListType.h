//Oniel Toledo    Assignment 12   CS202
//linkedListType base class header file + function definitions
//contains virtual functions and public functions for the 2 derived classes
//orderedLinkedList and unorderedLinkedList to copy from

//header gaurds
#ifndef H_LINKED
#define H_LINKED

#include<iostream>
#include<iomanip>
#include <cmath>
#include <string>
using namespace std;

//struct nodeType, the actual list structure
template <class myType>
struct nodeType{ //struct for each array containing
  myType info;//an info data location and a 
  nodeType<myType> *link;//link pointer to another nodeType list info location
};

template<class myType>
class linkedListType{
 public:
  //constructors/destructors
  linkedListType();
  linkedListType(const linkedListType<myType>&);
  ~linkedListType();
  //member functions, for further description look for the function below
  void initializeList();
  bool isEmptyList() const;
  void print() const;
  void reversePrint() const;
  int length() const;
  void destroyList();
  myType front() const;
  myType back() const;
  nodeType<myType>* firstPtr() const;
  //abstract functions no class definitions in this abstract class
  //virtual bool search(const myType&) const =0;
  //virtual void insert(const myType&) =0;
  //virtual void insertLast(const myType&) =0;
  //virtual void deleteNode(const myType&) =0;

 private:
  //will copy the contents of a passed list to the current object
  void copyList(const linkedListType<myType>&);
  //recusrive function to print out list in reverse order
  void recursiveReversePrint(nodeType<myType> *) const;

 protected:
  int count;
  nodeType<myType> *first;
  nodeType<myType> *last;
};

//~~~~~~~~~~~~~~Class member function definitons~~~~~~~~~~~~~~~~~~
//~~~~Constructors/Destructors~~~~
//constructor that initializes the list to an empty state
//sets base class variables to empty state
template<class myType>
linkedListType<myType>::linkedListType(){
  first=NULL;
  last=NULL;
  count=0;
}

//copy constructor performs same function as copyList, first will be set to null
//and then the copyList function will be called
template<class myType>
linkedListType<myType>::linkedListType(const linkedListType<myType> &pObj){
  first = NULL;
  copyList(pObj);
}


//destroyList() is the function that will be performing the destruction,
//the destructor below will call on the that function to destruct
template<class myType>
linkedListType<myType>::~linkedListType(){
  destroyList();
}


//~~~~~~~~~~~~~~~~~~function definitions~~~~~~~~~~~~~~~~~~

//function to copy list, will deep copy the passed list into the current class list
template<class myType>
void linkedListType<myType>::copyList(const linkedListType<myType> &pObj){
  nodeType<myType> *newNode;
  nodeType<myType> *current;
  //fist check that current object list is empty if not call destroy it
  if(first != NULL)
    destroyList();
  //Now check and see that the passed object list is not empty, if it is
  //the the the function does not need to copy anything set current class
  //variables to empty
  if(pObj.first == NULL){
    first =NULL;
    last =NULL;
    count =0;
  }
  else{//not empty, copy passed object list to current list
    //the current pointer will be vital for getting data from the pObj list, it
    // will be pointing to the passed object's list 'info' and 'link' nodes
    current = pObj.first;//set current to the first location of passed object
    count = pObj.count;//get count
   
    first = new nodeType<myType>;//create new node
    first->info = current->info;//set first info location
    first->link =NULL;//set first node link to NULL, in case its the last 
    last = first;//set the value pointer last to first
    current = current->link;//go to the link cell of first node
    //now copy remaining list
    while(current != NULL){//while current(link) is not NULL(last) loop
      newNode = new nodeType<myType>;//create a new node
      //if current isn't null then there is another list, current->link
      //will point to the new list so set the info of pObj to class list
      newNode->info = current->info;
      //then set link to NULL in case it is the last link in the linked lists
      newNode->link = NULL;
      last->link = newNode;//last will be the this current nodeType list
      last = newNode;
      current = current->link;//point to next link in pObj list, loop if not NULL
    }  
  }
}

//destroyList function acts as destructor
//will deallocate the linked list from first list until the last is reached
template<class myType>
void linkedListType<myType>::destroyList(){
  nodeType<myType> *tmp;
  while(first!=NULL){
    tmp = first;//set tmp to first node(in the list that is being deleted)
    first = first->link;//set the first pointer to the location of the next list
    delete tmp;//delete the current list
  }//loop until the last link is reached which will return NULL
  last = NULL;
  count = 0;
}

//initializes list to an empty state by calling destroyList and removing any nodes already there
template<class myType>
void linkedListType<myType>::initializeList(){
  destroyList();
}

//function to output the linked list
template<class myType>
void linkedListType<myType>::print() const{
  nodeType<myType> *current;//create a node to go throught the class linked list
  
  current = first;//set to head of linked list
  while(current!=NULL){
    cout << current->info << " ";//output data in info block of current node
    current = current->link;//will point to next list
  }
}

//return length of node
template<class myType>
int linkedListType<myType>::length() const{
  return count;
}

//returns the data in the first node
template<class myType>
myType linkedListType<myType>::front() const{
  if(first!=NULL)
    return first->info;
  else
    return 0;
}

//returns the data in the last node
template<class myType>
myType linkedListType<myType>::back() const{
  if(first!=NULL)
    return last->info;
  else
    return 0;
}

//function to return true or false depending if there is a list
template<class myType>
bool linkedListType<myType>::isEmptyList() const{
  return (first==NULL);
}

//returns a copy of the first pointer
template<class myType>
nodeType<myType> * linkedListType<myType>::firstPtr() const{
  nodeType<myType> *tmp = first;
  return tmp;
}

//function to print list in reverse order, calls the 
//recursiveReversePrint function to output using recursion
template<class myType>
void linkedListType<myType>::reversePrint() const{
  nodeType<myType> *tmp = first;
  recursiveReversePrint(tmp);//current pointer will be of first
  cout << endl;
}

//via recursion the following class outputs the list in reverse order
template<class myType>
void linkedListType<myType>::recursiveReversePrint(nodeType<myType> *current) const{
  if(current!=NULL){//if not NULL
    recursiveReversePrint(current->link);//perform recursion until NULL is reached
    cout << current->info << " ";//print out the info cell in the current nodeType list
  }
}

#endif
