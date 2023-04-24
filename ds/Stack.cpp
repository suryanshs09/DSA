#include <iostream>
using namespace std;

template <class T>
class Stack{
    class Node{
        public:
        T data;
        Node* next;
        
        Node(T data){
            this->data = data;
            next = NULL;
        }
    };
    
    Node* head;
    int size;
    
    public:
    
    Stack(){
        head = NULL;
        size = 0;
    }
    Stack(T data){
        Node* n = new Node(data);
        head = n;
        size = 1;
    }
    Stack(Stack const &s){
        this->head = s.head;
        this->size = s.size;
    }
    
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    T top(){
        if(head == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
    void push(T data){
        Node* n = new Node(data);
        n->next = head;
        head = n;
        size++;
    }
    T pop(){
        if(head == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }
        T temp = head->data;
        Node* n = head;
        head = head->next;
        delete n;
        size--;
        return temp;
    }
};