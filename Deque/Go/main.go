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

package main

import "fmt"

// Node to represent the double linked list
type Node struct {
	data int   // data of the node
	next *Node // pointer to next node
	prev *Node // pointer to prev node
}

// Deque structure and operations on it
type Deque struct {
	front *Node // pointer to the front
	rear  *Node // pointer to the rear
}

// IsEmpty
func (dq *Deque) IsEmpty() bool {
	return dq.front == nil
}

// Insert at Front with O(1) time complexity
func (dq *Deque) InsertFront(data int) {
	newNode := &Node{data: data}
	if dq.IsEmpty() {
		dq.front = newNode
		dq.rear = newNode
	} else {
		newNode.next = dq.front
		dq.front.prev = newNode
		dq.front = newNode
	}
}

// Insert at Rear with O(1) time complexity
func (dq *Deque) InsertRear(data int) {
	newNode := &Node{data: data}
	if dq.IsEmpty() {
		dq.front = newNode
		dq.rear = newNode
	} else {
		newNode.prev = dq.rear
		dq.rear.next = newNode
		dq.rear = newNode
	}
}

// Delete from front, O(1) time complexity
func (dq *Deque) DeleteFront() {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return
	}

	dq.front = dq.front.next
	if dq.front == nil {
		dq.rear = nil
	} else {
		dq.front.prev = nil
	}

}

// Delete element from rear, O(1) time complexity
func (dq *Deque) DeleteRear() {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return
	}
	dq.rear = dq.rear.prev
	if dq.rear == nil {
		dq.front = nil
	} else {
		dq.rear.next = nil
	}
}

// Get element from the Front , O(1) time complexity
func (dq *Deque) Front() int {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return -1
	}
	return dq.front.data
}

// Get the element from Rear, O(1) time complexity
func (dq *Deque) Rear() int {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return -1
	}
	return dq.rear.data
}

func (dq *Deque) Display() {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return
	}
	temp := dq.front
	for temp != nil {
		fmt.Printf("%d ", temp.data)
		temp = temp.next
	}
	fmt.Println()
}

func main() {
	dq := &Deque{}
	dq.InsertFront(1) // 1
	dq.InsertFront(2) // 2 1
	dq.InsertRear(3)  // 2 1 3
	dq.InsertRear(4)  // 2 1 3 4

	dq.Display()

	dq.DeleteFront() // 1 3 4
	dq.Display()

	dq.DeleteRear() // 1 3
	dq.Display()

	dq.DeleteFront() // 3
	dq.DeleteRear()  //

	dq.Display() // Deque is empty

}
