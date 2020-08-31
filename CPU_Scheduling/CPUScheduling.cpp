//OS Assignment CPU process scheduling
//Submitted by: Rutik Pol
//PRN: 0120180381
//Roll number: 090 TY #include<iostream> #include<string.h>
using namespace std; class processnode
{
public:
//user input char p_name[50]; double a_time=0;
double b_time=NULL;
//Evaluation
double s_time=NULL; double w_time=0; double ta_time=NULL;

};

class process_scheduling
{
public:
void input_processes();
void FCFS(int n, processnode process_arr[]); void SJF(int n, processnode process_arr[]);
void Roundrobin(int n, processnode process_arr[]);


};


void sorting(int n, processnode *process_arr)
{
processnode temp; for(int i=0; i<n; ++i)
{
for(int j=0; j<n-1; ++j)
{
if(process_arr[j].a_time>process_arr[j+1].a_time)
{
temp=process_arr[j]; process_arr[j]=process_arr[j+1]; process_arr[j+1]=temp;
}
}
}
 
}

//This function returns index of the shortest burst time of the arrived and not completed processes.
int shortes_b_time(int n, int arrived[], int completed[], processnode process_arr[])
{
double min=9999; //initialising minimum as largest number! say 9999
int index=-1; for(int i=0;i<n;++i)
{
if(arrived[i]==1)//process arrived
{
if(completed[i]!=1)//Processes incompleted
{
if(process_arr[i].b_time<min)
{
min=process_arr[i].b_time; index=i;
}
}
}
}
return index;
}

void process_scheduling::Roundrobin(int n, processnode process_arr[])
{
//round robin algorithm.
double time_quantum,time,ta_time_avg=0, w_time_avg=0; cout<<"\n\t\tEnter the time slice/quantum for RR algorithm: "; cin>>time_quantum;
int remain=n,i,temps=0; sorting(n,process_arr); double b_time_arr[n]; for(int i=0;i<n;++i)
{
b_time_arr[i]=process_arr[i].b_time;
}
cout<<"*******************Round Robin Algorithm*******************"; cout<<"\n\n\tProcess: \t:Turnaround Time: Waiting Time\n\n"; for(time=0,i=0;remain!=0;)
{
if(b_time_arr[i]<=time_quantum && b_time_arr[i]>0)
 
{
time += b_time_arr[i];
//Addition using shorthand operators
b_time_arr[i]=0; temps=1;
}

else if(b_time_arr[i]>0)
{
b_time_arr[i] -= time_quantum;
//Subtraction using shorthand operators
time += time_quantum;
//Addition using shorthand operators
}

if(b_time_arr[i]==0 && temps==1)
{
remain--;
//Desplaying the result of wating, turn around time: process_arr[i].ta_time=time-process_arr[i].a_time; process_arr[i].w_time=time-process_arr[i].a_time-process_arr[i].b_time; cout<<"\tProcess: "<<process_arr[i].p_name<<"\t:\t"<<process_arr[i].ta_time; cout<<"\t:\t"<<process_arr[i].w_time;
//printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,process_arr[i].ta_time,process_arr[i].w_time);
cout<<endl;

w_time_avg += time-process_arr[i].a_time-process_arr[i].b_time; ta_time_avg += time-process_arr[i].a_time;
temps=0;
}

if(i == n-1) i=0;
else if(process_arr[i+1].a_time <= time) i++;
 
else

}
 

i=0;
 
cout<<"\n\t\t\tAverage Waiting time is: "<<w_time_avg/n;
cout<<"\n\t\t\tAverage Turn Around time is: "<<ta_time_avg/n;

}

void process_scheduling::SJF(int n, processnode process_arr[])
{
sorting(n,process_arr);//sorting
double time=process_arr[0].a_time+process_arr[0].b_time;
//time scale after execution of first arrived process process_arr[0].s_time=process_arr[0].a_time; process_arr[0].w_time=0; process_arr[0].ta_time=process_arr[0].w_time+process_arr[0].b_time; double ta_time_avg=process_arr[0].ta_time, w_time_avg=0;
int arrived[n],completed[n],sequence[n]; sequence[0]=0;
arrived[0]=1; completed[0]=1; for(int i=1;i<n;++i)
{
arrived[i]=0; completed[i]=0;
}
int index,k=1; while(1)
{
for(int i=0;i<n;++i)
{
if(completed[i]!=1)
{
if(process_arr[i].a_time<=time)
{
arrived[i]=1;
}
}
}
index=shortes_b_time(n,arrived,completed,process_arr); if(index==-1)
{
//cout<<"\n\t\tNo process has arrived or all processes has been completed";
break;
}
process_arr[index].s_time=time; process_arr[index].w_time=process_arr[index].s_time-process_arr[index].a_time; process_arr[index].ta_time=process_arr[index].w_time+process_arr[index].b_time; time=time+process_arr[index].b_time;
completed[index]=1; w_time_avg=w_time_avg+process_arr[index].w_time; ta_time_avg=ta_time_avg+process_arr[index].ta_time; sequence[k]=index;
++k;

}
cout<<"*******************Shortest Job First Algorithm*******************";
cout<<"\n\n\tProcess: \t:Turnaround Time: Waiting Time\n\n"; for(int i=0;i<n;++i)
 
{
cout<<"\tProcess: "<<process_arr[sequence[i]].p_name; cout<<"\t:\t"<<process_arr[sequence[i]].ta_time; cout<<"\t:\t"<<process_arr[sequence[i]].w_time; cout<<endl;
}

cout<<"\n\t\tGantt Representation of SJF algorithm is as follows: ";
cout<<"\n\t\tOrder of processes is as follows: "; for(int i=0;i<n;++i)
{
if(i==n-1)
{

break;
}
cout<<process_arr[sequence[i]].p_name<<"-->";
}
cout<<"\n\t\t"<<process_arr[0].s_time; for(int i=0;i<n;++i)
{
for(int j=0;j<int(process_arr[sequence[i]].b_time);++j)
{
cout<<" _";
}
if(i==n-1)
{
cout<<process_arr[sequence[i]].s_time+process_arr[sequence[i]].b_time;
}
else
cout<<process_arr[sequence[i+1]].s_time;
}
cout<<"\n\t\t\tAverage Waiting time is: "<<w_time_avg/n;
cout<<"\n\t\t\tAverage Turn Around time is: "<<ta_time_avg/n;
}

