/*
 * Job.h
 *
 *  Created on: 1 de out de 2016
 *      Author: johannes
 */

#ifndef JOB_H_
#define JOB_H_

#include <iostream>

#include <chrono>
#include <ctime>
#include <sys/time.h>

typedef struct timeval Time;

class Job {
private:
	Time _begin;  // Time when the Job entered the Jobs list.
	Time _exec;   // Time when the Job began execution.
	Time _ret;    // Time when the Job returned.

public:
	int _duration;
	int _call;

	Job(int start, int duration);
	void Init(void);
	void Process(void);
	void End(void);

	float getWaitTime(void);
	float getRetTime(void);
};

#endif /* JOB_H_ */
