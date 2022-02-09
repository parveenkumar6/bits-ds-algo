#include <iostream>
#include <ios>

using namespace std;

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

	int n;
	int out = 12345;
	cin >> n;
	cout << n << out << "\n";
	return 0;

}