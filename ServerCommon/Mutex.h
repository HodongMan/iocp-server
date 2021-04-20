#pragma once


class Mutex
{
public:
	Mutex( const int spinLockCount = 1500 );
	virtual ~Mutex( void );

	void				lock( void ) noexcept;
	bool				tryLock( void ) noexcept;
	void				unlock( void ) noexcept;

	unsigned int		getLockCount( void ) const noexcept;

private:
	CRITICAL_SECTION	_mutex;
	unsigned int		_numLocks;
};


class SpinLock
{
public:
	SpinLock( void );
	~SpinLock( void );

	void				lock( void ) noexcept;
	bool				tryLock( void ) noexcept;
	void				unlock( void ) noexcept;

private:
	volatile long		_lock
};