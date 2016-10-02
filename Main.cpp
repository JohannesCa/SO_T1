/*
 * Main.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: johannes
 */

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

#include "Job.h"

using namespace std;


bool PrepareJobs(string fName);

vector<Job*> LoadedJobsList;


int main(int argc, char** argv)
{

	for(int i = 0; i < argc; i++)
		cout << *argv[i] << endl;


/*
	Job aa(0, 12);
	aa.Init();

	usleep(12000);

	aa.Process();

	usleep(24000);

	aa.End();

	printf("Wait time: %3.1f ms\n", aa.getWaitTime());
	printf("Return time: %3.1f ms\n", aa.getRetTime());
*/


	printf("o arquivo %s\n", PrepareJobs("inputs")? "existe." : "não existe!");

	for(vector<Job*>::iterator it = LoadedJobsList.begin(); it != LoadedJobsList.end(); ++it)
		delete *it;

	LoadedJobsList.clear();

	return 0;
}


bool PrepareJobs(string fName) // Return if the file either exists or not
{
	bool ret = true;

	string line;
	ifstream input;
	input.open(fName, ios::in);

	if(!input)
		ret = false;
	else{
		while(getline(input, line)){
			int i;
			int beg, dur; // Begin, Duration
			string Buff;

			for(i = 0; line[i] != ' '; ++i)
				Buff += line[i];

			beg = stoi(Buff);
			Buff.clear();

			for(++i; line[i] != '\0'; ++i)
				Buff += line[i];

			dur = stoi(Buff);
			printf("Beg: %i, Dur: %i\n", beg, dur);
			LoadedJobsList.push_back(new Job(beg, dur));
		}
	}

	return ret;
}
