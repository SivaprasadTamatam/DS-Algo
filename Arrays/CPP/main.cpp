#include<iostream>
using namespace std;

int main(){
    // Declaration and init an array
    int arr[5] = {1, 2, 3, 4, 5};

    cout<<"Arrays elements: ";
    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Accessing elements O(1)
    cout<<"Element at index - 2 : "<<arr[2]<<endl;

    // Modifying an element in an array
    arr[2] = 6;
    cout<<"After modifying the value at index - 2 : ";
    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Insert an element at position 2 -- O(N)
    for(int i = 4; i>=2; i--){
        arr[i+1] = arr[i];
    }
    arr[2] = 7;

    cout<<" After inserting 7 at position 2: ";
    for(int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Deleting an element at position 2 -- O(N)
    for(int i = 2; i< 6; i++){
        arr[i] = arr[i+1];
    }

    arr[5] = 0;

    cout<<"After deleting element at index 2: ";
    for(int i =0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}