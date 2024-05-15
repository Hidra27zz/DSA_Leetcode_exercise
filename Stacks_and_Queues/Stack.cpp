#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Stack{
    private:
        Node* top;
        int height;
    public:
        
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        void printStack(){
            Node* temp = top;
            while(temp){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
        void getTop(){
            cout << "Top: " << top->value << endl;
        }

        void getHeight(){
            cout << "Height: " << height << endl;
        }

        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop(){
            Node* temp = top;
            if(height == 0) return -1;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;
            return poppedValue;
        }

        //~Stack();

};

int main(){
    Stack myStack = Stack(3);
    myStack.push(5);
    myStack.push(2);
    myStack.printStack();
    myStack.getTop();
    myStack.getHeight();
    cout<<"The number was popped: "<< myStack.pop() << endl; 
    myStack.printStack();
    return 0;
}