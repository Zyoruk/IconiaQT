#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "src/dataStructures/interfaceNode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"

template <typename K>
/*!
 * \brief The GraphNode class
*/

class GraphNode: public interfaceNode<K>{
public:
    GraphNode();
    /*!
     * \brief existsConnection Will search if this node is connected to a B one.
     * \param pNodeTo graph node pointer.
     * \return if exists
     */
    bool existsConnection(GraphNode<K>* pNodeTo);
    /*!
     * \brief removeConnectionTo If the connection exists, then remove it.
     * \param pNodeTo Graph node pointer to the one we want to remove connection.
     * \return if it was able to remove.
     */
    bool removeConnectionTo(GraphNode<K>* pNodeTo);
    /*!
     * \brief connectTo
     * \param pNodeTo
     * \return
     */
    bool connectTo(GraphNode<K>* pNodeTo);

    SimpleList<GraphNode<K>*>* getConnections();
private:
    /*!
     * \brief _connectedTo is the list that contains all the nodes this is connected to.
     */
    SimpleList<GraphNode<K>*>* _connectedTo;
};
template <typename K>
GraphNode<K>::GraphNode(){
    this->_connectedTo = new SimpleList<GraphNode<K>*>();
}
template <typename K>
bool GraphNode<K>::existsConnection(GraphNode<K> *pNodeTo){
    return this->_connectedTo->ifExists(pNodeTo);
}

template <typename K>
bool GraphNode<K>::connectTo(GraphNode<K> *pNodeTo){
   return this->_connectedTo->append(pNodeTo);
}
template <typename K>
bool GraphNode<K>::removeConnectionTo(GraphNode<K> *pNodeTo){
    return this->_connectedTo->remove(pNodeTo);
}
template <typename K>
SimpleList<GraphNode<K>* >* GraphNode<K>::getConnections(){
    return this->_connectedTo;
}

#endif // GRAPHNODE_H
