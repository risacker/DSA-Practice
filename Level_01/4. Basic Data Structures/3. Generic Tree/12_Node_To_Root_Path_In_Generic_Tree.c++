/*1. You are given a partially written GenericTree class. 
2. You are required to complete the body of nodeToRootPath function. The function is expected to return in form of linked list the path from element to root, if the element with data is found. 
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
120

Sample Output
[120, 80, 30, 10]


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
  s += to_string(node->data) + " Child: ";
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


bool find(Node *node, int data)
{
  if (node->data == data)
  {
    return true;
  }

  for (Node *child : node->children)
  {
    bool ans = find(child, data);
    if(ans == true) 
    {
      return true;
    }
  }

  return false;
}



void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i = 0; i < arr.size(); i++)
    {
        cin>>arr[i];
    }
    
    int data;
    cin>>data;
   
    Node *root = constructor01(arr);
    bool flag = find(root,data);
    if(flag == true){
        cout <<"true"<<endl;
    }
    else{
        cout <<"false"<<endl;
    }
    
}

int main()
{
    solve();
    return 0;
}
*/