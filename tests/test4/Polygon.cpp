
// this file is intended to be compiled as shared object and loaded to program using ClassFactory

#ifndef POLYGON_CPP
#define POLYGON_CPP

#include "Polygon.h"

#include <iostream>

CLASS_FACTORY_GENERATE_NEEDED_FUNCTIONS_DEFINITION( Polygon );

CLASS_FACTORY_GENERATE_NEEDED_METHODS_DEFINITION( Polygon );

Polygon::Polygon()
{
	printf( "\n new Polygon;" );
}

Polygon::Polygon( void * args )
{
	printf( "\n new Polygon;" );
}

Polygon::~Polygon()
{
	printf( "\n delete Polygon;" );
}

void Polygon::Print()
{
	std::cout << "\n Polygon!!";
	this->Square::Print();
}

#endif

