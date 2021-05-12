#ifndef MODYFIKACJA_H
#define MODYFIKACJA_H

#include <QDialog>

namespace Ui {
class Modyfikacja;
}

class Modify : public QDialog
{
    Q_OBJECT


public:
    explicit Modify(QWidget *parent = 0);
    ~Modify();

    void display_parameters();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();


private:
    Ui::Modyfikacja *ui;
};

#endif // MODYFIKACJA_H
