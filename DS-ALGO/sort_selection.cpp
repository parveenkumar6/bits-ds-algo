#include <iostream>
#include <ios>

using namespace std;

class sort_selection
{
public:
	void selectionSort(int A[], int n) {
		for (int i = 1; i <= n - 1; i++) {
			int currentMin = A[0];
			int minIndex = 0;
			for (int j = 1 ; j <= n - i; j++) {
				if (A[j] < currentMin) {
					currentMin = A[j];
					minIndex = j;
				}
			}
			cout << "Pass: " << i << " min indx " << minIndex << " min value " << A[minIndex] << " --> ";
			swap(A[minIndex], A[n - i]);
			printArr(A, n);
		}

	}
	void printArr(int A[], int size) {
		for (int i = 0; i < size; i++) {
			cout << A[i] << ", ";
		}
		cout << "\n";
	}

};

int main() {
#ifndef ONLINE_JUDGE
	//Get input from input.in file
	//Write output to output.in file
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif

	sort_selection b;
	int a[] = {1, 4, 7, 5, 2, 3};
	//int a[] = {7, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	cout << "Input : ";
	b.printArr(a, n);
	b.selectionSort(a, n);
	cout << "Final OutPut : ";
	b.printArr(a, n);

}