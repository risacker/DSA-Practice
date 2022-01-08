/*1. You are given an array of size 'n' and n elements of the same array.
2. You are required to find and print all the subarrays of the given array. 
3. Each subarray should be space seperated and on a seperate lines. Refer to sample input and output.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
[Tab separated elements of subarray]
..
All subarrays

Constraints
1 <= n <= 10
0 <= n1, n2
 .. n elements <= 10 ^9

Sample Input
3
10
20
30

Sample Output
10	
10	20	
10	20	30	
20	
20	30	
30*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    for (int startPoint = 0; startPoint < n; startPoint++)
    {
      //group sizes
      for (int grps = startPoint + 1; grps <= n; grps++)
      {
        //if start point = 1 then
        //grp size = 1 , print 1
        //grp size = 2, print 1 2
        //grp size = 3, print 1 2 3 ans so on
        for (int j = startPoint; j < grps; j++)
        {
          cout<<arr[j]<<" ";
        }
        cout<<endl;
      }
    } 
    return 0;
}

/*Time Complexity: O(n^3)

Double nested "for" loop has been used to print all the subarrays of the given array; travelling the n sized array 3 times makes the time complexity O(n^3).

SPACE COMPLEXITY: O(1)

Since no extra space is used, therefore space complexity is constant.*/