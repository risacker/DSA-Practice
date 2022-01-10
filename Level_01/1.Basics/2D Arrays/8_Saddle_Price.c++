/*1. You are given a square matrix of size 'n'. You are given n*n elements of the square matrix. 
2. You are required to find the saddle price of the given matrix and print the saddle price. 
3. The saddle price is defined as the least price in the row but the maximum price in the column of the matrix.

Input Format
A number n
e11
e12..
e21
e22..
.. n * n number of elements of array a

Output Format
Saddle point of the matrix if available or "Invalid input" if no saddle point is there.

Constraints
1 <= n <= 10^2
-10^9 <= e11, e12, .. n * m elements <= 10^9

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
41*/

#include <iostream>
#include <vector>
using namespace std;

void saddle_point(int n, vector<vector<int>>& arr)
{
  bool f1 = false;
  for (int i = 0; i < n; i++)
  {
    bool f2 = true;
    int minj = 0;
    for (int j = 0; j < n; j++)
      if (arr[i][j] < arr[i][minj])
        minj = j;

    for (int ii = 0; ii < n; ii++)
    {
      if (arr[ii][minj] > arr[i][minj])
      {
        f2 = false;
        break;
      }
    }
    if (f2)
    {
      f1 = true;
      cout << arr[i][minj];
      break;
    }
  }
  if (!f1)
    cout << "Invalid input";
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  saddle_point(n, arr);
}

/*Time Complexity : O(n*n)
In the worst-case scenario we might need to traverse all the elements in the matrix, 
so the time complexity comes out to be n square O(n*n).

Space Complexity : O(1)
Since we are using only a handful of variables, space complexity is constant, O(1).*/