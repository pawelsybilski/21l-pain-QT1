#include "mainwindow.h"
#include <QtSvg>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include "ui_mainwindow.h"
#include "source_of_constant_voltage.h"
#include "non_linear_resistor.h"
#include "line.h"
#include "document.h"
#include "element.h"
#include "QFile"
#include <sstream>
#include "mytypes.h"
#include "QFileDialog"
#include "iostream"
#include "exceptions.h"
#include <QMessageBox>
#include "line.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Non_linear_resistor::id_=Document::document_.registerElement(Non_linear_resistor::create_non_linear_resistor);
    Source_of_constant_voltage::id_=Document::document_.registerElement(Source_of_constant_voltage::create_source_of_constant_voltage);
    Line::id_=Document::document_.registerElement(Line::create_line);

    ui->frameModify->hide();

}
int MainWindow :: elem_counter=0;

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionsave_elements_triggered()
{

    QString file_name = QFileDialog :: QFileDialog::getSaveFileName(nullptr, "Save to file", ".", "text files (*.txt)" );

    if(file_name.isEmpty())
       return;
    else
       Document::document_.save_for_reading(file_name.toStdString());

}

void MainWindow::on_actionread_elements_triggered()
{
    QString file_name = QFileDialog :: QFileDialog::getOpenFileName(nullptr, "Save to file", ".", "text files (*.txt)" );

    if(file_name.isEmpty())
        return;
    else
        Document::document_.read_from_file(file_name.toStdString());

    ui->spinBoxID->setValue(elem_counter);
    MainWindow::display();
}

void MainWindow::display()
{
    Document::document_.save_svg();
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(new QGraphicsSvgItem("plik.html"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}




void MainWindow::on_btnUp_clicked()
{
    Document::document_.modify_element(ui->spinBoxID->value(),0,-50,0);
    MainWindow::display();
}

void MainWindow::on_btnDown_clicked()
{
    Document::document_.modify_element(ui->spinBoxID->value(),0,50,0);
    MainWindow::display();
}

void MainWindow::on_btnRight_clicked()
{
    Document::document_.modify_element(ui->spinBoxID->value(),50,0,0);
    MainWindow::display();
}

void MainWindow::on_btnLeft_clicked()
{
    Document::document_.modify_element(ui->spinBoxID->value(),-50,0,0);
    MainWindow::display();
}

void MainWindow::on_btnAddSource_clicked()
{
    elem_counter++;
    Element * wsk = new Source_of_constant_voltage;
    wsk->set_parameters(elem_counter,ui->comboBoxColor->currentText().toUtf8().constData(),ui->spinBoxCorX->value(),ui->spinBoxCorY->value(),ui->spinBoxAng->value());
    Document::document_.add_element(wsk);

    ui->spinBoxID->setValue(elem_counter);
    MainWindow::display();
}

void MainWindow::on_btnAddResistor_clicked()
{
    elem_counter++;
    Element * wsk = new Non_linear_resistor;
    wsk->set_parameters(elem_counter,ui->comboBoxColor->currentText().toUtf8().constData(),ui->spinBoxCorX->value(),ui->spinBoxCorY->value(),ui->spinBoxAng->value());
    Document::document_.add_element(wsk);

    ui->spinBoxID->setValue(elem_counter);
    MainWindow::display();

}

void MainWindow::on_btnAddLine_clicked()
{
    elem_counter++;
    Element * wsk = new Line;
    wsk->set_parameters(elem_counter,ui->comboBoxColor->currentText().toUtf8().constData(),ui->spinBoxCorX->value(),ui->spinBoxCorY->value(),ui->spinBoxAng->value());
    Document::document_.add_element(wsk);

    ui->spinBoxID->setValue(elem_counter);
    MainWindow::display();
}


void MainWindow::on_btnRotate_clicked()
{
    Document::document_.modify_element(ui->spinBoxID->value(),0,0,90);
    MainWindow::display();
}

void MainWindow::on_btnDelete_clicked()
{
    Document::document_.delete_element(ui->spinBoxID->value());
    MainWindow::display();
}




