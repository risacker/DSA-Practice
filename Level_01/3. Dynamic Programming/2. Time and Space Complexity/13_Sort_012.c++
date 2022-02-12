/*1. You are given an array(arr) containing only 0's, 1's, and 2's.
2. You have to sort the given array in increasing order and in linear time.

Constraints
1 <= N <= 10000
arr[i] = 0,1,2

Format
Input
An Integer N 
arr1
arr2..
n integers

Output
Check the sample output and question video.

Example
Sample Input
10
1
0
2
2
1
0
2
1
0
2

Sample Output
Swapping index 1 and index 0
Swapping index 2 and index 9
Swapping index 2 and index 8
Swapping index 2 and index 1
Swapping index 3 and index 7
Swapping index 5 and index 2
Swapping index 6 and index 6
0
0
0
1
1
1
2
2
2
2*/

#include <iostream>
#include <vector>
using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(vector<int> &arr)
{
    int n = arr.size();
    int pt1 = 0, itr = 0, pt2 = n - 1;
    while (itr <= pt2)
    {
        if (arr[itr] == 0)
            swap(arr, itr++, pt1++);
        else if (arr[itr] == 2)
            swap(arr, itr, pt2--);
        else
            itr++;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);
    sort012(A);
    print(A);
    return 0;
}