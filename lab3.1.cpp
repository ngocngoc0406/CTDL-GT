#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_operator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
if (c == '+' || c == '-') {
return 1;
} else if (c == '*' || c == '/') {
return 2;
} else {
return 0;
}
}

string infix_to_postfix(string infix) {
stack<char> op_stack;
string postfix = "";

for (int i = 0; i < infix.length(); i++) {
if (isalnum(infix[i])) {
postfix += infix[i];
} else if (is_operator(infix[i])) {
while (!op_stack.empty() && precedence(op_stack.top()) >= precedence(infix[i])) {
postfix += op_stack.top();
op_stack.pop();
}
op_stack.push(infix[i]);
} else if (infix[i] == '(') {
op_stack.push(infix[i]);
} else if (infix[i] == ')') {
while (!op_stack.empty() && op_stack.top() != '(') {
postfix += op_stack.top();
op_stack.pop();
}
op_stack.pop();
}
}

while (!op_stack.empty()) {
postfix += op_stack.top();
op_stack.pop();
}

return postfix;
}

int evaluate_postfix(string postfix) {
stack<int> num_stack;

for (int i = 0; i < postfix.length(); i++) {
if (isdigit(postfix[i])) {
num_stack.push(postfix[i] - '0');
} else if (is_operator(postfix[i])) {
int operand2 = num_stack.top();
num_stack.pop();
int operand1 = num_stack.top();
num_stack.pop();
switch (postfix[i]) {
case '+':
num_stack.push(operand1 + operand2);
break;
case '-':
num_stack.push(operand1 - operand2);
break;
case '*':
num_stack.push(operand1 * operand2);
break;
case '/':
num_stack.push(operand1 / operand2);
break;
}
}
}

return num_stack.top();
}

int main() {
string infix = "(7+3)*10";
string postfix = infix_to_postfix(infix);
cout << "Postfix: " << postfix << endl;
int result = evaluate_postfix(postfix);
cout << "Result: " << result << endl;
return 0;
}

