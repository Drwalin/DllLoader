
#ifndef POLYGON_H
#define POLYGON_H

#include "Square.h"

class Polygon 
	 : public Square
{
protected:
	
public:
	
	virtual void Print() override;
	
	CLASS_FACTORY_GENERATE_NEEDED_METHODS_DECLARATION( Polygon, ClassFactoryBase );
	CLASS_FACTORY_GENERATE_OPTIONAL_EMPTY_CONSTRUCTOS_DESTRUCTOR_DECLARATION( Polygon );
};

#endif

