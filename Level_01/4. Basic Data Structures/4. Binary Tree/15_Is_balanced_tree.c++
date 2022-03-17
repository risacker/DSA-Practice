/*1. You are given a partially written BinaryTree class.
2. You are required to check if the tree is balanced. A binary tree is balanced if for every node the gap between height's of it's left and right subtree is not more than 1.
3. Input is managed for you. 

Note -> Please refer the question video for clarity.

Constraints
Time complexity must be O(n)
Space should not be more than required for recursion (call-stack)

Format
Input
Input is managed for you.

Output
true if the tree is balanced, false otherwise

Example
Sample Input
21
50 25 12 n n 37 30 n n 51 n n 75 62 60 n n 70 n n n

Sample Output
false*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data=0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair {
    public:
    Node *node=nullptr;
    int state=0;
    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr){
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

void display(Node *node){
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout<<str<<endl;
    display(node->left);
    display(node->right);
}

int height(Node *node){
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; 
}

bool isbal = true;
int isbalance(Node *node){
      if(node == nullptr)
      {
          return -1;
      }     
      int l = isbalance(node->left);
      int r = isbalance(node->right);     
      int gap = abs(l-r);
      if(gap>1)
      {
          isbal = false;
      }
      int th = max(l,r)+1;     
      return th;
}

int main(){
    int n;
    cin>>n;  
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        string tmp;
        cin>>tmp;
      if (tmp=="n") {
        arr[i] = -1;
      } 
      else {
        arr[i] = stoi(tmp);
      }
    }    
    Node *root = constructTree(arr);
    int r = isbalance(root);
    if(isbal == 1)
       cout << "true";
    else 
       cout<<"false";
}

/*Time Complexity: O(n)

The time complexity of the above solution is O(n) as we are visiting every node to check whether it is balanced or not.

Space Complexity: O(h)

The space complexity for the above code is O(1) as we have not used any extra data structure. 
If we consider the recursion space then the space complexity will be O(log2n) because this is the max height of the stack at any time during the recursion. 
This is equal to the height of the tree.*/