#include <iostream>
#include <ios>
//#include <math.h>
#include <bits/stdc++.h>
#define INT_RANGE 9
#define CHAR_RANGE 255

using namespace std;

class sort_count
{
public:
	int maxValue(int A[], int n) {
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (A[i] > max) {
				max = A[i];
			}
		}
		return max;
	}

	void countSort(int A[], int size) {
		int max = maxValue(A, size);
		int len = max + 1;
		int* frequency = new int [max + 1];
		for (int i = 0; i < size; i++) {
			frequency[A[i]]++;
		}
		for (int i = 0; i < len; i++) {
			cout << "frequency : " << frequency[i] << ", ";
		}
		int i = 0;
		int j = 0;
		while (j < max + 1) {
			if (frequency[j] > 0) {
				A[i++] = j;
				frequency[j]--;
			} else {
				j++;
			}
		}

		cout << endl;
		delete[] frequency;
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
	sort_count b;
	//int a[] = {6, 1, 8, 3, 7, 2, 3, 9, 7};
	int a[] = {26, 23, 25, 22, 23, 24, 21, 24, 23, 25, 26, 28, 29, 28, 26};
	int n = sizeof(a) / sizeof(int);
	cout << "Input : ";
	b.printArr(a, n);
	b.countSort(a, n);
	cout << "Final OutPut : ";
	b.printArr(a, n);
}