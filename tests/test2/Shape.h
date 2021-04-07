
#ifndef SHAPE_H
#define SHAPE_H

#include "../../template/ClassFactoryBase.h"

class Shape 
	 : public ClassFactoryBase
{
protected:
	
public:
	
	virtual void Print() = 0;
	
//	CLASS_FACTORY_GENERATE_NEEDED_METHODS_DECLARATION( Shape );
//	CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DECLARATION( Shape );
};

#endif

