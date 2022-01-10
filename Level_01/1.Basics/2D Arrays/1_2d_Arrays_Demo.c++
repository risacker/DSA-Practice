/*1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a.
4. You are required to display the contents of 2d array as suggested by output format below.

Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements

Output Format
e11 e12 e13 ..
e21 e22 e23 ..

Constraints
1 <= n <= 10^2
1 <= m <= 10^2
-10^9 <= e1, e2, .. n * m elements <= 10^9

Sample Input
2
4
11
12
13
14
21
22
23
24

Sample Output
11 12 13 14
21 22 23 24*/

#include<bits/stdc++.h>
using namespace std;
int main() {
  int r;
  int c;
  cin >> r;
  cin >> c;

  vector<vector<int>>marr;
  for (int i = 0; i < r; i++) {
    vector<int>sarr;
    for (int j = 0; j < c; j++) {
      int ele;
      cin >> ele;
      sarr.push_back(ele);
    }
    marr.push_back(sarr);
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << marr[i][j] << " ";
    }
    cout << endl;
  }
}

/*Time Complexity: O(n^2)

This time complexity is quadratic due to the use of nested for loops.

SPACE COMPLEXITY: O(n^2)

As a 2D array is used to store input values, therefore space complexity is quadratic.*/