/*1. You are given a string. 
2. You have to print all permutations of the given string iteratively.

Input Format
A String

Output Format
All permutations of the given string(one in a line).

Constraints
1 <= length of string <= 15

Sample Input
abc

Sample Output
abc
bac
cab
acb
bca
cba */

#include<iostream>
#include<string>
using namespace std;

int fact(string str)
{
  int n = str.length();
  int count = 1;
  for (int i = n; i >= 1; i--)
  {
    count *= i;
  }
  return count;

}

void printallperm(string str)
{
  int limit = fact(str);
  int k = 0;
  while (k < limit)
  {
    int temp = k;
    string ans = str;
    for (int i = str.length(); i >= 1; i--)
    {
      int rem = temp % i;
      temp = temp / i;
      cout << ans[rem];
      ans.erase(rem, 1);
    }
    cout << endl;
    k++;
  }
}

int main()
{
  string str;
  getline(cin, str);
  printallperm(str);
}

/*Time Complexity : O(n!)
O(n! * n) = O(n!)

We are looping from 1 to n! in the outer loop. 
And in the inner loop, we are performing some operations which are running n times. 
Here n represents the length of the string. Thus, we have a total time complexity of O(n! * n).

SPACE COMPLEXITY : O(n)

For space complexity, we are not storing the permutations but we are using a StringBuilder for the string operations. 
So the auxiliary space will remain O(n).O(n).*/