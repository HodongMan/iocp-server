#include "pch.h"


#include "Semaphore.h"


Semaphore::Semaphore( const long initialCount, const long maximumCount )
	: _semaphoreHandle( INVALID_HANDLE_VALUE )
{
	_semaphoreHandle = ::CreateSemaphore( NULL, initialCount, maximumCount, NULL );
}

Semaphore::~Semaphore( void )
{
	::CloseHandle( _semaphoreHandle );
}

bool Semaphore::acquire( void )
{
	if ( WAIT_FAILED != ::WaitForSingleObject( _semaphoreHandle, INFINITE ) )
	{
		return true;
	}

	return false;
}

void Semaphore::release( void )
{
	::ReleaseSemaphore( _semaphoreHandle, 1, NULL );
}
