/*1. You are given a string str.
2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
Use sample input and output to take idea about subsequences.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A string str

Output Format
Contents of the arraylist containing subsequences as shown in sample output.

Constraints
0 <= str.length <= 20

Sample Input
abc

Sample Output
[, c, b, bc, a, ac, ab, abc]*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    if (s == ""){
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }
    char ch = s[0];
    string ros = s.substr(1);
    vector<string> rres = gss(ros);
    vector<string> mres;
    for (string s : rres){
        mres.push_back(s);
    }
    for (string s : rres){
        mres.push_back(ch + s);
    }
    return mres;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;
    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}