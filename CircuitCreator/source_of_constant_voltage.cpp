#include <iostream>
#include "source_of_constant_voltage.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void Source_of_constant_voltage:: set_parameters(unsigned int ident,string w1, unsigned int w2, unsigned int w3,unsigned int w4)
{
    id=ident;
    source_colour=w1;
    x_coordinates=w2;
    y_coordinates=w3;
    angle=w4;
}
unsigned int Source_of_constant_voltage:: get_id()
{
return id;
}

string Source_of_constant_voltage::generate_svg()
{
    ostringstream svg_code;
    svg_code<<"<circle cx=\""<<100+x_coordinates<<"\" cy=\""<<50+y_coordinates<<"\" r=\"10\" stroke=\""<<source_colour<<"\" stroke-width=\"2\" fill=\"white\" />"<<endl;
    svg_code<<"<line x1=\""<<100+x_coordinates<<"\" y1=\""<<40+y_coordinates<<"\" x2=\""<<100+x_coordinates<<"\" y2=\""<<
              y_coordinates<<"\" style=\"stroke:rgb(0,0,0);stroke-width:2\"  transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    svg_code<<"<line x1=\""<<100+x_coordinates<<"\" y1=\""<<60+y_coordinates<<"\" x2=\""<<100+x_coordinates<<"\" y2=\""<<
              100+y_coordinates<<"\" style=\"stroke:rgb(0,0,0);stroke-width:2\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    svg_code<<"<line x1=\""<<95+x_coordinates<<"\" y1=\""<<50+y_coordinates<<"\" x2=\""<<105+x_coordinates<<"\" y2=\""<<
              50+y_coordinates<<"\" style=\"stroke:"<<source_colour<<";stroke-width:2\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\"  />"<<endl;
    svg_code<<"  <text font-size=\"15\" x=\""<< 82+x_coordinates<<"\" y=\""<< 35+y_coordinates<<"\">"<<id<<"</text>";

    return svg_code.str();
}

void Source_of_constant_voltage::change_parameters(int w1,  int w2, int w3 )
{
    if(x_coordinates+w1 >= 0 && x_coordinates+w1 <= 700)
    x_coordinates=x_coordinates+w1;

    if(y_coordinates+w2 >= 50 && y_coordinates+w2 <= 450)
    y_coordinates=y_coordinates+w2;

    angle=angle+w3;
    if(angle>=360)
    angle =angle-360;

}


void Source_of_constant_voltage ::save_elements(ofstream &file)
{

    file<<Source_of_constant_voltage::id_<<endl;
    file<<source_colour<<endl;
    file<<angle<<endl;
    file<<x_coordinates<<endl;
    file<<y_coordinates<<endl;

}
void Source_of_constant_voltage:: read_parameters_from_file(ifstream & file,int ident)
{
    id=ident;
    file>>source_colour;
    file>>angle;
    file>>x_coordinates;
    file>>y_coordinates;
}





unsigned int Source_of_constant_voltage::id_=0;
