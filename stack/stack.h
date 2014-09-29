#ifndef STACK_H
#define STACK_H

#include "src/dataStructures/stack/stackNode.h"
template <typename K>
class Stack{
public:
    Stack();
    bool push(K pNewTop);
    StackNode<K>* top();
    StackNode<K>* pop();
    bool isEmpty();
    bool ifExists(K pElement);
    unsigned int getLenght();
private:
    int _lenght;
    StackNode<K>* _top;
};
template<typename K>
Stack<K>::Stack(){
    this->_lenght = 0;
    this->_top= 0;
}

template <typename K>
bool Stack<K>::isEmpty(){ return this->_lenght == 0;}

template <typename K>
unsigned int Stack<K>::getLenght(){return this->_lenght;}

template <typename K>
StackNode<K>* Stack<K>::top(){return this->_top;}

template <typename K>

StackNode<K>* Stack<K>::pop(){
     StackNode<K>* tmp = this->_top;
     this->_top = this->_top->getUnder();
     this->_lenght-=1;
     return tmp;
}

template <typename K>
bool Stack<K>::ifExists(K pElement){
    if (this->_lenght == 0){
        return false;
    }
    StackNode<K>* current = this->_top;
    for ( int i = 0 ; i < this->_lenght ; i++){
        if (*(current->getElement()) == pElement){
            return true;
        }else{
            if ( current->getUnder() == 0){
                return false;
            }
            current = current->getUnder();
        }
    }
    return false;
}

template <typename K>
bool Stack<K>::push(K pElement){
    if (this->_lenght == 0){
        StackNode<K>* tmp = new StackNode<K>();
        tmp->setElement(pElement);
        this->_top = tmp;
        this->_lenght += 1;
        return true;
    }else{
        StackNode<K>* tmp = new StackNode<K>();
        tmp->setElement(pElement);
        tmp->setUnder(this->_top);
        this->_top = tmp;
        this->_lenght += 1;
        return true;
    }
    return false;
}
#endif // STACK_H
