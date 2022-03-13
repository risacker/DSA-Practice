/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of levelorderLineWise function. The function is expected to visit every node in "levelorder fashion" and print them from left to right (level by level). All nodes on same level should be separated by a space. Different levels should be on separate lines. Please check the question video for more details.
3. Input is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
All nodes from left to right (level by level) all separated by a space.
All levels on separate lines starting from top to bottom.

Example
Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1

Sample Output
10 
20 30 40 
50 60 70 80 90 100 
110 120

#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node
{
public:
  int data = 0;
  vector<Node *> children;
  Node(int data)
  {
    this->data = data;
  }
};

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }
  cout << s << "." << endl;
  for (Node *child : node->children)
  {
    display(child);
  }
}

Node *constructor01(vector<int> &arr)
{
  if (arr.size() == 0)
    return NULL;
  vector<Node *> stack;
  stack.push_back(new Node(arr[0]));
  Node *root = stack[0];
  for (int i = 1; i < arr.size(); i++){
    if (arr[i] != -1){
      Node *node = stack.back();
      Node *nnode = new Node(arr[i]);
      node->children.push_back(nnode);
      stack.push_back(nnode);
    }
    else
      stack.pop_back();
  }
  return root;
}

Node *linearize(Node *node)
{
  if (node->children.size() == 0)
    return node;
  Node *finalTail = linearize(node->children.back());
  for (int i = node->children.size() - 2; i >= 0; i--)
  {
    Node *tail = linearize(node->children[i]);
    tail->children.push_back(node->children.back());
    node->children.pop_back();
  }
  return finalTail;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node * root = constructor01(arr); 
   linearize(root);
   display(root); 
}

int main(){
    solve();
    return 0;
}
*/