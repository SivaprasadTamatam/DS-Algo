/*
Deque, short for Double Ended Queue, is a data structure that allows insertion and 
removal of elements from both ends, front and rear.

The time complexity of common operations of deque implemented as a doubly 
linked list are:

Insertion at front: O(1) - this is a simple operation as we just need to add a new 
    node at the front of the list.
Deletion at front: O(1) - this is a simple operation as we just need to remove 
    the node at the front of the list.
Insertion at rear: O(1) - this is a simple operation as we just need to add a 
    new node at the end of the list.
Deletion at rear: O(1) - this is a simple operation as we just need to remove 
    the node at the end of the list.
Accessing the front or rear element: O(1) - we can just return the data of 
    the first or last node without any extra operation.
Checking if deque is empty: O(1) - we can just check if the head and tail pointers 
    are equal to NULL.
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int d):data(d), next(NULL), prev(NULL){}
};

class Deque{
    private:
        Node* front;
        Node* rear;
    public:
    Deque(): front(NULL), rear(NULL){}

    bool IsEmpty(){
        return front == NULL;
    }

    // Insert at Front, O(1) time complexity
    void InsertFront(int data){
        Node* newNode = new Node(data);

        if(IsEmpty()){
            front = newNode;
            rear = newNode;
        } else {

            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
    }

    // Insert at rear, O(1) time complexity 
    void InsertRear(int data){
        Node* newNode = new Node(data);
        if(IsEmpty()){
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev= rear;
            rear = newNode;
        }
    }

    // Delete element from Front, O(1) time complexity
    void DeleteFront(){
        if(IsEmpty()){
            cout<<"Dequeue is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        } else {
            front->prev = NULL;
        }
        delete temp;
    }

    // Delete element from the rear, O(1) time complexity 
    void DeleteRear(){
        if(IsEmpty()){
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if(rear == NULL){
            front = NULL;
        } else {
            rear->next = NULL;
        }
        delete temp;
    }

    // Get the Front element, O(1) time complexity
    int Front(){
        if(IsEmpty()){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    // Get element from rear, O(1) time complexity
    int Rear(){
        if(IsEmpty()){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        return rear->data;
    }

    void Display(){
        if(IsEmpty()){
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main(){
    Deque dq;
    dq.InsertFront(1); // 1
    dq.InsertFront(2); // 2 1
    dq.InsertRear(3); // 2 1 3
    dq.InsertRear(4); // 2 1 3 4

    dq.Display();

    dq.DeleteFront(); // 1 3 4
    dq.Display();

    dq.DeleteRear(); // 1 3
    dq.Display();

    cout<<dq.Front()<<endl;
    cout<<dq.Rear()<<endl;

    dq.DeleteFront();
    dq.DeleteRear();

    dq.Display(); // Deque is empty
}