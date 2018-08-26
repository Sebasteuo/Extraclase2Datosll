#include <iostream>

using namespace std;

template <class S>
class Node{
public:
    Node(S data){
        this->data = data;
        next = nullptr;
    }

    Node(){
        next = nullptr;
    }

    void setNext(Node<S> *next){
        this->next = next;
    }

    Node<S> *getNext(){
        return next;
    }

    void setData(S data){
        this->data = data;
    }

    S getData(){
        return data;
    }

    ~Node(){
        next = nullptr;
        data = NULL;
    }

private:
    Node<S> *next;
    S data;
};

template <class T>
class LinkedList{
public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    void add(T data){
        if (head == nullptr){
            head = new Node<T>(data);
            size++;
        }
        else{
            Node<T> *tmp = head;

            while(tmp->getNext() != nullptr){
                tmp = tmp->getNext();
            }
            tmp->setNext(new Node<T>(data));
            size++;
        }
    }

    void remove(int index){
        if (index == 0){
            Node<T> *tmp;
            tmp = head;
            head = head->getNext();
            size--;
            delete tmp;
            return;
        }
        else{
            Node<T> *tmp = head;
            Node<T> *tmp2;

            for (int i = 0; i < size; ++i) {
                if (i == index){
                    tmp2->setNext(tmp->getNext());
                    delete tmp;
                    size--;
                    return;
                }
                tmp2 = tmp;
                tmp = tmp->getNext();
            }
        }
    }

    T get(int index){
        Node<T> *tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->getNext();
        }
        return tmp->getData();
    }

    int length(){
        return size;
    }

    ~LinkedList(){
        head = nullptr;
        size = NULL;
    }

private:
    Node<T> *head;
    int size;
};