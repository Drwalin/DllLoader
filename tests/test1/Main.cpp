
#include "Shape.h"
#include "../../include/ClassFactory.h"

#include <cstdio>

#include "../../src/ModulesFactory.cpp"
#include "../../src/ClassFactory.cpp"
#include "../../src/DllImporter.cpp"

int main()
{
	ClassFactory<Shape> cf;
	
	cf.AddClass( "Square.dll", "Square" );
	cf.AddClass( "Circle.dll", "Circle" );
	
	cf.GetClassInstantiator("Circle")->New();
	
	std::dynamic_pointer_cast<Shape>( cf.GetClassInstantiator("Circle") )->Print();
	std::dynamic_pointer_cast<Shape>( cf.GetClassInstantiator("Square") )->Print();
	
	return 0;
}

