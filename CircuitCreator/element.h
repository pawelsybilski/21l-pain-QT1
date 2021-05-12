#pragma once
#include <iostream>
using namespace std;

class Element
{
protected:
    unsigned int id;
    unsigned int angle;
    unsigned int y_coordinates;
    unsigned int x_coordinates;
public:
    virtual void set_parameters(unsigned int,string,unsigned int,unsigned int,unsigned int)=0;
    virtual string generate_svg()=0;
    virtual void change_parameters(int, int, int)=0;
    virtual void save_elements(ofstream &)=0;
    virtual void read_parameters_from_file(ifstream &,int ident)=0;
    virtual unsigned int get_id()=0;
    static unsigned int id_;
};
