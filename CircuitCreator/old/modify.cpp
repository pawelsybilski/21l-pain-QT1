#include "modify.h"
#include "ui_modify.h"
#include "document.h"
#include "mainwindow.h"

Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
    QIcon qicon;
    qicon.addFile("unnamed.jpg");
    ui->toolButton_5->setIcon(qicon);

}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_toolButton_clicked()
{
  Document::document_.modify_element(ui->spinBoxID->value(),0,100);
  MainWindow m=new MainWindow();
         m.display();
}

void Modify::on_btnLeft_clicked()
{
  Document::document_.modify_element(ui->spinBoxID->value(),-100,0);
}

void Modify::on_btnRight_clicked()
{
 Document::document_.modify_element(ui->spinBoxID->value(),100,0);
}

void Modify::on_btnDown_clicked()
{
 Document::document_.modify_element(ui->spinBoxID->value(),0,-100);
}
