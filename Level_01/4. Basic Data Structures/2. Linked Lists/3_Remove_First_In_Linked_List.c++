/*1. You are given a partially written LinkedList class.
2. Here is a list of existing functions:
   2.1 addLast - adds a new element with given value to the end of Linked List
   2.2. display - Prints the elements of linked list from front to end in a single line. All 
     elements are separated by space
     2.3. size - Returns the number of elements in the linked list.
3. You are required to complete the body of removeFirst function 
     3.1. removeFirst - This function is required to remove the first element from 
          Linked List. Also, if there is only one element, this should set head and tail to 
          null. If there are no elements, this should print "List is empty".
4. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
addLast 10
addLast 20
addLast 30
display
removeFirst
size
addLast 40
addLast 50
removeFirst
display
size
removeFirst
removeFirst
removeFirst
removeFirst
quit

Sample Output
10 20 30 
2
30 40 50 
3
List is empty*/

#include <iostream>
#include<string>
using namespace std;

class node
{
 public:
  int data;
  node* next;
};

class linked_list
{
 public:
  node* head, *tail;
  int size = 0;

 public:
  linked_list()
  {
    head = NULL;
    tail = NULL;
  }

  void addLast(int n)
  {
    node* tmp = new node;
    tmp->data = n;
    tmp->next = NULL;
    if (head == NULL)
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
    for (node* tmp = head; tmp != NULL; tmp = tmp->next){
      cout << tmp->data << " ";
    }
    cout << endl;
  }

  void removeFirst(){
    if (size == 0) {
      cout << "List is empty" << endl;
      return;
    }
    head = head->next;size--;
  }

  void testList(){
    for (node* temp = head; temp != NULL; temp = temp->next){
      cout << temp->data << endl;
    }
    cout << size << endl;

    if (size > 0){
      cout << tail->data << endl;
    }
  }
};

int main(){
  string str;
  linked_list l;
  while (true){
    getline(cin, str);
    if (str[0] == 'q'){
      break;
    }
    else if (str[0] == 'a'){
      string ss = str.substr(8, 2);
      int n = stoi(ss);
      l.addLast( n);
    }
    else if (str[0] == 's'){
      cout << l.size << endl;
    }
    else if (str[0] == 'd'){
      l.display();
    }
    else if (str[0] == 'r'){
      l.removeFirst();
    }
  }
  return 0;
}

/*Time Complexity: O(1)

This is a constant-time operation. Cause all we are doing is just a few operations, no loops or anything. Hence the time complexity is O(1).

Space Complexity: O(1)

We are not using any extra space, so the space complexity is also O(1).*/