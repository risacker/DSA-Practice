/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the all indices at which x occurs in array a.
5. Return an array of appropriate size which contains all indices at which x occurs in array a.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
n1
n2
.. n number of elements
A number x

Output Format
Return the array of indices from the allIndices function. Display is managed for you.

Constraints
1 <= n <= 10^4
0 <= n1, n2, .. n elements <= 10 ^ 3
0 <= x <= 10 ^ 3

Sample Input
6
15
11
40
4
4
9
4

Sample Output
3
4*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
  if (idx == arr.size())
  {
    vector<int> base(count, 0);
    return base;
  }
  if (arr[idx] == data)
    count++;
  vector<int> ans = allIndex(arr, idx + 1, data, count);
  if (arr[idx] == data)
    ans[count - 1] = idx;
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans)
   cout << ele << endl;
  return 0;
}

/*Time Complexity: O(n)
As n (array's length) calls are made and work is done corresponding to these n calls therefore the time complexity becomes O(n).

Space Complexity: O(1)
Since an array has been used to store all the indices which can be, therefore space complexity is constant, 
however you should know that if the recursion call stack is taken into account, then space complexity will be O(n) as there are n recursive calls.*/