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

	HANDLE					getHandle( void ) const noexcept;
	DWORD					getThreadId( void ) const noexcept;
	void					setThreadId( const DWORD threadId ) noexcept;

	void					changeHardwareThread( const unsigned int hardwareThread ) noexcept;
	static void				suspendAllThread( DWORD exceptionThread ) noexcept;


	virtual void			run( void ) = 0;

protected:

	virtual ~Thread( void );

private:
	void					updateHardwareThread( void ) const noexcept { }
private:
	volatile bool			_stopRequested;
	HANDLE volatile			_threadHandle;
	UINT					_threadId;
};