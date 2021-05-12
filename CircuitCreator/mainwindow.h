#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display();
    static int elem_counter;


private slots:
    void on_actionsave_elements_triggered();

    void on_actionread_elements_triggered();

    void on_btnUp_clicked();

    void on_btnRight_clicked();

    void on_btnDown_clicked();

    void on_btnLeft_clicked();

    void on_btnAddSource_clicked();

    void on_btnAddResistor_clicked();

    void on_btnAddLine_clicked();

    void on_btnRotate_clicked();

    void on_btnDelete_clicked();

private:
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
