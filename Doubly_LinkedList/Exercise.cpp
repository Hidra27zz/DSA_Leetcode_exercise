#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        Node* get(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }
            Node*temp = head;
            if(index < length/2){
                for(int i = 0; i < index; i++){
                    temp = temp->next;
                }

            }
            else{
                temp = tail;
                for(int i = length - 1; i > index; i--){
                    temp = temp->prev;
                }
            }

            return temp;
        }
        void swapPairs(){
            if(length < 2){
                return;
            }
            else{
                int i = 0;
                while(i < (length)/2){
                    Node* before= get(i*2);
                    Node* after = get(i*2+1);
                    int temp = 0;
                    temp = before->value;
                    before->value = after->value;
                    after->value = temp;
                    i++; 
                }
            }
        }

        void swapPairs_Way2() {
            Node dummyNode(0);
            dummyNode.next = head;
            Node* previousNode = &dummyNode;
        
            while (head != nullptr && head->next != nullptr) {
                Node* firstNode = head;
                Node* secondNode = head->next;
        
                previousNode->next = secondNode;
                firstNode->next = secondNode->next;
                secondNode->next = firstNode;
        
                secondNode->prev = previousNode;
                firstNode->prev = secondNode;
                if (firstNode->next != nullptr) {
                    firstNode->next->prev = firstNode;
                }
        
                head = firstNode->next;
                previousNode = firstNode;
            }
        
            head = dummyNode.next;
            if (head) head->prev = nullptr;
        }


        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - The swapPairs function swaps adjacent pairs       |
        //   |   of nodes in a doubly linked list.                 |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Utilizes a dummyNode to simplify edge cases.      |
        //   | - Uses pointers to navigate and swap nodes.         |
        //   | - Pay close attention to the 'next' and 'prev'      |
        //   |   pointers of the nodes.                            |
        //   | - Works in-place; doesn't create new nodes.         |
        //   | - Always checks if the list is empty or has only    |
        //   |   one node.                                         |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+

};


int main() {

    // Test: Swap Pairs with Single Node
    {
        cout << "\n----- Test: Swap Pairs with Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
        int value = list.getHead()->value;
        cout << "Head value after swapping pairs: " << value << " - EXPECTED: 1\n";
        cout << (value == 1 ? "PASS\n" : "FAIL\n");
    }

    // Test: Swap Pairs with Two Nodes
    {
        cout << "\n----- Test: Swap Pairs with Two Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int nextValue = list.getHead()->next->value;
        cout << "Head value after swapping pairs: " << headValue << " - EXPECTED: 2\n";
        cout << "Next value after swapping pairs: " << nextValue << " - EXPECTED: 1\n";
        cout << (headValue == 2 && nextValue == 1 ? "PASS\n" : "FAIL\n");
    }

    // Test: Swap Pairs with Multiple Nodes
    {
        cout << "\n----- Test: Swap Pairs with Multiple Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
        //cout << "PASS/FAIL test: ";
        cout << (list.getHead()->value == 2 && 
                 list.getHead()->next->value == 1 && 
                 list.getHead()->next->next->value == 4 &&
                 list.getHead()->next->next->next->value == 3 ? "PASS\n" : "FAIL\n");
    }

}

