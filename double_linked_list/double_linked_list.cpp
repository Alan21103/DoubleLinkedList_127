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
	void hapus();
	void searchData();
};

