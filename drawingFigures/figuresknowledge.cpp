#include "figuresknowledge.h"
#include "stack/stack.h"
figuresKnowledge::figuresKnowledge(){
    this->vertexes = new SimpleList<int>();
    this->figures = new SimpleList<drawingFigures*>();
}

void figuresKnowledge::describe() {
    this->vertexes->describe();
}

SimpleList<drawingFigures*>* figuresKnowledge::getFigures(){
    return this->figures;
}

SimpleList<int>* figuresKnowledge::getElements() {
    return this->vertexes;
}

bool figuresKnowledge::clear(){
    while (this->vertexes->getLenght()!=0){
        this->vertexes->deleteHead();
    }
    return true;
}

bool figuresKnowledge::add(int pNode, string ID){
    if (this->exists(pNode)){
        return false;
    }else{
        drawingFigures* temp = new drawingFigures();
        temp->setID( ID);
        temp->setVertexes(pNode);
        this->figures->append(temp);
        this->vertexes->append(pNode);
        return true;
    }

}

bool figuresKnowledge::remove(int pNode){
    if (this->exists(pNode)){
        int index =this->vertexes->indexOf(pNode);
        this->vertexes->remove(pNode);
        this->figures->removeAt(index);
        return true;
    }else{
        return false;
    }

}

bool figuresKnowledge::exists(int pNode){

    if(this->vertexes->ifExists(pNode)){
        return true;
    }else{
        return false;
    }
}

bool figuresKnowledge::areConnected(int pNodeA, int pNodeB) {
    int indexA = this->vertexes->indexOf(pNodeA);
    int indexB = this->vertexes->indexOf(pNodeB);
    drawingFigures* nodeA= *this->figures->elementAt(indexA)->getElement();
    drawingFigures* nodeB= *this->figures->elementAt(indexB)->getElement();
    return nodeA->existsConnection(nodeB);
}

bool figuresKnowledge::connect(int pNodeA, int pNodeB) {
    if (areConnected(pNodeA, pNodeB)){
        return false;
    } else {
        int indexA = this->vertexes->indexOf(pNodeA);
        int indexB = this->vertexes->indexOf(pNodeB);
        drawingFigures* nodeA= *this->figures->elementAt(indexA)->getElement();
        drawingFigures* nodeB= *this->figures->elementAt(indexB)->getElement();
        nodeA->connectTo(nodeB);
        return true;
    }
}

bool figuresKnowledge::moveAB(int pNodeA, int pNodeB) {
    int indexA = this->vertexes->indexOf(pNodeA);
    int indexB = this->vertexes->indexOf(pNodeB);
    drawingFigures* nodeA= *this->figures->elementAt(indexA)->getElement();
    drawingFigures* nodeB= *this->figures->elementAt(indexB)->getElement();
    SimpleList<int>* solution = new SimpleList<int>();
    SimpleList<int>* closed = new SimpleList<int>();
    Stack<drawingFigures* >* path = new Stack<drawingFigures* >();
    if (nodeA->getConnections()->getLenght() == 0){
        return false;
    }

    this->searchforPaths(nodeA,nodeB,solution,path,closed);
    cout << "solution lenght" << solution->getLenght();
    Stack<int>* temp =  new Stack<int>();
    while (solution->getLenght() !=0){
        temp->push(*solution->getHead()->getElement());
        solution->deleteHead();
    }

    SimpleList<int >* newsolution = new SimpleList<int >();
    while (temp->getLenght() != 0){
        int tp = *temp->pop()->getElement();
        newsolution->append(tp);
    }

    newsolution->describe();
    //revisar solucion
    if(newsolution->getLenght() == 1 || newsolution->getLenght() == 0){
        return false;
    }else if ((*newsolution->getHead()->getElement()) == nodeA->getVertexes() &&
              (*newsolution->getTail()->getElement()) == nodeB->getVertexes()){
        return true;
    }else{
        return false;
    }
}

void figuresKnowledge::searchforPaths(drawingFigures *pNodeA, drawingFigures* pNodeB, SimpleList<int>* pList, Stack<drawingFigures* >* path, SimpleList<int>* closed){
    path->push(pNodeA);
    //Hay coneccion con el nodo final
    if ((*path->top()->getElement())->existsConnection(pNodeB)){
        path->push(pNodeB);        
        //armar solucion
        while (path->getLenght() != 0){
            drawingFigures* temp = *path->pop()->getElement();
            pList->append(temp->getVertexes());
        }
    //El nodo no tiene conecciones
    } else if((*path->top()->getElement())->getConnections()->getLenght() == 0){
        path->pop();
        if ( path->getLenght() != 0){
            this->searchforPaths(*path->top()->getElement(), pNodeB, pList, path, closed);
        }
    //El nodo existe en la lista de elementos cerrados
    } else if (closed->ifExists((*path->top()->getElement())->getVertexes())){
        path->pop();
        if ( path->getLenght() != 0){
            this->searchforPaths(*path->top()->getElement(), pNodeB, pList, path, closed);
        }
    // El nodo tiene conecciones, se procede a revisarlas
    } else{
        SimpleList<drawingFigures* >* temp = (*path->top()->getElement())->getConnections();
        //El nodo tiene conecciones
        while (temp->getLenght() != 0){
            //La coneccion existe en la lista de elementos cerrados, se elimina
            if (closed->ifExists((*temp->getHead()->getElement())->getVertexes() )){
                temp->deleteHead();
            //Se corre el programa con el nodo obtenido en la coneccion
            } else {
               // cout << (*temp->getHead()->getElement())->getVertexes();

                this->searchforPaths(*temp->getHead()->getElement(), pNodeB, pList, path, closed);
                temp->deleteHead();
            }
        }
    }
}
