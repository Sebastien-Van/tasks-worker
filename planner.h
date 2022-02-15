#pragma once
#include "tasks.h"
//this is for my cin.ignore(1000,'/n')
#define MAX 1000
//this function asks the user how many jobs they would like to enter, then error proofs it.
int jobsneeded();
//this function asks and receives the tasks and persons for each number of jobs in 
//the array then calls to insert() to populate the array.
void getinfo(joblist &j);
//this function prompts the user to input a 'L' for lookup or 'Q' for quit 
//then loops either the lookup() function, an error message or an exit command.
void lookinfo(joblist &j);
