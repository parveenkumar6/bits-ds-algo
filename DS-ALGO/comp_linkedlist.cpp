#include <ios>
#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};
//Build a List
struct Node* buildOneTwoThree() {
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (Node*)malloc(sizeof(struct Node));
	second = (Node*)malloc(sizeof(struct Node));
	third = (Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}

//Before - Return a Node before p Node.
struct Node* before(struct Node* p, struct Node* head) {
	struct Node* currentNode = head;
	if (p == NULL || p == head)
		return NULL;
	while (currentNode->next != p)
		currentNode = currentNode->next;
	return currentNode;
}
//After - Return a Node after p Node.
struct Node* after(struct Node* p) {
	return p->next;
}

//while(currentNode->next != NULL)
//Return the Last Node.
struct Node* last(Node* head) {
	struct Node* currentNode;
	currentNode = head;
	if (head == NULL)
		return NULL;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;
	return currentNode;
}
//Return data/Value of Node p
int getDataAt(struct Node* p) {
	return p->data;
}
int getDataAtPos(int k, struct Node* head) {
	int  i = 1;
	struct Node* currentNode = head;
	while (i < k && currentNode->next != NULL) {
		currentNode = currentNode->next;
		i = i + 1;
	}
	if (i == k) return currentNode->data;
	else return 0;
}

int size_len(struct Node* head) {
	int s = 0;
	struct Node* currentNode = head;
	while (currentNode != NULL) {
		currentNode = currentNode->next;
		s = s + 1;
	}
	return s;
}
//Insert Before Node P (New Node with data key)
void insert_before(struct Node* p, int key, struct Node* head) {
	struct Node* newNode;
	newNode = (Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->next = p;
	struct Node* currentNode = head;
	while (currentNode->next != p)
		currentNode = currentNode->next;
	currentNode->next = newNode;
}

//Insert After Node P(new Node with data key)
void insert_after(struct Node* p, int key, struct Node* head) {
	struct Node* newNode;
	newNode = (Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->next = p->next;
	p->next = newNode;
}
//Insert At the begining
void insert_atbegining(struct Node* head, int key) {
	struct Node* newNode;
	newNode = (Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->next = head;
	head = newNode;
}
//Insert at the end of List
void insert_atend(struct Node* head, int key) {
	struct Node* newNode;
	newNode = (Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->next = NULL;
	if (head == NULL) {
		head = newNode;
	} else {
		struct Node* currentNode = head;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	//Get input from input.in file
	//Write output to output.in file
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Node* inputNode = buildOneTwoThree();

	int size = size_len(inputNode);
	cout << "Size : " << size << endl;

	cout << "Get Data at Postition(2) : ";
	cout << getDataAtPos(2, inputNode) << endl;

	cout << "Get Data at Head : ";
	cout << getDataAt(inputNode) << endl;

	cout << "Get Last Node : " << last(inputNode)->data << endl;
	cout << "Linked List" << endl;

	cout << "Insert Befor Node 2 : ";
	insert_before(inputNode->next, 4, inputNode);
	cout << inputNode->next->data << endl;

	cout << "Insert After Node 1 : ";
	insert_after(inputNode, 10, inputNode);
	cout << inputNode->next->data << endl;
	return 0;
}

