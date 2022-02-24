/*1. You are given an infix expression.
2. You are required to convert it to postfix and print it.
3. You are required to convert it to prefix and print it.

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
postfix
prefix

Example
Sample Input
a*(b-c+d)/e

Sample Output
abc-d+*e/
/*a+-bcde

*/

#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int pre(char ch){
    if(ch == '*'){
        return 2;
    }else if(ch == '/'){
        return 2;
    }else if(ch == '+'){
        return 1;
    }else{
        return 1;
    }
}

int main(){
    string str;
    getline(cin, str);
    stack<string> postFix;
    stack<string> preFix;
    stack<char> op;   
    for(int i = 0; i < str.length(); i++){
        char ch = str.at(i);     
        if(ch == '('){
            op.push(ch);         
        }
        else if( (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ){
            string s = string(1, ch);   
            postFix.push(s);
            preFix.push(s);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(op.size() > 0 && op.top() != '(' && pre(ch) <= pre(op.top())){
                char o = op.top();
                op.pop();
                string s = string(1, o);        
                string postVal2 = postFix.top();
                postFix.pop();
                string postval1 = postFix.top();
                postFix.pop();       
                postFix.push(postval1 + postVal2 + s);       
                string preval2 = preFix.top();
                preFix.pop();
                string preval1 = preFix.top();
                preFix.pop();       
                preFix.push(s + preval1 + preval2);
            }
            op.push(ch);
        }
        else if(ch == ')'){
            while(op.size() > 0 && op.top() != '('){
                char o = op.top();
                op.pop();
                string s = string(1, o);       
                string postVal2 = postFix.top();
                postFix.pop();
                string postval1 = postFix.top();
                postFix.pop();       
                postFix.push(postval1 + postVal2 + s);       
                string preval2 = preFix.top();
                preFix.pop();
                string preval1 = preFix.top();
                preFix.pop();       
                preFix.push(s + preval1 + preval2);
            }
            op.pop();
        }
    }
    
    while(op.size() > 0){
        char o = op.top();
        op.pop();
        string s = string(1, o);   
        string postVal2 = postFix.top();
        postFix.pop();
        string postval1 = postFix.top();
        postFix.pop();    
        postFix.push(postval1 + postVal2 + s);    
        string preval2 = preFix.top();
        preFix.pop();
        string preval1 = preFix.top();
        preFix.pop();    
        preFix.push(s + preval1 + preval2);
    }
    
    string post = postFix.top();
    string pre = preFix.top();
    cout << post << endl;
    cout << pre << endl;  
    return 0;
}