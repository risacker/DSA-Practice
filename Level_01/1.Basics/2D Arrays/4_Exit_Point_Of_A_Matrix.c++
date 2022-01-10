/*1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers (1's and 0's), representing elements of 2d array a.
4. Consider this array a maze and a player enters from top-left corner in east direction.
5. The player moves in the same direction as long as he meets '0'. On seeing a 1, he takes a 90 deg right turn.
6. You are required to print the indices in (row, col) format of the point from where you exit the matrix.

Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements

Output Format
row
col (of the point of exit)

Constraints
1 <= n <= 10^2
1 <= m <= 10^2
e1, e2, .. n * m elements belongs to the set (0, 1)

Sample Input
4
4
0
0
1
0
1
0
0
0
0
0
0
0
1
0
1
0

Sample Output
1
3*/

#include <iostream>
using namespace std;

const int mr = 100, mc = 100;
int** input(int** mat, int n, int m)
{
  mat = new int* [n];
  for (int i = 0; i < n; i++)
  {
    int* arr = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin >> arr[j];
    }
    mat[i] = arr;
  }
  return mat;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int** mat = input(mat, n, m);

  int i = 0, j = 0, dir = 0;

  int count = 0;
  int total = n * m;
  while (count < total)
  {

    dir = (dir + mat[i][j]) % 4;
    count++;
    if (dir == 0)
    {
      j++;
      if (j == m)
      {
        j--;
        break;
      }
    }
    else if (dir == 1)
    {
      i++;
      if (i == n)
      {
        i--;
        break;
      }
    }
    else if (dir == 2)
    {
      j--;
      if (j == -1)
      {
        j++;
        break;
      }
    }
    else
    {
      i--;
      if (i == -1)
      {
        i++;
        break;
      }
    }
  }

  cout <<  i << endl << j;
  return 0;
}

/*Time Complexity: O(n^2) 
We have already mentioned that the time complexity of this method is O(mxn) where m is the number of rows and n is the number of columns. 
You can see we may have to traverse a large part of the 2-D array depending upon the combinations of values in the matrix. 
Therefore, the time complexity is O(mxn). 
If the array is a square matrix, we may write the time complexity is: O(n^2) .

SPACE COMPLEXITY: O(1)
The Space Complexity for this problem will be O(1) as we have not used any extra array or any extra memory to solve the problem.
*/