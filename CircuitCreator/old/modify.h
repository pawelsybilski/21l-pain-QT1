#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>

namespace Ui {
class Modify;
}

class Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();

private slots:
    void on_toolButton_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_btnDown_clicked();

private:
    Ui::Modify *ui;
};

#endif // MODIFY_H
