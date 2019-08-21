
#ifndef CLASS_FACTORY_H
#define CLASS_FACTORY_H

#include "ModulesFactory.h"
#include "ClassFactoryBase.h"

template < typename T = ClassFactoryBase >
class ClassFactory : public ModulesFactory
{
protected:
	
	std::map < std::string, std::shared_ptr<T> > uniqueObjects;
	
public:
	
	std::shared_ptr<T> GetNewOf( const char * moduleName );
	std::shared_ptr<T> GetNewOf( const char * moduleName, void * args );
	
	std::shared_ptr<T> GetClassInstantiator( const char * moduleName );
	std::shared_ptr<T> AddClass( const char * modulePath, const char * moduleName );
	void RemoveClass( const char * moduleName );
	
	ClassFactory();
	~ClassFactory();
};


#endif

