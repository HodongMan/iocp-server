#pragma once


class Event
{
public:
	Event( void );
	~Event( void );

	void			signal( void ) noexcept;
	void			clearSignal( void ) noexcept;
	void			waitForSignal( void ) noexcept;
	void			timedWaitForSignal( const DWORD timeoutPeriod, _Out_ bool& signalled ) noexcept;

private:

	HANDLE			_eventHandle;
};