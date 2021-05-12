#pragma once
#include <iostream>
#include "resistor.h"
using namespace std;


class Non_linear_resistor : public Resistor
{
    string resistor_colour;
public:
    void set_parameters(unsigned int,string,unsigned int,unsigned int,unsigned int);
    string generate_svg();
    void change_parameters(int, int, int);
    void save_elements(ofstream &);
    void read_parameters_from_file(ifstream &,int ident);
    unsigned int get_id();
    static unsigned int id_;
static Element *  create_non_linear_resistor(){return new Non_linear_resistor();}
};



