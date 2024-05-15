#include <iostream>
#include <queue>
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


        void BFS() {
            queue<Node*> myQueue;
            myQueue.push(root);

            while(myQueue.size() > 0) {
                Node* currentNode = myQueue.front();
                myQueue.pop();
                cout << currentNode->value << " ";

                if(currentNode->left != nullptr) {
                    myQueue.push(currentNode->left);
                }
                if(currentNode->right != nullptr) {
                    myQueue.push(currentNode->right);
                }
            }
        }

        void DFSPreOrder(Node* currentNode) {
            cout << currentNode->value << " ";
            if(currentNode->left) {
                DFSPreOrder(currentNode->left);
            }
            if(currentNode->right) {
                DFSPreOrder(currentNode->right);
            }
        }

        void DFSPreOrder() {
            DFSPreOrder(root);
        }

        void DFSPostOrder(Node* currentNode) {
            if(currentNode->left) {
                DFSPreOrder(currentNode->left);
            }
            if(currentNode->right) {
                DFSPreOrder(currentNode->right);
            }
            cout << currentNode->value << " ";
        }

        void DFSPostOrder() {
            DFSPostOrder(root);
        }

        void DFSInOrder(Node* currentNode) {
            if(currentNode->left) {
                DFSInOrder(currentNode->left);
            }
            cout << currentNode->value <<" ";
            if(currentNode->right) {
                DFSInOrder(currentNode->right);
            }
        }

        void DFSInOrder() {
            DFSInOrder(root);
        }

};

int main() {
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);

    myBST->BFS();
    cout << endl;
    myBST->DFSPreOrder();
    cout << endl;
    myBST->DFSPostOrder();
    cout << endl;
    myBST->DFSInOrder();
    cout << endl;
}