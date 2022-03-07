/*1. You are given a partially written LinkedList class.
2. You are required to complete the body of kReverse function. The function is expected to tweak the list such that all groups of k elements in the list get reversed and linked. If the last set has less than k elements, leave it as it is (don't reverse).
3. Input and Output is managed for you.

Constraints
1. Time complexity -> O(n)
2. Space complexity -> constant

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
11
1 2 3 4 5 6 7 8 9 10 11
3
100
200

Sample Output
1 2 3 4 5 6 7 8 9 10 11 
3 2 1 6 5 4 9 8 7 10 11 
100 3 2 1 6 5 4 9 8 7 10 11 200*/

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
    
public:
    void kReverse(int k){
        linkedlist prev;
        while(this->size > 0){
            linkedlist curr;   
            if(this->size >= k){
                for(int i = 0; i < k; i++){
                    int val = this->getFirst();
                    this->removeFirst(val);
                    curr.addFirst(val);
                }
            }
            else{
                int sz = this->size;
                for(int i = 0; i < sz; i++){
                    int val = this->getFirst();
                    this->removeFirst(val);
                    curr.addLast(val);
                }
            }
            if(prev.size==0){
                prev = curr;
            }
            else{
                prev.tail->next = curr.head;
                prev.tail = curr.tail;
                prev.size += curr.size;
            }
        }
        this->head = prev.head;
        this->tail = prev.tail;
        this->size = prev.size;
    }
};
    
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
    linkedlist l = makeList();
    int k;
    cin >>k;
    int a;
    cin >>a;
    int b;
    cin >>b;
    cout<<l.toString()<< endl;
    l.kReverse(k);
    cout<<l.toString()<< endl;
    l.addLast(b);
    l.addFirst(a);
    cout<<l.toString()<< endl;
    return 0;
}

/*Time Complexity: O(n)

We are processing each node from the original linked list, and adding it in the current linked list (or directly to the previous linked list if size < k).
Hence, time complexity is equal to O(n) where n = number of nodes in linked list.

Space Complexity: O(1)

We are not using any extra space in this solution. 
As discussed in previous problems, we are REMOVING nodes from the given list and then only adding them into the current (or previous) list. 
Hence, only constant space O(1) is taken, to form new linked list's head, tail & size integer variables.*/