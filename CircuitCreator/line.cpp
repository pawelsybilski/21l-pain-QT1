#include "line.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "element.h"

void Line:: set_parameters(unsigned int ident,string w1, unsigned int w2, unsigned int w3,unsigned int w4)
{
    id=ident;
    line_colour=w1;
    x_coordinates=w2;
    y_coordinates=w3;
    angle=w4;
}

unsigned int Line:: get_id()
{
return id;
}

string Line::generate_svg()
{
    ostringstream svg_code;

    svg_code<<"<line x1=\""<<100+x_coordinates<<"\" y1=\""<<50+y_coordinates<<"\" x2=\""<<100+x_coordinates<<"\" y2=\""<<
        y_coordinates<<"\" style=\" stroke:"<<line_colour<<";stroke-width:2\"  transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    svg_code<<"<line x1=\""<<100+x_coordinates<<"\" y1=\""<<50+y_coordinates<<"\" x2=\""<<100+x_coordinates<<"\" y2=\""<<
        100+y_coordinates<<"\" style=\"stroke:"<<line_colour<<";stroke-width:2\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    svg_code<<"  <text font-size=\"15\" x=\""<< 85+x_coordinates<<"\" y=\""<< 42+y_coordinates<<"\">"<<id<<"</text>";

    return svg_code.str();
}

void Line::change_parameters( int w1, int w2, int w3)
{
    if(x_coordinates+w1 >= 0 && x_coordinates+w1 <= 700)
    x_coordinates=x_coordinates+w1;

    if(y_coordinates+w2 >= 50 && y_coordinates+w2 <= 450)
    y_coordinates=y_coordinates+w2;

    angle=angle+w3;
    if(angle>=360)
    angle =angle-360;

}


void Line::save_elements(ofstream &file)
{
    file<<Line::id_<<endl;
    file<<line_colour<<endl;
    file<<angle<<endl;
    file<<x_coordinates<<endl;
    file<<y_coordinates<<endl;
}

void Line::read_parameters_from_file(ifstream & file,int ident)
{
    id=ident;
    file>>line_colour;
    file>>angle;
    file>>x_coordinates;
    file>>y_coordinates;
}
unsigned int Line::id_=0;
