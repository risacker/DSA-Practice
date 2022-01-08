/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are required to print all subsets of arr. Each subset should be
on separate line. For more clarity check out sample input and output.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
[Tab separated elements of subset]
..
All subsets

Constraints
1 <= n <= 10
0 <= n1, n2, .. n elements <= 10^3

Sample Input
3
10
20
30

Sample Output
-	-	-	
-	-	30	
-	20	-	
-	20	30	
10	-	-	
10	-	30	
10	20	-	
10	20	30	*/

/*#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
     int limit = (int) pow (2, n); //calculating the number of subsets
    for (int i = 0; i < limit; i++)
    {
      //convert i to binary and use 0's and 1's
      //to check if an array's element is to be printed or not
      string set = " ";
      // we make use of set to print in required order
      int temp = i;
      // we store i because we need to use value
      // of i without manipulating the actual i
      // as i is the outer loop iterator
      for (int j = n - 1; j >= 0; --j)
      {
        //calculating the binary, extracting //
        // the remainder one and by one
        // and putting required element
        // in the String to be printed.
        int rem = temp % 2;
        temp = temp / 2;
        if (rem == 0)   //nothing to be printed
        {
          cout<< "-   "<<set ;
        }
        else
        {
          // we print the element, so we add it to our answer string
          cout<<set << "   "<<arr[j];
        }
      }
      cout<<set<<endl;
      // printing the required pattern line-by-line
    }
    return 0;
}*/
#include<iostream>
using namespace std;
// arr: input array
// i: ith index of input array
// n: size of arr
// subset: array to store the subset
// j: current size of subset
void PrintAllSubsets(int *arr, int i, int n,int *subset, int j){    
    // checking if all elements of the array are traverse or not
    if(i==n){
        // print the subset array
        int idx = 0;
        while(idx<j){
            cout<<subset[idx]<<' ';
            ++idx;
        }
        cout<<endl;
        return;
    }
    // for each index i, we have 2 options
    // case 1: i is not included in the subset
    // in this case simply increment i and move ahead
    PrintAllSubsets(arr,i+1,n,subset,j);
    // case 2: i is included in the subset
    // insert arr[i] at the end of subset
    // increment i and j
    subset[j] = arr[i];
    PrintAllSubsets(arr,i+1,n,subset,j+1);
        
}
int main()
{
    int arr[] = {10,20,30}; // input array
    int subset[100];       // temporary array to store subset
    int n = 3;
    PrintAllSubsets(arr,0,n,subset,0);   
}
