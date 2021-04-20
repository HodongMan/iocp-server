#pragma once


class Thread
{
public:
	Thread( void );


	bool					start( void );
	void					stop( void );
	void					stopAndDelete( void );

	void					suspend( void );
	unsigned int			resume( void );

	bool					stopRequested( void ) const noexcept;
	bool					isRunning( void ) const noexcept;

	uintptr_t				getHandle( void ) const noexcept;
	DWORD					getThreadId( void ) const noexcept;

private:
	void					updateHardwareThread( void ) const noexcept { }
private:
	volatile bool			_stopRequested;
	uintptr_t volatile		_threadHandle;
	UINT					_threadId;


};