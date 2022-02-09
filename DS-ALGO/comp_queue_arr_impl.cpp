#include <iostream>
#include <cstdlib>
using namespace std;

// Define the default capacity of the queue
#define SIZE 17

// A class to represent a queue
template <class X>
class queue
{
	X *arr;         // array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;      // front points to the front element in the queue (if any)
	int rear;       // rear points to the last element in the queue
	int count;      // current size of the queue

public:
	queue(int size = SIZE);     // constructor

	void dequeue();
	void enqueue(X x);
	X peek();
	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize a queue
template <class X>
queue<X>::queue(int size)
{
	arr = new X[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Utility function to dequeue the front element
template <class X>
void queue<X>::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "Underflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	cout << "Front : " << front << " ";

	cout << "Removing " << arr[front] << " At Pos : " << front;
	front = (front + 1) % capacity;
	cout << "Front2 : " << front << " ";
	count--;
	cout << " Size : " << size() << endl;
}

// Utility function to add an item to the queue
template <class X>
void queue<X>::enqueue(X item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "Overflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Rear : " << rear << " ";
	rear = (rear + 1) % capacity;
	cout << " Rear2  : " << rear << " ";
	cout << "Inserting " << item << " At Pos : " << rear;
	arr[rear] = item;
	count++;
	cout << " Size : " << size() << endl;
}

// Utility function to return the front element of the queue
template <class X>
X queue<X>::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

// Utility function to return the size of the queue
template <class X>
int queue<X>::size() {
	return count;
}

// Utility function to check if the queue is empty or not
template <class X>
bool queue<X>::isEmpty() {
	return (size() == 0);
}

// Utility function to check if the queue is full or not
template <class X>
bool queue<X>::isFull() {
	return (size() == capacity);
}

int main()
{
#ifndef ONLINE_JUDGE
	//Get input from input.in file
	//Write output to output.in file
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<int> q(5);
	q.enqueue(31);
	q.enqueue(53);
	q.enqueue(75);

	q.dequeue();
	q.dequeue();

	q.enqueue(19);
	q.enqueue(42);

	q.dequeue();

	q.enqueue(64);

	q.dequeue();

	q.enqueue(86);



	/* create a queue of capacity 4
	queue<int> q(4);
	q.enqueue(8);
	q.enqueue(6);
	q.enqueue(4);

	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.enqueue(2);
	q.enqueue(7);
	q.enqueue(5);
	q.enqueue(3);

	q.dequeue();
	q.dequeue();

	q.enqueue(1);
	q.dequeue();
	*/
	/*
	q.enqueue(44);
	q.enqueue(52);
	q.enqueue(69);
	q.enqueue(72);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	//cout << "SIZE : " << q.size() << endl;
	q.enqueue(37);
	q.dequeue();
	q.enqueue(28);
	q.enqueue(13);
	q.dequeue();
	q.dequeue();
	*/
	return 0;
}