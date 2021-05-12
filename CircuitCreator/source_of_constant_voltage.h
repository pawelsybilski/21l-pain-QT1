#pragma once
#include <iostream>
#include "source_of_voltage.h"
using namespace std;


class Source_of_constant_voltage : public Source_of_voltage
{
    string source_colour;
  public:

    void set_parameters(unsigned int,string,unsigned int,unsigned int,unsigned int);
    string generate_svg();
    void change_parameters(int, int,  int);
    void save_elements(ofstream &);
    void read_parameters_from_file(ifstream &,int ident);
    unsigned int get_id();
    static Element* create_source_of_constant_voltage(){return new Source_of_constant_voltage;}
    static unsigned int id_;

};


