/*1. You are given an ArrayList of positive integers.
2. You have to remove prime numbers from the given ArrayList and return the updated ArrayList.

Note -> The order of elements should remain same.

Input Format
A number N
arr1
arr2.. N numbers

Output Format
An Arraylist

Constraints
1 <= N <= 10000

Sample Input
4
3 12 13 15

Sample Output
[12, 15]*/

#include<iostream>
#include<vector>
using namespace std;

bool isprime(int val)
{
  for (int j = 2; j <= val / 2; j++)
  {
    if (val % j == 0)
    {
      return false;
    }
  }
  return true;
}

void removeprimes(vector<int> v)
{
  for (int i = v.size() - 1; i >= 0; i--)
  {
    if (isprime(v[i]))
    {
      v.erase(v.begin() + i);
    }
  }
  cout << "[";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i < v.size() - 1)
      cout << ", ";
  }
  cout << "]";
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  removeprimes(v);
}

/*Time Complexity : O(n^2)
The time complexity for the above procedure is O(n^2). Why? Think about it?

You might think that the time complexity should be O(n) as we are just traversing the Arraylist and removing the prime numbers but, you should not forget about the internal shifting of the elements, although it is not performed by us, it is still happening and we should consider it as well.

SPACE COMPLEXITY : O(1)

The space complexity of the procedure is O(1) as we have not used any extra space.*/