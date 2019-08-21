
// this file is intended to be compiled as shared object and loaded to program using ClassFactory

#ifndef CIRCLE_CPP
#define CIRCLE_CPP

#include "Circle.h"

#include <iostream>

CLASS_FACTORY_GENERATE_NEEDED_FUNCTIONS_DEFINITION( Circle );

CLASS_FACTORY_GENERATE_NEEDED_METHODS_DEFINITION( Circle );

Circle::Circle()
{
	printf( "\n new Circle;" );
}

Circle::Circle( void * args )
{
	printf( "\n new Circle;" );
}

Circle::~Circle()
{
	printf( "\n delete Circle;" );
}

void Circle::Print()
{
	std::cout << "\n Circle!!\n";
}

#endif

