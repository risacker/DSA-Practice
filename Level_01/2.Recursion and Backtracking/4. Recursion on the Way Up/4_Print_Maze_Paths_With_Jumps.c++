/*1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of printMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
A number m

Output Format
Print paths (one path in each line) in order hinted by Sample output.

Constraints
0 <= n <= 5
0 <= m <= 5

Sample Input
3
3

Sample Output
h1h1v1v1
h1h1v2
h1v1h1v1
h1v1v1h1
h1v1d1
h1v2h1
h1d1v1
h2v1v1
h2v2
v1h1h1v1
v1h1v1h1
v1h1d1
v1h2v1
v1v1h1h1
v1v1h2
v1d1h1
v2h1h1
v2h2
d1h1v1
d1v1h1
d1d1
d2*/

#include<iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    if(sr > dr || sc > dc){
            return;
    }
    if(sr == dr && sc == dc){
            cout<<psf<<endl;
            return;
    }
    for(int jumps = 1; jumps <= dc - sc; jumps++){
            printMazePaths(sr, sc + jumps, dr, dc, psf + "h" + (to_string)(jumps));
    }
    for(int jumps = 1; jumps <= dr - sr; jumps++){
            printMazePaths(sr + jumps, sc, dr, dc, psf + "v" + (to_string)(jumps));
    }
    for(int jumps = 1; jumps <= dr - sr && jumps <= dc - sc; jumps++){
            printMazePaths(sr + jumps, sc + jumps, dr, dc, psf + "d" + (to_string)(jumps));
    }       
}

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
}

/*Time Complexity :  O(3m+n)
The time complexity of this procedure is O(3m+n) where n is the number of rows and m is the number of columns in the matrix. 
We have discussed the derivation of this complexity in GET MAZE PATHS WITH JUMPS ARTICLE. You may refer to the article to know how the time complexity is derived.

SPACE COMPLEXITY :  O(1)
The space complexity of this procedure is O(1) since we have not used any extra memory or any extra data structure.*/