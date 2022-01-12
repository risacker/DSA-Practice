/*1. You are given a string that contains only lowercase and uppercase alphabets. 
2. You have to form a string that contains the difference of ASCII values of every two consecutive characters between those characters.
   For "abecd", the answer should be "a1b3e-2c1d", as 
   'b'-'a' = 1
   'e'-'b' = 3
   'c'-'e' = -2
   'd'-'c' = 1

Input Format
A String

Output Format
A String

Constraints
1 <= length of string <= 1000

Sample Input
pepCODinG

Sample Output
p-11e11p-45C12O-11D37i5n-39G*/

#include<iostream>
#include<string.h>
using namespace std;

void printstr(string str)
{
  int i = 0;
  while (i < str.length() - 1)
  {
    int diff = (int)str[i + 1] - (int)str[i];
    cout << str[i] << diff;

    i++;
  }
  cout << str[i];
}

int main()
{
  string str;
  getline(cin, str);

  printstr(str);
  return 0;
}

/*Time Complexity : O(n)
O(n) where n is the length of the string

Now, a question for you. What do you think is the time complexity for this problem? Yes, it is O(n).
You are running one loop from 1 to str length - 1 and in each iteration, 
you are performing constant-time operations.

It is O(1) when appending single characters to StringBuilder.
A StringBuilder is like an ArrayList. When you append a single item the cost is O(1)

SPACE COMPLEXITY : O(n)

And finally the .toString() before return that is also O(n). So, it is O(n+n) i.e O(n).*/