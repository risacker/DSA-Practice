/*1. You are given a partially written LinkedList class.
2. Here is a list of existing functions:
   2.1 addLast - adds a new element with given value to the end of Linked List
3. You are required to complete the body of display function and size function
   3.1. display - Should print the elements of linked list from front to end in a single line. Elements should be separated by space.
   3.2. size - Should return the number of elements in the linked list.
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
size
addLast 40
addLast 50
display
size
quit

Sample Output
10 20 30 
3
10 20 30 40 50 
5*/

#include <iostream>
#include<string>
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
    cout << endl;
  }

  void testList() {
    for (node* temp = head; temp != NULL; temp = temp->next){
      cout << temp->data << endl;
    }
    cout << size << endl;
    if (size > 0) {
      cout << tail->data << endl;
    }
  }
};

int main(){
  string str;
  linked_list l;
  while (true) {
    getline(cin, str);
    if (str[0] == 'q') {
      break;
    }
    else if (str[0] == 'a') {
      string ss = str.substr(8, 2);
      int n = stoi(ss);
      l.addLast( n);
    }
    else if (str[0] == 's') {
      cout << l.size << endl;
    }
    else if (str[0] == 'd') {
      l.display();
    }
  }
  return 0;
}

/*Time Complexity:-

Size: The time complexity of the size method is O(1) as we are just returning the size of the linked list.
Display: The time complexity of display is O(n) as we are traversing the entire linked list of n elements.

Space Complexity:O(1)
The space complexity of the above methods is O(1) as we have not used any extra space for any of the above methods*/