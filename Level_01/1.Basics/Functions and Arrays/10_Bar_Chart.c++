/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print a bar chart representing value of arr a.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
A bar chart of asteriks representing value of array a

Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 10

Sample Input
5
3
1
0
7
5

Sample Output
			*		
			*		
			*	*	
			*	*	
*			*	*	
*			*	*	
*	*		*	*	

*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
      if (arr[i]  > max)
      {
        max = arr[i];
      }
    }
    for (int i = 0; i < max; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if ( max - arr[j]  <= i)
        {
          cout<<"*	";
        }
        else
        {
          cout<<"	";
        }
      }
      cout<<endl;
    }
    return 0;
}

/*Time Complexity: O(n^2)
This time complexity is quadratic because nested for loops are used.

SPACE COMPLEXITY: O(n)*/