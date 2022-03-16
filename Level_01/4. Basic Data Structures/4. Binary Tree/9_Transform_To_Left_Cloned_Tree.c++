/*1. You are given a partially written BinaryTree class.
2. You are required to complete the body of createLeftCloneTree function. The function is expected to create a new node for every node equal in value to it and inserted between itself and it's left child. 
3. Input and Output is managed for you.

Input Format
Input is managed for you.

Output Format
Output is managed for you. 

Constraints
None

Sample Input
15
50 25 12 n n 37 n n 75 62 n n 87 n n

Sample Output
50 <- 50 -> 75
25 <- 50 -> .
25 <- 25 -> 37
12 <- 25 -> .
12 <- 12 -> .
. <- 12 -> .
37 <- 37 -> .
. <- 37 -> .
75 <- 75 -> 87
62 <- 75 -> .
62 <- 62 -> .
. <- 62 -> .
87 <- 87 -> .
. <- 87 -> .
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data,Node *left,Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
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
    Node *node = new Node(arr[idx++],nullptr,nullptr);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node) {
    if (node == nullptr) {
      return;
    }
    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout<<str<<endl;
    display(node->left);
    display(node->right);
}

Node *createLeftCloneTree(Node *node){
    if(node == nullptr)
    {
        return nullptr;
    }
    Node *left = createLeftCloneTree(node->left);
    Node *right = createLeftCloneTree(node->right);
    Node *clone = new Node(node->data,left,nullptr);
    node->left = clone;
    node->right = right;
    return node;
  }
  
int main(){
        vector<int> arr;
        int n;
        cin>>n;    
        for(int i = 0; i<n; i++){
            string inp;
            cin>>inp;
            if(inp != "n"){
                arr.push_back(stoi(inp));
            }
            else{
                arr.push_back(-1);
            }
        }  
        Node *root = constructTree(arr);
        root = createLeftCloneTree(root);
        display(root);
}

/*Time Complexity: O(n)

We are traversing the entire tree and duplicating each node, hence the total time complexity is O(n) where n = number of nodes in the tree.

Space Complexity:-

If we take the space taken by the duplicate nodes created, then the space complexity will be O(n).
Also, the recursion stack space will take O(d) space where d = maximum depth of the binary tree.*/