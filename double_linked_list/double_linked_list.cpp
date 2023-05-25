#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int roolNo, Node** previous, Node** current);
	bool deleteNode(int roolNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();		// step 1
	newNode->noMhs = nim;			// step 2
	newNode->name = nm;				// step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;	// step 3
		if (START != NULL)
			START->prev = newNode;	// step 4
		newNode->prev = NULL;		// step 5
		START = newNode;			// step 6
		return;
	}

	/*Inserting a Node between two nodes in the list*/
	Node* current = START;	//step 1a
	Node* previous = NULL;	//step 1b
	while (current->next != NULL && current->next->noMhs < nim)  // step 1c
	{
		previous = current;
		current = current->next;
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = current->next;	//step 4
	newNode->prev = current;		// step 5
	if (current->next != NULL)
		current->next->prev = newNode;		//step 6
	current->next = newNode;			// step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;	// step 1.a
	*current = START;	// step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {	//step 1c
		*previous = *current;	//step 1d
		*current = (*current)->next;	//step 1e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)	
		return false;
	if (current->next != NULL)
		current->next->prev = previous;					//step 2
	if (previous != NULL)
		previous->next = current->next;					// step 3
	else
		START = current->next;

	delete current;	//step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted" << endl;
}