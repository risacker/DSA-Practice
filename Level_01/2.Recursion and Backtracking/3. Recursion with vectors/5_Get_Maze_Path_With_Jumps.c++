/*1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
A number m

Output Format
Contents of the arraylist containing paths as shown in sample output.

Constraints
0 <= n <= 10
0 <= m <= 10

Sample Input
2
2

Sample Output
[h1v1, v1h1, d1]*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
  if (sr == dr && sc == dc) {
    vector<string> empty_ans;
    empty_ans.push_back("");
    return empty_ans;
  }
  vector<string> ans;
  for (int jump = 1; jump + sc <= dc; jump++) {
    vector<string> h_paths = get_maze_paths(sr, sc + jump, dr, dc);
    for (string str : h_paths) {
      ans.push_back("h" + to_string(jump) + str);
    }
  }
  for (int jump = 1; jump + sr <= dr; jump++) {
    vector<string> v_paths = get_maze_paths(sr + jump, sc, dr, dc);
    for (string str : v_paths) {
      ans.push_back("v" + to_string(jump) + str);
    }
  }
  for (int jump = 1; jump + sr <= dr && jump + sc <= dc; jump++) {
    vector<string> d_paths = get_maze_paths(sr + jump, sc + jump, dr, dc);
    for (string str : d_paths) {
      ans.push_back("d" + to_string(jump) + str);
    }
  }
  return ans;
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }
  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);
  return 0;
}