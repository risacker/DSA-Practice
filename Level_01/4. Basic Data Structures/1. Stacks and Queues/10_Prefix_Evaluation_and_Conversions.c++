/*1. You are given a prefix expression.
2. You are required to evaluate it and print it's value.
3. You are required to convert it to infix and print it.
4. You are required to convert it to postfix and print it.

Note -> Use brackets in infix expression for indicating precedence. Check sample input output for more details.

Constraints
1. Expression is a valid prefix expression
2. The only operators used are +, -, *, /
3. All operands are single digit numbers.

Format
Input
Input is managed for you

Output
value, a number
infix
prefix

Example
Sample Input
-+2/*6483

Sample Output
2
((2+((6*4)/8))-3)
264*8/+3-

*/

#include <bits/stdc++.h>
using namespace std;

int operation(int v1, int v2, char op) {
  if (op == '+') {
    return v1 + v2;
  } 
  else if (op == '-') {
    return v1 - v2;
  } 
  else if (op == '*') {
    return v1 * v2;
  } 
  else if (op == '/') {
    return v1 / v2;
  } 
  else {
    return 0;
  }
}

int main() {
  string exp;
  cin >> exp;
  stack<int> vstack;
  stack<string> infix;
  stack<string> postfix;
  for (int i = exp.length() - 1; i >= 0; i--) {
    char ch = exp[i];
    if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
      stringstream ss;
      string s;
      ss << ch;
      ss >> s;
      int v1 = vstack.top();
      vstack.pop();
      int v2 = vstack.top();
      vstack.pop();
      int val = operation(v1, v2, ch);
      vstack.push(val);
      string inv1 = infix.top();
      infix.pop();
      string inv2 = infix.top();
      infix.pop();
      string inv = "(" + inv1 + s + inv2 + ")";
      infix.push(inv);
      string postv1 = postfix.top();
      postfix.pop();
      string postv2 = postfix.top();
      postfix.pop();
      string postv = postv1 + postv2 + s;
      postfix.push(postv);
    } 
    else {
      vstack.push(ch - '0');
      stringstream ss;
      string s;
      ss << ch;
      ss >> s;
      infix.push(s);
      postfix.push(s);
    }
  }
  cout << vstack.top() << endl;
  vstack.pop();
  cout << infix.top() << endl;
  vstack.pop();
  cout << postfix.top() << endl;
  vstack.pop();
}

/*Time Complexity : O(n)

This is because a single for loop is used in the program and the rest of the functions of stack use O(1) time.

SPACE COMPLEXITY : O(n)

We use a stack of space n to run the program hence space complexity is of order n.*/