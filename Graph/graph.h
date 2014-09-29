#ifndef GRAPH_H
#define GRAPH_H
#include "src/dataStructures/Graph/graphNode/graphnode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "src/dataStructures/stack/stack.h"
#include "iostream"

template <typename K>

class Graph{
public:
    Graph();
    /*!
     * \brief add is going to create a new node to the graph.
     * \param pNode which is the element of the node we want to add.
     * \return boolean depending if it was able to add.
     */
    bool add (K pNode);
    /*!
     * \brief remove is going to delete a node that contains the element
     * \param pNode is the element of the node we want to remove.
     * \return boolean if it was able.
     */
    bool remove(K pNode);
    /*!
     * \brief exists searches for  the node containing the element
     * \param pNode is the element contained
     * \return boolean if it was able
     */
    bool exists(K pNode);
    /*!
     * \brief connect will connect the two nodes that contains A and B.
     * \param pNodeA element of the node.
     * \param pNodeB element of the node.
     * \return boolean if it was able to connect, the only way it wouldn't is if the connection already exists. Or that one node doesn't exist.
     */
    bool connect(K pNodeA , K pNodeB);
    /*!
     * \brief areConnected search if the two nodes are connected.
     * \param pNodeA element of the node.
     * \param pNodeB element of the node.
     * \return boolean if the nodes were connected.
     */
    bool areConnected(K pNodeA, K pNodeB);
    /*!
     * \brief describe will print every node of the graph.
     */
    void describe();

    /*!
     * \brief clears empties the graph
     * \return boolean
     */
    bool clear();

    /*!
     * \brief getNode returns the node.
     * \param pNode is the one we want to get
     * \return pointer to the node.
     */
    GraphNode<K>* getNode(K pNode);
    /*!
     * \brief moveAB move from A to B
     * \param nodeA node from where we move
     * \param nodeB node where to move
     * \return boolean if it was able to move from A to B.
     */
    bool moveAB(K nodeA, K nodeB);
private:
    /*!
     * \brief _GraphNodes simple linked list containing the pointers to the nodes.
     */
    SimpleList<GraphNode<K>* >* _GraphNodes;
    /*!
     * \brief _elements simple linked list containing only the elements of every node.
     */
    SimpleList<K>* _elements;

    /*!
     * \brief searchforPaths uses backtracking in order to get a Path from A to B
     * \param pNodeA
     * \param pNodeB
     * \param pList
     * \param closed
     */
    void searchforPaths (GraphNode<K> *pNodeA, GraphNode<K> *pNodeB, SimpleList<GraphNode<K> *>* pList, Stack<GraphNode<K>* >* path, SimpleList<GraphNode<K>* >* closed);
};
template <typename K>
Graph<K>::Graph(){
    this->_GraphNodes = new SimpleList<GraphNode<K>* >();
    this->_elements = new SimpleList<K>();
}
template <typename K>
bool Graph<K>::add(K pNode){
    if (this->_elements->ifExists(pNode)){
        return false;
    }
    GraphNode<K>* newNode = new GraphNode<K>();
    newNode->setElement(pNode);
    this->_elements->append(pNode);
    this->_GraphNodes->append(newNode);
    return true;
}

template <typename K>
bool Graph<K>::remove(K pNode){
    int index = this->_elements->indexOf(pNode);
    if (index == -1){
        return false;
    }
    this->_elements->removeAt(index);
    this->_GraphNodes->removeAt(index);
    return true;
}

template <typename K>
bool Graph<K>::areConnected(K pNodeA, K pNodeB){
    int indexA = this->_elements->indexOf(pNodeA);
    int indexB = this->_elements->indexOf(pNodeB);
    GraphNode<K>* nodeA = (*this->_GraphNodes->elementAt(indexA)->getElement());
    GraphNode<K>* nodeB = (*this->_GraphNodes->elementAt(indexB)->getElement());
    return nodeA->existsConnection(nodeB);
}

template <typename K>
bool Graph<K>::connect(K pNodeA, K pNodeB){
    int indexA = this->_elements->indexOf(pNodeA);
    int indexB = this->_elements->indexOf(pNodeB);
    GraphNode<K>* nodeA = (*this->_GraphNodes->elementAt(indexA)->getElement());
    GraphNode<K>* nodeB = (*this->_GraphNodes->elementAt(indexB)->getElement());
    return nodeA->connectTo(nodeB);
}

