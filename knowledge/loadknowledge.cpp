#include "loadknowledge.h"
#include "drawingFigures/figuresknowledge.h"

loadKnowledge::loadKnowledge(figuresKnowledge* programmKnowledge)
{
    programmKnowledge->add(4,"RECT");
    programmKnowledge->add(3,"TRI");
    programmKnowledge->add(5,"PENTA");
    programmKnowledge->add(2,"LINE");
    programmKnowledge->add(6,"HEXA");
    programmKnowledge->add(7,"HEPTA");
    programmKnowledge->add(8,"CIRC");
}
