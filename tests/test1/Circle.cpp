
// this file is intended to be compiled as shared object and loaded to program using ClassFactory

#ifndef CIRCLE_CPP
#define CIRCLE_CPP

#include "Circle.h"

#include <iostream>

CLASS_FACTORY_GENERATE_NEEDED_FUNCTIONS_DEFINITION( Circle, ClassFactoryBase );

CLASS_FACTORY_GENERATE_NEEDED_METHODS_DEFINITION( Circle, ClassFactoryBase );
CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DEFINITION( Circle );

void Circle::Print()
{
	std::cout << "\n Circle!!\n";
}

#endif

