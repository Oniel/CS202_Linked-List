#Oniel Toledo    Assignmnet 12 makefile    CS202
#make file for the inherited class linkedListType as well as the
#two derived class unorderedLinkedList and orderedLinkList, because
#the assignmnet focuses on template usage there will be no
#implementation file needed only header files

#current compiler - g++
cc = g++
#object file to be created only main
OBJS = main.o
#dependency header files
DEPS1 = linkedListType.h unorderedLinkedList.h orderedLinkedList.h
#target for main
all: main

main: $(OBJS)
	$(cc) -o main $(OBJS)
#for the target object file use the main.cpp file and the headers
main.o: main.cpp $(DEPS1)
	$(cc) -c -g main.cpp
clean:
	rm $(OBJS)