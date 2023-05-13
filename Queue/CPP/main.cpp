/*
Queues are a type of linear data structure where elements are inserted at one end (rear) and removed from the other end (front). 
The operations of a queue are:
Enqueue: Add an element to the rear of the queue.
Dequeue: Remove the element at the front of the queue.
Front: Get the element at the front of the queue without removing it.
Rear: Get the element at the rear of the queue without removing it.
Size: Get the number of elements in the queue.
IsEmpty: Check if the queue is empty.

The time complexities of these operations are as follows:
Enqueue: This operation is used to add an element at the rear end of the queue. It has a time complexity of O(1), which means it takes constant time to perform this operation.
Dequeue: This operation is used to remove an element from the front end of the queue. It has a time complexity of O(1), which means it takes constant time to perform this operation.
Front: This operation is used to get the value of the front end element without removing it from the queue. It has a time complexity of O(1), which means it takes constant time to perform this operation.
Rear: This operation is used to get the value of the rear end element without removing it from the queue. It has a time complexity of O(1), which means it takes constant time to perform this operation.
Size: This operation is used to get the number of elements present in the queue. It has a time complexity of O(1), which means it takes constant time to perform this operation.
IsEmpty: This operation is used to check whether the queue is empty or not. It has a time complexity of O(1), which means it takes constant time to perform this operation.
*/

#include<iostream>
using namespace std;

const int MAX_SIZE = 100;
class Queue{
    private:
        int front; // index of the front element
        int rear; // index of the rear element
        int arr[MAX_SIZE]; // array to hold the queue elements
    public:
        Queue(){
            front = -1;
            rear = -1;
        }

        // Is empty is empty O(1) time complexity
        bool IsEmpty(){
            return front == -1;
        }

        // Is Full to check the queue is full or not , O(1) time complexity
        bool IsFull(){
            return rear == MAX_SIZE-1;
        }
        // Add element to the rear of the Queue, O(1) time complexity
        void Enqueue(int data){
            if(IsFull()){
                cout<<"Queue is Full"<<endl;
                return;
            }

            if( IsEmpty()){
                front = 0;
            }
            rear++;
            arr[rear] = data;
        }

        // remove element from the front of the queue, O(1) time complexity
        void Dequeue(){
            if(IsEmpty()){
                cout<<"Queue is empty"<<endl;
                return;
            }
            if( front == rear){
                front = -1;
                rear = -1;
            } else {
                front++;
            }
        }

        // Get the element from the front of the Queue, O(1) time complexity

        int Front(){
            if(IsEmpty()){
                cout<<"Queue is empty" <<endl;
                return -1;
            }
            return arr[front];
        }

        // get the element at the rear position of the queue, O(1) time complexity
        int Rear(){
            if(IsEmpty()){
                cout<<"Queue is empty"<<endl;
                return  -1;
            }
            return arr[rear];
        }

        // display the elements of the Queue
        void Display(){
            if(IsEmpty()){
                cout<<"Queue is empty"<<endl;
                return;
            }

            for( int i = front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};


int main(){
    Queue q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    q.Display(); // expected 1 2 3

    q.Dequeue();
    q.Display(); // Expected 2 3

    cout<<q.Front()<<endl;
    cout<<q.Rear()<<endl;

    q.Dequeue();
    q.Dequeue();
    q.Display();

}