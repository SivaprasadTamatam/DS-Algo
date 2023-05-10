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

package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	head *Node
}

//Inserting a Node at the beginning of the Linked List : O(1)
func (list *LinkedList) InsertAtBeginning(data int) {
	newNode := &Node{data: data, next: list.head}
	list.head = newNode
}

// Inserting a Node at the End of the Linked List: O(n)
func (list *LinkedList) InsertAtEnd(data int) {
	newNode := &Node{data: data}

	if list.head == nil {
		list.head = newNode
	} else {
		curr := list.head
		for curr.next != nil {
			curr = curr.next
		}
		curr.next = newNode
	}
}

//Inserting a Node at a Specific Position in the Linked List: O(n)
func (list *LinkedList) InsertAtPosition(data int, position int) {
	newNode := &Node{data: data}
	if list.head == nil {
		list.head = newNode
	} else if position == 0 {
		newNode.next = list.head
		list.head = newNode
	} else {
		curr := list.head
		for i := 0; i < position; i++ {
			if curr.next == nil {
				fmt.Println("Position out of range")
				return
			}
			curr = curr.next
		}
		newNode.next = curr.next
		curr.next = newNode
	}
}

// Deleting a Node from the Beginning of the Linked List: O(1)
func (list *LinkedList) DeleteAtBeginning() {
	if list.head == nil {
		fmt.Println("Linkedlist is empty")
	} else {
		curr := list.head
		list.head = curr.next
		curr.next = nil
	}
}

//Deleting a Node from the End of the Linked List: O(n)
func (list *LinkedList) DeleteAtEnd() {
	if list.head == nil {
		fmt.Println("Linked list is empty")
	} else if list.head.next == nil {
		list.head = nil
	} else {
		curr := list.head
		for curr.next.next != nil {
			curr = curr.next
		}
		curr.next = nil
	}
}

// Deleting a Node from a Specific Position in the Linked List: O(n)
func (list *LinkedList) DeleteAtPosition(position int) {
	if list.head == nil {
		fmt.Println("Linked list is empty")
	} else if position == 0 {
		curr := list.head
		list.head = curr.next
		curr.next = nil
	} else {
		curr := list.head
		for i := 0; i < position; i++ {
			if curr.next == nil {
				fmt.Println("Position is out of range")
				return
			}
			curr = curr.next
		}
		temp := curr.next
		curr.next = temp.next
		temp.next = nil
	}
}

//Accessing an element: O(n)

func (list *LinkedList) Get(position int) int {
	if position < 0 {
		return -1
	}
	curr := list.head

	for i := 0; i < position; i++ {
		if curr == nil {
			return -1
		}
		curr = curr.next
	}
	if curr == nil {
		return -1
	}
	return curr.data
}

// Display LinkedList
func (list *LinkedList) Display() {
	if list.head == nil {
		fmt.Println("Linked list is empty")
	} else {
		curr := list.head
		for curr != nil {
			fmt.Printf("%d	", curr.data)
			curr = curr.next
		}
		fmt.Println()
	}
}

func main() {
	list := LinkedList{}

	list.InsertAtBeginning(1)
	list.InsertAtBeginning(2)
	list.InsertAtBeginning(3)
	list.Display()

	list.InsertAtEnd(4)
	list.InsertAtEnd(5)
	list.Display()

	list.InsertAtPosition(6, 4)
	list.Display()

	list.DeleteAtBeginning()
	list.Display()

	list.DeleteAtEnd()
	list.Display()

	list.DeleteAtPosition(2)
	list.Display()

	fmt.Println(list.Get(2))
}
