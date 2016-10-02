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


vector<Job*> preJobList;


int main(int argc, char** argv)
{

	for(int i = 0; i < argc; i++)
		cout << *argv[i] << endl;

	Job aa(0, 12);
	aa.Init();

	usleep(12000);;;;;;

	aa.Process();

	usleep(24000);

	aa.End();

	printf("Wait time: %5.1f ms\n", aa.getWaitTime());
	printf("Return time: %5.1f ms\n", aa.getRetTime());

	return 0;
}


bool ReadFile(string fName)
{
	bool ret;

	string line;
	ifstream input;
	input.open(fName, ios::in);

	while(getline(input, line)){
		;
	}

	return ret;
}
