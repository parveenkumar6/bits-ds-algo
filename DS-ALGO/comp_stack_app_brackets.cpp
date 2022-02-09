#include <stack>
#include <iostream>
#include <ios>

using namespace std;

class BracketProblem {
public:
	bool bracketCheck(const string& s) {
		stack<char> st;
		int i, n;
		char ch, tmp;
		n = s.size();
		for (i = 0; i < n; i++) {
			ch = s[i];
			if ((ch == '(') || (ch == '{') || (ch == '[')) {
				st.push(ch);
				cout << st.size();
			} else if (ch == ')') {
				if (st.empty())
					return false;
				tmp = st.top();
				st.pop();
				cout << st.size();
				if (tmp != '(')
					return false;
			} else if (ch == '}') {
				if (st.empty())
					return false;
				tmp = st.top();
				st.pop();
				cout << st.size();
				if (tmp != '{')
					return false;
			} else if (ch == ']') {
				if (st.empty())
					return false;
				tmp = st.top();
				st.pop();
				cout << st.size();
				if (tmp != '[')
					return false;
			}
		}
		if (!st.empty()) {
			cout << st.size();
			cout << endl;
			return false;
		}
		cout << endl;
		return true;

	}

};

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

	BracketProblem b;
	string input = "([]){(){}}";
	cout << "Input : " << input << endl;
	bool o = b.bracketCheck(input);
	cout << "Output : " << o << endl;

	input = "([)])";
	cout << "Input : " << input << endl;
	o = b.bracketCheck(input);
	cout << "Output : " << o << endl;

	input = "([]";
	cout << "Input : " << input << endl;
	o = b.bracketCheck(input);
	cout << "Output : " << o << endl;
	input = "([)";
	cout << "Input : " << input << endl;
	o = b.bracketCheck(input);
	cout << "Output : " << o << endl;
}