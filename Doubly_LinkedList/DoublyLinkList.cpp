#include <iostream>
using namespace std;

class Node{
    public: 
        int value;
        Node* next;
        Node* prev;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;

        }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList(){
            Node* temp = head;
            while(temp){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead(){
            cout << "Head: " << head->value << endl;
        }
        void getTail(){
            cout << "Tail: " << tail->value << endl;
        }

        void getLength(){
            cout << "Length: " << length << endl;
        }

        void append(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        void deleteLast(){
            Node* temp = tail;
            if(length == 0) return;
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;

        }

        void prepend(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst(){
            Node* temp = head;
            if(length == 0) return;
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
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
                for(int i = length - 1; i > index; i++){
                    temp = temp->prev;
                }
            }

            return temp;
        }
        
        bool set(int index, int value){
            Node* temp = get(index);
            if(temp){
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value){
            Node* newNode = new Node(value);
            Node* before = head;
            Node* after = head;
            if(index < 0 || index > length){
                return false;
            }
            if(index == 0){
                prepend(value);
                return true;
            }
            if(index == length){
                append(value);
                return true;
            }

            before = get(index - 1);
            after = before->next;
            before->next = newNode;
            newNode->next = after;
            after->prev = newNode;
            newNode->prev = before;
            length++;
            return true;

        }

        void deleteNode(int index){
            if(index < 0 || index <= length) return;
            if(index == 0){
                return deleteFirst();
            }

            if(index == length-1){
                return deleteLast();
            }
            Node* temp = get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
        }


};





int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->printList();
    myDLL->getHead();
}