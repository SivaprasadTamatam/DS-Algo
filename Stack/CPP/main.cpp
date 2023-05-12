/*
A stack is a linear data structure in which elements are added and removed from only one end, known as the top of the stack. The operations that can be performed on a stack are:

Push: This operation adds an element to the top of the stack.
Pop: This operation removes the top element from the stack.
Peek or Top: This operation returns the top element from the stack without removing it.
isEmpty: This operation checks if the stack is empty.
Size: This operation returns the number of elements in the stack.
The time complexity for each of these operations in a stack implemented using an array or a linked list is as follows:

Push: O(1) - This operation adds an element to the top of the stack in constant time since we simply add the element to the end of the array or the head of the linked list.
Pop: O(1) - This operation removes the top element from the stack in constant time since we simply remove the last element of the array or the head of the linked list.
Peek or Top: O(1) - This operation returns the top element from the stack without removing it in constant time since we simply return the last element of the array or the head of the linked list.
isEmpty: O(1) - This operation checks if the stack is empty in constant time by simply checking if the size of the stack is zero.
Size: O(1) - This operation returns the number of elements in the stack in constant time since we can simply return the size of the array or the linked list.
*/

#include<iostream>
#include<vector>

using namespace std;
class Stack{
private:
    vector<int> stack;

public:
    // Push operation O(1) time complexity
    void Push(int data){
        stack.push_back(data);
    }

    // Pop operation, O(1) time complexity
    void Pop(){
        if(!stack.empty()){
            stack.pop_back();
        }
    }
    
    // Top operation O(1) time complexity
    int Top(){
        if(!stack.empty()){
            return stack.back();
        }
        return -1; // stack is empty
    }

    // IsEmpty operation is O(1) time complexity
    bool IsEmpty(){
        return stack.empty();
    }

    // Size operation O(1) time complexity

    int Size(){
        return stack.size();
    }
};

int main(){
    Stack s;

    s.Push(10);
    s.Push(9);
    cout<<"Size of the stack is :   "<<s.Size()<<endl;

    cout<<"Top of the stack element :   "<<s.Top()<<endl;
    s.Pop();
    cout<<"Top of the stack element :   "<<s.Top()<<endl;
    s.Pop();
    if (s.IsEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    
}