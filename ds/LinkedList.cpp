#include <iostream>
using namespace std;

template <class T>
class LinkedList{
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
    
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    LinkedList(T data){
        Node* n = new Node(data);
        head = n;
        tail = n;
        size = 1;
    }
    LinkedList(LinkedList const &l){
        this->head = l.head;
        this->tail = l.tail;
        this->size = l.size;
    }
    
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    T getFirst(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return -1;
        }
        return head->data;
    }
    T getLast(){
        if(tail == NULL){
            cout << "List is empty" << endl;
            return -1;
        }
        return tail->data;
    }
    T get(int index){
        if(index < 0 || index >= size){
            cout << "Index out of bound" << endl;
            return -1;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    void addFirst(T data){
        Node* n = new Node(data);
        n->next = head;
        head = n;
        if(size == 0){
            tail = n;
        }
        size++;
    }
    void addLast(T data){
        Node* n = new Node(data);
        if(size == 0){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    void add(int index, T data){
        if(index < 0 || index > size){
            cout << "Index out of bound" << endl;
            return;
        }
        if(index == 0){
            addFirst(data);
        }
        else if(index == size){
            addLast(data);
        }
        else{
            Node* n = new Node(data);
            Node* temp = head;
            for(int i = 0; i < index-1; i++){
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
            size++;
        }
    }
    T removeFirst(){
        if(size == 0){
            cout << "List is empty" << endl;
            return -1;
        }
        T temp = head->data;
        head = head->next;
        size--;
        if(size == 0){
            tail = NULL;
        }
        return temp;
    }
    T removeLast(){
        if(size == 0){
            cout << "List is empty" << endl;
            return -1;
        }
        T temp = tail->data;
        if(size == 1){
            head = NULL;
            tail = NULL;
        }
        else{
            Node* n = head;
            for(int i = 0; i < size-2; i++){
                n = n->next;
            }
            n->next = NULL;
            tail = n;
        }
        size--;
        return temp;
    }
    T remove(int index){
        if(index < 0 || index >= size){
            cout << "Index out of bound" << endl;
            return -1;
        }
        if(index == 0){
            return removeFirst();
        }
        else if(index == size-1){
            return removeLast();
        }
        else{
            Node* temp = head;
            for(int i = 0; i < index-1; i++){
                temp = temp->next;
            }
            T ans = temp->next->data;
            temp->next = temp->next->next;
            size--;
            return ans;
        }
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};