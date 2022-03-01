/*1. You are required to complete the code of our CustomQueue class. The class should mimic the behaviour of a Queue and implement FIFO semantic.
2. Here is the list of functions that are written in the class
    2.1. add -> Accepts new data if there is space available in the underlying array or 
    print "Queue overflow" otherwise.
    2.2. remove -> Removes and returns value according to FIFO, if available or print 
    "Queue underflow" otherwise and return -1.
    2.3. peek -> Returns value according to FIFO, if available or print "Queue 
     underflow" otherwise and return -1.
    2.4. size -> Returns the number of elements available in the queue.
    2.5. display -> Prints the elements of queue in FIFO manner (space-separated) 
    ending with a line-break.
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
10 20 30 40 50 60 
10
10
20 30 40 50 60 
20
20
30 40 50 60 
30
30
40 50 60 
40
40
50 60 
50
50
60 
60
60*/

#include <iostream>
#include <exception>
using namespace std;

class DynamicQueue{
    public:
    int *arr;
    int sizeQ;
    int front;
    int arrSize;
    
    DynamicQueue(int cap){
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
            int *newArr = new int[2*arrSize];
            for(int i=0; i<arrSize; i++){
                newArr[i]=arr[(front+i)%arrSize];
            }
            arr=newArr;
            arrSize=2*arrSize;
            front=0;
        }
        int k=arrSize;
        int idx = (front+sizeQ)%(k);
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
    DynamicQueue q(n);
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

/*Time Complexity : O(n)

The time complexity of the above procedure will be O(1) if we have to insert an element just at the end without increasing the size and O(n) if we have to increase the size as we will have to copy all the values of the queue to the array. 
Since the question is about creating a dynamic queue, the time complexity for creating a dynamic queue is O(n) .

SPACE COMPLEXITY : O(n)

The space complexity is also O(n) as we make an array of size=2n where n is the current size of the queue.*/