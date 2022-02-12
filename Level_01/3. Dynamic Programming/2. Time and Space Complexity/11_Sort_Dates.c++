/*1. You are given an array(arr) of different dates in format DD-MM-YYYY.
2. You have to sort these dates in increasing order.

Constraints
1 <= N <= 10000
All dates are between year 0 to year 2500

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
5
12041996
20101996
05061997
12041989
11081987

Sample Output
11081987
12041989
12041996
20101996
05061997
*/

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

void sort01(vector<int> &arr)
{
    int n = arr.size();
    int pt = 0, itr = 0;
    while (itr < n)
    {
        if (arr[itr] == 0)
            swap(arr, itr++, pt++);
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
    sort01(A);
    print(A);
    return 0;
}