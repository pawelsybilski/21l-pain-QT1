#pragma once
#include "element.h"
#include "document.h"
#include <vector>
#include <map>
using std::vector;
using std::map;

typedef Element * (*createElement)();
//using createFigure=Element * (*)();
typedef map<unsigned int, createElement> CreatorsMap;
//using CreatorsMap=map<unsigned int, createElement>;

