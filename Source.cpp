#include<iostream>
#include<iomanip>

using namespace std;
typedef int Info;

struct Node
{
	Node* next;
	Info info;
};

Node* createNode(int info) 
{
	Node* node = new Node;
	node->info = info;
	node->next = nullptr;
	return node;
}

void insert(Node*& head, int data, Node* current = nullptr) {
	if (head == nullptr) {
		head = createNode(data);
		head->next = head;
		return;
	}
	if (current == nullptr) {
		current = head;
	}
	if (current->next == head) {
		Node* node = createNode(data);
		current->next = node;
		node->next = head;
		return;
	}
	insert(head, data, current->next);
}


void Print(Node* head, Node* current = nullptr) {
	if (head == nullptr) {
		cout << "List is empty." << endl;
		return;
	}
	if (current == nullptr) {
		current = head;
	}
	cout << current->info << " ";
	if (current->next != head) {
		Print(head, current->next);
	}
	else {
		cout << endl;
	}
}

int sumOfEvenElements(Node* head, Node* curr = nullptr, int sum = 0)
{
	if (curr == nullptr) {
		curr = head;
	}
	if (curr->info % 2 == 0) {
		sum += curr->info;
	}
	if (curr->next != head) {
		return sumOfEvenElements(head, curr->next, sum);
	}
	return sum;
}

void deleteList(Node*& head, Node* current = nullptr) {
	if (head != nullptr) {
		if (current == nullptr) {
			current = head;
		}
		Node* next = current->next;
		delete current;
		if (next != head) {
			deleteList(head, next);
		}
		else {
			head = nullptr;
		}
	}
}


int main()
{
	Node* L = NULL;

	insert(L, 23);
	insert(L, 18);
	insert(L, 45);
	insert(L, 27);
	insert(L, 34);
	insert(L, 57);
	insert(L, 64);

	cout << "List: ";
	Print(L);
	cout << endl;

	cout << "Sum of even elements: " << sumOfEvenElements(L) << endl;
	deleteList(L);

	return 0;
}
