#include <iostream>

#include "schedule.h"
#pragma once

using namespace std;

class priority:public schedule
{
    int tat[5],pr[5];
    float atat,awt;

    public:
    void computePri(int processess[],int bt[],int n,int pr[])
    {
        int i,j,pos,temp;
        atat=0.0;
        awt=0.0;
        float total=0.0;
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(pr[j]<pr[pos])
                pos=j;
            }

            temp=pr[i];
            pr[i]=pr[pos];
            pr[pos]=temp;

            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;

            temp=processess[i];
            processess[i]=processess[pos];
            processess[pos]=temp;


        }

        wt[0]=0;
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
            wt[i]+=bt[j];

            total+=wt[i];
        }

        awt=total/n;
        total=0;
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];
            total+=tat[i];
        }

        atat=total/n;

        cout<<"\nProcess-ID\tPriority\tBurst Time\tWaiting Time\tTurn-A Time\n";

        for(int i=0;i<n;i++)
        {
            cout<<processess[i]<<"\t\t"<<pr[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<endl;
        }

        cout<<"\nAverage Waiting Time: "<<awt<<"\nAverage Turn Around Time: "<<atat;

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