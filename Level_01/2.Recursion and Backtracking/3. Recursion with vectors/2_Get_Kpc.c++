/*1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map :
    0 -> .;
    1 -> abc
    2 -> def
    3 -> ghi
    4 -> jkl
    5 -> mno
    6 -> pqrs
    7 -> tu
    8 -> vwx
    9 -> yz
3. Complete the body of getKPC function - without changing signature - to get the list of all words that could be produced by the keys in str.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A string str

Output Format
Contents of the arraylist containing words as shown in sample output

Constraints
0 <= str.length <= 10
str contains numbers only

Sample Input
78

Sample Output
[tv, tw, tx, uv, uw, ux]*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> keypad = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
vector<string> getKPC(string s) {
  if (s.size() == 0) {
    vector<string> empty_ans;
    empty_ans.push_back("");
    return empty_ans;
  }
  string new_question = s.substr(1, s.size() - 1);
  vector<string> small_ans = getKPC(new_question);
  vector<string> ans;
  char ch = s.at(0);
  int idx = ch - '0';
  for (int i = 0; i < keypad[idx].size(); i++) {
    char c = keypad[idx].at(i);
    for (int j = 0; j < small_ans.size(); j++) {
      string str = small_ans[j];
      string final = c + str;
      ans.push_back(final);
    }
  }
  return ans;
}


int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;
  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}