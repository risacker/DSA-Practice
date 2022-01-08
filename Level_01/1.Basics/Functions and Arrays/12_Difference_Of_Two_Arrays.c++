/*1. You are given a number n1, representing the size of array a1.
2. You are given n1 numbers, representing elements of array a1.
3. You are given a number n2, representing the size of array a2.
4. You are given n2 numbers, representing elements of array a2.
5. The two arrays represent digits of two numbers.
6. You are required to find the difference of two numbers represented by two arrays and print the arrays. a2 - a1

Assumption - number represented by a2 is greater.

Input Format
A number n1
n1 number of elements line separated
A number n2
n2 number of elements line separated

Output Format
A number representing difference of two numbers (a2 - a1), represented by two arrays.

Constraints
1 <= n1, n2 <= 100
0 <= a1[i], a2[i] < 10
number reresented by a1 is smaller than number represented by a2

Sample Input
3
2
6
7
4
1
0
0
0

Sample Output
7
3
3*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1;
    cin>>n1;
    int* a1 = new int[n1];
    for (int i = 0; i < n1; i++)
    {
      cin>>a1[i];
    }
    int n2;
    cin>>n2;
    int* a2 = new int[n2];
    for (int i = 0; i < n2; i++)
    {
      cin>>a2[i];
    }
    int max = (n1 > n2) ? n1 : n2;
    int* ans = new int[max];
    int idx = max - 1;
    n1--;
    n2--;
    int carry = 0, diff;
    while (n1 >= 0 && n2 >= 0){
     if (carry != 0)
      a2[n2]--;
     carry = 0;
     if (a2[n2] < a1[n1]){
      a2[n2] += 10;
      carry++;
    }
    diff = a2[n2] - a1[n1];
    n1--;
    n2--;
    ans[idx--] = diff;
  }
  if (n2 >= 0)
  {
    for (int i = n2; i >= 0; i--)
    {
      if (carry != 0)
      {
        ans[i] = a2[i] - 1;
        carry = 0;
        if (ans[i] < 0)
        {
          ans[i] += 10;
          carry = 1;
        }
      }
      else
        ans[i] = a2[i];
    }
  }

  bool startzero = true;
  for (int i = 0; i < max; i++)
  {
    if (ans[i] != 0)
      startzero = false;
    if (!startzero)
      cout << ans[i] << endl;
  }
  return 0;
}

/*Time Complexity: O(n2) = Linear

Let's look at the number of loop passes we are doing. [Ignore the input-output operation]. 
There is just one loop where we have iterated through the size of the array a2 i.e n2. 
Hence we can clearly state that the time complexity is of order n2.

SPACE COMPLEXITY:
Although we are not using any extra space for calculation just storing the digits of the result in the diff array. 
So still we can assume it is using constant auxiliary space.

*/