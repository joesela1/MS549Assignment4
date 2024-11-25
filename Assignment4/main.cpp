#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class Node {
	public:
		int d;
		Node* next;
		Node* previous;

		Node() {
			next = nullptr;
			previous = nullptr;
		}
		Node(int num) {
			d = num;
			next = nullptr;
			previous = nullptr;
		}
};

//Stack implement as doubly-linked list
class Stack {
	Node* top;
	public:
		Stack() {
			top = nullptr;
		}
		//insert, remove, print
		void insert(int num) {
			Node* topNode = new Node(num);
			if (top == nullptr) {
				top = topNode;
			}
			else {
				topNode->next = top;
				top->previous = topNode;
				top = topNode;
			}
		}
		void remove() {
			Node* temp = top;
			top = top->next;
			if (top != nullptr) {
				top->previous = nullptr;
			}
			delete temp;
		}
		void print() {
			Node* curr = top;
			cout << "Current stack is: " << endl;
			while (curr != nullptr) {
				cout << curr->d << " ";
				curr = curr->next;
			}
			cout << endl;
			cout << "--------------------------------------------" << endl;
		}
};

class Queue {
	Node* head;
	Node* tail;
	public:
		Queue() {
			head = nullptr;
			tail = nullptr;
		}
		//insert, remove, print
		void insert(int num) {
			Node* newN = new Node(num);
			if (tail == nullptr) {
				head = tail = newN;
			}
			else {
				tail->next = newN;
				newN->previous = tail;
				tail = newN;
			}
		}
		void remove() {
			Node* temp = head;
			head = head->next;
			if (head != nullptr) {
				head->previous = nullptr;
			}
			else {
				tail = nullptr;
			}
			delete temp;
		}
		void print() {
			Node* curr = head;
			cout << "Current Queue is: " << endl;
			while (curr != nullptr) {
				cout << curr->d << " ";
				curr = curr->next;
			}
			cout << endl;
			cout << "--------------------------------------------" << endl;
		}

};

int main() {
	Stack s1;
	Stack s2;
	Stack s3;
	Queue q1;
	Queue q2;
	Queue q3;

	//Insert
	//100 stack
	cout << "--------------------------------" << endl;
	cout << "Inserting 100 random numbers into stack 1..." << endl;
	auto startTimeS1 = high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		int randN = rand() % 5000;
		s1.insert(randN);
	}
	auto endTimeS1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(endTimeS1 - startTimeS1);
	
	//1000 stack
	cout << "--------------------------------" << endl;
	cout << "Inserting 1000 random numbers into stack 2..." << endl;
	auto startTimeS2 = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		int randN = rand() % 5000;
		s2.insert(randN);
	}
	auto endTimeS2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(endTimeS2 - startTimeS2);
	
	//10000 stack
	cout << "--------------------------------" << endl;
	cout << "Inserting 10000 random numbers into stack 3..." << endl;
	auto startTimeS3 = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		int randN = rand() % 5000;
		s3.insert(randN);
	}
	auto endTimeS3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(endTimeS3 - startTimeS3);
	
	//Delete
	//100 stacks
	cout << "--------------------------------" << endl;
	cout << "Deleting 100 numbers from stack 1..." << endl;
	auto startTimeS1remove = high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		s1.remove();
	}
	auto endTimeS1remove = high_resolution_clock::now();
	auto duration1remove = duration_cast<microseconds>(endTimeS1remove - startTimeS1remove);
	
	//1000 stacks
	cout << "--------------------------------" << endl;
	cout << "Deleting 1000 numbers from stack 1..." << endl;
	auto startTimeS2remove = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		s2.remove();
	}
	auto endTimeS2remove = high_resolution_clock::now();
	auto duration2remove = duration_cast<microseconds>(endTimeS2remove - startTimeS2remove);
	
	//10000 stacks
	cout << "--------------------------------" << endl;
	cout << "Deleting 10000 numbers from stack 1..." << endl;
	auto startTimeS3remove = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		s3.remove();
	}
	auto endTimeS3remove = high_resolution_clock::now();
	auto duration3remove = duration_cast<microseconds>(endTimeS3remove - startTimeS3remove);

	//Insert
	//100 queue
	cout << "--------------------------------" << endl;
	cout << "Inserting 100 random numbers into Queue 1..." << endl;
	auto startTimeS1q = high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		int randN = rand() % 5000;
		q1.insert(randN);
	}
	auto endTimeS1q = high_resolution_clock::now();
	auto duration1q = duration_cast<microseconds>(endTimeS1q - startTimeS1q);

	//1000 queue
	cout << "--------------------------------" << endl;
	cout << "Inserting 1000 random numbers into Queue 2..." << endl;
	auto startTimeS2q = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		int randN = rand() % 5000;
		q2.insert(randN);
	}
	auto endTimeS2q = high_resolution_clock::now();
	auto duration2q = duration_cast<microseconds>(endTimeS2q - startTimeS2q);

	//10000 queue
	cout << "--------------------------------" << endl;
	cout << "Inserting 10000 random numbers into Queue 3..." << endl;
	auto startTimeS3q = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		int randN = rand() % 5000;
		q3.insert(randN);
	}
	auto endTimeS3q = high_resolution_clock::now();
	auto duration3q = duration_cast<microseconds>(endTimeS3q - startTimeS3q);

	//Delete
	//100 queue
	cout << "--------------------------------" << endl;
	cout << "Deleting 100 numbers from Queue 1..." << endl;
	auto startTimeQ1remove = high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		q1.remove();
	}
	auto endTimeQ1remove = high_resolution_clock::now();
	auto durationQ1remove = duration_cast<microseconds>(endTimeQ1remove - startTimeQ1remove);

	//1000 queue
	cout << "--------------------------------" << endl;
	cout << "Deleting 1000 numbers from Queue 2..." << endl;
	auto startTimeQ2remove = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		q2.remove();
	}
	auto endTimeQ2remove = high_resolution_clock::now();
	auto durationQ2remove = duration_cast<microseconds>(endTimeQ2remove - startTimeQ2remove);

	//10000 queue
	cout << "--------------------------------" << endl;
	cout << "Deleting 10000 numbers from Queue 3..." << endl;
	auto startTimeQ3remove = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		q3.remove();
	}
	auto endTimeQ3remove = high_resolution_clock::now();
	auto durationQ3remove = duration_cast<microseconds>(endTimeQ3remove - startTimeQ3remove);


	//Table output
	cout << left << setw(10) << " " << setw(20) << "Insert" << setw(10) << " " << "Delete" << endl;
	cout << left << setw(10) << "Method" << setw(10) << "100" << setw(10) << "1000" << setw(10) << "10000" << setw(10) << "100" << setw(10) << "1000" << setw(10) << "10000" << endl;
	//Output for Stack inserting
	cout << left << setw(10) << "Stack" << setw(10) << duration1.count() << setw(10) << duration2.count() << setw(10) << duration3.count() << setw(10) << duration1remove.count() << setw(10) << duration2remove.count() << setw(10) << duration3remove.count() << endl;
	//Output for Queue deleting
	cout << left << setw(10) << "Queue" << setw(10) << duration1q.count() << setw(10) << duration2q.count() << setw(10) << duration3q.count() << setw(10) << durationQ1remove.count() << setw(10) << durationQ2remove.count() << setw(10) << durationQ3remove.count() << endl;
	return 0;
}