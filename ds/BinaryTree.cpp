#include <iostream>
using namespace std;

template <class T>
class BinaryTree{
    class Node{
        public:
        T data;
        Node* left;
        Node* right;
        
        Node(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    
    Node* root;
    int size;
    
    public:
    
    BinaryTree(){
        root = NULL;
        size = 0;
    }
    BinaryTree(T data){
        Node* n = new Node(data);
        root = n;
        size = 1;
    }
    BinaryTree(BinaryTree const &bt){
        this->root = bt.root;
        this->size = bt.size;
    }
    
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    T getRoot(){
        if(root == NULL){
            cout << "Tree is empty" << endl;
            return -1;
        }
        return root->data;
    }
    void insert(T data){
        Node* n = new Node(data);
        if(root == NULL){
            root = n;
        }
        else{
            Node* temp = root;
            while(temp != NULL){
                if(data < temp->data){
                    if(temp->left == NULL){
                        temp->left = n;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = n;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
        size++;
    }
    
    void remove(T data){
        if(root == NULL){
            cout << "Tree is empty" << endl;
            return;
        }
        else{
            Node* temp = root;
            Node* parent = NULL;
            while(temp != NULL){
                if(data < temp->data){
                    parent = temp;
                    temp = temp->left;
                }
                else if(data > temp->data){
                    parent = temp;
                    temp = temp->right;
                }
                else{
                    if(temp->left == NULL && temp->right == NULL){
                        if(parent == NULL){
                            root = NULL;
                        }
                        else{
                            if(parent->left == temp){
                                parent->left = NULL;
                            }
                            else{
                                parent->right = NULL;
                            }
                        }
                    }
                    else if(temp->left == NULL){
                        if(parent == NULL){
                            root = temp->right;
                        }
                        else{
                            if(parent->left == temp){
                                parent->left = temp->right;
                            }
                            else{
                                parent->right = temp->right;
                            }
                        }
                    }
                    else if(temp->right == NULL){
                        if(parent == NULL){
                            root = temp->left;
                        }
                        else{
                            if(parent->left == temp){
                                parent->left = temp->left;
                            }
                            else{
                                parent->right = temp->left;
                            }
                        }
                    }
                    else{
                        Node* min = temp->right;
                        Node* minParent = temp;
                        while(min->left != NULL){
                            minParent = min;
                            min = min->left;
                        }
                        temp->data = min->data;
                        if(minParent->left == min){
                            minParent->left = min->right;
                        }
                        else{
                            minParent->right = min->right;
                        }
                    }
                    break;
                }
            }
        }
        size--;
    }

    void print(){
        print(root);
    }
    void print(Node* node){
        if(node == NULL){
            return;
        }
        cout << node->data << " ";
        print(node->left);
        print(node->right);
    }
};