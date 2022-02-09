#include <ios>
#include <iostream>

using namespace std;

template <class T>
void Print(T& v, int n, string s) {

}

class sort_merge
{
public:
	int count = 0;
	int count_rec = 0;
	void merge(int A[], int  start, int mid , int end) {
		//cout << "Called Merge " << count++ << "\n";
		cout << "Array Before Merge " << count << " --> ";
		printArr(A, sizeof(A) / sizeof(int));
		cout << "Start : " << start << " End: " << end;
		cout << " Mid : " << mid << " \n";
		int i = start;
		int k = start;
		int j = mid + 1;

		int B[end + 1];

		while (i <= mid && j <= end) {
			if (A[i] < A[j]) {
				B[k++] = A[i++];
			} else {
				B[k++] = A[j++];
			}
		}
		while (i <= mid) {
			B[k++] = A[i++];
		}
		while (j <= end) {
			B[k++] = A[j++];
		}
		for (int i = start; i <= end; i++) {
			A[i] = B[i];
		}
		cout << "Array After Merge " << count << " --> ";
		printArr(B, sizeof(B) / sizeof(int));
		cout << "End Merge " << count++ << endl;
	}

	void mergeSort(int A[], int  start, int  end) {
		cout << "MergeSort Call: " << count_rec++;
		cout << "||Start: " << start << " End: " << end << " \n";

		if (start < end) {
			int mid = start + (end - start) / 2;
			//cout << "Called Recursion " << count_rec++ << " Mid Value " << mid << endl;
			mergeSort(A, start, mid);
			mergeSort(A, mid + 1, end);
			merge(A, start, mid, end);
			printArrIND(A, start, mid);
		}
	}
	void printArr(int A[], int size) {
		for (int i = 0; i < size; i++) {
			cout << A[i] << ", ";
		}
		cout << "\n";
	}
	void printArrIND(int A[], int s, int e) {
		for (int i = s; i < e; i++) {
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
	sort_merge b;
	int a[] = {85, 24, 63, 45, 17, 31, 96, 50, 33, 12, 22, 23};
	//int a[] = {7, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	cout << "Input : ";
	b.printArr(a, n);
	b.mergeSort(a, 0, n - 1);
	cout << "Final OutPut : ";
	b.printArr(a, n);

}