#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int evalPostfix(string exp) {
	stack<int> st;
	for (char c : exp) {
		if (c >= '0' && c <= '9') {
			st.push(c - '0');
		} else {
			int b = st.top();
			st.pop();

			int a = st.top();
			st.pop();

			if (c == '+') {
				st.push(a + b);
				cout << "Push : (a + b) " << a << "+" << b << endl;
			} else if (c == '-') {
				st.push(a - b);
				cout << "Push : (a - b) " << a << "-" << b << endl;
			} else if (c == '*') {
				st.push(a * b);
				cout << "Push : (a * b) " << a << "*" << b << endl;
			} else if (c == '/') {
				st.push(a / b);
				cout << "Push : (a / b) " << a << "/" << b << endl;
			} else if (c == '^') {
				st.push(pow(a, b));
				cout << "Push : (a ^ b) " << a << "^" << b << endl;
			}
		}
	}
	return st.top();
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

	string exp = "123*+4-";
	cout << evalPostfix(exp) << endl;
}