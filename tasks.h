#pragma once
#include <string>

// each task has a name and a person it is assigned to
struct task {
   std::string taskname;
   std::string assignedto;
};

// a collection of tasks
struct joblist {
   task *jobsarr;  // dynamically allocated array of tasks
   int  allocated; // size of the allocated array
   int numjobs;    // how many jobs tasks are currently stored in the array
};

// in the given joblist, intempts to allocate a task array of the given size
// if successful sets allocated to size, numjobs to 0, and returns true
// otherwise sets both to 0 and returns false
bool initialize(joblist &j, int size);

// if the joblist's array isn't null already
//    deletes the array and sets allocated and numjobs to 0
void deallocate(joblist &j); 

// displays all the jobs currently stored in the joblist
void display(joblist j);

// attempt to store a new task in the joblist's array
//    using the passed parameters for the taskname and assignedto name
// returns true if successful, false otherwise
// (i.e. checks if the array has been allocated and isn't full)
bool insert(joblist &j, std::string tname, std::string aname);

// searches for the specified task in the passed joblist,
//    and returns the name of the person it was assigned to
// returns an empty string ("") if no such task can be found
std::string lookup(joblist j, std::string tname);

