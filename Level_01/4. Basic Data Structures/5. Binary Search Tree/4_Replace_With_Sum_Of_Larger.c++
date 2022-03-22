/*1. You are given a partially written BST class.
2. You are required to complete the body of rwsol function. "rwsol" function is expected to replace a node's value with sum of all nodes greater than it.
3. Input and Output is managed for you. 

Note -> Please watch the question video for clarity. Use the statis sum data member to complete your code.

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

Sample Output
311 <- 224 -> 87
336 <- 311 -> 274
. <- 336 -> .
. <- 274 -> .
162 <- 87 -> 0
. <- 162 -> .
. <- 0 -> .
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

int sumi=0;
void replacewithsum(Node* &root){
    if(root==nullptr){
        return;
    }
    replacewithsum(root->right);
    int x=root->data;
    root->data=sumi;
    sumi+=x;
    replacewithsum(root->left);
    
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

    Node* root= construct(arr);
    
    replacewithsum(root);

    display(root);
}

/*Time Complexity: O(n)

The time complexity for the function is linear as tree traversal is involved which is linear in terms of time complexity.

Space Complexity:O(logn)

The space complexity for the function is proportional to the height of the tree due to the recursion stack.*/