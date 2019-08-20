
#ifndef CLASS_FACTORY_H
#define CLASS_FACTORY_H

#include "ModulesFactory.h"
#include "ClassFactoryBase.h"

class ClassFactory : public ModulesFactory
{
protected:
	
	std::map < std::string, std::shared_ptr<ClassFactoryBase> > uniqueObjects;
	
public:
	
	std::shared_ptr<ClassFactoryBase> GetNewOf( const char * moduleName );
	std::shared_ptr<ClassFactoryBase> GetNewOf( const char * moduleName, void * args );
	
	std::shared_ptr<ClassFactoryBase> GetClassInstantiator( const char * moduleName );
	std::shared_ptr<ClassFactoryBase> AddClass( const char * modulePath, const char * moduleName );
	void RemoveClass( const char * moduleName );
	
	ClassFactory();
	~ClassFactory();
};


#endif

