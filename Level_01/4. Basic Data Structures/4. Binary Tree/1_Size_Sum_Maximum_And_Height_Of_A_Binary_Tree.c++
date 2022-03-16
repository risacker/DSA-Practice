/*1. You are given a partially written BinaryTree class.
2. You are required to complete the body of size, sum, max and height function. The functions are expected to
    2.1. size - return the number of nodes in BinaryTree
    2.2. sum - return the sum of nodes in BinaryTree
    2.3. max - return the highest node in BinaryTree
    2.4. height - return the height of tree in terms of edges
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
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
9
448
87
3*/

#include<iostream>
#include<climits>
#include<string.h>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair{
    public:
    Node * node = nullptr;
    int state=0;
    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{
    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;
    display(node->left);
    display(node->right);
}

int size(Node *node)
{
    return node == nullptr ? 0 : size(node->left) + size(node->right) + 1;
}

int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; 
}

int maximum(Node *node)
{
    return node == nullptr ? -1e8 : max(max(maximum(node->left), maximum(node->right)), node->data);
}

int sum(Node *root){
    
    return root==nullptr ? 0 : sum(root->left) + sum(root->right)+root->data;
}

int main(){
  int n;
  cin>>n; 
  vector<int> arr(n,0);
  for(int i = 0; i < n; i++){
      string temp;
      cin>>temp;   
      if(temp=="n")
      {
        arr[i] = -1;  
      }
      else
      {
        arr[i] = stoi(temp); 
      }
    }
    Node *root = constructTree(arr);
    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout<<sz<<endl;
    cout<<sm<<endl;
    cout<<max<<endl;
    cout<<ht<<endl;
}

/*Time Complexity: O(n)

The time complexity for the function is linear as tree traversal is involved which is linear in terms of time complexity. 
Also each element is pushed and popped out only once.

Space Complexity: O(n)

The space complexity for the function is proportional to the space used by stack, which can be O(n) at max*/