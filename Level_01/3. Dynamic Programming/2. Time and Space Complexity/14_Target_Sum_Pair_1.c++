/*1. You are given an array(arr) of distinct integers and a target.
2. You have to print all the pairs having their sum equal to the target.

Constraints
1 <= N <= 10000
-10^9<= arr[i] <= 10^9

Format
Input
An Integer N 
arr1
arr2..
n integers
An integer target

Output
Check the sample output and question video.

Example
Sample Input
12
9 
-48 
100 
43 
84 
74 
86 
34 
-37 
60 
-29 
44
160

Sample Output
60, 100
74, 86*/

#include<bits/stdc++.h>
using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void targetSumPair(vector<int> &arr,int target)
{
    sort(arr.begin(),arr.end());
    int si=0,ei=arr.size()-1;
    while(si<ei)
    {
        int sum=arr[si]+arr[ei];
        if(sum<target)
        {
            si++;
        }else if(sum>target)
        {
            ei--;
        }
        else
        {
            cout<<arr[si]<<", "<<arr[ei]<<endl;
           si++;
           ei--;
        }
    }
}

int main()
{
    int n,target;
    cin>>n;
    vector<int> vec(n,0);
    input(vec);
    cin>>target;
    targetSumPair(vec,target);
    return 0;
}