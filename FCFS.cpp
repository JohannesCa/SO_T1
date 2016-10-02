/*
 * FCFS.cpp
 *
 *  Created on: 1 de out de 2016
 *      Author: johannes
 */

#include "FCFS.h"

namespace Scheduler{

FCFS::FCFS(){

}

void FCFS::InsertJob(Job* in)
{
	in->Init();
	this->_JobsLits.push_back(in);
}

} /* namespace Scheduler */
