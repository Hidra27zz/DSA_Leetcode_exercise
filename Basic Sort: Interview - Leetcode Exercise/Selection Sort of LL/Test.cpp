#include <iostream>
#include <vector>
#include "InsertionSort.cpp"

using namespace std;


//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+


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