template <typename K>
bool Graph<K>::exists(K pNode){
    return this->_elements->ifExists(pNode);
}

template< typename K>
void Graph<K>::describe(){
    SimpleListNode<K>* temp = this->_elements->getHead();
    int i = 0;
    while (i!=this->_elements->getLenght()){
        cout << *temp->getElement()<< " ";
        temp = temp->getNext();
        i++;
    }
}
template <typename K>
bool Graph<K>::clear(){
    this->_elements->clear();
    this->_GraphNodes->clear();
    return true;
}

template <typename K>
GraphNode<K>* Graph<K>::getNode(K pNode){
    int index = this->_elements->indexOf(pNode);
    return *this->_GraphNodes->elementAt(index)->getElement();
}

template <typename K>
bool Graph<K>::moveAB(K nodeA, K nodeB){
    int indexA = this->_elements->indexOf(nodeA);
    int indexB = this->_elements->indexOf(nodeB);
    GraphNode<K>* tempA = *this->_GraphNodes->elementAt(indexA)->getElement();
    GraphNode<K>* tempB = *this->_GraphNodes->elementAt(indexB)->getElement();
    SimpleList<GraphNode<K>* >* solution = new SimpleList<GraphNode<K>* >();
    SimpleList<GraphNode<K>* >* closed = new SimpleList<GraphNode<K>* >();
    Stack<GraphNode<K>* >* path = new Stack<GraphNode<K>* >();
    if (tempA->getConnections()->getLenght() == 0){
        return false;
    }
    this->searchforPaths(tempA,tempB,solution,path,closed);
    Stack<GraphNode<K>* >* temp =  new Stack<GraphNode<K>* >();
    while (solution->getLenght() !=0){
        temp->push(*solution->getHead()->getElement());
        solution->deleteHead();
    }

    SimpleList<GraphNode<K>* >* newsolution = new SimpleList<GraphNode<K>* >();
    while (temp->getLenght() != 0){
        GraphNode<K>* tp = *temp->pop()->getElement();
        newsolution->append(tp);
    }
    this->searchforPaths(tempA,tempB,solution,path,closed);

    //revisar solucion
    if(newsolution->getLenght() == 1 || newsolution->getLenght() == 0){
        return false;
    }else if (*(*newsolution->getHead()->getElement())->getElement() == nodeA &&
              *(*newsolution->getTail()->getElement())->getElement() == nodeB){
        return true;
    }else{
        return false;
    }
}

template <typename K>
void Graph<K>::searchforPaths(GraphNode<K> *pNodeA, GraphNode<K> *pNodeB, SimpleList<GraphNode<K> *>* pList, Stack<GraphNode<K>* >* path, SimpleList<GraphNode<K>* >* closed){
    path->push(pNodeA);
    //Hay coneccion con el nodo final
    if ((*path->top()->getElement())->existsConnection(pNodeB)){
        path->push(pNodeB);
        //armar solucion
        while (path->getLenght() != 0){
            GraphNode<K>* temp = *path->pop()->getElement();
            pList->append(temp);
        }
    //El nodo no tiene conecciones
    } else if((*path->top()->getElement())->getConnections()->getLenght() == 0){
        path->pop();
        if ( path->getLenght() != 0){
            this->searchforPaths(*path->top()->getElement(), pNodeB, pList, path, closed);
        }
    //El nodo existe en la lista de elementos cerrados
    } else if (closed->ifExists(*path->top()->getElement())){
        path->pop();
        if ( path->getLenght() != 0){
            this->searchforPaths(*path->top()->getElement(), pNodeB, pList, path, closed);
        }
    // El nodo tiene conecciones, se procede a revisarlas
    } else{
        SimpleList<GraphNode<K>* >* temp = (*path->top()->getElement())->getConnections();
        //El nodo tiene conecciones
        while (temp->getLenght() != 0){
            //La coneccion existe en la lista de elementos cerrados, se elimina
            if (closed->ifExists(*temp->getHead()->getElement() )){
                temp->deleteHead();
            //Se corre el programa con el nodo obtenido en la coneccion
            } else {
                this->searchforPaths(*temp->getHead()->getElement(), pNodeB, pList, path, closed);
                temp->deleteHead();
            }
        }
    }
}





#endif // GRAPH_H
