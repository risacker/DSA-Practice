/*1. You are given a string str.
2. You are required to find the character with maximum frequency.

Constraints
0 < str.length() <= 100
There will be a single character with highest frequency

Format
Input
A string str

Output
The character with highest frequency

Example
Sample Input
zmszeqxllzvheqwrofgcuntypejcxovtaqbnqyqlmrwitc

Sample Output
q*/

#include <bits/stdc++.h>
using namespace std;
int main(){
  string str;
  cin>>str;
  unordered_map<char, int> fmap;
  for(int i = 0; i < str.size(); i++){
    fmap[str[i]]++;
  }
  int maxcount = 0;
  char ch;
  for(pair<char, int>  m : fmap){
    if (m.second > maxcount){
      maxcount = m.second;
      ch = m.first;
    }
  }
  cout<<ch;
}

/*Time Complexity: O(n)

Space Complexity: O(n)

O(n) where n is the number of entities added to the hashmap.*/