#include <iostream>
using namespace std;

template <class T>
class Queue{
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
    Node* tail;
    int size;
    
    public:
    
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    Queue(T data){
        Node* n = new Node(data);
        head = n;
        tail = n;
        size = 1;
    }
    Queue(Queue const &q){
        this->head = q.head;
        this->tail = q.tail;
        this->size = q.size;
    }
    
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    T front(){
        if(head == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }
    void enqueue(T data){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    T dequeue(){
        if(head == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        T temp = head->data;
        head = head->next;
        size--;
        return temp;
    }
};