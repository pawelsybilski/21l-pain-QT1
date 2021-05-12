#include <iostream>
#include <fstream>
#include "document.h"
#include "mainwindow.h"
#include <sstream>
#include "mytypes.h"
#include "algorithm"
#include <QMessageBox>
#include "exceptions.h"
#include <QFileDialog>
using namespace std;

void Document::add_element(Element * ptr)
{
container.push_back(ptr);
}

void Document :: save_svg()
{
fstream file;

    file.open("plik.html",ios::out);
    file<<"<!DOCTYPE html><svg width=\"880\" height=\"580\">"<<endl;

for(unsigned int i=0;i<container.size();i++)
    file<<container[i]->generate_svg();

file<<"</svg><!DOCTYPE html>"<<endl;
    file.close();
}

void Document :: delete_element(int id)
{
    Element* ele;
    try {
        ele=find_element(id);
    }
    catch(QString w)
    {

        Exceptions excep;
        excep.str=w;
        excep.setModal(true);
        excep.show();
        excep.exec();
        return;
    }

   vector<Element*>::iterator it = find(container.begin(), container.end(),ele );
   delete ele;
   container.erase(it);
}
Element* Document ::find_element(unsigned int id)
{
    for(int i=0;i<container.size();i++)
    {
        if(container[i]->get_id()==id)
            return container[i];
    }

    QString wyjatek = "Nie ma takiego elementu!";
    throw wyjatek;

}

void Document:: modify_element(int id,int w1 ,int w2,int w3)
{
    try {
      find_element(id)->change_parameters(w1,w2,w3);
    } catch (QString w)
    {
        Exceptions excep;
        excep.str=w;
        excep.setModal(true);
        excep.show();
        excep.exec();

    }

}


void Document:: save_for_reading(string file_name)
{

    ofstream outputFile;
    outputFile.open((file_name).c_str());
    if(!outputFile.is_open())
    {
        QString wyjatek = "Blad zapisu pliku";
        throw wyjatek;
    }

    for(unsigned int i =0;i<container.size();i++)
    container[i]->save_elements(outputFile);

    outputFile.close();
}

void Document::read_from_file(string file_name)
{
    int type=1;

    ifstream file;
    file.open((file_name).c_str());
    if(!file.is_open())
    {
        QString wyjatek = "Blad odczytu z pliku";
        throw wyjatek;
    }
    Element * tempFigure;
    file>>type;

    while(!file.eof())
    {
        tempFigure=create(type);
        if (tempFigure!=NULL)
        {
            MainWindow::elem_counter++;
            tempFigure->read_parameters_from_file(file,MainWindow::elem_counter);
            container.push_back(tempFigure);

        }
        file>>type;
    }

    file.close();
}

Document:: ~Document()
{
    for(unsigned int i=0;i<container.size();i++)
        delete[] container[i];
}

unsigned int Document::registerElement(createElement fun)
{
    elementCreators_.insert(pair<unsigned int,createElement>(++ID_,fun));
    return ID_;
}

Element * Document::create(unsigned int id)
{
    CreatorsMap::iterator it=elementCreators_.find(id);
    if (it!=elementCreators_.end())
    {
        return (it->second)();
    }
    return NULL;
}

unsigned int Element:: id_=0;
unsigned int Document::ID_=1;
Document Document::document_;
Document::Document(){}
