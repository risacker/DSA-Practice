/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of linearize function. The function is expected to create a linear tree i.e. every node will have a single child only. For details check the question video.
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
10 -> 20, .
20 -> 50, .
50 -> 60, .
60 -> 30, .
30 -> 70, .
70 -> 80, .
80 -> 110, .
110 -> 120, .
120 -> 90, .
90 -> 40, .
40 -> 100, .
100 -> .
*/

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

int main()
{
    solve();
    return 0;
}

/*Time Complexity: O(n^2)

We have visited every node to linearize it. Although the leaf nodes do not get linearized, still we have visited them and so, we have visited n nodes. 
Also, when we visit them and try to linearize them, we visit all the nodes after linearizing in order to find the tail and add the next node in the pre-order to its children's ArrayList. 
This happens inside the first loop of traversal. So, in a way- we have a nested loop where we are visiting almost n elements every time. So, the time complexity is O(n^2).

Space Complexity: O(1)

The space complexity remains O(1) since we haven't used any extra space.*/