#include "pch.h"

#include "Task.h"



Task::Task( void )
	: _supervisor( nullptr )
	, _job( nullptr )
{
	ZeroMemory( _data, sizeof( _data ) );
}

void Task::execute( void ) noexcept
{

}

void taskRunnerCallback( void* data ) noexcept
{
	TaskRunner* taskRunner = static_cast<TaskRunner*>( data );
	if ( nullptr != taskRunner )
	{
		taskRunner->runTask();
	}
}
