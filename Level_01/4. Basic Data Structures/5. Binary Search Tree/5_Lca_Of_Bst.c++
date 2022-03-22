/*1. You are given a partially written BST class.
2. You are required to complete the body of lca function. "lca" function is expected to find the lowest commong ancestor of d1 and d2.
3. Input and Output is managed for you. 

Note -> Please watch the question video for clarity.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
21
50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
12
30

Sample Output
25*/

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

int ans;
int lca(Node* root,int a,int b){
    if(root== nullptr){
        return 0;
    }
    if(root->data > a && root->data > b){
        ans=root->left->data;
        lca(root->left,a,b);
        return ans;
    }
    else if(root->data < a && root->data < b){
        ans=root->right->data;
        lca(root->right,a,b);
        return ans;
    }
    
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
    int a,b;
    cin >> a >> b;
    Node* root= construct(arr);
    ans=root->data;
    lca(root,a,b);
    cout << ans << endl;
    
}

/*Time Complexity: O(h)

The time complexity of this program is of order h where h = height of the tree.

Space Complexity: O(1)

O(1) not including the space used for stack call in recursion.*/