#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
}

popup::~popup()
{
    delete ui;
}

void popup::on_buttonBox_accepted()
{
    s = ui->lineEdit->text().toLocal8Bit().constData();
}

void popup::setLabel(QString s){
    ui->lineEdit->setText(s);
}

string popup::getString(){
    return this->s;
}
