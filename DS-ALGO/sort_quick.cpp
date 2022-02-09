#include <iostream>
#include <ios>

using namespace std;

class sort_quick
{
public:
	int partition(int A[], int low, int high) {
		printArr(A, high + 1);
		int pivot = A[high];
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (A[j] < pivot) {
				i++;
				swap(A[i], A[j]);
				cout << "Swaped : " << A[i] << " : " << A[j] <<  "\n";
			}
		}
		//printArr(A, high);
		swap(A[i + 1], A[high]);
		cout << "Second Swaped : " << A[i + 1] << " : " << A[high] <<  "\n";
		printArr(A, high + 1);

		return (i + 1);
	}
	void quickSort(int A[], int low, int high) {
		if (low < high) {
			int p = partition(A, low, high);
			cout << "Pivot Value : " << p << " A[p]: " << A[p]  << " low :" << low << " high: " << high << endl;
			cout << endl;
			quickSort(A, low, p - 1);
			quickSort(A, p + 1, high);
			//cout << "Array After Sort : ";
			//printArr(A, sizeof(A) / sizeof(int));
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
	sort_quick b;
	int a[] = {85, 24, 63, 45, 17, 31, 96, 50};
	//int a[] = {7, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	cout << "Input : ";
	b.printArr(a, n);
	b.quickSort(a, 0, n - 1);
	cout << "Final OutPut : ";
	b.printArr(a, n);

}