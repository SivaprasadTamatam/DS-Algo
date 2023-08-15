#include<iostream>

using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v) : data(v), left(nullptr), right(nullptr){}
};

class BST{
    public:
        BST(): root(nullptr){}
        void Insert(int v){
            root = Insert(root, v);
        }

        void Delete(int v){
            root = Delete(root, v);
        }

        bool Search(int v){
            return Search(root, v);
        }
    private:
        TreeNode* root;


        TreeNode* Insert(TreeNode* node, int v){
            if(node == nullptr){
                return new TreeNode(v);
            }

            if(v <node->data ){
                node->left = Insert(node->left, v);
            } else if (v > node->data){
                node->right = Insert(node->right, v);
            }

            return node;
        }

        TreeNode* Delete(TreeNode* node, int v){

            if(node == nullptr){
                return nullptr;
            }

            if(v < node->data){
                node->left = Delete(node->left, v);
            } else if (v > node->data){
                node->right = Delete(node->right, v);
            } else {
                if( node->left == nullptr){
                    TreeNode* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr){
                    TreeNode* temp = node->left;
                    delete node;
                    return temp;
                }

                TreeNode* temp = MinNode(node->right);
                node->data = temp->data;
                node->right = Delete(node->right, temp->data);
            }
        }

        TreeNode* MinNode(TreeNode* node){
            while(node->left != nullptr){
                node = node->left;
            }
            return node;
        }

        bool Search(TreeNode* node, int v){
            if (node == nullptr){
                return false;
            }

            if(v == node->data){
                return true;
            } else if (v < node->data){
                return Search(node->left, v);
            } else {
                return Search(node->right, v);
            }
        }
};

int main(){
    BST bst;

    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.Insert(80);

   if (bst.Search(40)){
    cout<<"Found 40"<<endl;
   } else {
    cout<<" 40 not found"<<endl;
   }

  if (bst.Search(49)){
    cout<<"Found 90"<<endl;
   } else {
    cout<<" 90 not found"<<endl;
   }

    bst.Delete(40);
    if (bst.Search(40)){
    cout<<"Found 40"<<endl;
   } else {
    cout<<" 40 not found"<<endl;
   }
   
    return 0;
}