void process_scheduling::FCFS(int n, processnode process_arr[])
{

sorting(n,process_arr); process_arr[0].s_time=process_arr[0].a_time; process_arr[0].w_time=0; process_arr[0].ta_time=process_arr[0].b_time;
double ta_time_avg=process_arr[0].ta_time, w_time_avg=0; for(int i=1;i<n;++i)
{
process_arr[i].s_time=process_arr[i-1].s_time+process_arr[i-1].b_time; process_arr[i].w_time=process_arr[i].s_time-process_arr[i].a_time; if(process_arr[i].w_time<0)
{

process_arr[i].w_time=0; //waiting time becomes 0
}
process_arr[i].ta_time=process_arr[i].w_time+process_arr[i].b_time; w_time_avg=w_time_avg+process_arr[i].w_time; ta_time_avg=ta_time_avg+process_arr[i].ta_time;
}
cout<<"*******************First Come First Served Algorithm*******************";
cout<<"\n\n\tProcess: \t:Turnaround Time: Waiting Time\n\n"; for(int i=0;i<n;++i)
{
 
cout<<"\tProcess: "<<process_arr[i].p_name<<"\t:\t"<<process_arr[i].ta_time;
cout<<"\t:\t"<<process_arr[i].w_time; cout<<endl;
}
cout<<"\n\t\tGantt Representation of FCFS algorithm is as follows: ";
cout<<"\n\t\tOrder of processes is as follows: "; for(int i=0;i<n;++i)
{
if(i==n-1)
{
cout<<process_arr[i].p_name; break;
}
cout<<process_arr[i].p_name<<"-->";
}
cout<<"\n\t\t"<<process_arr[0].s_time; for(int i=0;i<n;++i)
{
for(int j=0;j<int(process_arr[i].b_time);++j)
{
cout<<" _";
}
if(i==n-1)
{
cout<<process_arr[i].s_time+process_arr[i].b_time;
}
else
cout<<process_arr[i+1].s_time;
}
cout<<"\n\t\t\tAverage Waiting time is: "<<w_time_avg/n;
cout<<"\n\t\t\tAverage Turn Around time is: "<<ta_time_avg/n;



}

void process_scheduling::input_processes()
{
int n,choice;
cout<<"\n\t\t\tOS CPU Process Scheduling Assignment"; cout<<"\n\t\t\t\tBy Sanskar Sharma"; cout<<"\n\t\t\t\t PRN 0120180381";
cout<<"\n\tEnter the number of processes: ";
cin>>n;
processnode process_arr[n]; for(int i=0;i<n;++i)
{
cout<<"\n\t\tEnter the process "<<i+1<<" name: ";
cin>>process_arr[i].p_name;
cout<<"\n\t\tEnter the arrival time of process "<<i+1<<" : ";
cin>>process_arr[i].a_time; if(process_arr[i].a_time<0)
{
process_arr[i].a_time=0;
}
cout<<"\n\t\tEnter the burst time of process "<<i+1<<" : "; cin>>process_arr[i].b_time; while(process_arr[i].b_time<=0)
{
cout<<"\n\t\t\tEnter a positive busrt time!! Enter again: ";
 
cin>>process_arr[i].b_time;
}

}
while(1)
{
cout<<"\n\tChoose an Algorithm to schedule the processes: ";
cout<<"\n\t\tNon-Preemptive Algorithms: \n\t\t "; cout<<"1. First Come First Served (FCFS)."; cout<<"\n\t\t 2. Shortest Job First (SJF)."; cout<<"\n\t\tPreemptive Algorithms: \n\t\t "; cout<<"3. Round Robin Algorithm.";
cout<<"\n\t4. Exit"; cout<<"\n\tEnter your choice: "; cin>>choice;
switch(choice)
{
case 1:
FCFS(n,process_arr); break;
case 2:
SJF(n,process_arr); break;
case 3:
Roundrobin(n,process_arr); break;
case 4:
exit(0);//Sucessfully exited
default:
//unsuccessful exit.
exit(-1);
}
}

}

int main()
{
process_scheduling ps; ps.input_processes();

return 0;

}

