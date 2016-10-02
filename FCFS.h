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
#include "Job.h"

using namespace std;

namespace Scheduler{

class FCFS{
private:
	vector<Job*> _JobsLits;
public:
	FCFS();
	void InsertJob(Job* in);
	void ScheduleJobs(void);
};

} /* namespace Scheduler */

#endif /* FCFS_H_ */
