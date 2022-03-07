/*1. You are given a partially written LinkedList class.
2. You are required to complete the body of addLinkedLists function. The function is passed two linked lists which represent two numbers - the first element is the most significant digit and the last element is the least significant digit. The function is expected to add the two linked list and return a new linked list.

The following approaches are not allowed :
    1. Don't reverse the linked lists in order to access them from least significant digit 
     to most significant.
    2. Don't use arrays or explicit extra memory.
    3. Don't convert linked lists to number, add them up and convert the result back 
     to a linked list.

Hint - You are expected to take help of recursion to access digits from least significant to most significant. You have to tackle the challenge of unequal size of lists and manage carry where required.

3. Input and Output is managed for you. 

Note-> Make sure to set head and tail appropriately because addFirst and addLast has been used to test their values in the input-output code.

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
1
1
3
9 9 9
10
20

Sample Output
1 
9 9 9 
1 0 0 0 
10 1 0 0 0 20 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
        int data = 0;
        Node *next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
};

class linkedlist{    
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    int size_()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    string toString()
    {
        Node *curr = this->head;
        string sb = "";
        while (curr != nullptr)
        {
            sb += to_string(curr->data);
            if (curr->next != nullptr)
                sb += " ";
            curr = curr->next;
        }
        return sb;
    }

private:
    void addFirstNode(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }
        this->size++;
    }

public:
    void addFirst(int val)
    {
        Node *node = new Node(val);
        addFirstNode(node);
    }

public:
    void addLastNode(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            this->tail->next = node;
            this->tail = node;
        }
        this->size++;
    }

    void addLast(int val)
    {
        Node *node = new Node(val);
        addLastNode(node);
    }

    void addNodeAt(Node *node, int idx)
    {
        if (idx == 0)
            addFirstNode(node);
        else if (idx == this->size)
            addLastNode(node);
        else
        {
            Node *prev = getNodeAt(idx - 1);
            Node *curr = prev->next;
            prev->next = node;
            curr->next = node;
            this->size++;
        }
    }

    void addAt(int data, int idx)
    {
        if (idx < 0 || idx > this->size)
        {
            throw("invalidLocation: " + to_string(idx));
        }
        Node *node = new Node(data);
        addNodeAt(node, idx);
    }

    Node *removeFirstNode()
    {
        Node *node = this->head;
        if (this->size == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            this->head = this->head->next;
            node->next = nullptr;
        }
        this->size--;
        return node;
    }

    int removeFirst(int val)
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException: -1");
        }
        Node *node = removeFirstNode();
        int rv = node->data;
        delete node;
        return rv;
    }

    Node *removeLastNode()
    {
        Node *node = this->tail;
        if (this->size == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node *prev = getNodeAt(this->size - 2);
            this->tail = prev;
            prev->next = nullptr;
        }
        this->size--;
        return node;
    }

    int removeLast(int val)
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException: -1");
        }
        Node *node = new Node(val);
        int rv = node->data;
        delete node;
        return rv;
    }

    Node *removeNodeAt(int idx)
    {
        if (idx == 0)
            return removeFirstNode();
        else if (idx == this->size - 1)
            return removeLastNode();
        else
        {
            Node *prev = getNodeAt(idx - 1);
            Node *curr = prev->next;
            prev->next = curr->next;
            curr->next = nullptr;
            this->size--;
            return curr;
        }
    }

    int removeAt(int idx)
    {
        if (idx < 0 || idx >= this->size)
        {
            throw("invalidLocation: " + idx);
        }
        Node *node = removeNodeAt(idx);
        int rv = node->data;
        delete node;
        return rv;
    }

    Node *getFirstNode()
    {
        return this->head;
    }

    int getFirst()
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException: -1");
        }
        Node *node = getFirstNode();
        return node->data;
    }

    Node *getLastNode()
    {
        return this->tail;
    }

    int getLast()
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException");
        }
        Node *node = getLastNode();
        return node->data;
    }

    Node *getNodeAt(int idx)
    {
        Node *curr = this->head;
        while (idx-- > 0)
        {
            curr = curr->next;
        }
        return curr;
    }

    int getAt(int idx)
    {
        if (idx < 0 || idx >= this->size)
        {
            throw("invalidLocation: " + idx);
        }
        Node *node = getNodeAt(idx);
        return node->data;
    }
};

    Node* getMid(Node* head, Node* tail){
        Node* slow = head, *fast = head;
        while(fast->next != tail && fast->next->next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }     
        return slow;
    }

    //merge two sorted linkedlist
    linkedlist mergeTwoSortedLists(linkedlist l1, linkedlist l2){
          linkedlist ans;
          Node* one = l1.head;
          Node* two = l2.head;
          while(one != nullptr && two != nullptr){
              if(one->data < two->data){
                  ans.addLast(one->data);
                  one = one->next;
                }
              else{
                  ans.addLast(two->data);
                  two = two->next;
                }
            }
          while(one!=nullptr){
              ans.addLast(one->data);
              one = one->next;
            }
          while(two !=nullptr){
              ans.addLast(two->data);
              two = two->next;
            }      
        return ans;
    }
    
    linkedlist mergeSort(Node* head,Node* tail){
        if(head == tail){
            linkedlist base;
            base.addLast(head->data);
            return base;
        }    
        Node* mid = getMid(head,tail);
        linkedlist fsh = mergeSort(head, mid);
        linkedlist ssh = mergeSort(mid->next, tail);   
        return mergeTwoSortedLists(fsh,ssh);
    }
    
    int addTwoLists(Node* on, Node* tn, int pio, int pit, linkedlist & res){
      if(on == nullptr && tn == nullptr){
        return 0;
      }
      int carry = 0;
      int data = 0;
      if(pio > pit){
        carry = addTwoLists(on->next, tn, pio - 1, pit, res);
        data = carry + on->data;
      } 
      else if(pio < pit){
        carry = addTwoLists(on, tn->next, pio, pit - 1, res);
        data = carry + tn->data;
      } 
      else {
        carry = addTwoLists(on->next, tn->next, pio - 1, pit - 1, res);
        data = carry + on->data + tn->data;
      }
      carry = data / 10;
      data = data % 10;
      res.addFirst(data);
      return carry;
    }

    linkedlist addTwoLists(linkedlist one, linkedlist two) {
    linkedlist res ;
    int carry = addTwoLists(one.head, two.head, one.size, two.size, res);
    if(carry > 0){
        res.addFirst(carry);
    }
      return res;
    }
    
linkedlist makeList() {
    linkedlist l;
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        l.addLast(val);
    }
    return l;
}

int main(){
   linkedlist l= makeList();
   linkedlist m= makeList();
   int a;
   cin>>a;
   int b;
   cin>>b;
   linkedlist res= addTwoLists(l,m);
    cout << l.toString() << endl;
    cout << m.toString() << endl;
    cout << res.toString() << endl;
    res.addFirst(a);
    res.addLast(b);
    cout << res.toString() << endl;
    return 0;
}

/*Time Complexity: O(n)

Since recursion calls are made in this program, therefore its complexity is linear.

Space Complexity: O(n)

The recursion space used in this program is of order n hence the space complexity is linear.*/