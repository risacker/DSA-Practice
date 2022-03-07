/* 1. You are given a partially written LinkedList class.
2. You are required to complete the body of removeDuplicates function. The function is called on a sorted list. The function must remove all duplicates from the list in linear time and constant space
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
10
2 2 2 3 3 5 5 5 5 5

Sample Output
2 2 2 3 3 5 5 5 5 5 
2 3 5*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data = 0;
  Node* next = nullptr;

  Node(int data)
  {
    this->data = data;
  }
};

class linkedlist{
public:
  Node* head = nullptr;
  Node* tail = nullptr;
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
    Node* curr = this->head;
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
  void addFirstNode(Node* node)
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
    Node* node = new Node(val);
    addFirstNode(node);
  }

public:
  void addLastNode(Node* node)
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
    Node* node = new Node(val);
    addLastNode(node);
  }

  void addNodeAt(Node* node, int idx)
  {
    if (idx == 0)
      addFirstNode(node);
    else if (idx == this->size)
      addLastNode(node);
    else
    {
      Node* prev = getNodeAt(idx - 1);
      Node* curr = prev->next;
      prev->next = node;
      curr->next = node;
      this->size++;
    }
  }

  void addAt(int data, int idx)
  {
    if (idx < 0 || idx > this->size)
    {
      throw ("invalidLocation: " + to_string(idx));
    }
    Node* node = new Node(data);
    addNodeAt(node, idx);
  }

  Node* removeFirstNode()
  {
    Node* node = this->head;
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
  
  void removeFirst()
  {
    if (this->size == 0)
    {
      throw ("nullptrPointerException: -1");
    }
    Node* node = removeFirstNode();
    int rv = node->data;
    delete node;
  }

  Node* removeLastNode()
  {
    Node* node = this->tail;
    if (this->size == 1)
    {
      this->head = nullptr;
      this->tail = nullptr;
    }
    else
    {
      Node* prev = getNodeAt(this->size - 2);
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
      throw ("nullptrPointerException: -1");
    }
    Node* node = new Node(val);
    int rv = node->data;
    delete node;
    return rv;
  }

  Node* removeNodeAt(int idx)
  {
    if (idx == 0)
      return removeFirstNode();
    else if (idx == this->size - 1)
      return removeLastNode();
    else
    {
      Node* prev = getNodeAt(idx - 1);
      Node* curr = prev->next;
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
      throw ("invalidLocation: " + idx);
    }
    Node* node = removeNodeAt(idx);
    int rv = node->data;
    delete node;
    return rv;
  }

  Node* getFirstNode()
  {
    return this->head;
  }

  int getFirst()
  {
    if (this->size == 0)
    {
      throw ("nullptrPointerException: -1");
    }
    Node* node = getFirstNode();
    return node->data;
  }

  Node* getLastNode()
  {
    return this->tail;
  }

  int getLast()
  {
    if (this->size == 0)
    {
      throw ("nullptrPointerException");
    }
    Node* node = getLastNode();
    return node->data;
  }

  Node* getNodeAt(int idx)
  {
    Node* curr = this->head;
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
      throw ("invalidLocation: " + idx);
    }

    Node* node = getNodeAt(idx);
    return node->data;
  }

public:
  void removeDuplicates() {
    linkedlist res;
    while (this->size > 0) {
      int val = this->getFirst();
      this->removeFirst();
      if (res.size == 0 || val != res.tail->data) {
        res.addLast(val);
      }
    }
    this->head = res.head;
    this->tail = res.tail;
    this->size = res.size;
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

int main()
{
  linkedlist l = makeList();
  cout << l.toString() << endl;
  l.removeDuplicates();
  cout << l.toString() << endl;
  return 0;
}

/*Time Complexity: O(n)

As we are calling removeFirst() method on original linked list for n times (n = size of linked list), thus time taken will be n * O(1) = O(n).
For some nodes, we are calling addLast() method on the resultant linked list. 
In worst case, when all nodes are distinct/unique, we will call addLast() for n times, thus time taken will be n * O(1) = O(n).
Hence, the total time taken will be O(n) + O(n) = O(n) only.

Space Complexity: O(1)*/