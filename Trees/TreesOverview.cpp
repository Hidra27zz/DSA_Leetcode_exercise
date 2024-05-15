#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;;
        }
};

class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() {
            root = nullptr;
        }
        bool insert(int value) {
            Node* newNode = new Node(value);
            if(root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true){
                if(newNode->value == temp->value) return false;
                if(newNode->value < temp->value){
                    if(temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }
                else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value){
            //if(root == nullptr) return false;
            Node* temp = root;
            while(temp){
                if(value < temp->value){
                    temp = temp->left;
                }
                else if(value > temp->value){
                    temp = temp->right;
                } 
                else{
                    return true;
                }
            }
            return false;
        }

        Node* deleteNode(Node* currentNode, int value) {
            if(!currentNode) return nullptr;
            if(value < currentNode->value) {
                currentNode->left = deleteNode(currentNode->left, value);
            }
            else if(value > currentNode->value) {
                currentNode->right = deleteNode(currentNode->right, value);
            }
            else {
                if(currentNode->left == nullptr && currentNode->right == nullptr) {
                    delete(currentNode);
                    return nullptr;
                }
                else if(currentNode->left == nullptr) {
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                }
                else if(currentNode->right == nullptr) {
                    Node* temp = currentNode->left;
                    delete(currentNode);
                    return temp;
                }
                else {
                    int subTreeMin = minValue(currentNode->right);
                    currentNode->value = subTreeMin;
                    currentNode->right = deleteNode(currentNode->right, subTreeMin);
                }
            }
            return currentNode;
        }

        void deleteNode(int value) { 
            root = deleteNode(root, value); 
        }
       
};


