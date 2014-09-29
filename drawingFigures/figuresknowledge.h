#ifndef FIGURESdrawingFiguresNOWLEDGE_H
#define FIGURESdrawingFiguresNOWLEDGE_H
#include "Graph/graph.h"
#include "drawingfigures.h"
#include "SimpleList/SimpleList.h"

class figuresKnowledge
{
public:
    figuresKnowledge();
    /*!
     * \brief add is going to create a new node to the graph.
     * \param pNode which is the element of the node we want to add.
     * \return boolean depending if it was able to add.
     */
    bool add (int pNode, string ID);
    /*!
     * \brief remove is going to delete a node that contains the element
     * \param pNode is the element of the node we want to remove.
     * \return boolean if it was able.
     */
    bool remove(int pNode);
    /*!
     * \brief exists searches for  the node containing the element
     * \param pNode is the element contained
     * \return boolean if it was able
     */
    bool exists(int pNode);
    /*!
     * \brief connect will connect the two nodes that contains A and B.
     * \param pNodeA element of the node.
     * \param pNodeB element of the node.
     * \return boolean if it was able to connect, the only way it wouldn't
     * is if the connection already exists. Or that one node doesn't exist.
     */
    bool connect(int pNodeA , int pNodeB);
    /*!
     * \brief areConnected search if the two nodes are connected.
     * \param pNodeA element of the node.
     * \param pNodeB element of the node.
     * \return boolean if the nodes were connected.
     */
    bool areConnected(int pNodeA, int pNodeB);
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
    drawingFigures* getNode(int pNode);
    /*!
     * \brief moveAB move from A to B
     * \param nodeA node from where we move
     * \param nodeB node where to move
     * \return boolean if it was able to move from A to B.
     */
    bool moveAB(int nodeA, int nodeB);

    SimpleList<int>* getElements();

    SimpleList<drawingFigures*>* getFigures();
private:
    /*!
     * \brief searchforPaths
     * \param pNodeA
     * \param pNodeB
     * \param pList
     * \param path
     * \param closed
     */
    void searchforPaths(drawingFigures *pNodeA, drawingFigures *pNodeB,
                        SimpleList<drawingFigures*>* pList, Stack<drawingFigures* >* path,
                        SimpleList<drawingFigures*>* closed);
    SimpleList<int>* vertexes;
    SimpleList<drawingFigures*>* figures;
};
#endif // FIGURESdrawingFiguresNOWLEDGE_H
