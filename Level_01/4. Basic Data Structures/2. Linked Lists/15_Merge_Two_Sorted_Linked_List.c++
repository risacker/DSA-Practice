/*1. You are given a partially written LinkedList class.
2. You are required to complete the body of mergeTwoSortedLists function. The function is static and is passed two lists which are sorted. The function is expected to return a new sorted list containing elements of both lists. Original lists must stay as they were.
3. Input and Output is managed for you.

Constraints
1. O(n) time complexity and constant space complexity expected.

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
5
10 20 30 40 50
10
7 9 12 15 37 43 44 48 52 56

Sample Output
7 9 10 12 15 20 30 37 40 43 44 48 50 52 56 
10 20 30 40 50 
7 9 12 15 37 43 44 48 52 56 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class linkedlist{    
public:
 class Node
    {
    public:
        int data = 0;
        Node *next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };

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
        else{
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
        else{
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
        else{
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

    void mergeTwoSortedLists(linkedlist l1, linkedlist l2) {
          Node* one = l1.head;
          Node* two = l2.head;
          while(one != nullptr && two != nullptr){
              if(one->data < two->data){
                  this->addLast(one->data);
                  one = one->next;
              }
              else{
                  this->addLast(two->data);
                  two = two->next;
              }
          }
          while(one!=nullptr){
              this->addLast(one->data);
              one = one->next;
          }
          while(two !=nullptr){
              this->addLast(two->data);
              two = two->next;
          }
    }
};

int main(){
    linkedlist l1;
    linkedlist l2;
    int n1;
    cin>>n1;
    for (int i = 0; i <n1; i++)
    {
        int val;
        cin>>val;      
        l1.addLast(val);
    }
    int n2;
    cin>>n2;
    for (int i = 0; i<n2; i++)
    {
        int val;
        cin>>val;      
        l2.addLast(val);
    }
    linkedlist  merged; 
    merged.mergeTwoSortedLists(l1, l2);
    cout << merged.toString() << endl;
    cout << l1.toString() << endl;
    cout << l2.toString() << endl;
    return 0;
}

/*Time Complexity: O(n)

Time complexity is linear due to the use of "while loop" in the code.

Space Complexity: O(n)

The space complexity of a linked list is of order n as it increases linearly with the increase in the number of nodes.*/