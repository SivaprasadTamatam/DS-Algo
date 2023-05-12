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

package main

import (
	"errors"
	"fmt"
)

type Stack struct {
	items []int
}

// Push operation O(1) time complexity
func (s *Stack) Push(item int) {
	s.items = append(s.items, item)
}

// Pop operation O(1) time complexity
func (s *Stack) Pop() (int, error) {
	if len(s.items) == 0 {
		return 0, errors.New("Stack is empty")
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item, nil
}

// Top or Peek O(1) time complexity
func (s *Stack) Top() (int, error) {
	if len(s.items) == 0 {
		return 0, errors.New("Stack is empty")
	}
	return s.items[len(s.items)-1], nil
}

// IsEmpty operation O(1) time complexity

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

// Size operation O(1) time complexity

func (s *Stack) Size() int {
	return len(s.items)
}

func main() {
	s := Stack{}
	s.Push(10)
	s.Push(9)

	fmt.Println(s)
	v, _ := s.Top()

	fmt.Println("Top of the stack is : ", v)

	v, _ = s.Pop()
	fmt.Println("Pop element is : ", v)

	fmt.Println(s)

	fmt.Println(s.Size())
	fmt.Println(s.IsEmpty())

	s.Pop()

	_, err := s.Pop()

	if err != nil {
		fmt.Println(err.Error())
	}

	fmt.Println(s.Size())
	fmt.Println(s.IsEmpty())
}
