#include <iostream>
using namespace std;

template <class T>
class Graph{
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
    
    Graph(){
        head = NULL;
        size = 0;
    }
    Graph(T data){
        Node* n = new Node(data);
        head = n;
        size = 1;
    }
    Graph(Graph const &g){
        this->head = g.head;
        this->size = g.size;
    }
    
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    T getFirst(){
        if(head == NULL){
            cout << "Graph is empty" << endl;
            return -1;
        }
        return head->data;
    }
    T getLast(){
        if(head == NULL){
            cout << "Graph is empty" << endl;
            return -1;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp->data;
    }
    T get(int index){
        if(head == NULL){
            cout << "Graph is empty" << endl;
            return -1;
        }
        if(index < 0 || index >= size){
            cout << "Index out of bounds" << endl;
            return -1;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    void add(T data){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
        size++;
    }
    void add(int index, T data){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
        }
        else if(index < 0 || index > size){
            cout << "Index out of bounds" << endl;
        }
        else if(index == 0){
            n->next = head;
            head = n;
        }
        else{
            Node* temp = head;
            for(int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
        size++;
    }
    void removeFirst(){
        if(head == NULL){
            cout << "Graph is empty" << endl;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }
    void removeLast(){
        if(head == NULL){
            cout << "Graph is empty" << endl;
        }
        else if(size == 1){
            delete head;
            head = NULL;
            size--;
        }
        else{
            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
    void remove(int index){
        if(head == NULL){
            cout << "Graph is empty" << endl;
        }
        else if(index < 0 || index >= size){
            cout << "Index out of bounds" << endl;
        }
        else if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        else{
            Node* temp = head;
            for(int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            size--;
        }
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};