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

package main

import "fmt"

const maxSize = 100 // max size of the queue

type Queue struct {
	front int          // index of the front element in the queue
	rear  int          // index of the rear element in the queue
	arr   [maxSize]int // array to hold the queue elements
}

// Checks queue is empty or not, O(1) time complexity
func (q *Queue) IsEmpty() bool {
	return q.front == -1
}

// Checking is the queue is full or not, O(1) time complexity
func (q *Queue) IsFull() bool {
	return q.rear == maxSize-1
}

// Add element at rear, O(1) time complexity
func (q *Queue) Enqueue(data int) {
	if q.IsFull() {
		fmt.Println("Queue is full")
		return
	}
	if q.IsEmpty() {
		q.front = 0
	}
	q.rear++
	q.arr[q.rear] = data
}

// Remove element at front, O(1) time complexity
func (q *Queue) Dequeue() {
	if q.IsEmpty() {
		fmt.Println("Queue is empty")
		return
	}

	if q.front == q.rear {
		q.front = -1
		q.rear = -1
	} else {
		q.front++
	}
}

// Get element from front of the queue. O(1) time complexity
func (q *Queue) Front() int {
	if q.IsEmpty() {
		fmt.Println("Queue is empty")
		return -1
	}

	return q.arr[q.front]
}

// Get an element from the rear, O(1) time complexity
func (q *Queue) Rear() int {
	if q.IsEmpty() {
		fmt.Println("Queue is empty")
		return -1
	}
	return q.arr[q.rear]
}

// Display

func (q *Queue) Display() {
	if q.IsEmpty() {
		fmt.Println("Queue is empty")
		return
	}
	for i := q.front; i <= q.rear; i++ {
		fmt.Printf("%d ", q.arr[i])
	}
	fmt.Println()
}

func main() {
	q := Queue{front: -1, rear: -1}

	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	q.Display() // Expected 1 2 3

	q.Dequeue()
	q.Display() // expected 2 3

	fmt.Println(q.Front()) // 2
	fmt.Println(q.Rear())  // 3

	q.Dequeue()
	q.Dequeue()
	q.Display() // Queue is empty
}
