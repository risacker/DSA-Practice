/*1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using quick-sort.

Constraints
1 <= N <= 100000
-10^9 <= arr[i] <= 10^9

Format
Input
An Integer n 
arr1
arr2..
n integers

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

Sample Output
pivot -> 3
Swapping -2 and 7
Swapping 1 and 7
Swapping 3 and 4
pivot index -> 2
pivot -> 1
Swapping -2 and -2
Swapping 1 and 1
pivot index -> 1
pivot -> -2
Swapping -2 and -2
pivot index -> 0
pivot -> 4
Swapping 4 and 7
pivot index -> 3
pivot -> 7
Swapping 7 and 7
pivot index -> 4
-2 1 3 4 7 */

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

void quicksort(vector<int> &arr, int lo, int hi){
    if(lo > hi){
        return;
    }   
    int pivot = arr[hi];
    int pIdx = partition(arr, pivot, lo, hi);  
    quicksort(arr, lo, pIdx - 1);
    quicksort(arr, pIdx + 1, hi);
}

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    Display(arr);
    return 0;
}