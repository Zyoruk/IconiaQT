#include "mainwindow.h"
#include <QApplication>
#include "drawingFigures/figuresknowledge.h"
#include "stack/stack.h"
//int argc, char *argv[]
int main()
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
    figuresKnowledge* kn = new figuresKnowledge();
    kn->add(4,"RECT");
    kn->add(3,"TRI");
    kn->add(5,"PENTA");
    kn->connect(4,3);
    kn->connect(3,5);

    kn->moveAB(4,5);
//    Stack<drawingFigures*>* tp = new Stack<drawingFigures*>();
//    drawingFigures* tp2 = new drawingFigures();
//    tp2->setID("sd");
//    tp2->setVertexes(34);
//    drawingFigures* t3 = new drawingFigures();
//    t3->setID("345");
//    t3->setVertexes(345);
//    tp2->connectTo(t3);

//    tp->push(t3);
//    tp->push(tp2);


//    cout << (*tp->top()->getElement())->existsConnection(t3) << "\n";
//    cout << (*tp->top()->getElement())->existsConnection(tp2) << "\n";

}
