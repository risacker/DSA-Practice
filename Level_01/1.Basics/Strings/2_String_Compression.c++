/*1. You are given a string. 
2. You have to compress the given string in the following two ways - 
   First compression -> The string should be compressed such that consecutive duplicates of characters are replaced with a single character.
   For "aaabbccdee", the compressed string will be "abcde".
   Second compression -> The string should be compressed such that consecutive duplicates of characters are replaced with the character and followed by the number of consecutive duplicates.
   For "aaabbccdee", the compressed string will be "a3b2c2de2".

Input Format
A String

Output Format
Two strings representing first compressed string and second compressed string respectively.

Constraints
1 <= length of string <= 1000

Sample Input
wwwwaaadexxxxxx

Sample Output
wadex
w4a3dex6*/

#include<iostream>
#include<string.h>
using namespace std;

void String_compression01(string str)
{
  int i = 0;
  while (i < str.length())
  {
    while (i < str.length() && str[i] == str[i + 1])
    {
      i++;

    }

    cout << str[i];
    i++;
  }
  cout << endl;
}

void String_compression02(string str)
{
  int i = 0;
  while (i < str.length())
  {
    int count = 1;
    while (i < str.length() && str[i] == str[i + 1])
    {
      i++;
      count++;
    }
    cout << str[i];
    if (count > 1)
      cout << count;

    i++;
  }

}

int main()
{
  string str;
  getline(cin, str);
  String_compression01(str);
  String_compression02(str);
}

/*Time Complexity : O(n)
In both ways, we are traversing the input string once, hence the time complexity will be O(n).

SPACE COMPLEXITY : O(n)
If we take the space of the output string, then the solution is taking O(n) space. 
Although, if we ignore the space taken by the output, (which we generally do), the solution is said to take O(1) auxiliary space.*/