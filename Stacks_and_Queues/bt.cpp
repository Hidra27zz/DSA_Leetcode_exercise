#include <vector>
#include <iostream>
#include <limits.h>
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
        Stack(){};
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
        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }
        int pop(){
            if(height == 0) return INT_MIN;
            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            
            height--;
            return poppedValue;
        }
        void dec_to_bin(int number){
            Stack* result;
            while(number > 0){
                int x = number%2;
                number /= 2;
                result->push(x);
            }
            while(result){
                int item = result->top->value;
                result->pop();
                cout << item;
            }
        }
        
        --
        ~Stack(){};
        
};

int main(){
    int number;
    cin >> number;
    Stack a;
    a.dec_to_bin(number);
}