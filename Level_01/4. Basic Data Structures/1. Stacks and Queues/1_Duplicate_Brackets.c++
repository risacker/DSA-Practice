/*1. You are given a string exp representing an expression.
2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
3. But, some of the pair of brackets maybe extra/needless. 
4. You are required to print true if you detect extra brackets and false otherwise.

e.g.'
((a + b) + (c + d)) -> false
(a + b) + ((c + d)) -> true

Constraints
0 <= str.length <= 100

Format
Input
A string str

Output
true or false

Example
Sample Input
(a + b) + ((c + d))

Sample Output
true*/

#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  string s;
  getline(cin,s);
  string flag="false";
  stack<char>st;
  for(int i=0;i<s.size();i++)
  {
      char ch=s.at(i);  
      if(ch==')'){
          if(st.top()=='(')
          {
              flag ="true";
          }
          else
          {
              while(st.top()!='(')
              {
                  st.pop();
              }
              st.pop();
          }
      }
      else
      {
          st.push(ch);
      }
  }
  cout<<flag;
  return 0;
}

/*Time Complexity :O(2*n) = O(n)
SPACE COMPLEXITY : O(n)*/