package main

import (
	"fmt"
)

type TreeNode struct {
	data     int
	children []*TreeNode
}

/*
Inorder Traversal:
Step 1 - Traverse the left subtree
Step 2 -  Visit the current node
Step 3 - Traverse the right subtree.

*/

func inOrderTraversal(node *TreeNode) {
	if node == nil {
		return
	}

	if len(node.children) > 0 {
		inOrderTraversal(node.children[0])
	}

	fmt.Printf("%d	", node.data)

	for i := 1; i < len(node.children); i++ {
		inOrderTraversal(node.children[i])
	}
}

/*
Preorder Traversal:
Step 1 - Visit the current node
Step 2 - Traverse the left subtree
Step 3 - Traverse the right subtree

*/

func preOrderTraversal(node *TreeNode) {
	if node == nil {
		return
	}

	fmt.Printf("%d	", node.data)

	for i := 0; i < len(node.children); i++ {
		preOrderTraversal(node.children[i])
	}
}

/*
Postorder Traversal:
Step 1- Traverse the left subtree
Step 2 - Traverse the right subtree
Step 3 - Visit the current node

*/

func postOrderTraversal(node *TreeNode) {
	if node == nil {
		return
	}

	for i := 0; i < len(node.children); i++ {
		postOrderTraversal(node.children[i])
	}

	fmt.Printf("%d	", node.data)
}

func main() {
	root := &TreeNode{data: 1}

	ch1 := &TreeNode{data: 2}
	ch2 := &TreeNode{data: 3}

	root.children = append(root.children, ch1)
	root.children = append(root.children, ch2)

	grandCh1 := &TreeNode{data: 4}
	grandCh2 := &TreeNode{data: 5}

	ch1.children = append(ch1.children, grandCh1)
	ch1.children = append(ch1.children, grandCh2)

	grandCh3 := &TreeNode{data: 6}
	grandCh4 := &TreeNode{data: 7}

	ch2.children = append(ch2.children, grandCh3)
	ch2.children = append(ch2.children, grandCh4)

	inOrderTraversal(root)
	fmt.Println()
	preOrderTraversal(root)
	fmt.Println()
	postOrderTraversal(root)
	fmt.Println()

}
