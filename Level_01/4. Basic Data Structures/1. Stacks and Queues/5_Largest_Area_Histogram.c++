/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the height of bars in a bar chart.
3. You are required to find and print the area of largest rectangle in the histogram.

e.g.
for the array [6 2 5 4 5 1 6] -> 12

Constraints
0 <= n < 20
0 <= a[i] <= 10

Format
Input
Input is managed for you

Output
A number representing area of largest rectangle in histogram

Example
Sample Input
7
6
2
5
4
5
1
6

Sample Output
12
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerLeft(vector<int>arr){
 int n=arr.size();
 vector<int>nsl(n,0);
 stack<int>st;
 nsl[0]=-1;
 st.push(0);
 for(int i=0;i<n;i++)
 {
     while(st.size()>0&&arr[i]<=arr[st.top()]){
         st.pop();
     }
     if(st.size()==0)
     {
         nsl[i]=-1;
         
     }else
     {
         nsl[i]=st.top();
     }
     st.push(i);
 }
 return nsl;
}

vector<int> nextSmallerRight(vector<int>arr){
     int n=arr.size();
     vector<int>nsr(n,0);
     stack<int>st;
     nsr[n-1]=n;
     st.push(n-1);
     for(int i=n-2;i>=0;i--)
     {
     while(st.size()>0&&arr[i]<=arr[st.top()]){
         st.pop();
     }
     if(st.size()==0)
     {
         nsr[i]=n;
         
     }else
     {
         nsr[i]=st.top();
     }
     st.push(i);
 }
 return nsr;
}

int largestAreaHistogram(vector<int>arr)
{
    vector<int>nsl=nextSmallerLeft(arr);
    vector<int>nsr=nextSmallerRight(arr);
    int max=0;
    for(int i=0;i<arr.size();i++)
    {
        int ans=arr[i]*(nsr[i]-nsl[i]-1);
        if(ans>max)
        {
            max=ans;
        }
    }
    return max;
}

int main()
{  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=largestAreaHistogram(arr);
    cout<<ans;
    return 0;
}

/*Time Complexity: O(n)

Calculating NSE is O(n) we already know that.
And to calculate the maximum area we are just doing a single loop. Hence that too results in O(n).

Space Complexity: O(n)
We are just using stacks for calculating the NSEs but for the maximum area we are not using any auxiliary space, so the space complexity will still be O(n)*/