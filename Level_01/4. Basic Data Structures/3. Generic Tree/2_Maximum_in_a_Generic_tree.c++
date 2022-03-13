/*1. You are given a partially written GenericTree class. 
2. You are required to complete the body of max function. The function is expected to find the node with maximum value and return it. 
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
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1

Sample Output
60*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp = new Node;
	temp->data = key;
	return temp;
}

Node *construct(int arr[],int n ){
    Node *root = NULL;
    stack<Node*>st;
    for(int i = 0;i < n;i++){
        if(arr[i] == -1){
            st.pop();
        }
        else{
            Node *t = newNode(arr[i]);
            if(st.size()>0){
                st.top()->children.push_back(t);
            }
            else{
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

int max1(Node *node)
{
   int m = INT_MIN;
   for(Node *child : node->children)
   {
       int cm = max1(child);
       m = max(m,cm);
   }
   m = max(m, node->data);
   return m;
}

int main(){ 
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node *root = construct(arr,n);
    int maximum = max1(root);
    cout<<maximum<<endl;
}  

/*Time Complexity: O(n)

The time complexity of the above solution is O(n) as we are traversing all the nodes of the tree to find the maximum value.

Space Complexity:-

Without Considering Recursion Space: Since we have not used any extra data structure therefore the space complexity of this solution is O(1).
Considering the Recursion Space: If we consider the recursion space then the stack has at most logn elements in it at a time (we will learn about this later in this section). So, the space complexity considering the recursion space will be O(logn).
Also, this is the best case and the average case space complexity. The worst case complexity will be O(n) if the tree is a skewed tree (if all the nodes are either on the left side or on the right side.)*/