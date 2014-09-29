#include "popup.h"
#include "ui_popup.h"
#include <iostream>


popup::popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
    ui->lineEdit->setText("New string");
}

popup::~popup()
{
    delete ui;
}

void popup::on_buttonBox_accepted()
{
    this->s = ui->lineEdit->text().toLocal8Bit().constData();
}

void popup::setLabel(QString s){
    ui->label->setText(s);
}

string popup::getString(){
    this->s = ui->lineEdit->text().toLocal8Bit().constData();
    cout << s << "___";
    return this->s;
}
