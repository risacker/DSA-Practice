/*1. You are given a partially written GenericTree class. 
2. You are require to complete the body of function IterativePreandPostOrder. The function does not use recursion and prints preorder and postorder of the tree. 
Both orders are printed in separate lines (preorder first, followed by post order in next line). Elements in an order are separated by space. 
3. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
Elements in preorder separated by a space
Elements in postorder separated by a space

Example
Sample Input
24
10 20 -50 -1 60 -1 -1 30 70 -1 -80 110 -1 -120 -1 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
10 20 -50 60 30 70 -80 110 -120 90 40 -100 
-50 60 20 70 110 -120 -80 90 30 -100 40 10*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*>children;
};

void iterativePreAndPostOrder(Node* root){
	stack<pair<Node*, int>>st;
	st.push({root,-1});
	string preorder;
	string postorder;
	while(st.size() > 0){
		pair<Node*,int> top = st.top();
		st.pop();
		if(top.second == -1){
			preorder+=to_string(top.first->data)+" ";
			top.second++;
			st.push(top);
		}
		else if(top.second >= 0 and top.second<top.first->children.size()){
			pair<Node*,int> cp(top.first->children[top.second],-1);
			top.second++;
			st.push(top);
			st.push(cp);
		}
		else{
			postorder += to_string(top.first->data)+" ";
		}
	}
	cout<<preorder<<endl;
	cout<<postorder<<endl;
}

Node* construct(vector<int>&arr) {
    Node* root = nullptr;
    stack <Node*> st;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == -1) {
        st.pop();
      } e
      lse {
        Node* t = new Node();
        t->data = arr[i];
        if (st.size() > 0) {
          st.top()->children.push_back(t);
        } 
        else {
          root = t;
        }
        st.push(t);
      }
    }
    return root;
}
  
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i = 0;i < n;i++){
        cin>>x;
        arr.push_back(x);
    }
    Node *root = construct(arr);
    iterativePreAndPostOrder(root);
}

/*Time Complexity: O(n)

The time complexity for the function is linear as tree traversal is involved which is linear in terms of time complexity.

Space Complexity: O(logn)

The space complexity for the function is proportional to the height of the stack.*/