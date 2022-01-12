/*1. You are given a string that contains only lowercase and uppercase alphabets. 
2. You have to toggle the case of every character of the given string.

Input Format
A String

Output Format
A String

Constraints
1 <= length of string <= 1000

Sample Input
pepCODinG

Sample Output
PEPcodINg*/

#include<iostream>
#include<string>
using namespace std;

void togglecase(string str)
{
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = (char)('A' - 'a' + str[i]);
    }
    else {
      str[i] = (char)('a' - 'A' + str[i]);
    }
  }
  cout << str;
}

int main() {
  string str;
  getline(cin, str);
  togglecase(str);
  return 0;
}