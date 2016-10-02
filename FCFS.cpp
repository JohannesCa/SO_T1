/*
 * FCFS.cpp
 *
 *  Created on: 1 de out de 2016
 *      Author: johannes
 */

#include "FCFS.h"

namespace Scheduler{

mutex Scheduler::FCFS::_mute;
vector<Job*> Scheduler::FCFS::_JobsList;

FCFS::FCFS()
{
	;
}

void FCFS::InsertJob(Job* in)
{
	this->_mute.lock();

	in->Init();
	_JobsList.push_back(in);

	_mute.unlock();
}

void FCFS::ScheduleJobs(void)
{
	for(JobIt it = _JobsList.begin(); it != _JobsList.end(); ++it){
		Job* aux = *it;

		_mute.lock();

		aux->Process();
		_JobsList.erase(it);

		_mute.unlock();

		usleep(aux->getDuration() * 1000); // Milliseconds to Microseconds
		aux->End();
	}
}

} /* namespace Scheduler */
