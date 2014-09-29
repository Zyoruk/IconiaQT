/**
* Simple shape detector program.
* It loads an image and tries to find simple shapes (rectangle, triangle, circle, etc) in it.
* This program is a EXTRA - modified version of `squares.cpp` found in the OpenCV sample dir.
*/

#include "detector.h"
#include "drawingFigures/figuresknowledge.h"
#include "popup.h"
detector::detector(QString *Qpath, figuresKnowledge *programKnowledge)
{
    this->path = Qpath->toStdString();
    this->programKnowledge = programKnowledge;
}

/**
* Helper function to find a cosine of angle between vectors
* from pt0->pt1 and pt0->pt2
*/
double detector::angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

/**
* Helper function to display text in the center of a contour
*/
void detector::setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour)
{
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.4;
    int thickness = 1;
    int baseline = 0;
    cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
    cv::Rect r = cv::boundingRect(contour);
    cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
    cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255,255,255), CV_FILLED);
    cv::putText(im, label, pt, fontface, scale, CV_RGB(0,0,0), thickness, 8);
}

int detector::doStuff()
{
    cv::Mat src;
    src = cv::imread(path);
    if (!src.data)
    {
        std::cout << "The image" << src << " could not be loaded." << std::endl;
        return -1;
    }

    // Convert to grayscale
    cv::Mat gray;

    /*!
     * \brief cv::cvtColor
     * Filters on color, Gaussian and Canny.
     */
    cv::cvtColor(src, gray, CV_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(7,7), 1.5, 1.5);
    cv::Canny(gray, gray, 0, 50, 5);

    cv::imshow("opencvtest",gray);
    //cv::waitKey(0);

    /* La función findContours() define vectors como salida lo cual hace
    / que no se pueda implementar de forma que no implique rediseño de algoritmos,
    / la lista simple.
    */

    // Find contours
    std::vector< std::vector< cv::Point > > contours;
    cv::findContours(gray.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    std::vector<cv::Point> approx;
    cv::Mat dst = src.clone();

    for (unsigned int i = 0; i < contours.size(); i++)
    {
        // Approximate contour with accuracy proportional
        // to the contour perimeter
        //cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);
        cv::approxPolyDP(contours[i], approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

        // Skip small or non-convex objects
        if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
            continue;
        if(this->programKnowledge->getElements()->ifExists((int)approx.size())){
            int j = this->programKnowledge->getElements()->indexOf((int)approx.size());
            //cout <<(*this->programKnowledge->getFigures()->elementAt(j)->getElement())->getID();
            setLabel(dst,(*this->programKnowledge->getFigures()->elementAt(j)->getElement())->getID(), contours[i]);
        }else{
            cout << "Entra Aca";
            //ENVIARLO A COSAS CONOCIDAS
            popup* newPop = new popup();
            int K = approx.size();
            string tempstr = "A figure was found. It contains:";
            std::stringstream sstm;
            sstm << tempstr << K <<" angles";
            tempstr = sstm.str();
            newPop->setLabel(QString::fromStdString(tempstr));
            newPop->show();
            string s = newPop->getString();
            this->programKnowledge->add(K , s);

        }
    }

    //cv::imshow("input", src);
    cv::imshow("output", dst);
    cv::waitKey(0);
    return 0;
}

