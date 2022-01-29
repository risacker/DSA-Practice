/*1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using insertion sort.

Input Format
An Integer n 
arr1
arr2..
n integers

Output Format
Check the sample output and question video.

Constraints
1 <= N <= 10000
-10^9 <= arr[i] <= 10^9

Sample Input
5
7 
-2 
4 
1 
3

Sample Output
Comparing -2 and 7
Swapping 7 and -2
Comparing 4 and 7
Swapping 7 and 4
Comparing 4 and -2
Comparing 1 and 7
Swapping 7 and 1
Comparing 1 and 4
Swapping 4 and 1
Comparing 1 and -2
Comparing 3 and 7
Swapping 7 and 3
Comparing 3 and 4
Swapping 4 and 3
Comparing 3 and 1
-2
1
3
4
7*/

#include<iostream>
using namespace std;

bool isGreater(int arr[], int j, int i ) {
  cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
  if (arr[i] < arr[j]) {
    return true;
  } 
  else {
    return false;
  }
}

void swap(int arr[], int i, int j) {
  cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (isGreater(arr, j, j + 1)) {
        swap(arr, j, j + 1);
      } else {
        break;
      }
    }
  }
}

void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertionSort(arr, n);
  print(arr, n);
}

/*Time Complexity : O(n^2)

We are just making two loops. What do you think will be the worst case for Insertion sort? 
Yes, when all the numbers are sorted in reverse (in descending order). Then for each iteration of n-1 we will have to perform 1+ 2 + 3 + ... swaps. 
So in total, this is an Arithmetic Progression whose result is n*(n+1)/2 equivalent to n2.

Worst Case: O(n^2)

Best Case: O(n) [We discussed this previously]

SPACE COMPLEXITY : O(1)

We are working with constant auxiliary space because the only main operation is a swap.*/