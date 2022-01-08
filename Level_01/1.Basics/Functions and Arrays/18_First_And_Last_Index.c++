/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.

Asssumption - Array is sorted. Array may have duplicate values.

Input Format
A number n
n1
n2
.. n number of elements
A number d

Output Format
A number representing first index
A number representing last index

Constraints
1 <= n <= 1000
1 <= n1, n2, .. n elements <= 100
1 <= d <= 100

Sample Input
15
1
5
10
15
22
33
33
33
33
33
40
42
55
66
77
33

Sample Output
5
9*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data; 
    cin>>data; // enter data to be searched
    //binary search to find last index
    int low = 0;
    int high = n - 1;
    int last_index = -1;
    int first_index = -1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (data < arr[mid])
      {
        high = mid - 1;
      }
      else if (data > arr[mid])
      {
        low = mid + 1;
      }
      else
      {
        last_index = mid; // potential answer
        low = mid + 1;  // we do not break on getting the match and further update the low pointer
        // as there could be another index holding the required value on the right side
      }
    }
    //binary search to find the first index
    low = 0;
    high = n - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (data < arr[mid])
      {
        high = mid - 1;
      }
      else if (data > arr[mid])
      {
        low = mid + 1;
      }
      else
      {
        first_index = mid;  // potential answer
        high = mid - 1; // we do not break on getting the match and further update the high pointer
        // as there could be another index holding the required value on the left side
      }

    }
    //both the binary search implementations store the final answer when the loop breaks
    cout<<first_index<<endl;
    cout<<last_index<<endl;
    return 0;
}

/*Time Complexity: O(log2 n)
We are doing binary search only. 
Even if we are continuing our binary search after finding an element,
it is still reducing the search space by half of the original size. 
Hence, the time complexity will remain as O(log2 n).

SPACE COMPLEXITY: O(1) 
auxiliary space is required to store three integer pointers, low, high and mid.*/