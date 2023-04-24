#include <iostream>
using namespace std;

template <class T>
class DynamicArray{
    T* data;
    int capacity;
    int nextIndex;
    
    public:
    
    DynamicArray(){
        data = new T[1];
        capacity = 1;
        nextIndex = 0;
    }
    DynamicArray(int cap){
        data = new T[cap];
        capacity = cap;
        nextIndex = 0;
    }
    DynamicArray(DynamicArray const &d){
        this->data = new T[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    
    int getCapacity(){
        return capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
    T get(int index){
        if(index < 0 || index >= nextIndex){
            cout << "Index out of bound" << endl;
            return -1;
        }
        return data[index];
    }
    void set(int index, T value){
        if(index < 0 || index >= nextIndex){
            cout << "Index out of bound" << endl;
            return;
        }
        data[index] = value;
    }
    void add(T value){
        if(nextIndex == capacity){
            T* temp = new T[2*capacity];
            for(int i = 0; i < size; i++){
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
            capacity *= 2;
        }
        data[nextIndex] = value;
        nextIndex++;
    }
    void remove(int index){
        if(index < 0 || index >= nextIndex){
            cout << "Index out of bound" << endl;
            return;
        }
        for(int i = index; i < nextIndex-1; i++){
            data[i] = data[i+1];
        }
        nextIndex--;
    }
    void print(){
        for(int i = 0; i < nextIndex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};