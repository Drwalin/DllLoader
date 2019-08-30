
// this file is intended to be compiled as shared object and loaded to program using ClassFactory

#if !defined DERIVET_TYPE_HEADER_TEMPLATE_CPP
#define DERIVET_TYPE_HEADER_TEMPLATE_CPP

#include "DerivedTypeHeaderTemplate.h"

CLASS_FACTORY_GENERATE_NEEDED_FUNCTIONS_DEFINITION( DerivedTypeHeaderTemplate, ClassFactoryBase );

CLASS_FACTORY_GENERATE_NEEDED_METHODS_DEFINITION( DerivedTypeHeaderTemplate, ClassFactoryBase );
CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DEFINITION( DerivedTypeHeaderTemplate );

int DerivedTypeHeaderTemplate::SomeFunction( int a, int b )		// not needed
{
	return this->someData * a + b;
}

#endif

