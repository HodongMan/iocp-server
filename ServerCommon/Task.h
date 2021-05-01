#pragma once

class Supervisor;
class Job;


typedef void (*TASKFUNC)(void* taskData);

__declspec( align( 64 ) )
class Task
{
public:
	Task( void );

public:
	void					execute( void ) noexcept;

private:

	Supervisor*				_supervisor;
	TASKFUNC				_functionPointer;
	Job*					_job;
	int						_data[12];
};

class TaskRunner
{
public:
	virtual void			runTask( void ) noexcept = 0;
};

void taskRunnerCallback( void* data ) noexcept;