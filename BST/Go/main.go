package main

import "fmt"

type TreeNode struct {
	data  int
	left  *TreeNode
	right *TreeNode
}

func newNode(v int) *TreeNode {
	return &TreeNode{data: v, left: nil, right: nil}
}

type BST struct {
	root *TreeNode
}

func (bst *BST) Insert(v int) {
	bst.root = insert(bst.root, v)
}

func insert(node *TreeNode, v int) *TreeNode {

	if node == nil {
		return newNode(v)
	}

	if v < node.data {
		node.left = insert(node.left, v)
	} else if v > node.data {
		node.right = insert(node.right, v)
	}

	return node
}

func (bst *BST) Delete(v int) {
	bst.root = delete(bst.root, v)
}

func delete(node *TreeNode, v int) *TreeNode {
	if node == nil {
		return nil
	}

	if v < node.data {
		node.left = delete(node.left, v)
	} else if v > node.data {
		node.right = delete(node.right, v)
	} else {
		if node.left == nil {
			temp := node.right
			node = nil
			return temp
		} else if node.right == nil {
			temp := node.left
			node = nil
			return temp
		}

		temp := minNode(node.right)
		node.data = temp.data
		node.right = delete(node.right, temp.data)
	}
	return node
}

func minNode(node *TreeNode) *TreeNode {
	for node.left != nil {
		node = node.left
	}
	return node
}

func (bst *BST) Search(v int) bool {
	return search(bst.root, v)
}

func search(node *TreeNode, v int) bool {
	if node == nil {
		return false
	}

	if v == node.data {
		return true
	} else if v < node.data {
		return search(node.left, v)
	} else {
		return search(node.right, v)
	}
}

func main() {
	bst := BST{}

	bst.Insert(50)
	bst.Insert(30)
	bst.Insert(70)
	bst.Insert(20)
	bst.Insert(40)
	bst.Insert(60)
	bst.Insert(80)

	if bst.Search(40) {
		fmt.Println("Found 40")
	} else {
		fmt.Println("40 not found")
	}

	if bst.Search(90) {
		fmt.Println("Found 90")
	} else {
		fmt.Println("90 not found")
	}

	bst.Delete(40)

	if bst.Search(40) {
		fmt.Println("Found 40")
	} else {
		fmt.Println("40 not found")
	}
}
