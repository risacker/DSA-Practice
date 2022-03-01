/*1. You are required to complete the code of our CustomQueue class. The class should mimic the behaviour of a Queue and implement FIFO semantic.
2. Here is the list of functions that you are supposed to complete
     2.1. add -> Should accept new data if there is space available in the underlying 
     array or print "Queue overflow" otherwise.
     2.2. remove -> Should remove and return value according to FIFO, if available or 
     print "Queue underflow" otherwise and return -1.
     2.3. peek -> Should return value according to FIFO, if available or print "Queue 
     underflow" otherwise and return -1.
     2.4. size -> Should return the number of elements available in the queue.
     2.5. display -> Should print the elements of queue in FIFO manner (space- 
     separated) ending with a line-break.
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
5
add 10
display
add 20
display
add 30
display
add 40
display
add 50
display
add 60
display
peek
remove
display
peek
remove
display
peek
remove
display
peek
remove
display
peek
remove
display
peek
remove
quit

Sample Output
10 
10 20 
10 20 30 
10 20 30 40 
10 20 30 40 50 
Queue overflow
10 20 30 40 50 
10
10
20 30 40 50 
20
20
30 40 50 
30
30
40 50 
40
40
50 
50
50
Queue underflow
Queue underflow*/

#include <iostream>
#include <exception>
using namespace std;

class CustomQueue{
    public:
    int *arr;
    int sizeQ;
    int front;
    int arrSize;
  
    CustomQueue(int cap){
        sizeQ = 0;
        front = 0;
        arr = new int[cap];
        arrSize = cap;
    }
    
    int size(){
        return sizeQ;
    }
    
    void add(int data){
        if(sizeQ == arrSize){
            cout<<"Queue overflow"<<endl;
            return;
        }
        int idx = (front+sizeQ)%(arrSize);
        arr[idx] = data;
        sizeQ++;
    }

    int peek(){
        if (sizeQ == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        else{
            int val=arr[front];
            return val;
        }
    }

    int remove(){
        if (sizeQ == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        else{
            int rem = arr[front];
            front=(front+1)%arrSize;
            sizeQ--;
            return rem;
        }
    }
    
    void display() {
    for(int i=0 ;i<sizeQ ;i++){
        int idx = (front+i)%arrSize;
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    CustomQueue q(n);
    string str;
    cin>>str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin>>val;
            q.add(val);
        }
        else if(str=="remove"){
            int val = q.remove();
            if(val != -1){
                cout<<val<<endl;
            }
        }
        else if(str=="peek"){
            int val = q.peek();
            if(val != -1){
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<q.size()<<endl;
        }
        else if(str=="display"){
            q.display();
        }
        cin>>str;
    }
    return 0;
}

/*Time Complexity :-

Add: We always add the element at the last index in the queue but for that, we do not traverse the array. We directly access the last index. So, the time complexity is O(1).

Remove: We always remove the first element from the queue and we do not traverse the queue at all. So, the time complexity will be O(1).

Peek: We just have to return data[front], so the time complexity is O(1).

Size: We just have to return the size of the queue. So, the time complexity is O(1).

Display: For this, we have to traverse the entire array (queue) to print all the values. So, the time complexity is O(n).

SPACE COMPLEXITY : O(1)

Let us talk about space complexity first. We have not used any extra data structure to implement any of the above-mentioned methods. So, the space complexity for all these methods is O(1).*/