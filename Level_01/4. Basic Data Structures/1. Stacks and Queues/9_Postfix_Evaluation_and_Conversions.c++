/*1. You are given a postfix expression.
2. You are required to evaluate it and print it's value.
3. You are required to convert it to infix and print it.
4. You are required to convert it to prefix and print it.

Note -> Use brackets in infix expression for indicating precedence. Check sample input output for more details.

Constraints
1. Expression is a valid postfix expression
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
264*8/+3-

Sample Output
2
((2+((6*4)/8))-3)
-+2/*6483

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
  stack<int> vs;
  stack<string> is;
  stack<string> ps;
  for (int i = 0; i < exp.length(); i++) {
    char ch = exp[i];
    if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
      string s = string(1, ch);     
      int v2 = vs.top();
      vs.pop();
      int v1 = vs.top();
      vs.pop();
      int val = operation(v1, v2, ch);
      vs.push(val);
      string inv2 = is.top();
      is.pop();
      string inv1 = is.top();
      is.pop();
      string inv = "(" + inv1 + s + inv2 + ")";
      is.push(inv);
      string postv2 = ps.top();
      ps.pop();
      string postv1 = ps.top();
      ps.pop();
      string postv = s + postv1 + postv2;
      ps.push(postv);      
    } 
    else {
      vs.push(ch - '0');
      string s = string(1, ch);
      is.push(s);
      ps.push(s);
    }
  }
  cout << vs.top() << endl;
  vs.pop();
  cout << is.top() << endl;
  is.pop();
  cout << ps.top() << endl;
  ps.pop();
  return 0;
}

/*Time Complexity : O(n)

This is because a single for loop is used in the program and the rest of the functions of stack use O(1) time.

SPACE COMPLEXITY : O(n)

We use a stack of space n to run the program hence space complexity is of order n.*/