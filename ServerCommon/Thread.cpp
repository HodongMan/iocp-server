#include "pch.h"


#include "Thread.h"


struct ThreadWrapper
{
	static unsigned int WINAPI thunk( LPVOID lpParameter ) noexcept
	{
		Thread* thread = nullptr;

		thread = static_cast<Thread*>( lpParameter );

		thread->setThreadId( ::GetCurrentThreadId() );

		thread->run();


		// terminate thread

		::_endthreadex( 0 );

		return 0;
	}
};

Thread::Thread( void )
	: _threadHandle( INVALID_HANDLE_VALUE )
	, _threadId( 0 )
	, _stopRequested( true )
{

}

bool Thread::start( void )
{
	_stopRequested = false;

	_threadHandle = reinterpret_cast<HANDLE>( ::_beginthreadex( nullptr, 0, ThreadWrapper::thunk, reinterpret_cast<LPVOID>( this ), 0, nullptr ) );

	if ( INVALID_HANDLE_VALUE == _threadHandle )
	{
		return false;
	}

	return true;
}

void Thread::stop( void )
{
	_stopRequested = true;
}

void Thread::stopAndDelete( void )
{
	stop();

	int retryCount = 0;

	delete this;
}

void Thread::suspend( void )
{
	while ( 0xffffffff == ::SuspendThread( _threadHandle ) );
}

unsigned int Thread::resume( void )
{
	return ::ResumeThread( _threadHandle );
}

bool Thread::stopRequested( void ) const noexcept
{
	updateHardwareThread();

	return _stopRequested;
}

bool Thread::isRunning( void ) const noexcept
{
	return _threadHandle != INVALID_HANDLE_VALUE;
}

HANDLE Thread::getHandle( void ) const noexcept
{
	return _threadHandle;
}

DWORD Thread::getThreadId( void ) const noexcept
{
	return _threadId;
}

void Thread::setThreadId( const DWORD threadId ) noexcept
{
	_threadId = threadId;
}

void Thread::changeHardwareThread( const unsigned int hardwareThread ) noexcept
{

}

void Thread::suspendAllThread(DWORD exceptionThread) noexcept
{
}

Thread::~Thread(void)
{
}
