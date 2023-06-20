#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
string prefixToInfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isOperator(ch)) {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string expression = "(" + operand1 + ch + operand2 + ")";
            st.push(expression);
        } else {
            st.push(string(1, ch));
        }
    }
    return st.top();
}
int main() {
    string prefixExpression = "-/ab*+bcd";
    cout << "Prefix expression: " << prefixExpression << endl;
    string infixExpression = prefixToInfix(prefixExpression);
    cout << "Infix expression: " << infixExpression << endl;
    return 0;
}

