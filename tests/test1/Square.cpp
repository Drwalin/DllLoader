
// this file is intended to be compiled as shared object and loaded to program using ClassFactory

#ifndef SQUARE_CPP
#define SQUARE_CPP

#include "Square.h"

#include <iostream>

CLASS_FACTORY_GENERATE_NEEDED_FUNCTIONS_DEFINITION( Square );

CLASS_FACTORY_GENERATE_NEEDED_METHODS_DEFINITION( Square );
CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DEFINITION( Square );

void Square::Print()
{
	std::cout << "\n Square!!\n";
}

#endif

