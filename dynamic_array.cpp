#include<array>
#include<stdexcept>
#include<cstdio>
#include<stdlib.h>
#include<iostream>

#define MIN_CAPACITY 10
#define Growth_Factor 2
using namespace std;

template<class T>
class Array {
public:
    int m_capacity;
    int m_size;
    T* m_data;

public:
    Array();   // constructor declared
    ~Array();
    void push(T value);
    T pop();
    T get(size_t index);
    void set(size_t index , T value);
    size_t size();
    size_t capacity();
    void resize();
    void print();
};

template<class T>
Array<T>::Array(){
    m_capacity=MIN_CAPACITY;
    m_size=0;
    m_data=(T*)malloc(m_capacity * sizeof(int));

    if((!m_data)){
        throw std::bad_alloc();
    }
}


// destructor when memory on heap

template<class T>
Array<T> ::~Array()
{
    free(m_data);
}


template<class T>
void Array<T>::push(T value){
if(m_size >=m_capacity){
    resize();
}
 *(m_data+ m_size++)=value;
}

template<class T>
T Array<T>:: pop(){
    if(m_size==0){
        cout << "Nothing to print" << endl;
        return -1;
    }
    return *(m_data + --m_size);
}


template<class T>
void Array<T>:: set(size_t index, T value){
    while(index>=m_size){
        this->push(0);
    }
    *(m_data+index)=value;
}


template<class T>
T Array<T>:: get(size_t index){
    return *(m_data+index);
}

template<class T>
size_t  Array<T> :: size(){
    return m_size;
}

template<class T>
size_t Array<T>::capacity(){
    return m_capacity;
}

template <class T>
void Array<T>::resize() {
    size_t capacity = m_capacity*Growth_Factor;
    
    T *tmp = (T*)realloc(m_data, capacity * sizeof(*m_data));
    
    if (!tmp) //if null
        throw std::bad_alloc();
  
    m_data = tmp;
 
    m_capacity = capacity;
}

template <class T>
void Array<T>::print() {
    size_t i = 0;
    // print all the elements of the array
    while (i < m_size) {
        cout << "Array[" << i << "] = " << this->get(i) << "\n";
        i++;
    }
}

