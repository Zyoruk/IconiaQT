#ifndef POPUP_H
#define POPUP_H

#include <QDialog>

using namespace std;
namespace Ui {
class popup;
}

class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = 0);
    ~popup();
    string getString();
    void setLabel(QString s);
private slots:
    void on_buttonBox_accepted();

private:
    string s;
    Ui::popup *ui;
};

#endif // POPUP_H
