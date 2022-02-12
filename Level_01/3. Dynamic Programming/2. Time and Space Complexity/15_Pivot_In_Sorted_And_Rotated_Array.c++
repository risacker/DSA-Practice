/*1. You are given an array(arr) of distinct integers, which is sorted and rotated around an unknown point.
2. You have to find the smallest element in O(logN) time-complexity

Constraints
1 <= N <= 10000
-10^9 <= arr[i] <= 10^9

Format
Input
An Integer N 
arr1
arr2..
n integers

Output
The smallest element

Example
Sample Input
9
15
16
19
21
23
24
1
2
12

Sample Output
1*/

#include<bits/stdc++.h>
using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
 }

int findpivot(vector<int>&arr)
 {
     int lo=0;
     int hi=arr.size()-1;
     while(lo<hi)
     {
         int mid=(lo+hi)/2;
         if(arr[mid]<arr[hi])
         {
             hi=mid;
         }
         else if(arr[mid]>arr[hi])
         {
             lo=mid+1;
         }
     }
     
     return arr[hi];
 }

int main()
{
     int n;
     cin>>n;
     vector<int> vec(n,0);
     input(vec);
     int pivot=findpivot(vec);
     cout<<pivot;
     return 0;
} 