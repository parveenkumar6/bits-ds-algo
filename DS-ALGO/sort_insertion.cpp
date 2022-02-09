#include <iostream>
#include <ios>

using namespace std;

class sort_insertion
{
public:
	void insertionSort(int A[], int size) {
		for (int i = 1; i < size; i++) {
			int j = i - 1;
			while (A[i] < A[j]) {
				j = j - 1;
				if (j < 0)
					break;
			}
			int temp = A[i];
			int k = i - 1;
			while (k >= j + 1) {
				A[k + 1] = A[k];
				k = k - 1;
			}
			A[j + 1] = temp;
			cout << "Pass " << i << " : ";
			printArr(A, size);
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
	sort_insertion b;
	//int a[] = {1, 4, 7, 5, 2, 3};
	//int a[] = {7, 5, 4, 3, 2, 1};
	int a[] = {6, 3, 8, 1, 13, 7, 5};
	int n = sizeof(a) / sizeof(int);
	cout << "Input : ";
	b.printArr(a, n);
	b.insertionSort(a, n);
	cout << "Final OutPut : ";
	b.printArr(a, n);

}