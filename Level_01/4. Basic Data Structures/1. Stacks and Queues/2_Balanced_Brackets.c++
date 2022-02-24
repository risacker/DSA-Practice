/*1. You are given a string exp representing an expression.
2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

e.g.
[(a + b) + {(c + d) * (e / f)}] -> true
[(a + b) + {(c + d) * (e / f)]} -> false
[(a + b) + {(c + d) * (e / f)} -> false
([(a + b) + {(c + d) * (e / f)}] -> false

Constraints
0 <= str.length <= 100

Format
Input
A string str

Output
true or false

Example
Sample Input
[(a + b) + {(c + d) * (e / f)}]

Sample Output
true*/

#include <bits/stdc++.h>
using namespace std;
int main()
{ 
  string s;
  getline(cin,s);
  stack<char>st;
  for(int i=0;i<s.size();i++)
  {
      char ch=s[i];
      if(ch=='('||ch=='{'||ch=='[')
      {
          st.push(ch);
      }else
      if(ch==')')
      {
          if(st.size()==0||st.top()!='(')
          {
              cout<<"false";return 0;   
          }else
          {
              st.pop();
          }
      }else
      if(ch=='}')
      {
          if(st.size()==0||st.top()!='{')
          {
              cout<<"false";return 0;
          }
          else
          {
              st.pop();
          }
      }
      else if(ch==']')
      {
          if(st.size()==0||st.top()!='[')
          {
              cout<<"false";return 0;
          }else
          {
              st.pop();
          }
      }
  }
  if(st.size()==0)
  {
      cout<<"true";
  }
  else
  {
      cout<<"false";
  }
   return 0;
}