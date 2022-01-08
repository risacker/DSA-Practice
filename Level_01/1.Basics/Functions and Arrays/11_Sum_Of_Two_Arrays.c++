/*1. You are given a number n1, representing the size of array a1.
2. You are given n1 numbers, representing elements of array a1.
3. You are given a number n2, representing the size of array a2.
4. You are given n2 numbers, representing elements of array a2.
5. The two arrays represent digits of two numbers.
6. You are required to add the numbers represented by two arrays and print the
arrays.

Input Format
A number n1
n1 number of elements line separated
A number n2
n2 number of elements line separated

Output Format
A number representing sum of two numbers, represented by two arrays.

Constraints
1 <= n1, n2 <= 100
0 <= a1[i], a2[i] < 10

Sample Input
5
3
1
0
7
5
6
1
1
1
1
1
1

Sample Output
1
4
2
1
8
6*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1;
    cin>>n1;
    int* a1 = new int[n1];
    for (int i = 0; i < n1; i++)
    {
      cin>>a1[i];
    }
    int n2;
    cin>>n2;
    int* a2 = new int[n2];
    for (int i = 0; i < n2; i++)
    {
      cin>>a2[i];
    }
    int m = max(n1,n2);
    int* sum = new int[m];
    int carry = 0;
    int i = n1 - 1;
    int j = n2 - 1;
    int k = m - 1;
    while (k >= 0)
    {
      int digit = carry;
      if (i >= 0)
      {
        digit += a1[i--];
      }
      if (j >= 0)
      {
        digit += a2[j--];
      }
      carry = digit / 10;
      digit %= 10;
      sum[k--] = digit;
    }
    if (carry > 0)
    {
      cout<<carry<<endl;
    }
    for(int i = 0 ; i < m; i++)
    {
      cout<<sum[i]<<endl;
    }
    return 0;
  }

/*TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)*/