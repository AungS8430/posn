#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	stack<char> brackets;
	string expression;
	cin >> expression;
	for (char character : expression) {
		if (character == '{' || character == '[' || character == '(') brackets.push(character);
		if (brackets.empty()) {
			cout << "Right is more than left";
			return 1;
		}
		else if (character == '}' || character == ']' || character == ')') {
			if ((character == '}' && brackets.top() == '{') || (character == ']' && brackets.top() == '[') || (character == ')' && brackets.top() == '(')) brackets.pop();
			else {
				cout << "Right and left are not the same type";
				return 1;
			}
		}
	}
	if (!brackets.empty()) {
		cout << "Left is more than right";
		return 0;
	}
	cout << "Correct";
	return 0;
}