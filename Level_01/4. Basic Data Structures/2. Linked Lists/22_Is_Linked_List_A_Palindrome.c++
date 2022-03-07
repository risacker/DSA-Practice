/*1. You are given a partially written LinkedList class.
2. You are required to complete the body of IsPalindrome function. The function is expected to check if the linked list is a palindrome or not and return true or false accordingly.
3. Input and Output is managed for you.

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
1 2 3 2 1

Sample Output
true*/

#include <bits/stdc++.h>
using namespace std;

class node{
public :
    int data;
    node *next;
};

class linked_list{
public:
    node *head,*tail;
    int size=0;
    
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
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
      else{
        pleft = pleft->next;
        return 1;
      }
    }
    
    int isPalindrome(){
      pleft = head;
      return IsPalindromeHelper(head);
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
    int res = a.isPalindrome();
    if(res==1)
       cout<<"true";
    else
       cout<<"false";
    return 0;
}

/*Time Complexity: O(n)

This is an O(n) solution because all you need to do is look at the recursive stack. How many items/nodes do you see? Yes. n items where n is the size of the linked list.
And in each recursive call, we are doing constant-time operations. So it will be O(n).

Space Complexity: O(n)

Even though we are not using any auxiliary space, we are using the run-time stack n times to store the params of the recursive function. So it will be O(n) as well.*/