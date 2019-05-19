#ifndef LAB7_LIST
#define LAB7_LIST
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T  item;
	bool marker = false;
	Node *next;
	Node *head;
	Node *tail;
};

// Generic Class List - Barely used
// Had problems establishing Class hierarchy 
template <class T> class ListInterface : public Node<T>
{
public:

	virtual bool isEmpty() { return true; };
	virtual void add(T newEntry) { return; };
	virtual void displayList() { return; };
};


template <class T> class List : public ListInterface<T>
{
private:
	using Node<T>::head;
	using Node<T>::tail;

public:

	int findMinPosition_inList() {
		Node<T> *rover = head;
		int min = INT_MAX;
		int counter = 0;
		int position = 0;
		while (rover != NULL) {
			if (min > rover->item && rover->item != 0 && rover->marker == false) {
				min = rover->item;
				position = counter;
			}

			rover = rover->next;
			counter++;
		}

		return position;
	}

	void setMarker(int position) {
		Node<T> *rover = head;
		int counter = 0;
			while (rover != NULL) {
				if (counter == position) {
					rover->marker = true;
					return;
				}
				rover = rover->next;
				counter++;
			}
	}

	int returnCost() {

		Node<T> *rover = head;
		int min = INT_MAX;
		int counter = 0;
		int cost = 0;
		while (rover != NULL) {
			if (min > rover->item && rover->item != 0 && rover->marker == false) {
				min = rover->item;
				cost = min;
			}

			rover = rover->next;
			counter++;
		}

		return cost;
	}

	
	List() { head = nullptr; }

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else { return false; }
	}


	void add(T newEntry) {
		Node<T> *newNode = new Node<T>;
		newNode->item = newEntry;
		newNode->next = NULL;
		

		if (isEmpty() == true) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void clear() {
		Node<T> *nodePtr = head;
		Node<T> *n;
		while (nodePtr) {
			n = nodePtr->next;
			delete nodePtr; // delete Dynamic memory
			nodePtr = n;
		}
		head = nullptr; // point head to null 
		cout << "List has been cleared!" << endl;
	}

	void displayList()
	{
		// Rover will go through the list one by one
		Node<T> *rover;
		rover = head;
		if (isEmpty() == true) {
			return;
		}
		else {
			while (rover) // Rover goes until it hits the end of the list
			{
				cout << rover->item << "\t";
				// Setting rover to the previous
				rover = rover->next;
			}
		}
	}

};


#endif