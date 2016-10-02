/*
 * FCFS.h
 *
 *  Created on: 1 de out de 2016
 *      Author: johannes
 */

#ifndef FCFS_H_
#define FCFS_H_

#include <iostream>
#include <vector>

#include <thread>
#include <mutex>
#include <unistd.h>

#include "Job.h"

using namespace std;

namespace Scheduler{

typedef vector<Job*>::iterator JobIt;

class FCFS{
private:
	static mutex _mute;
	static vector<Job*> _JobsList;
public:
	FCFS();
	void InsertJob(Job* in);
	void ScheduleJobs(void);
};

} /* namespace Scheduler */

#endif /* FCFS_H_ */
