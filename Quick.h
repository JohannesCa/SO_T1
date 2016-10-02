/*
 * Quick.h
 *
 *  Created on: 25 de ago de 2016
 *      Author: johannes
 */

#ifndef QUICK_H_
#define QUICK_H_

#include <iostream>
#include <vector>

#include "Job.h"

using namespace std;

namespace Sort {

typedef vector<Job*> JobList;
typedef vector<Job*>::iterator JobIt;

class Quick {
private:
	JobList* _LJobsList;
	void Swap(JobIt a, JobIt b);
	void Sort(JobIt Lo, JobIt Hi, bool SortByDuration);
	//void SortDur(JobIt Lo, JobIt Hi);
	JobIt PartCall(JobIt Lo, JobIt Hi);  // Part by Calling time
	JobIt PartDur(JobIt Lo, JobIt Hi);   // Part by Duration time

public:
	Quick(JobList* input, bool SortByDuration); // Sort dy duration time if true
};

} /* namespace Sort */

#endif /* QUICK_H_ */
