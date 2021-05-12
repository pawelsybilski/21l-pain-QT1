#include "modify_dialog.h"
#include "ui_modyfikacja.h"
#include "document.h"
#include "exceptions.h"
#include "mainwindow.h"
Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modyfikacja)
{
    ui->setupUi(this);
    display_parameters();
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_pushButton_4_clicked()
{ui->pushButton_4->text()="test";
    try{
    if(ui->spinBox_8->value()>Document::document_.container.size())
    {QString wyjatek = "Nie ma takiego numeru elementu!";
        throw wyjatek;
    }
    else
    Document::document_.modify_element(ui->spinBox_6->value(),ui->spinBox_7->value(),ui->spinBox_5->value(),ui->spinBox_8->value());
    }
    catch(QString w)
    {
        Exceptions::str=w;
        Exceptions excep;
        excep.setModal(true);
        excep.show();
        excep.exec();
    }
display_parameters();
}

void Modify::on_pushButton_clicked()
{
    close();
}

void Modify::display_parameters()
{
    string parameters_in_string_for_display;
    parameters_in_string_for_display.append(Document::document_.convert_to_string_for_display());
    ui->textBrowser->setText(QString::fromStdString(parameters_in_string_for_display));
}
