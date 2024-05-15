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
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }

        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }


        bool rContains(Node* currentNode, int value) {
            if(!currentNode) return false;

            if(currentNode->value == value) return true;

            if(value < currentNode->value) {
                return rContains(currentNode->left, value);
            }
            else{
                return rContains(currentNode->right, value);
            }

        }

        bool rContains(int value) { 
            return rContains(root, value); 
        } 

        Node* rInsert(Node* currentNode, int value) {
            if(!currentNode) return new Node(value);

            if(value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            }

            else if(value > currentNode->value) {
                currentNode->right = rInsert(currentNode->right, value);
            }

            return currentNode;
        }


        void rInsert(int value){
            if(!root) root = new Node(value);
            rInsert(root, value);
        }

        
        Node* deleteNode(Node* currentNode, int value) {
            if(currentNode == nullptr) return nullptr;
            if(value < currentNode->value) {
                currentNode->left = deleteNode(currentNode->left, value);
            }
            else if(value > currentNode->value) {
                currentNode->right = deleteNode(currentNode->right, value);
            }
            else {
                if(currentNode->left == nullptr && currentNode->right == nullptr){
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

        int minValue(Node* currentNode) {
            while(currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }

};

int main() {
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->rInsert(47);
    myBST->rInsert(21);
    myBST->rInsert(49);
    myBST->rInsert(18);
    myBST->rInsert(46);
    myBST->rInsert(52);
    myBST->rInsert(82);

    cout << myBST->minValue(myBST->root) << endl;
    cout << myBST->minValue(myBST->root->right) << endl;

    myBST->deleteNode(47);
    cout << "\nBST Contains 27:\n";
    cout<< myBST->rContains(27);

    cout << "\nBST Contains 17:\n";
    cout << myBST->rContains(17);
    cout << "\n" << myBST->root->value << endl;
    cout << myBST->minValue(myBST->root) << endl;
    cout << myBST->minValue(myBST->root->right) << endl;

}