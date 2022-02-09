#include <iostream>
#include <ios>

using namespace std;

class sort_bubble
{
public:
	void bubbleSort(int A[], int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (A[j] > A[j + 1]) {
					cout << "Pass: " << i << " Swap indx " << j << " & " << j + 1 << " :- ";
					swap(A[j], A[j + 1]);
					printArr(A, n);
				}
			}
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
	/*in >> "Bubble Sort";
	int n, inp[];
	cin >> n;
	while (n--) {
		cin >> inp[n];
	}*/
	sort_bubble b;
	//int a[] = {1, 4, 7, 2, 5, 3};
	int a[] = {7, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	cout << "Input : ";
	b.printArr(a, n);
	b.bubbleSort(a, n);
	cout << "Final OutPut : ";
	b.printArr(a, n);
}