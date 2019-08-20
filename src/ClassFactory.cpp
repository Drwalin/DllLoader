
#ifndef CLASS_FACTORY_CPP
#define CLASS_FACTORY_CPP

#include "ClassFactory.h"

#include <cstdio>

std::shared_ptr<ClassFactoryBase> ClassFactory::GetNewOf( const char * moduleName )
{
	auto it = this->uniqueObjects.find( moduleName );
	if( it == this->uniqueObjects.end() )
		return NULL;
	return it->second->New();
}

std::shared_ptr<ClassFactoryBase> ClassFactory::GetNewOf( const char * moduleName, void * args )
{
	auto it = this->uniqueObjects.find( moduleName );
	if( it == this->uniqueObjects.end() )
		return NULL;
	return it->second->New( args );
}

std::shared_ptr<ClassFactoryBase> ClassFactory::GetClassInstantiator( const char * moduleName )
{
	auto it = this->uniqueObjects.find( moduleName );
	if( it == this->uniqueObjects.end() )
		return NULL;
	return it->second;
}

std::shared_ptr<ClassFactoryBase> ClassFactory::AddClass( const char * modulePath, const char * moduleName )
{
	auto it = this->uniqueObjects.find( moduleName );
	if( it != this->uniqueObjects.end() )
		return it->second;
	std::shared_ptr<Dll> dll = this->AddModule( modulePath, moduleName );
	if( dll == NULL )
	{
		fprintf( stderr, "\n Cannot get module: <%s>", modulePath );
		return NULL;
	}
	
	std::shared_ptr<ClassFactoryBase>(*GetClassInstantiator)();
	GetClassInstantiator = dll->Get<decltype(GetClassInstantiator)>( "GetClassInstantiator" );
	if( GetClassInstantiator == NULL )
	{
		fprintf( stderr, "\n Cannot get symbol: \"GetClassInstantiator\" from: <%s>", modulePath );
		this->RemoveModule( moduleName );
		return NULL;
	}
	
	std::shared_ptr<ClassFactoryBase> instantiator = GetClassInstantiator();
	if( instantiator == NULL )
	{
		fprintf( stderr, "\n Cannot get instantiator from: <%s>", moduleName );
		this->RemoveModule( moduleName );
		return NULL;
	}
	
	this->uniqueObjects.insert( std::pair(std::string(moduleName),instantiator) );
	return instantiator;
}

void ClassFactory::RemoveClass( const char * moduleName )
{
	this->uniqueObjects.erase( moduleName );
	this->RemoveModule( moduleName );
}

ClassFactory::ClassFactory(){}
ClassFactory::~ClassFactory(){}


#endif

