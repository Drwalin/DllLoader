
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle 
	 : public Shape
{
protected:
	
public:
	
	virtual void Print() override;
	
	CLASS_FACTORY_GENERATE_NEEDED_METHODS_DECLARATION( Circle );
	CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DECLARATION( Circle );
};

#endif

