/*1. You are given a partially written LinkedList class.
2. You are required to complete the body of fold function. The function is expected to place last element after 1st element, 2nd last element after 2nd element and so on. For more insight check the example

Example 1
1->2->3->4->5
will fold as
1->5->2->4->3

Example 2
1->2->3->4->5->6
1->6->2->5->3->4

Constraints
1. Time complexity -> O(n)
2. Space complexity -> Recursion space, O(n)

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
5
1 2 3 4 5
10
20

Sample Output
1 2 3 4 5 
1 5 2 4 3 
10 1 5 2 4 3 20*/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};

class linked_list{
private:
    node *head, *tail;
    int size=0;
    
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

  void addFirst(int val) 
   {
      node* temp = new node();
      temp->data = val;
      temp->next = head;
      head = temp;
      if (size == 0) {
        tail = temp;
      }
      size++;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;        
    }
     void display(){
      for(node* tmp = head; tmp != NULL; tmp = tmp->next){
        cout<<tmp->data<<" ";
      }
      cout<<endl;
    }
    
    node* pleft;
    int IsPalindromeHelper(node* right){
      if(right == NULL){
        return 1;
      }
      int rres = IsPalindromeHelper(right->next);
      if(rres == 0){
        return 0;
      } 
      else if(pleft->data != right->data){
        return 0;
      } 
      else {
        pleft = pleft->next;
        return 1;
      }
    }
    
    int isPalindrome(){
      pleft = head;
      return IsPalindromeHelper(head);
    }
    
    node *fleft;
    void foldHelper(node *  right, int floor) {  
      if (right == NULL) {
        return;
      }
        // cout<<"11";
      foldHelper(right->next, floor + 1);
      if (floor > size / 2) {
        node* temp = fleft->next;
        fleft->next = right;
        right->next = temp;
        fleft = temp;
      } 
      else if(floor == size / 2){
        tail = right;
        tail->next = NULL;
      }  
    }
     
    void  fold() {
      fleft  = head;
      foldHelper(head, 0);  
    }
};

int main(){    
    int b ;
    cin>>b;
    linked_list a;
    vector<int> arr(b,0);
    for(int i=0;i<b;i++){            
        cin>>arr[i];
        a.add_node(arr[i]);
    }
    int c;
    cin>>c;
    int d;
    cin>>d;
    a.display();
    a.fold();
    a.display();
    a.addFirst(c);
    a.add_node(d);
    a.display();
};

/*Time Complexity: O(n)

Here we are again simply visiting the nodes recursively there are n nodes. And each visit takes constant time, hence O(n) time complexity overall.

Space Complexity: O(n)

Even though we are not using any auxiliary space, we are using the run-time stack n times to store the params of the recursive function. So it will be O(n) as well.*/