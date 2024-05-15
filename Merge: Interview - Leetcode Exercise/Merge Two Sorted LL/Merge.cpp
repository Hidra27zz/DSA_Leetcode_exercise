#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
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
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
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
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        
		//   +=====================================================+
		//   |                WRITE YOUR CODE HERE                 |
		//   | Description:                                        |
		//   | - This method merges two sorted linked lists        |
		//   |   into a single sorted linked list.                 |
		//   | - Utilizes a dummy node to simplify merging.        |
		//   |                                                     |
		//   | Return type: void                                   |
		//   | - Modifies the list in place.                       |
		//   | - Sets the 'head' and 'tail' pointers correctly.    |
		//   |                                                     |
		//   | Tips:                                               |
		//   | - Uses a dummy node for easier linking.             |
		//   | - Check output from Test.cpp in "User logs".        |
		//   +=====================================================+
		
		
		
		void merge(LinkedList& otherList) {
		    Node* dummy = new Node(0);
            Node* current = dummy;
            Node* otherHead = otherList.getHead();
            while(head && otherHead) {
                if(head->value < otherHead->value) {
                    current->next = head;
                    head = head->next;
                }
                else {
                    current->next = otherHead;
                    otherHead = otherHead->next;
                }
                current = current->next;
            }
            if(head) {
                current->next = head;
                while (current->next) {
                    current = current->next;
                }
            }
            else {
                current->next = otherHead;
                while (current->next) {
                    current = current->next;
                }
		    }
            tail = current;
            head = dummy->next;
            delete dummy;
            length += otherList.getLength();
        
            otherList.head = nullptr;
            otherList.tail = nullptr;
            otherList.length = 0;

        }


		
};


