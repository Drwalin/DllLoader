
#ifndef SHAPE_CPP
#define SHAPE_CPP

#include "Shape.h"

#include <cstdio>

CLASS_FACTORY_GENERATE_NEEDED_FUNCTIONS_DEFINITION( Shape, ClassFactoryBase );
CLASS_FACTORY_GENERATE_NEEDED_METHODS_DEFINITION( Shape, ClassFactoryBase );
CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DEFINITION( Shape );

void Shape::Print()
{
	printf( "\n Shape, shouldn't apper" );
}

#endif

