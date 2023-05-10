/*
    Linked list operations and time complexity:
        Accessing an element: O(n)
        Inserting a Node at the beginning of the Linked List: O(1)
        Inserting a Node at the End of the Linked List: O(n)
        Inserting a Node at a Specific Position in the Linked List: O(n)
        Deleting a Node from the Beginning of the Linked List: O(1)
        Deleting a Node from the End of the Linked List: O(n)
        Deleting a Node from a Specific Position in the Linked List: O(n)
*/

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int d) : data(d), next(NULL){

        }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    // Inserting a Node at the beginning of the Linked List: O(1)
    void InsertAtBeginning(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Inserting a Node at the End of the Linked List: O(n)
    void InsertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        } else {
            Node* curr = head;
            while(curr->next != NULL){
                curr =curr->next;
            }
            curr->next = newNode;
        }
    }

    //Inserting a Node at a Specific Position in the Linked List: O(n)
    void InsertAtPosition(int data, int position){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else if(position == 0){
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            for(int i = 0; i<position; i++){
                if(curr->next == NULL){
                    cout<<"Position out of range"<<endl;
                    return;
                }
                curr = curr -> next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    //Deleting a Node from the Beginning of the Linked List: O(1)
    void DeleteAtBeginning(){
        if(head == NULL){
            cout<<"Linked list is empty()"<<endl;
        } else {
            Node* curr = head;
            head = curr->next;
            delete curr;
        }
    }

    // Deleting a Node from the End of the Linked List: O(n)
    void DeleteAtEnd(){
        if(head == NULL){
            cout<<"Linked list empty"<<endl;
        } else if(head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* curr = head;
            while(curr->next->next != NULL){
                curr = curr->next;
            }
            delete curr->next;
            curr->next= NULL;
        }
    }
    // Deleting a Node from a Specific Position in the Linked List: O(n)
    void DeleteAtPosition(int position){
        if(head == NULL){
            cout<<"Linked list is empty"<<endl;
        } else if (position == 0){
            Node* curr = head;
            head = curr->next;
            delete curr;
        } else {
            Node* curr = head;
            for(int i =0; i<position; i++){
                if( curr->next == NULL){
                    cout<<"Position is out of range"<<endl;
                    return;
                }
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    // Display linked list
    void Display(){
        if(head == NULL){
            cout<<"Linked list is empty()"<<endl;
        } else{
            Node* curr = head;
            while(curr != NULL){
                cout<<curr->data<<" ";
                curr = curr->next;
            }
        }
        cout<<endl;
    }

    // Accessing an element
    int Get(int position){
        if(position < 0){
            return -1;
        }
        Node * curr = head;
        for(int i = 0; i<position; i++){
            if(curr == NULL){
                return -1;
            }
            curr = curr->next;
        }

        if(curr == NULL) return -1;

        return curr->data;
    }
};

int main(){
    LinkedList list;
    // Insert elements 3 - 2 - 1
    list.InsertAtBeginning(1);
    list.InsertAtBeginning(2);
    list.InsertAtBeginning(3);
    list.Display();

    list.InsertAtEnd(4);
    list.InsertAtEnd(5);
    list.Display();

    list.InsertAtPosition(6,4);
    list.Display();

    list.DeleteAtBeginning();
    list.Display();

    list.DeleteAtEnd();
    list.Display();

    list.DeleteAtPosition(2);
    list.Display();

    cout<<list.Get(2)<<endl;
}

