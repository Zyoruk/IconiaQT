#ifndef DRAWINGFIGURES_H
#define DRAWINGFIGURES_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include "SimpleList/SimpleList.h"

using namespace std;
using namespace cv;

class drawingFigures
{
public:
    drawingFigures();
    void setWidth(int w);
    void setHeight(int h);
    void setID(string ID);
    void setVertexes(int v);
    void draw();
    string getID();
    int getVertexes();
    int getArea();
    bool connectTo (drawingFigures* A);
    bool existsConnection(drawingFigures* A);
    bool removeConnection(drawingFigures* A);
    SimpleList<drawingFigures*>* getConnections();


protected:
    int width;
    int height;
    int vertexes;
    string ID;
    SimpleList<drawingFigures*>* connectedTo;
    SimpleList<int>* _auxConnections;
};

#endif // DRAWINGFIGURES_H
