//  CS 202 Provided Main
//  Uses various functions for linked lists (unordered and ordered)

#include <iostream>
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"

using namespace std;

int main()
{
// ----------------------------------------------------------------------
//  Simple header.

	string bars;
	bars.append(70, '-');

	cout << endl;
	cout << "CS 202 - Assignment #12" << endl;
	cout << "Linked Lists" << endl << endl;

// ----------------------------------------------------------------------
//  Initializations used on the following series of tests.

	int	inums[] = {22, 34, 56, 4, 19, 2, 89, 90, 3, 14, 32,
				88, 125, 56, 11, 43, 55};
	double	dnums[] = {22.1, 34.5, 56.6, 4.3, 19.2, 2.5, 89.4, 90.8,
				3.14, 14.3, 32.9, 88.1, 125.3, 56.7,
				11.5, 43.8, 55.2};

	unorderedLinkedList<int> ilist1u;
	unorderedLinkedList<int> ilist2u;
	unorderedLinkedList<double> dlist3u;

	orderedLinkedList<int> ilist1o;
	orderedLinkedList<int> ilist2o;
	orderedLinkedList<double> dlist3o;

	int	ilen = ( sizeof(inums) / sizeof(inums[0]) );
	int	iitem;

	int	dlen = ( sizeof(dnums) / sizeof(dnums[0]) );
	double	ditem;

// ----------------------------------------------------------------------
//  Test Set #1

	cout << bars << endl;
	cout << "List 1 - Integers" << endl << endl;

	for (int i=0; i<ilen; i++) {
		ilist1u.insert(inums[i]);
		ilist1o.insert(inums[i]);
	}

	cout << "List 1 - Unordered: " << endl;
	ilist1u.print();
	cout << endl;

	cout << endl << "List 1 Unordered, in reverse order: " << endl;
	ilist1u.reversePrint();
	cout << endl;

	cout << "List 1 Ordered: " << endl;
	ilist1o.print();
	cout << endl;

	cout << endl << "List 1 Ordered, in reverse order: " << endl;
	ilist1o.reversePrint();
	cout << endl;

// ----------------------------------------------------------------------
//  Test Set #2

	cout << bars << endl;
	cout << "List 2 - Integers:" << endl << endl;

	for (int i=0; i<ilen; i++) {
		ilist2u.insertLast(inums[i]);
		ilist2o.insertLast(inums[i]);
	}

	cout << "List 2 length: " << ilist2u.length() << endl;
	cout << "List 2 Unordered: " << endl;
	ilist2u.print();
	cout << endl << endl;

	ilist2u.deleteNode(3);
	ilist2u.deleteNode(14);
	ilist2u.deleteNode(32);

	cout << endl << "List 2 Unordered New Length: " << ilist2u.length() << endl;
	cout << "List 2 Unordered -> With nodes removed:  0  14  32" << endl;
	ilist2u.print();
	cout << endl << endl;

	cout << "List 2 Unordered -> Search tests (for 14 and 90): " << endl;

	iitem = 14;
	if ( ilist2u.search(iitem) )
		cout << "List 2: item " << iitem << " was found." << endl;
	else
		cout << "List 2: item " << iitem << " was not found." << endl;

	iitem = 90;
	if ( ilist2u.search(iitem) )
		cout << "List 2: item " << iitem << " was found." << endl;
	else
		cout << "List 2: item " << iitem << " was not found." << endl;
	cout << endl;

// ----------------------------------------------------------------------
//  Test Set #3

	cout << bars << endl;
	cout << "List 3 - Doubles:" << endl << endl;

	for (int i=0; i<dlen; i++) {
		dlist3u.insertLast(dnums[i]);
		dlist3o.insertLast(dnums[i]);
	}

	// Unordered
	cout << "List 3 Unordered: " << endl;
	dlist3u.print();
	cout << endl << endl;

	cout << "List 3 Unordered (reverse order): " << endl;
	dlist3u.reversePrint();
	cout << endl;

	cout << "List 3 Unordered -> Search tests (for 11.5 and 19.2): " << endl;

	ditem = 11.5;
	if ( dlist3u.search(ditem) )
		cout << "List 3: item " << ditem << " was found." << endl;
	else
		cout << "List 3: item " << ditem << " was not found." << endl;

	ditem = 19.2;
	if ( dlist3u.search(iitem) )
		cout << "List 3: item " << ditem << " was found." << endl;
	else
		cout << "List 3: item " << ditem << " was not found." << endl;
	cout << endl;

	// Ordered
	cout << "List 3 Ordered: " << endl;
	dlist3o.print();
	cout << endl << endl;

	cout << "List 3 Ordered (reverse order): " << endl;
	dlist3o.reversePrint();
	cout << endl;

	cout << "List 3 Ordered -> Search tests (for 11.5 and 19.2): " << endl;

	ditem = 11.5;
	if ( dlist3o.search(ditem) )
		cout << "List 3: item " << ditem << " was found." << endl;
	else
		cout << "List 3: item " << ditem << " was not found." << endl;

	ditem = 19.2;
	if ( dlist3o.search(iitem) )
		cout << "List 3: item " << ditem << " was found." << endl;
	else
		cout << "List 3: item " << ditem << " was not found." << endl;
	cout << endl;

// ----------------------------------------------------------------------
//  Test Set #4

	cout << bars << endl;
	cout << "List 4 - Doubles:" << endl << endl;

	{
		unorderedLinkedList<double> dlist4u(dlist3u);
		orderedLinkedList<double> dlist4o(dlist3o);

		// Unordered tests...
		cout << "List 4 Unordered (original list): " << endl;
		dlist4u.print();
		cout << endl << endl;

		cout << "List 4 Unordered Delete Testing..." << endl;
		dlist4u.deleteNode(55.2);
		dlist4u.deleteNode(34.0);
		dlist4u.deleteNode(43.8);
		dlist4u.deleteNode(22.1);
		dlist4u.deleteNode(3.14);
		dlist4u.deleteNode(34.5);
		cout << endl;

		cout << "List 4 Unordered (modified): " << endl;
		dlist4u.print();
		cout << endl << endl;

		cout << "List 4 Unordered - first item: ";
		cout << dlist4u.front() << endl;

		cout << "List 4 Unordered - last item: ";
		cout << dlist4u.back() << endl << endl;

		// Ordered tests...
		cout << endl << "List 4 Ordered (original list): " << endl;
		dlist4o.print();
		cout << endl << endl;

		cout << "List 4 Ordered Delete Testing..." << endl;
		dlist4o.deleteNode(55.2);
		dlist4o.deleteNode(34.0);
		dlist4o.deleteNode(43.8);
		dlist4o.deleteNode(22.1);
		dlist4o.deleteNode(3.14);
		dlist4o.deleteNode(34.5);
		cout << endl;

		cout << "List 4 Ordered (modified): " << endl;
		dlist4o.print();
		cout << endl << endl;

		cout << "List 4 Ordered - first item: ";
		cout << dlist4o.front() << endl;

		cout << "List 4 Ordered - last item: ";
		cout << dlist4o.back() << endl << endl;
	}

// ----------------------------------------------------------------------
//  Test Set #5

	cout << bars << endl;
	cout << "List 5 - Short's (0-4):" << endl << endl;

	unorderedLinkedList<short> ilist5u;
	orderedLinkedList<short> ilist5o;

	if (ilist5u.isEmptyList())
		cout << "List is initially empty, adding 4, 3, 2, 1 and 0."
				<< endl << endl;

	for (int i=4; i>=0; i--) {
		ilist5u.insertLast(i);
		ilist5o.insertLast(i);
	}

	// unordered
	cout << "List 5 Unordered: " << endl;
	ilist5u.print();
	cout << endl << endl;

	cout << "List 5 Unordered - first item: ";
	cout << ilist5u.front() << endl;

	cout << "List 5 Unordered - last item: ";
	cout << ilist5u.back() << endl;


	// ordered
	cout << "List 5 Ordered: " << endl;
	ilist5o.print();
	cout << endl << endl;

	cout << "List 5 Ordered - first item: ";
	cout << ilist5o.front() << endl;

	cout << "List 5 Ordered - last item: ";
	cout << ilist5o.back() << endl;

// ----------------------------------------------------------------------
//  Test Set #6

	unorderedLinkedList<short> ilist6u(ilist5u);
	unorderedLinkedList<short> ilist7u(ilist5u);
	orderedLinkedList<short> ilist6o(ilist5o);
	orderedLinkedList<short> ilist7o(ilist5o);

	cout << bars << endl;
	cout << "Lists 6 and 7 - Even Short's (2-20)" << endl;
	cout << "Copy of list 5 with 5, 6, 7, 8, and 9 added." << endl << endl;

	for (int i=5; i<10; i++) {
		ilist6u.insertLast(i);
		ilist6o.insertLast(i);
		ilist7u.insertLast(i);
		ilist7o.insertLast(i);
	}

	// unordered
	cout << "List 6 Unordered (length=" << ilist6u.length() << ") : ";
	ilist6u.print();
	cout << endl;
	cout << "List 7 Unordered (length=" << ilist7u.length() << ") : ";
	ilist7u.print();
	cout << endl << endl;

	cout << "Destroying List 6 Unordered..." << endl;
	ilist6u.destroyList();
	cout << "List 6 Unordered (should be empty): ";
	ilist6u.print();
	cout << endl << endl;

	cout << "Initializing List 7 Unordered..." << endl;
	ilist7u.initializeList();
	cout << "List 7 Unordered (should be empty): " << endl;
	ilist7u.print();
	cout << endl << endl;

	// ordered
	cout << "List 6 Ordered (length=" << ilist6o.length() << ") : ";
	ilist6o.print();
	cout << endl;
	cout << "List 7 Ordered (length=" << ilist7o.length() << ") : ";
	ilist7o.print();
	cout << endl << endl;

	cout << "Destroying List 6 Ordered..." << endl;
	ilist6o.destroyList();
	cout << "List 6 Ordered (should be empty): ";
	ilist6o.print();
	cout << endl << endl;

	cout << "Initializing List 7 Ordered..." << endl;
	ilist7o.initializeList();
	cout << "List 7 Ordered (should be empty): " << endl;
	ilist7o.print();
	cout << endl << endl;

// ----------------------------------------------------------------------
//  Test Sets -> Ordered only

	int	inumsa[] = {2, 4, 6, 8, 10, 12, 14};
	int	inumsb[] = {1, 3, 5, 7, 9, 11, 13, 15};

	orderedLinkedList<int> ilist8, ilist9, ilist10, ilist11;
	orderedLinkedList<int> ilist12, ilist13;
	orderedLinkedList<int> ilista, ilistb, ilistc, ilistd;
	orderedLinkedList<int> ilistEmpty;

	int	ilena = ( sizeof(inumsa) / sizeof(inumsa[0]) );
	int	ilenb = ( sizeof(inumsb) / sizeof(inumsb[0]) );

	cout << bars << endl;
	cout << "List 8 Ordered - Integers:" << endl << endl;

	for (int i=0; i<ilena; i++)
		ilista.insert(inumsa[i]);
	for (int i=0; i<ilenb; i++)
		ilistb.insert(inumsb[i]);
	ilistc.insert(0);
	ilistd.insert(50);

	cout << "List A Ordered: " << endl;
	ilista.print();
	cout << endl;
	cout << "List B Ordered: " << endl;
	ilistb.print();
	cout << endl;
	cout << "List C Ordered: " <<endl;
	ilistc.print();
	cout << endl;
	cout << "List D Ordered: " << endl;
	ilistd.print();
	cout << endl;

	ilist8.sortedMerge(ilista, ilistb);
	cout << endl << "List 8 Ordered (sorted merge): " << endl;
	ilist8.print();
	cout << endl << "List 8 Length: " << ilist8.length() << endl;

	ilist9.sortedMerge(ilista, ilistEmpty);
	cout << endl << "List 9 Ordered (sorted merge, A only): " << endl;
	ilist9.print();
	cout << endl << "List 9 Length: " << ilist9.length() << endl;

	ilist10.sortedMerge(ilistEmpty, ilistb);
	cout << endl << "List 10 Ordered (sorted merge, B only): " << endl;
	ilist10.print();
	cout << endl << "List 10 Length: " << ilist10.length() << endl;

	ilist11.sortedMerge(ilistEmpty, ilistEmpty);
	cout << endl << "List 11 Ordered (sorted merge, none): " << endl;
	ilist11.print();
	cout << endl << "List 11 Length: " << ilist11.length() << endl;

	ilist12.sortedMerge(ilista, ilistc);
	cout << endl << "List 12 Ordered (sorted merge, 0+A): " << endl;
	ilist12.print();
	cout << endl << "List 12 Length: " << ilist12.length() << endl;

	ilist13.sortedMerge(ilista, ilistd);
	cout << endl << "List 13 Ordered (sorted merge, A+50): " << endl;
	ilist13.print();
	cout << endl << "List 13 Length: " << ilist13.length() << endl;
	cout << endl;

// ----------------------------------------------------------------------
//  Testing with strings.

	unorderedLinkedList<string> slistu;
	orderedLinkedList<string> slisto;

	string words[] = {"enters", "green", "in", "a", "jumps", "big",
			"familiar", "dog", "hills"};
	int	sLen = sizeof(words) / sizeof(string);

	cout << bars << endl;
	cout << "String List:" << endl << endl;

	if (slistu.isEmptyList())
		cout << "String List is initially empty, adding words..."
				<< endl << endl;

	for (int i=0; i<sLen; i++) {
		slistu.insert(words[i]);
		slisto.insert(words[i]);
	}

	// unordered
	cout << "String List Unordered: " << endl;
	slistu.print();
	cout << endl << endl;

	cout << "String List Unordered - first item: ";
	cout << slistu.front() << endl;

	cout << "String List Unordered - last item: ";
	cout << slistu.back() << endl;

	slistu.destroyList();

	if (slistu.isEmptyList())
		cout << endl << "String List Unordered is now empty." << endl;
	cout << endl;


	// ordered
	cout << "String List Ordered: " << endl;
	slisto.print();
	cout << endl << endl;

	cout << "String List Ordered - first item: ";
	cout << slisto.front() << endl;

	cout << "String List Ordered - last item: ";
	cout << slisto.back() << endl;

	slisto.destroyList();

	if (slisto.isEmptyList())
		cout << endl << "String List Ordered is now empty." << endl;
	cout << endl;

// ----------------------------------------------------------------------
//  Done, end the program.

	cout << bars << endl;
	cout << endl << "Game Over, thank you for playing." << endl << endl;

	return 0;
}

