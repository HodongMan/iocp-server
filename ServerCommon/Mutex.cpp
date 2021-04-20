#include "pch.h"

#include "Mutex.h"


Mutex::Mutex( const int spinLockCount )
	: _numLocks( 0 )
{
	if ( 0 < spinLockCount )
	{
		const BOOL result = InitializeCriticalSectionAndSpinCount( &_mutex, spinLockCount );
		if ( FALSE == result )
		{
			InitializeCriticalSection( &_mutex );
		}
	}
	else
	{
		InitializeCriticalSection( &_mutex );
	}
}


Mutex::~Mutex( void )
{
	DeleteCriticalSection( &_mutex );
}

void Mutex::lock( void ) noexcept
{
	if ( FALSE == TryEnterCriticalSection( &_mutex ) )
	{
		EnterCriticalSection( &_mutex );
	}

	_numLocks += 1;
}

bool Mutex::tryLock( void ) noexcept
{
	if ( FALSE != TryEnterCriticalSection( &_mutex ) )
	{
		_numLocks += 1;

		return true;
	}

	return false;
}

void Mutex::unlock( void ) noexcept
{
	_numLocks -= 1;

	LeaveCriticalSection( &_mutex );
}

unsigned int Mutex::getLockCount( void ) const noexcept
{
	return _numLocks;
}

SpinLock::SpinLock( void )
	: _lock( 0 )
{

}

SpinLock::~SpinLock( void )
{

}

void SpinLock::lock( void ) noexcept
{
	while ( _InterlockedExchange( &_lock, 1) );
}

bool SpinLock::tryLock( void ) noexcept
{
	if ( !_InterlockedExchange( &_lock, 1 ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SpinLock::unlock( void ) noexcept
{
	_InterlockedExchange( &_lock, 0 );
}



template<typename MUTEX>
class AutoLocker
{
public:
	AutoLocker( MUTEX& mutex );
	~AutoLocker( void );
	
private:
	__forceinline void			unlock( void ) noexcept;

private:
	MUTEX*		_mutex;
};

using MutexLocker	= AutoLocker<Mutex>;
using SpinLocker	= AutoLocker<SpinLock>;