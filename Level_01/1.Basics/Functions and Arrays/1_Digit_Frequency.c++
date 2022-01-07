/*1. You are given a number n.
2. You are given a digit d.
3. You are required to calculate the frequency of digit d in number n.

Input Format
A number n
A digit d

Output Format
A number representing frequency of digit d in number n

Constraints
0 <= n <= 10^9
0 <= d <= 9
  
Sample Input
994543234
4

Sample Output
3*/

#include<iostream>
using namespace std;

int getFrequency(int n, int d){
    int cnt=0; // initialize digit counter to 0
    while(n>0){
        int t=n%10;
        n=n/10;
        if(t==d)
          cnt++;
    }
    return cnt;
}

int main(){
    int n,d;
    cin>>n>>d;
    int f=getFrequency(n,d);
    cout<<f<<endl;
    return 0;
}

/*Time Complexity: O(log10 n)

Space Complexity: O(1)*/