#include <iostream>
#include "MyHeader.h"

using namespace std;


int main() {

	MyList TheList;
	while (true) {
		cout << "Enter 1 for insert\n"
			<< "enter 2 for delete\n"
			<< "enter 999 for stop\n";
		int input;
		cin >> input;

		if (input == 999) {
			break;
		}

		switch (input) {
		case 1: {// insert
			cout << "What value do you want to insert ";
			int value;
			cin >> value;
			node* myNode = new node(value);
			TheList.inser(myNode);
			cout << " The content of the list: \n";
			TheList.print();
		}
				break;
		case 2: {//Delete
			cout << "What value do you want to delete?";
			int value;
			cin >> value;
			node* myNode = new node(value);
			TheList.Delete(myNode);
			cout << "The content of the list: \n";
			TheList.print();

		}
		}

	}

	system("pause");
}