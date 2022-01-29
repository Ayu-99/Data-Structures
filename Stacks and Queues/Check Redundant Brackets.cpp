/* C++ Program to check whether valid
expression is redundant or not*/
#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string& str)
{
	stack<char> st;

	for (auto& ch : str) {

		if (ch == ')') {
			char top = st.top();
			st.pop();

			bool flag = true; //there are redundant brackets

			while (!st.empty() and top != '(') {

				// Check for operators in expression
				if (top == '+' || top == '-' ||
					top == '*' || top == '/')
					flag = false;

				top = st.top();
				st.pop();
			}

			if (flag == true)
				return true; // there are redundant brackets
		}

		else
			st.push(ch); 
	}
	return false;
}

void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	string str = "a+(b)+c";
	findRedundant(str);

	return 0;
}
