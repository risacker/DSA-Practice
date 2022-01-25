/*1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
Use the input-output below to get more understanding on what is required
123 -> abc, aw, lc
993 -> iic
013 -> Invalid input. A string starting with 0 will not be passed.
103 -> jc
303 -> No output possible. But such a string maybe passed. In this case print nothing.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A string str

Output Format
Permutations of str in order hinted by Sample output.

Constraints
0 <= str.length <= 10

Sample Input
655196

Sample Output
feeaif
feesf*/

#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    if(str[0] == '0'){
        return;
    }
    string s1 = str.substr(0,1);
    string ros1 = str.substr(1);
    printEncoding(ros1,asf + (char)(stoi(s1) + 'a' - 1));
    if(str.length() >= 2){
        string s2 = str.substr(0,2);
        string ros2 = str.substr(2);
        if(stoi(s2) <= 26)
        printEncoding(ros2,asf + (char)(stoi(s2) + 'a' - 1));
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}

/*Time Complexity : O(2^n)
We can make atmax 2 decisions (1-length number or 2-length number), hence the time complexity will be O(2^n) (exponential in nature).

SPACE COMPLEXITY : O(n)
If we consider the space taken by the recursion call stack, then space complexity will be O(n) as the maximum depth of the recursion stack at any point can be equal to the length of the numeric string.*/