#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string str) {
    stack<char> stk;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stk.empty()) {
                return false;
            } else if (c == ')' && stk.top() == '(') {
                stk.pop();
            } else if (c == '}' && stk.top() == '{') {
                stk.pop();
            } else if (c == ']' && stk.top() == '[') {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string str;
    cout << "Enter a string with parentheses: ";
    getline(cin, str);
    if (isValid(str)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }
    return 0;
}
