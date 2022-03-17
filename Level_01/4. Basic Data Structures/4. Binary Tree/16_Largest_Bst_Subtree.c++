/*1. You are given a partially written BinaryTree class.
2. You are required to find the root of largest sub-tree which is a BST. Also, find the number of nodes in that sub-tree.
3. Input is managed for you.

Constraints
Time complexity must be O(n)
Space should not be more than required for recursion (call-stack)

Format
Input
Input is managed for you.

Output
@

Example
Sample Input
15
50 25 12 n n 37 n n 75 62 n n 87 n n

Sample Output
50@7*/

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

class Pair{
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

class bst{
public:
    bool isbst = false;
    int max = 0;
    int min = 0;
    Node *root = nullptr;
    int size = 0;
};
 
bst Bst(Node *node){    
    if(node == nullptr){
        bst bres;
        bres.isbst = true;
        bres.max = INT_MIN;
        bres.min = INT_MAX;
        return bres;
    }
    bst l = Bst(node->left);
    bst r = Bst(node->right); 
    bst ans; 
    ans.max = max(node->data, max(l.max,r.max));
    ans.min = min(node->data,min(l.min,r.min)); 
    if(l.isbst==true && r.isbst==true && (l.max < node->data && r.min > node->data)){
        ans.isbst=true;
    }  
    if(ans.isbst == true){
        ans.root = node;
        ans.size = l.size + r.size +1;
    }
    else if(l.size > r.size){
        ans.root = l.root;
        ans.size = l.size;
    }
    else{
        ans.root = r.root;
        ans.size = r.size;
    } 
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        string tmp;
        cin>>tmp;
        if (tmp=="n"){
            arr[i] = -1;
        } 
        else{
            arr[i] = stoi(tmp);
        }
    } 
    Node *root = constructTree(arr);
    bst r = Bst(root);
    cout<<r.root->data<<"@"<<r.size;  
}

/*TIME COMPLEXITY: O(n)

The time complexity of the above solution is O(n) as we are visiting every node to check whether it is balanced or not.

Space Complexity: O(h)

If space required for recursion (call-stack) is not included.*/