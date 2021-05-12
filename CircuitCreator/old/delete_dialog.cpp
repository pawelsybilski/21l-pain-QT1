#include "delete_dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "document.h"
#include "exceptions.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    display_parameters();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
close();
}

void Dialog::on_pushButton_3_clicked()
{
    try{
        if(ui->spinBox_4->value()>Document::document_.container.size())
        {QString wyjatek = "Nie ma takiego numeru elementu!";
            throw wyjatek;
        }
        else
       Document::document_.delete_element(ui->spinBox_4->value());

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

void Dialog::display_parameters()
{
    string parameters_in_string_for_display;
    parameters_in_string_for_display.append(Document::document_.convert_to_string_for_display());
    ui->textBrowser->setText(QString::fromStdString(parameters_in_string_for_display));
}
