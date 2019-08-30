
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square 
	 : public Shape
{
protected:
	
public:
	
	virtual void Print() override;
	
	CLASS_FACTORY_GENERATE_NEEDED_METHODS_DECLARATION( Square, ClassFactoryBase );
	CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DECLARATION( Square );
};

#endif

