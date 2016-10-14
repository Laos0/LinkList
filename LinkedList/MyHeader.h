#ifndef  MyHeader_H_INCLUDED

#endif // ! MyHeader_H_INCLUDED
#include <iostream>

using namespace std;

class node {
public:

	node(int myInfo) {
		info = myInfo;
		next = NULL;
	}

	int info;
	node* next;
};

class MyList {

public:
	// Count Function
	int count() {
		return counter;
	}

	// isEmpty function
	bool isEmpty() {
		return counter == 0;
	}

	//insertion function
	void inser(node* myNode) {
		// Case 1: the list is empty
		if (isEmpty()) {
			first = myNode;
			last = myNode;
		}
		else {//Case 2: The list is not empty
			  // Insert using forward method
			last->next = myNode;
			last = myNode;
		}

		counter++;
	}
	//Delete functino
	void Delete(node* myNode) {
		// Case 1: if the list is empty
		if (isEmpty()) {
			cout << "The list is empty, there is nothing to be deleted" << endl;
		}// case 2: myNode  is the firswt node in the list
		else if (myNode->info == first->info) {
			node* temp = first;
			first = first->next;
			delete temp;
			counter--;
		}//case 3: myNode is the last in the list
		else if (myNode->info == last->info) {
			node* current = first;
			node* previous = first;
			while (current->next != NULL) {
				previous = current;
				current = current->next;

			}
			last = previous;
			delete current;
			counter--;
		}//case 4: if myNode is in the middle of the list or it does not exist in the list
		else {
			node* current = first;
			node* previous = first;
			bool isThere = false;
			while (current->next != NULL) {
				previous = current;
				current = current->next;

				if (current->info == myNode->info) {
					isThere = true;
					break;

				}
			}
			if (isThere) {
				previous->next = previous->next->next;
				delete current;
				counter--;
			}
			else {
				cout << "The node that you want to delete does not exist in the list" << endl;
			}
		}
	}
	// print function
	void print() {
		node* current = first;
		while (current != NULL) {
			cout << current->info << " ";
			current = current->next;
		}
		cout << endl;
	}
	MyList() {
		counter = 0;
		first = NULL;
		last = NULL;
	}

	~MyList() {
		node* current = first;
		node* previous = last;
		while (current != NULL) {
			previous = current;
			current = current->next;
			delete previous;
		}
	}

private:
	node* first;
	node* last;
	int counter;
};
