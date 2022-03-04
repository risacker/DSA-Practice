/*1. You are given a partially written LinkedList class.
2. You are required to complete the body of addLast function. This function is supposed to add an element to the end of LinkedList. You are required to update head, tail and size as required.
3. Input and Output is managed for you. Just update the code in addLast function.

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
addLast 40
addLast 50
quit

Sample Output
10
20
30
40
50
5
50*/

#include <iostream>
using namespace std;

class node
{
 public :
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

  void display() {
    for (node* tmp = head; tmp != NULL; tmp = tmp->next){
      cout << tmp->data << " ";
    }
  }

  void testList() {
    for (node* temp = head; temp != NULL; temp = temp->next){
      cout << temp->data << endl;
    }
    cout<<size<< endl;
    if (size > 0) {
      cout <<tail->data << endl;
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
      if (str[0] == 'a'){
        string ss = str.substr(8, 2);
        int n = stoi(ss);
        l.addLast( n);
      }
    }
    l.testList();
    return 0;
}

/*Time Complexity: O(1)

First, we are creating a new node, which is a constant O(1) operation. Then, if the size = 0, then make head and tail point to temp, which is again O(1). 
Else, we are updating tails' next as temp and updating tail as temp, which is O(1) again. Also, updating size by 1 is constant O(1) operation.
Hence, the total time complexity is O(1) only.

Space Complexity: O(1)

We are creating only one node which has data and a pointer to the next node, hence auxiliary space required is constant O(1).
Note that the space complexity is equal to the size of the linked list, i.e. O(n), but we are required to find the extra space taken by the addLast function only.*/