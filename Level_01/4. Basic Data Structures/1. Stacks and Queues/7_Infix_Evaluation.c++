/*1. You are given an infix expression.
2. You are required to evaluate and print it's value.

Constraints
1. Expression is balanced
2. The only operators used are +, -, *, /
3. Opening and closing brackets - () - are used to impact precedence of operations
4. + and - have equal precedence which is less than * and /. * and / also have equal precedence.
5. In two operators of equal precedence give preference to the one on left.
6. All operands are single digit numbers.

Format
Input
Input is managed for you

Output
Value of infix expression

Example
Sample Input
2 + 6 * 4 / 8 - 3

Sample Output
2*/

#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int pre(char ch){
    if(ch == '*'){
        return 2;
    }
    else if(ch == '/'){
        return 2;
    }
    else if(ch == '+'){
        return 1;
    }
    else{
        return 1;
    }
}

int operation(int v1, int v2, char ch){
    if(ch == '*'){
        return v1 * v2;
    }
    else if(ch == '/'){
        return v1 / v2;
    }
    else if(ch == '+'){
        return v1 + v2;
    }
    else{
        return v1 - v2;
    }
}

int main(){
    string str;
    getline(cin, str);
    stack<int> is;
    stack<char> cs;
    for(int i = 0; i < str.length(); i++){
        char ch = str.at(i);    
        if(isdigit(ch)){
            is.push(ch - '0');
        }
        else if(ch == '('){
            cs.push(ch);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(cs.size() > 0 && cs.top() != '(' && pre(ch) <= pre(cs.top())){
                int v2 = is.top();
                is.pop();
                int v1 = is.top();
                is.pop();
                char op = cs.top();
                cs.pop();      
                int ans = operation(v1, v2, op);
                is.push(ans);
            }
            cs.push(ch);
        }
        else if(ch == ')'){
            while(cs.size() > 0 && cs.top() != '('){
                int v2 = is.top();
                is.pop();
                int v1 = is.top();
                is.pop();
                char op = cs.top();
                cs.pop();        
                int ans = operation(v1, v2, op);
                is.push(ans);
            }
            if(cs.size() > 0){
                cs.pop();
            }
        }
    }
    while(cs.size() > 0){
        int v2 = is.top();
        is.pop();
        int v1 = is.top();
        is.pop();
        char op = cs.top();
        cs.pop();   
        int ans = operation(v1, v2, op);
        is.push(ans);
    }  
    int ans = is.top();
    is.pop();
    cout << ans; 
    return 0;
}

/*Time Complexity: O(n)

Space Complexity: O(n)*/