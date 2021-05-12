#pragma once
#include <iostream>
#include <vector>
#include "source_of_constant_voltage.h"
#include "non_linear_resistor.h"
#include <QString>
#include "mytypes.h"

using namespace std;


class Document
{
    Element * create(unsigned int id);
    static unsigned int ID_;
    CreatorsMap elementCreators_;
public:
    vector <Element*> container;
    static Document document_;

    void add_element(Element *);
    void save_svg();
    void delete_element(int);
    void modify_element(int,int,int,int);
    string convert_to_string_for_display();
    void save_for_reading(string);
    void read_from_file(string );
    Element* find_element(unsigned int);
    Document();
    ~Document();

    unsigned int registerElement(createElement fun);
};
