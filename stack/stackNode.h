#ifndef STACKNODE_Hp
#define STACKNODE_H
#include "src/dataStructures/interfaceNode.h"
template <typename K>
class StackNode : public interfaceNode<K>{
public:
    StackNode();
    StackNode<K>* getUnder();
    void setUnder(StackNode<K>* pElement);
private:
    StackNode<K>* _underMe;


};
template <typename K>
StackNode<K>::StackNode(){
    this->_underMe = 0;
}

template <typename K>
StackNode<K>* StackNode<K>::getUnder(){
    return this->_underMe;
}
template <typename K>
void StackNode<K>::setUnder(StackNode<K>* pElement){
    this->_underMe = pElement;
}

#endif // STACKNODE_H
