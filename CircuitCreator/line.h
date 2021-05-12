#pragma once
#include <iostream>
#include "element.h"
#include "source_of_constant_voltage.h"
using namespace std;

class Line: public Element
{
    string line_colour;
public:
    void set_parameters(unsigned int,string,unsigned int,unsigned int,unsigned int);
    string generate_svg();
    void change_parameters(int, int, int);
    void save_elements(ofstream &);
    void read_parameters_from_file(ifstream &,int);
    unsigned int get_id();
    static unsigned int id_;
        static Element* create_line(){return new Line;}

};

