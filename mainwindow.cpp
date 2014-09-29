#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <iostream>
#include <string>
#include "detector.h"
#include "Graph/graph.h"
#include "drawingFigures/drawingfigures.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->programKnowledge = new figuresKnowledge();
    this->programKnowledge->add(4,"RECT");
    this->programKnowledge->add(3,"TRI");
    this->programKnowledge->add(5,"PENTA");
    this->programKnowledge->add(2,"LINE");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->pathline->setText(filename);
    QPixmap img(filename);
    ui->preview->setPixmap(img);
    detector* detect = new detector(&filename,this->programKnowledge);
    detect->doStuff();

}
