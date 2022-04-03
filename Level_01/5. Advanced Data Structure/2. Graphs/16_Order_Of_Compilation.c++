/*1. You are given a directed acyclic graph. The vertices represent tasks and edges represent 
    dependencies between tasks.
2. You are required to find and print the order in which tasks could be done. The task that should be 
    done at last should be printed first and the task which should be done first should be printed last. 
    This is called topological sort. Check out the question video for details.

Topological sort -> A permutation of vertices for a directed acyclic graph is called topological sort if 
                                    for all directed edges uv, u appears before v in the graph

Note -> For output, check the sample output and question video.

Constraints
None

Format
Input
Input has been managed for you

Output
Check the sample output

Example
Sample Input
7
7
0 1
1 2
2 3
0 3
4 5
5 6
4 6

Sample Output
4
5
6
0
1
2
3
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Edge{  
public:
  int src = 0; 
  int nbr = 0;
  Edge(int src, int nbr){
    this->src = src; 
    this->nbr = nbr;
  }
};

void ooc( vector<vector<Edge>> graph, int &src,vector<bool>&visited, stack<int>&st){
    visited[src] = true;
    for(Edge e: graph[src]){
        if(visited[e.nbr] == false){
            ooc(graph, e.nbr, visited, st); 
        }
    }
    st.push(src);
}

int main() {                                                                             
  int vtces;
  cin>>vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  int edges;
  cin>>edges;
  for(int i = 0; i < edges; i++ ) {  
    int u, v;  
    cin>>u>>v;   
    graph[u].push_back(Edge(u, v)); 
  } 
  vector<bool> visited(vtces,false);
  stack<int> st;
  for(int i = 0;i < vtces;i++){
      if(visited[i] == false){
          ooc(graph, i, visited, st);
      }
  }
  while(!st.empty()){
      cout<<st.top()<<endl;
      st.pop();
  }
  return 0;
}

/*Time Complexity: O(N + E)

Well, there is nothing magical here, just a simple variation of DFS to store the elements in a stack data structure. Hence the time complexity will be O(N + E) where N = number of vertices and E = number of edges.

Space Complexity: O(N)

Since, we are storing all the vertices in a stack data structure, also we will be using a visited array, the space complexity will be O(N). 
We are not considering the space of O(E) of the adjacency list, as it has been given to us in the form of input.*/