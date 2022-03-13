/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of removeLeaves function. The function is expected to remove all leaves from the tree. For more details, check out the question video.
3. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1

Sample Output
10 -> 20, 30, 40, .
20 -> .
30 -> 80, .
80 -> .
40 -> .*/

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
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] != -1)
    {
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

void removeLeaves(Node *node)
{
  vector<Node *> *childs = new vector<Node *>();
  for (Node *child : node->children)
  {
    if (child->children.size() != 0)
      childs->push_back(child);
  }
  node->children = *childs;
  for (Node *child : node->children)
  {
    removeLeaves(child);
  }
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
    removeLeaves(root);
    display(root);
}

int main()
{
    solve();
    return 0;
}

/*Time Complexity: O(n)

We are traversing all the nodes once, hence the time complexity will be O(n) where n = number of nodes in the generic tree.

Space Complexity: O(1)

We are not using any extra space in the form of any auxiliary data structure. Hence the space complexity is O(1).*/