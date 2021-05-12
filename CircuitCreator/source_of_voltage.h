#pragma once
#include <iostream>
#include "element.h"
using namespace std;

class Source_of_voltage: public Element
{
public :
    void set_parameters(unsigned int,string,unsigned int,unsigned int,unsigned int)=0;
    string generate_svg()=0;
    void change_parameters(int, int, int)=0;
    void save_elements(ofstream &)=0;
    void read_parameters_from_file(ifstream &,int ident)=0;
    unsigned int get_id()=0;

};

