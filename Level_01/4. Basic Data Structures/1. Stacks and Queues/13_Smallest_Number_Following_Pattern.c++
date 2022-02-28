/*1. You are given a pattern of upto 8 length containing characters 'i' and 'd'. 
2. 'd' stands for decreasing and 'i' stands for increasing 
3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that the digit decreases following a d and increases follwing an i. 
e.g. d -> 21 i -> 12 ddd -> 4321 iii -> 1234 dddiddd -> 43218765 iiddd -> 126543

Constraints
0 < str.length <= 8 str contains only 'd' and 'i'

Format
Input
Input is managed for you

Output
Smallest sequence of digits (from 1 to 9) without duplicacy and following the pattern

Example
Sample Input
ddddiiii

Sample Output
543216789*/

#include<iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<int> st;
    int num = 1;
    for(int i = 0; i < str.length() ; i++){
        char ch = str.at(i);
        if(ch == 'd'){
            st.push(num);
            num++;
        }
        else{
            st.push(num);
            num++;       
            while(st.size() > 0){
                cout << st.top();
                st.pop();
            }
        }
    } 
    st.push(num);
    while(st.size() > 0){
        cout << st.top();
        st.pop();
    }
    cout<<endl;   
}

/*Time Complexity : O(n)

Here to simply calculate the time complexity just notice the life cycle of a single num.
It will be pushed into the stack only once. Also, it will be popped only once. 
So there is a constant operation for every num. And the num can range from 1 to str.length. 
So the time complexity is O(n).

SPACE COMPLEXITY : O(n)

If the pattern is all d's then we will keep pushing elements into the stack only. 
That way the size of the stack will be that of the size of the str. So space is also O(n).*/