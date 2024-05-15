/*
Pseudo Code:



Check if List is Already Sorted

If the list has less than 2 elements, it's already sorted, so exit the function.

Initialize Sorted and Unsorted List Heads

sortedListHead starts at the head of the list.

unsortedListHead starts at the second node in the list.

Detach sortedListHead from the rest of the list by setting its next to nullptr.

Begin Main Loop

Loop while unsortedListHead is not nullptr.

Prepare for Insertion

Pick the first node from the unsorted list (current = unsortedListHead).

Move unsortedListHead to its next node.

Check Where to Insert

If current->value is less than sortedListHead->value:

Insert at Beginning

Set current->next to sortedListHead.

Update sortedListHead to be current.

Otherwise:

Initialize Search Pointer

Start at sortedListHead.

Search for Insert Position

Loop while searchPointer->next is not nullptr and current->value is greater than searchPointer->next->value.

Move searchPointer to its next node.

Insert Node

Set current->next to searchPointer->next.

Set searchPointer->next to current.

End of Main Loop

Update List Head

Set the head of the list to be sortedListHead.

Update List Tail

Start at sortedListHead and traverse to the end.

Update the tail to be the last node visited.

*/

#include <iostream>
#include <vector>
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
        
        void insertionSort() {
            if(length < 2) return;
            Node* sortedListHead = head;
            Node* unsortedListHead = head->next;
            sortedListHead->next = nullptr;
            while(unsortedListHead) {
                Node*current = unsortedListHead;
                unsortedListHead = unsortedListHead->next;
                if(current->value < sortedListHead->value) {
                    current->next = sortedListHead;
                    sortedListHead = current;
                    
                }
                else {
                    Node* searchPointer = sortedListHead;
                    while(searchPointer->next && current->value > searchPointer->next->value) {
                        searchPointer = searchPointer->next;
                    }
                    current->next = searchPointer->next;
                    searchPointer->next = current;
                }
            }
            head = sortedListHead;
            
            while(sortedListHead) {
                tail = sortedListHead;
                sortedListHead = sortedListHead->next;
            }
        }
        
		//   +=====================================================+
		//   |                WRITE YOUR CODE HERE                 |
		//   | Description:                                        |
		//   | - This method sorts the linked list using           |
		//   |   the Insertion Sort algorithm.                     |
		//   | - Divides the list into sorted and unsorted parts.  |
		//   | - Iterates through unsorted part and inserts each   |
		//   |   node into the sorted part at the right position.  |
		//   |                                                     |
		//   | Return type: void                                   |
		//   |                                                     |
		//   | Tips:                                               |
		//   | - Uses two sub-lists to divide original list.       |
		//   | - Uses while loops for list traversal.              |
		//   | - Check output from Test.cpp in "User logs".        |
		//   +=====================================================+

        static void test() {
            
            // Check test result: PASS or FAIL
            auto checkTestResult = [](bool condition) {
                cout << (condition ? "PASS" : "FAIL") << endl;
            };

            // Convert linked list to vector
            auto listToVector = [](LinkedList& list) {
                vector<int> result;
                Node* current = list.getHead();
                while (current != nullptr) {
                    result.push_back(current->value);
                    current = current->next;
                }
                return result;
            };

            // Test 1: EmptyList
            {
                cout << "\n------ Test: EmptyList ------\n";

                LinkedList list(0);
                list.deleteFirst();

                cout << "Before: ";
                list.printList();

                list.insertionSort();

                cout << "After: ";
                list.printList();

                checkTestResult(list.getLength() == 0);
            }

            // Test 2: SingleElement
            {
                cout << "\n------ Test: SingleElement ------\n";

                LinkedList list(5);

                cout << "Before: ";
                list.printList();

                list.insertionSort();

                cout << "After: ";
                list.printList();

                checkTestResult(list.getHead()->value == 5 && list.getTail()->value == 5);
            }

            // Test 3: TwoElements
            {
                cout << "\n------ Test: TwoElements ------\n";

                LinkedList list(5);
                list.append(3);

                cout << "Before: ";
                list.printList();

                list.insertionSort();

                cout << "After: ";
                list.printList();

                checkTestResult(listToVector(list) == vector<int>({3, 5}));
            }

            // Test 4: MultipleElements
            {
                cout << "\n------ Test: MultipleElements ------\n";

                LinkedList list(5);
                list.append(3);
                list.append(8);
                list.append(1);

                cout << "Before: ";
                list.printList();

                list.insertionSort();

                cout << "After: ";
                list.printList();

                checkTestResult(listToVector(list) == vector<int>({1, 3, 5, 8}));
            }

            // Test 5: AlreadySorted
            {
                cout << "\n------ Test: AlreadySorted ------\n";

                LinkedList list(1);
                list.append(3);
                list.append(5);
                list.append(8);

                cout << "Before: ";
                list.printList();

                list.insertionSort();

                cout << "After: ";
                list.printList();

                checkTestResult(listToVector(list) == vector<int>({1, 3, 5, 8}));
            }

            // Test 6: Reversed
            {
                cout << "\n------ Test: Reversed ------\n";

                LinkedList list(8);
                list.append(5);
                list.append(3);
                list.append(1);

                cout << "Before: ";
                list.printList();

                list.insertionSort();

                cout << "After: ";
                list.printList();

                checkTestResult(listToVector(list) == vector<int>({1, 3, 5, 8}));
            }
            
        }

};


int main() {
    LinkedList::test();
    return 0;
}