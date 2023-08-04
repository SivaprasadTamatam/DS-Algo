#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int data;
        vector<TreeNode*> children;
    
        TreeNode(int value) : data(value) {}
};

/*
Step 1 - Traverse the left subtree
Step 2 - Visit the current node
Step 3 - Traverse the right subtree
*/

void inOrderTraversal(TreeNode* node){
    if(node == nullptr){
        return;
    }

    if(!node->children.empty()){
        inOrderTraversal(node->children.front()); // Leftmost child
    }

    cout<<node->data<<" "; // Current node

    for(int i = 1; i<node->children.size(); ++i){
        inOrderTraversal(node->children[i]);
    }
}

/*
Preorder Traversal: 
Step 1 - Visit the current node
Step 2 - Traverse the left subtree
Step 3 - Traverse the right subtree
*/

void preOrderTraversal(TreeNode* node){
    if( node == nullptr) return;

    cout<<node->data<<" ";

    for(TreeNode* ch : node->children){
        preOrderTraversal(ch);
    }
}

/*
Postorder Traversal: 
Step 1- Traverse the left subtree
Step 2 - Traverse the right subtree
Step 3 - Visit the current node
*/

void postOrderTraversal(TreeNode* node){
    if(node == nullptr) return;

    for(TreeNode* ch : node->children){
        postOrderTraversal(ch);
    }

    cout<<node->data<<" ";
}

int main(){
    TreeNode* root = new TreeNode(1);

    TreeNode* ch1 = new TreeNode(2);
    TreeNode* ch2 = new TreeNode(3);

    root->children.push_back(ch1);
    root->children.push_back(ch2);

    TreeNode* grandCh1 = new TreeNode(4);
    TreeNode* grandCh2 = new TreeNode(5);

    ch1->children.push_back(grandCh1);
    ch1->children.push_back(grandCh2);

    TreeNode* grandCh3 = new TreeNode(6);
    TreeNode* grandCh4 = new TreeNode(7);

    ch2->children.push_back(grandCh3);
    ch2->children.push_back(grandCh4);

    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);

}