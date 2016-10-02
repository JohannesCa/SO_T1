/*
 * Quick.cpp
 *
 *  Created on: 25 de ago de 2016
 *      Author: johannes
 */

#include "Quick.h"

namespace Sort {

Quick::Quick(JobList* input, bool SortByDuration): _LJobsList(input)
{
/*	if(!SortByDuration){
		cout << "sorting by call\n\n";
		this->SortCall(this->_LJobsList->begin(), this->_LJobsList->end()-1);
	}else{
		cout << "sorting by duration\n\n";
		this->SortDur(this->_LJobsList->begin(), this->_LJobsList->end()-1);
	}
*/
	this->Sort(this->_LJobsList->begin(), this->_LJobsList->end()-1, SortByDuration);
}


void Quick::Sort(JobIt Lo, JobIt Hi, bool SortByDuration)
{
	if(Lo < Hi){
		JobIt part;
		if(SortByDuration){
			cout << "sorting by duration\n";
			part = this->PartDur(Lo, Hi);

		}else{
			cout << "sorting by duration\n";
			part = this->PartCall(Lo, Hi);
		}
		this->Sort(Lo, part-1, SortByDuration);
		this->Sort(part+1, Hi, SortByDuration);
	}
}


/****  Calling Sorting  ****/
/*
void Quick::SortCall(JobIt Lo, JobIt Hi)
{
	if(Lo < Hi){
		JobIt part = this->PartCall(Lo, Hi);
		this->SortCall(Lo, part-1);
		this->SortCall(part+1, Hi);
	}
}
*/

JobIt Quick::PartCall(JobIt Lo, JobIt Hi)
{
	int pivot = (*Hi)->getCall();
	JobIt i = Lo;

	for(JobIt j = Lo; j < Hi; j++){
		if((*j)->getCall() <= pivot){
			printf("swaping: %i, %i <-> %i, %i\n", (*i)->getCall(), (*i)->getDuration(), (*j)->getCall(), (*j)->getDuration());
			this->Swap(i, j);
			printf("ended swaping\n");
			i++;
		}
	}
	printf("swaping: %i, %i <-> %i, %i\n", (*i)->getCall(), (*i)->getDuration(), (*Hi)->getCall(), (*Hi)->getDuration());
	this->Swap(i, Hi);
	printf("ended swaping\n");
	return i;
}



/****  Duration sorting  ****/
/*
void Quick::SortDur(JobIt Lo, JobIt Hi)
{
	if(Lo < Hi){
		JobIt part = this->PartDur(Lo, Hi);
		this->SortDur(Lo, part-1);
		this->SortDur(part+1, Hi);
	}
}
*/

JobIt Quick::PartDur(JobIt Lo, JobIt Hi)
{
	int pivot = (*Hi)->getDuration();
	JobIt i = Lo;

	for(JobIt j = Lo; j < Hi; j++){
		if((*j)->getDuration() < pivot){
			for(JobIt it = this->_LJobsList->begin(); it != this->_LJobsList->end(); ++it)
				printf("%i, %i\n", (*it)->getCall(), (*it)->getDuration());

			printf(" >> swaping: %i, %i <-> %i, %i\n", (*i)->getCall(), (*i)->getDuration(), (*j)->getCall(), (*j)->getDuration());
			this->Swap(i, j);
			printf("ended swaping\n");
			for(JobIt it = this->_LJobsList->begin(); it != this->_LJobsList->end(); ++it)
				printf("%i, %i\n", (*it)->getCall(), (*it)->getDuration());
		}
	}


	for(JobIt it = this->_LJobsList->begin(); it != this->_LJobsList->end(); ++it)
		printf("%i, %i\n", (*it)->getCall(), (*it)->getDuration());
	printf(" > swaping: %i, %i <-> %i, %i\n", (*i)->getCall(), (*i)->getDuration(), (*Hi)->getCall(), (*Hi)->getDuration());
	this->Swap(i, Hi);
	printf("ended swaping\n");

	for(JobIt it = this->_LJobsList->begin(); it != this->_LJobsList->end(); ++it)
		printf("%i, %i\n", (*it)->getCall(), (*it)->getDuration());

	return i;
}



/****  Swap   ****/

void Quick::Swap(JobIt a, JobIt b)
{
	Job* aux = (*a);
	(*a) = (*b);
	(*b) = aux;
}


} /* namespace Sort */
