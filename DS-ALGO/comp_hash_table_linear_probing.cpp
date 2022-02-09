#include <bits/stdc++.h>
#define SIZE 17

using namespace std;

int hashF(int key) {
	return (key + 2) % SIZE;
}
int linearProbe(int HT[], int key) {
	int index = hashF(key);
	int i = 0;
	while (HT[(index + i) % SIZE] != 0)
		i++;
	return (index + i) % SIZE;
}
void insertKey(int HT[], int key) {
	int index = hashF(key);
	if (HT[index] != 0)
		index = linearProbe(HT, key);
	HT[index] = key;
}

int find(int HT[], int key) {
	int index = hashF(key);
	int i  = 0;
	while (HT[(index + i) % SIZE] != key) {
		i++;
		if (i > SIZE) {
			cout << "Not Found" << endl;
			return 0;
		}
	}
	return (index + i) % SIZE;
}

void printArr(int A[], int size) {
	for (int i = 0; i < size; i++) {
		cout << i << " -- > ";
		cout << A[i] << "";
		cout << endl;
	}
	cout << "\n";
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

	int HT[SIZE] = {0};
	//49, 38, 94, 89, 13, 6, 56, 98, 166, 79
	insertKey(HT, 49);
	insertKey(HT, 38);
	insertKey(HT, 94);
	insertKey(HT, 89);
	insertKey(HT, 13);
	insertKey(HT, 6);
	insertKey(HT, 56);
	insertKey(HT, 98);
	insertKey(HT, 166);
	insertKey(HT, 79);
	printArr(HT, SIZE);

	cout << find(HT, 68) << endl;
	//return 0;
}
