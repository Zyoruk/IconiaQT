#ifndef DETECTOR_H
#define DETECTOR_H
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
    detector(QString *Qpath);
    int doStuff();

private:
    static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
    void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);

    std::string path;
};

#endif // DETECTOR_H
