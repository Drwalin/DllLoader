
#include "Shape.h"
#include "../../src/ClassFactory.h"

#include <cstdio>

#include "../../src/ModulesFactory.cpp"
#include "../../src/ClassFactory.cpp"
#include "../../src/DllImporter.cpp"

int main()
{
	ClassFactory cf;
	
	cf.AddClass( "Square.dll", "Square" );
	cf.AddClass( "Circle.dll", "Circle" );
	cf.AddClass( "Polygon.dll", "Polygon" );
	
	auto p = cf.GetClassInstantiator("Square")->New()->New()->New()->New();
	p->New()->New();
	p = cf.GetClassInstantiator("Polygon")->New()->New()->New()->New();
	
	std::dynamic_pointer_cast<Shape>( cf.GetClassInstantiator("Circle") )->Print();
	std::dynamic_pointer_cast<Shape>( cf.GetClassInstantiator("Square") )->Print();
	std::dynamic_pointer_cast<Shape>( cf.GetClassInstantiator("Polygon") )->Print();
	
	return 0;
}

