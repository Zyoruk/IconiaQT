#ifndef DETECTOR_H
#define DETECTOR_H
#include "drawingFigures/figuresknowledge.h"
#include "drawingFigures/drawingfigures.h"
#include "SimpleList/SimpleList.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QStringList>
#include <cmath>
#include <iostream>
#include <string>

using namespace cv;

class detector
{
public:
    detector(QString *Qpath, figuresKnowledge *programKnowledge);
    int doStuff();

private:

    figuresKnowledge* programKnowledge;
    static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
    void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);

    std::string path;
};

#endif // DETECTOR_H
