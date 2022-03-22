/*1. You are given a partially written BST class.
2. You are required to complete the body of remove function. "remove" function is expected to remove a new node with given data to the tree and return the new root.
3. Input and Output is managed for you. 

Note -> Please watch the question video to figure out the algorithm required for deletion. It specifies some requirements of the question as well.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
15
50 25 12 n n 37 n n 75 62 n n 87 n n
62

Sample Output
25 <- 50 -> 75
12 <- 25 -> 37
. <- 12 -> .
. <- 37 -> .
. <- 75 -> 87
. <- 87 -> .
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* construct(vector<int> & arr){
    Node* root=new Node(arr[0]);
    pair<Node*,int> p={root,1};

    stack<pair<Node*,int>> st;
    st.push(p);

    int idx=1;
    while(!st.empty()){
        
        if(st.top().second==1){
            st.top().second++;
            if(arr[idx]!=-1){
                st.top().first->left=new Node(arr[idx]);
                pair<Node*,int> lp={st.top().first->left,1};
                st.push(lp);
            }
            else{
                st.top().first->left=nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->right = new Node(arr[idx]);
                pair<Node*,int> rp={st.top().first->right,1};
                st.push(rp);
            } else {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else {
            st.pop();
        }

    }
    return root;
}
void display(Node* node) {
    if (node == nullptr) {
        return;
    }

    string str = " <- " + to_string(node->data) + " -> ";

    string left = (node->left == nullptr) ? "." :  "" + to_string(node->left->data);
    string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

    str = left + str + right;
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int max(Node* root){
    if(root->right== nullptr){
        return root->data;
    }
    return max(root->right);
}


Node* remove(Node* root,int data){
    if(root== nullptr){
        return nullptr;
    }
    if(data<root->data){
        root->left= remove(root->left,data);

    }
    else if(data>root->data){
        root->right=remove(root->right,data);
    }
    else{
        if(root->left!= nullptr&& root->right!= nullptr){
            int lmx=max(root->left);
            root->data=lmx;
            root->left=remove(root->left,lmx);
        }
        else if(root->left!= nullptr){
            return root->left;
        } else if(root->right!= nullptr){
            return root->right;
        }
        else{
            return nullptr;
        }
    }

    return root;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        if(x=="n"){
            arr[i]=-1;

        }
        else{
            arr[i]=stoi(x);
        }
    }
    int data;
    cin >> data;
    Node* root= construct(arr);
    
    root=remove(root,data);

    display(root);
}

/*Time Complexity: O(logn)

The time complexity for the function is proportional to the height of the binary search tree as for every call we are neglecting one of the subtrees.

Space Complexity: O(logn)

The space complexity for the function is proportional to the height of the tree due to the recursion stack.*/