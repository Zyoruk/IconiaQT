#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <iostream>
#include <string>
#include "detector.h"
#include "knowledge/loadknowledge.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initialize knowledge.
    this->programKnowledge = new figuresKnowledge();
    loadKnowledge loadPK = loadKnowledge(this->programKnowledge);
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
