/*1. You are given an array(arr) of integers.
2. You have to find the k-th smallest element in the given array using the quick-select algorithm.

Constraints
1 <= N <= 100000
-10^9 <= arr[i] <= 10^9
1 <= k <= N

Format
Input
An Integer n 
arr1
arr2..
n integers
An integer k

Output
Check the sample output and question video.

Example
Sample Input
5
7 
-2 
4 
1 
3
3

Sample Output
pivot -> 3
Swapping -2 and 7
Swapping 1 and 7
Swapping 3 and 4
pivot index -> 2
3*/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    cout<<"Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr, int pivot, int lo, int hi){
    cout << "pivot -> " << pivot << endl;
    int curr = lo;
    int prev = lo - 1;
    while(curr <= hi){
        if(arr[curr] <= pivot){
            prev++;
            swap(arr, curr, prev);
        }
        curr++;
    }
    cout << "pivot index -> " << prev << endl;
    return prev;
}

int quickselect(vector<int>& arr, int lo, int hi, int k) {
    int pivot = arr[hi];
    int pIdx = partition(arr, pivot, lo, hi);
    if(pIdx > k){
        quickselect(arr, lo, pIdx - 1, k);
    }
    else if(pIdx < k){
        quickselect(arr, pIdx + 1, hi, k);
    }
    else{
        return arr[pIdx];
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;

  int ans = quickselect(arr, 0, n - 1, k-1);
  cout << ans << endl;
  return 0;
}                       