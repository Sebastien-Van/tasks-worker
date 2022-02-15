#include "tasks.h"
#include <iostream>


bool initialize(joblist &j, int size){
    j.jobsarr = new task[size];
    if (j.jobsarr == NULL) {
        j.allocated = 0;
        j.numjobs = 0;
        return false;
    } else { 
        j.numjobs = 0;
        j.allocated = size;
        return true;
    } 
}

void deallocate(joblist &j){
    
    if (j.jobsarr!=NULL){
        j.numjobs = 0;
        j.allocated = 0;
        delete[] j.jobsarr;
    }
}


void display(joblist j){
    std::cout<<"Current jobs list: "<<'\n';
    for(int i = 0; i<j.allocated; i++){
    std::cout<<'\t'<<j.jobsarr[i].taskname<<" allocated to "<<j.jobsarr[i].assignedto<<'\n';
    }
}


bool insert(joblist &j, std::string tname, std::string name){
    if(j.jobsarr!=NULL){
        j.jobsarr[j.numjobs].taskname = tname;
        j.jobsarr[j.numjobs].assignedto = name;
        return true;
    }else{
        return false;
    }
}


std::string lookup(joblist j, std::string tname){
    std::string person;
    for(int i=0;i<j.allocated; i++){
        if(j.jobsarr[i].taskname==tname){
            person = j.jobsarr[i].assignedto;
            break;
        }else{
            person = "";
        }
    }
    return person;
}
