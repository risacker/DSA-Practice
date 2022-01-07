/*1.You are given a number n, representing the size of array a.
2.You are given n distinct numbers, representing elements of array a.
3. You are given another number d.
4. You are required to check if d number exists in the array a and at what index (0 based). If found print the index, otherwise print -1.

Input Format
A number n
n1
n2
.. n number of elements
A number d

Output Format
A number representing index at which d is found in array a and -1 if not found

Constraints
1 <= n <= 10^7
-10^9 <= n1, n2 
.. n elements <= 10^9
-10^9 <= d <= 10^9

Sample Input
6
15
30
40
4
11
9
40

Sample Output
2*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];  //input array elements
    }
    int data;
    cin>>data;  // input data to match in array
    int idx = -1;   //set our answer to -1 if we do not find our element
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == data)
      {
        idx = i;
        break;
      }
    }
    cout<<idx; // it prints the index if number is present, else -1.
    return 0;
}

/*Time Complexity: O(n)

Space Complexity: O(1)*/