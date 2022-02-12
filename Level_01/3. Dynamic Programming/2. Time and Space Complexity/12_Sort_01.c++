/*1. You are given an array(arr) containing only 0's and 1's.
2. You have to sort the given array in increasing order and in linear time.

Constraints
1 <= N <= 10000
arr[i] = 0,1

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
0
1
0
1
0

Sample Output
Swapping index 0 and index 0
Swapping index 2 and index 1
Swapping index 4 and index 2
0
0
0
1
1*/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    cout<<"Swapping index " << i << " and index " << j << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort01(vector<int>& arr) {
    int curr = 0;
    int prev = -1;
    while(curr < arr.size()){
        if(arr[curr] == 0){
            prev++;
            swap(arr, curr, prev);
        }
        curr++;
    }
}

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << endl;
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort01(arr);
  Display(arr);
  return 0;
}