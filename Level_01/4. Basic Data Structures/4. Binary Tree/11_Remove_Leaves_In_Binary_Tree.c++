/*1. You are given a partially written BinaryTree class.
2. You are required to complete the body of removeLeaves function. The function is expected to remove all leaf nodes from the tree.
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
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
25 <- 50 -> 75
. <- 25 -> 37
. <- 37 -> .
62 <- 75 -> .
. <- 62 -> .
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
    Node(int data)
    {
        this->data = data;
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
    if(node == nullptr){
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

Node *removeLeaves(Node *node){
    if(node == nullptr)
    return nullptr;  
    if(node->left == nullptr && node->right == nullptr)
    {
        free(node);
        return nullptr;
    }   
    node->left = removeLeaves(node->left);
    node->right = removeLeaves(node->right);
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
        root = removeLeaves(root);
        display(root);
}

/*Time Complexity: O(n)

The time complexity of the above solution is O(n) as we are visiting every node in the tree to check whether it is a leaf node or not.

Space Complexity: O(1)

The space complexity of the above solution is O(1) as we are not using any extra data structure or memory. 
If we consider the recursion space then the time complexity of the above solution will become O(log2n) as the maximum height of the stack at any point of time will be O(log2n) which is also the height of the tree.*/