/*1. You are given a string str.
2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
Use sample input and output to take idea about permutations.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A string str

Output Format
Permutations of str in order hinted by Sample output

Constraints
0 <= str.length <= 7

Sample Input
abc

Sample Output
abc
acb
bac
bca
cab
cba*/

#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    for(int i = 0 ; i < str.length(); i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        printPermutations(ros,asf + ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
} 

/*SPACE COMPLEXITY : O(n!)
the time complexity of the above problem is O(n!).

SPACE COMPLEXITY : O(1)
The space complexity of the above problem is O(1) as we have not used any extra space or data structure.*/