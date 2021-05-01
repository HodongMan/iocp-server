#pragma once


class Supervisor;


#include "Thread.h"



class WorkerThread : public Thread
{
private:
	WorkerThread();
	~WorkerThread();

	virtual void	run();

	Supervisor*		_supervisor;
	char			_name[256];
};