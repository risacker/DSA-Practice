/*1. You are given a partially written BinaryTree class.
2. You are required to complete the body of transBackFromLeftClonedTree function. The function is expected to convert a left-cloned tree back to it's original form. 
The left cloned tree is dicussed in previous question. In a left-clone tree a new node for every node equal in value to it is inserted between itself and it's left child. 
3. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you.

Output
Output is managed for you.

Example
Sample Input
37
50 50 25 25 12 12 n n n n 37 37 30 30 n n n n n n 75 75 62 62 n n 70 70 n n n n 87 87 n n n

Sample Output
25 <- 50 -> 75
12 <- 25 -> 37
. <- 12 -> .
30 <- 37 -> .
. <- 30 -> .
62 <- 75 -> 87
. <- 62 -> 70
. <- 70 -> .
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
Node *constructTree(vector<int> &arr){
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
    if(node==nullptr)
    {
        return nullptr;
    }
    Node *left=createLeftCloneTree(node->left);
    Node *right=createLeftCloneTree(node->right);
    Node *clone=new Node(node->data,left,nullptr);    
    node->left=clone;
    node->right=right;
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

We are traversing only n/2 nodes (skipping the duplicate nodes), hence total time complexity will be O(n/2) = O(n).

Space Complexity:-

We are not taking any extra space, in fact we are freeing up some space by deleting duplicate nodes. Hence, the solution takes O(1) auxiliary space.
Although, there is still recursion call stack space of O(d) where d = maximum depth of the tree.*/