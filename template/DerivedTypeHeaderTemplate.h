
#if !defined DERIVET_TYPE_HEADER_TEMPLATE_H
#define DERIVET_TYPE_HEADER_TEMPLATE_H

#include <ClassFactoryBase.h>	// needed

class DerivedTypeHeaderTemplate 
	 : public ClassFactoryBase	// needed
{
protected:
	
	int someData;		// not needed
	
public:
	
	int SomeFunction( int a, int b );		// not needed, in use only in derived classes or inside methods of this class
	
	CLASS_FACTORY_GENERATE_NEEDED_METHODS_DECLARATION( DerivedTypeHeaderTemplate, ClassFactoryBase );			// needed
	CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DECLARATION( DerivedTypeHeaderTemplate );		// needed
};

#endif

