#include "drawingFigures/drawingfigures.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

drawingFigures::drawingFigures()
{
    this->connectedTo = new SimpleList<drawingFigures*>();
    this->_auxConnections = new SimpleList<int>();
    this->height = 0;
    this->width = 0;
}

void drawingFigures::setWidth(int w)
{
    this->width = w;
}

void drawingFigures::setHeight(int h)
{
    this->height = h;
}

void drawingFigures::setID(string ID)
{
    this->ID = ID;
}

void drawingFigures::setVertexes(int v)
{
    this->vertexes = v;
}

string drawingFigures::getID()
{
    return this->ID;
}

int drawingFigures::getVertexes()
{
    return this->vertexes;
}



bool drawingFigures::existsConnection(drawingFigures* A){
    int temp = A->getVertexes();
    return this->_auxConnections->ifExists(temp);;
}


bool drawingFigures::connectTo(drawingFigures* A){
   int temp = A->getVertexes();
   if (this->_auxConnections->ifExists(temp)){
       return false;
   }
   this->_auxConnections->append(temp);
   return this->connectedTo->append(A);
}

bool drawingFigures::removeConnection(drawingFigures* A){
    int temp = A->getVertexes();
    if (this->_auxConnections->ifExists(temp)){
        int index = this->_auxConnections->indexOf(temp);
        this->_auxConnections->removeAt(index);
        this->connectedTo->removeAt(index);
        return true;
    }
    return false;
}

SimpleList<drawingFigures*>* drawingFigures::getConnections(){
    return this->connectedTo;
}
