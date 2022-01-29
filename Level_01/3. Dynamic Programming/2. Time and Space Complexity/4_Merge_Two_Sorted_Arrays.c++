/*1. You are given two sorted arrays(a,b) of integers.
2. You have to merge them and form one sorted array.
3. You have to do it in linear time complexity.

Input Format
An Integer n 
a1
a2..n integers
An integer m
b1
b2..m integers

Output Format
Check the sample output and question video.

Constraints
1 <= N <= 10^8
-10^9 <= a[i],b[i] <= 10^9

Sample Input
4
-2 
5 
9 
11
3
4 
6 
8

Sample Output
-2
4
5
6
8
9
11*/
                      
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;
    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }
    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];
    return ans;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);
    cin >> m;
    vector<int> B(m, 0);
    input(B);
    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}

/*Time Complexity : O(n)

Time complexity will be O(n) where n = a.length + b.length because if we look at i it will move from 0 to a.length only once. 
And j will move from 0 to b.length only once. So total iterations is a.length + b.length. If you are still not impressed, look at k.
k will loop throughout the result array only once. Hence from here also we can say that the time complexity will be a.length + b.length i.e linear O(n).

SPACE COMPLEXITY : O(n)

Here we are actually using a temporary array of size a.length + b.length to store the merged array. So our space complexity is O(n) i.e Linear.*/