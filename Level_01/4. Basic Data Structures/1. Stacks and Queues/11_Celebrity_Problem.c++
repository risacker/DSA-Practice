/*1. You are given a number n, representing the number of people in a party.
2. You are given n strings of n length containing 0's and 1's
3. If there is a '1' in ith row, jth spot, then person i knows about person j.
4. A celebrity is defined as somebody who knows no other person than himself but everybody else knows him.
5. If there is a celebrity print it's index otherwise print "none".

Note -> There can be only one celebrity. Think why?

Constraints
1 <= n <= 10^4
e1, e2, .. n * n elements belongs to the set (0, 1)

Format
Input
Input is managed for you

Output
Index of celebrity or none

Example
Sample Input
4
0000
1011
1101
1110

Sample Output
0
*/

#include<bits/stdc++.h>
using namespace std;

void celebPrblm(vector<string> &v, int n){
    stack<int> st; 
    for(int i = 0; i < n; i++){
        st.push(i);
    }
    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(v[a][b] == '1'){
            st.push(b);
        }else{
            st.push(a);
        }
    }

    int possCel = st.top();
    st.pop();
    for(int i = 0; i < n; i++){
        if(i != possCel){
            if(v[i][possCel] == '0' || v[possCel][i] == '1'){
                cout << "none" << endl;
                return;
            }
        }
    }
    cout << possCel << endl;
}

int main(){
    int n;
    cin >> n;
    vector<string> s;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.push_back(str);
    }
    celebPrblm(s, n);
}

/*Time Complexity : O(n)
On Each iteration, we are popping two elements and pushing one element back. So, what we are doing overall is reducing the number of elements in stack (potential celebrities) by 1 each time.
We will keep on reducing the size until it becomes 0 or 1. Hence the time complexity of this part of the algorithm is O(n).
After we are left with a single potential celebrity candidate, we are checking whether it is actually a celebrity or not by checking it's row and column, hence time complexity will be O(n + n) = O(2 * n).
Thus, the overall time complexity will be O(3 * n) = O(n) only.

SPACE COMPLEXITY : O(n)
We started with pushing all the elements into the stack. Hence we are using O(n) auxiliary space.*/