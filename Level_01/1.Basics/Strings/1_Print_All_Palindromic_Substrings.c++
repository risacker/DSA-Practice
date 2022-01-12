/*1. You are given a string. 
2. You have to print all palindromic substrings of the given string.

Input Format
A String

Output Format
All palindromic substrings(one in a line).
First, all palindromic substrings starting from first character of string will be printed, 
then from second character and so on.

Constraints
1 <= length of string <= 500

Sample Input
abcc

Sample Output
a
b
c
cc
c*/

#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(string str)
{
  int lo = 0;
  int hi = str.length() - 1;
  while (lo < hi)
  {
    if (str[lo] != str[hi])
      return false;

    lo++;
    hi--;
  }
  return true;
}

void printallpalindrome(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    for (int len = 1; i + len <= str.length(); len++)
    {
      string s = str.substr(i, len);
      if (isPalindrome(s))
        cout << s << endl;
    }
  }
}

int main()
{
  string str;
  getline(cin, str);
  printallpalindrome(str);
  return 0;
}

/*Time Complexity : O(n^3)

We are running the outer loop from 0 to n-1 which takes O(n) and the inner loop from i to n-1, 
which will again take O(n).

Now, we are generating a substring from i to j, 
and checking whether it is a palindrome also takes O(j-i) = O(n) time.

Hence, the overall time complexity turns out to be O(n * n * n) = O(n^3) time.

SPACE COMPLEXITY : O(n) 
auxiliary space is required as we are passing the substring from i to j to isPalindrome function.*/