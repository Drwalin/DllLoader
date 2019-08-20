
#ifndef DLL_IMPORTER_CPP
#define DLL_IMPORTER_CPP


#if defined __WIN32__ || defined _WIN64

#include <windows.h>

void * DLLLoad( const char * file )
{
	if( file )
	{
		return LoadLibrary( file );
	}
	return nullptr;
}

void DLLRelease( void * handle )
{
	if( handle )
	{
		FreeLibrary( (HINSTANCE)handle );
	}
}

void * DLLGetObject( void * handle, const char * objectName )
{
	if( handle && objectName )
	{
		return (void*)GetProcAddress( (HINSTANCE)handle, objectName );
	}
	return nullptr;
}

#elif defined __unix__

#include <dlfcn.h>

void * DLLLoad( const char * file )
{
	if( file )
	{
		return dlopen( file, RTLD_LAZY );
	}
	return nullptr;
}

void DLLRelease( void * handle )
{
	if( handle )
	{
		dlclose( handle );
	}
}

void * DLLGetObject( void * handle, const char * objectName )
{
	if( handle && objectName )
	{
		return dlsym( handle, objectName );
	}
	return nullptr;
}

#  warning Not yet tested

#else

#  error Unknown system, or not defined symbol ( __unix__ or __WIN32__ or _WIN64 )

#endif		// system type



#if defined __cplusplus

void * Dll::Open( const char * dllFileName )
{
	this->Close();
	this->handle = DLLLoad( dllFileName );
	return this->handle;
}

void Dll::Close()
{
	if( this->handle )
		DLLRelease( this->handle );
}

Dll::Dll()
{
	this->handle = NULL;
}

Dll::Dll( const char * dllFileName )
{
	this->Open( dllFileName );
}

~Dll::Dll()
{
	this->Close();
}

#endif

#endif		// DLL_IMPORTER_CPP

