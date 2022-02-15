#include <iostream>
#include <string>
#include "planner.h"

int main()
{
   int todo = jobsneeded();
   joblist j;
   initialize(j, todo);
   getinfo(j);
   display(j); 
   lookinfo(j);
   return 0;
}

int jobsneeded(){
   int jobs;
   bool params = false;
   while(params == false){
      std::cout<<"Enter the number of jobs to be processed (as an integer):"<<std::endl;
      std::cin>>jobs;
      if(std::cin.fail()){
         std::cin.clear();
         std::cin.ignore(MAX,'\n');
         std::cerr<<"Error: needs to be an integer, please try again"<<'\n';
      } else if(jobs<=0){
         std::cerr<<"Error: needs to be greater than zero, please try again"<<'\n';
      }else{
         params = true;
      }
   }
   return jobs;
}
void getinfo(joblist &j){
   std::string task, holder;
   for(j.numjobs=0;  j.numjobs<j.allocated; j.numjobs++){
      std::cout<<"Enter the name of the job (one word): ";
      std::cin>>task;
      std::cout<<"Enter the name of the person the job is assigned to(one word): ";
      std::cin>>holder;
      insert(j, task, holder);
   }
}

void lookinfo(joblist &j){
    bool endloop = false;
    std::string name;
    std::string taskassign;
    char command;
    while(endloop == false){
        std::cout<<"Enter Q to quit, or L to lookup who a task is assigned to: ";
        std::cin>>command;
        if(command=='L'||command == 'l'){
            std::cout<<"Enter the name of the task: ";
            std::cin>>name;
            taskassign = lookup(j, name);
            std::cout<<"Task "<<name<<" is assigned to "<<taskassign<<'\n';
        }else if(command =='Q'||command == 'q'){
           std::cout<<"Goodbye!"<<'\n';
           deallocate(j);
           endloop = true;
           std::exit(0);
         }else{
            std::cerr<<"Enter an appropriate command"<<'\n';
         }
    } 
}