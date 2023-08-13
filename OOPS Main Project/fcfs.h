#include <iostream>
#include "schedule.h"
#pragma once
using namespace std;

class fcfs:public schedule
{
    float atat,awt;
    public:
    void findWaitingTime(int processess[],int n,int bt[],int wt[],int at[])
    {
        int service_time[n];
        service_time[0]=0;
        wt[0]=0;


        for(int i=1;i<n;i++)
        {
            service_time[i]=service_time[i-1]+bt[i-1];

            wt[i]=service_time[i]-at[i];

            if(wt[i]<0)
            wt[i]=0;
        }
    }

    void findTurnAroundTime(int processess[],int n,int bt[],int wt[],int tat[])
    {
        for(int i=0;i<n;i++)
        tat[i]=bt[i]+wt[i];
        
    }

    void findavgTime(int processess[],int n,int bt[],int at[])
    {
        int wt[n],tat[n];

        findWaitingTime(processess,n,bt,wt,at);

        findTurnAroundTime(processess,n,bt,wt,tat);

        cout<<"\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurn-A Time\tExit Time\n";
        int total_wt=0,total_tat=0;
        for(int i=0;i<n;i++)
        {
            total_wt=total_wt+wt[i];
            total_tat=total_tat+tat[i];
            int compl_time=tat[i]+at[i];
            cout<<" "<<i+1<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<compl_time<<endl;

        }

        awt=(float)total_wt/(float)n;
        atat=(float)total_tat/(float)n;
        cout<<"\nAverage Waiting Time: "<<(float)total_wt/(float)n;
        cout<<"\nAverage Turn Around Time: "<<(float)total_tat/(float)n;

    }
    // float sendAwt()
    // {
    //     return awt;
    // }
    // float sendAtat()
    // {
    //     return atat;
    // }

};
//Changes for Git