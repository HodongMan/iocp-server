#include "pch.h"

#include "WorkerThread.h"
#include "Task.h"



WorkerThread::WorkerThread()
	: _supervisor( nullptr )
{
	ZeroMemory( _name, sizeof( _name ) );
}

WorkerThread::~WorkerThread()
{

}

void WorkerThread::run()
{
	::SetThreadPriorityBoost( GetCurrentThread(), TRUE );


	while( false == stopRequested() )
	{
		Task* task					= nullptr;
		ULONG_PTR taskPtr			= 0;
		LPOVERLAPPED overlapped;
		DWORD shouldProcess			= 0;

		if ( ::GetQueuedCompletionStatus( &shouldProcess, &taskPtr, &overlapped, INFINITE ) )
		{
			if ( true == shouldProcess )
			{
				task = reinterpret_cast<Task*>( taskPtr );
				
				task->execute();

				delete task;
			}
			else
			{
				stop();
			}
		}
		else
		{
			stop();
		}
	}
}
