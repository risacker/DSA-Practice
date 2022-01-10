/*1. You are given a number n, representing the number of rows and columns of a square matrix.
2. You are given n * n numbers, representing elements of 2d array a. 
Note - Each row and column is sorted in increasing order.
3. You are given a number x.
4. You are required to find x in the matrix and print it's location int (row, col) format as discussed in output format below.
5. In case element is not found, print "Not Found".

Input Format
A number n
e11
e12..
e21
e22..
.. n * n number of elements of array a
A number x

Output Format
row
col of the location where element is found or "Not Found" if element is not in the matrix

Constraints
1 <= n <= 10^2
-10^9 <= e11, e12, .. n * m elements <= 10^9
All rows and columns are sorted in increasing order

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
43

Sample Output
3
2*/


#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
  int n = matrix.size();
  if (n == 0)
    return false;

  int r = 0, c = n - 1;
  while (r < n && c >= 0)
  {
    if (matrix[r][c] == target)
    {
      cout << r << endl << c << endl;
      return true;
    }
    if (matrix[r][c] < target)
      r++;
    else
      c--;
  }
  return false;
}

int main()
{
  int n, target;
  cin >> n;
  vector<vector<int>> mat(n, vector<int> (n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];
  cin >> target;

  if (!searchMatrix(mat, target)) 
    cout << "Not Found" << endl;
}

/*Time Complexity :O(m+n)
The time-complexity drops from O(m*n) to O(m+n).

Space Complexity : O(1)
The space-complexity of this approach is constant, O(1).*/