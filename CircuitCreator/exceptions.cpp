#include "exceptions.h"
#include "ui_exceptions.h"

Exceptions::Exceptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exceptions)
{
    ui->setupUi(this);
}

Exceptions::~Exceptions()
{
    delete ui;
}
void Exceptions::showEvent(QShowEvent *)
{
    ui->label->setText( str);
}

void Exceptions::on_pushButton_clicked()
{
    close();
}
