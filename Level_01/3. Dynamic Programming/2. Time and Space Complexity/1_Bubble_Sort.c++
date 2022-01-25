/*1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using bubble sort.

Input Format
An Integer n 
arr1
arr2..
n integers

Output Format
Check the sample ouput and question video.

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
Swapping -2 and 7
Comparing 4 and 7
Swapping 4 and 7
Comparing 1 and 7
Swapping 1 and 7
Comparing 3 and 7
Swapping 3 and 7
Comparing 4 and -2
Comparing 1 and 4
Swapping 1 and 4
Comparing 3 and 4
Swapping 3 and 4
Comparing 1 and -2
Comparing 3 and 1
Comparing 1 and -2
-2
1
3
4
7*/

#include<iostream>
using namespace std;


bool isSmaller(int arr[], int i, int j ) {
  cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
  if (arr[i] < arr[j]) {
    return true;
  } else {
    return false;
  }
}

void swap(int arr[], int i, int j) {
  cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;

}


void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int c = 1; c < n - i; c++) {
      int p = c - 1;
      if (isSmaller(arr, c, p)) {
        swap(arr, c, p);
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

  bubbleSort(arr, n);
  print(arr, n);
}

/*Time Complexity :
Worst Case Time Complexity: O(n*n). Worst case is when the array is in reverse order.

Best Case Time Complexity: O(n) Best case is when the input array is already sorted.

Average Case Time Complexity: O(n*n). The inner loop does O(n) work on each iteration, and the outer loop runs for O(n) iterations, so the total work is O(n 2).

SPACE COMPLEXITY :
Auxiliary Space: O(1), as no extra space is used.*/