#include "pch.h"


#include "Event.h"


Event::Event( void )
	: _eventHandle( INVALID_HANDLE_VALUE )
{
	_eventHandle = ::CreateEvent( NULL, TRUE, FALSE, NULL );
}

Event::~Event( void )
{
	::CloseHandle( _eventHandle );
}

void Event::signal( void ) noexcept
{
	::SetEvent( _eventHandle );
}

void Event::clearSignal( void ) noexcept
{
	::ResetEvent( _eventHandle );
}

void Event::waitForSignal( void ) noexcept
{
	if ( WAIT_OBJECT_0 != WaitForSingleObject( _eventHandle, INFINITE ) )
	{
		//static_assert(0);
	}
}

void Event::timedWaitForSignal( const DWORD timeoutPeriod, bool& signalled ) noexcept
{
	signalled = false;

	const DWORD result = WaitForSingleObject( _eventHandle, timeoutPeriod );
	if ( WAIT_OBJECT_0 == result )
	{
		signalled = true;
	}
	else if ( WAIT_TIMEOUT == result )
	{
		signalled = false;
	}
	else
	{
		//assert(0);
	}
}
