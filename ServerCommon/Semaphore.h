#pragma once


class Semaphore
{
public:
	Semaphore( const long initialCount, const long maximumCount );
	~Semaphore( void );


	bool				acquire( void );
	void				release( void );
private:
	HANDLE				_semaphoreHandle;
};