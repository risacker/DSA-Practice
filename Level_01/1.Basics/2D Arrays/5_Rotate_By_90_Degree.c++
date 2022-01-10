/*1. You are given a number n, representing the number of rows and number of columns.
2. You are given n*n numbers, representing elements of 2d array a.
3. You are required to rotate the matrix by 90 degree clockwise and then display the contents using display function.
*Note - you are required to do it in-place i.e. no extra space should be used to achieve it .*

Input Format
A number n
e11
e12..
e21
e22..
.. n * n number of elements

Output Format
output is taken care of by display function

Constraints
1 <= n <= 10^2
-10^9 <= e1, e2, .. n * n elements <= 10^9

Sample Input
4
11
12
13
14
21
22
23
24
31
32
33
34
41
42
43
44

Sample Output
41 31 21 11
42 32 22 12
43 33 23 13
44 34 24 14*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(int n, vector<vector<int>>& arr)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      swap(arr[i][j], arr[j][i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n / 2; j++)
      swap(arr[i][j], arr[i][n - 1 - j]);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  rotate(n, arr);
}

/*Time Complexity: O(n^2)
The time complexity for rotating the matrix by this procedure is O(n2) as for transposing we are traversing the upper triangle i.e. we are traversing n^2/2 elements and then reversing takes O(n) time and we have to reverse n rows. 
So it becomes O(n2 + n2/2) which is O(n^2).

SPACE COMPLEXITY: O(1)
The space complexity is O(1) as we are transposing and then reversing in-place and we are not consuming any auxiliary memory.
*/