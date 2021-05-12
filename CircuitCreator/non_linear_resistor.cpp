#include <iostream>
#include "non_linear_resistor.h"
#include <fstream>
#include <sstream>
#include <string>
#include "element.h"
using namespace std;

void Non_linear_resistor:: set_parameters(unsigned int ident,string w1, unsigned int w2, unsigned int w3,unsigned int w4)
{
    id=ident;
    resistor_colour=w1;
    x_coordinates=w2;
    y_coordinates=w3;
    angle=w4;
}
unsigned int Non_linear_resistor:: get_id()
{
return id;
}

string Non_linear_resistor::generate_svg()
{
    ostringstream kod_svg;
    kod_svg<<"<rect x=\""<<90+x_coordinates<<"\" y=\""<<30+y_coordinates<<
             "\" width=\"20\" height=\"40\" style=\"fill:rgb(255,255,255);stroke-width:2;stroke:"<<resistor_colour<<"\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    kod_svg<<"<line x1=\""<<100+x_coordinates<<"\" y1=\""<<30+y_coordinates<<"\" x2=\""<<100+x_coordinates<<"\" y2=\""<<
                     y_coordinates<<"\" style=\"stroke:rgb(0,0,0);stroke-width:2\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    kod_svg<<"<line x1=\""<<100+x_coordinates<<"\" y1=\""<<100+y_coordinates<<"\" x2=\""<<100+x_coordinates<<"\" y2=\""<<70+y_coordinates
          <<"\" style=\"stroke:rgb(0,0,0);stroke-width:2\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<< 50+y_coordinates<<")\" />"<<endl;
    kod_svg<<"<line x1=\""<<80+x_coordinates<<"\" y1=\""<<60+y_coordinates<<"\" x2=\""<<120+x_coordinates<<"\" y2=\""<<40+y_coordinates
          <<"\" style=\"stroke:"<<resistor_colour<<";stroke-width:2\" transform=\"rotate("<< angle<<","<< 100+x_coordinates<<","<<
            50+y_coordinates<<")\" />"<<endl;
    kod_svg<<"  <text font-size=\"15\" x=\""<< 75+x_coordinates<<"\" y=\""<< 30+y_coordinates<<"\">"<<id<<"</text>";
           return kod_svg.str();
}

void Non_linear_resistor::change_parameters( int w1, int w2,int w3)
{
    if(x_coordinates+w1 >= 0 && x_coordinates+w1 <= 700)
    x_coordinates=x_coordinates+w1;

    if(y_coordinates+w2 >= 50 && y_coordinates+w2 <= 450)
    y_coordinates=y_coordinates+w2;

    angle=angle+w3;
    if(angle>=360)
    angle =angle-360;
}


void Non_linear_resistor::save_elements(ofstream &file)
{
    file<<Non_linear_resistor::id_<<endl;
    file<<resistor_colour<<endl;
    file<<angle<<endl;
    file<<x_coordinates<<endl;
    file<<y_coordinates<<endl;
}

void Non_linear_resistor::read_parameters_from_file(ifstream & file,int ident)
{
    id=ident;
    file>>resistor_colour;
    file>>angle;
    file>>x_coordinates;
    file>>y_coordinates;

}
unsigned int Non_linear_resistor::id_=0;
