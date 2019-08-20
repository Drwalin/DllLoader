
#ifndef DLL_IMPORTER_H
#define DLL_IMPORTER_H

#ifdef __cplusplus
extern "C"
{
#endif

void * DllLoad( const char * file );
void DllRelease( void * handle );
void * DllGetObject( void * handle, const char * objectName );

#ifdef __cplusplus
}
#endif



#ifdef __cplusplus

class Dll
{
private:
	
	void * handle;
	
public:
	
	void * Open( const char * dllFileName );
	void Close();
	
	template < typename T >
	T * Get( const char * objectName )
	{
		return reinterpret_cast<T*>( DllGetObject( this->handle, objectName ) );
	}
	
	Dll();
	Dll( const char * dllFileName );
	
	~Dll();
};

#endif

#endif

