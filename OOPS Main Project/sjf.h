#include <iostream>
#pragma once
#include "schedule.h"
using namespace std;

class sjf:public schedule
{
    int e[5],tat[5];
    float atat,awt;
    public:
    
    void computeSJF(int processess[],int at[],int n,int bt[])
    {
        int temp,tt=0,min,d,i,j;
        atat=0;
        awt=0;
        float stat=0,swt=0;

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(bt[i]>bt[j])
                {
                    temp=at[i];
                    at[i]=at[j];
                    at[j]=temp;

                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;

                    temp=processess[i];
                    processess[i]=processess[j];
                    processess[j]=temp;
                }
            }
        }

        min=at[0];
        for(i=0;i<n;i++)
        {
            if(min>at[i])
            {
                min=at[i];
                d=i;
            }
        }


        tt=min;
        e[d]=tt+bt[d];
        tt=e[d];

        for(i=0;i<n;i++)
        {
            if(at[i]!=min)
            {
                e[i]=bt[i]+tt;
                tt=e[i];
            }
        }

        for(i=0;i<n;i++)
        {
            tat[i]=e[i]-at[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-bt[i];
            if(wt[i]<0)
            {
                wt[i]=0;

            }
            swt=swt+wt[i];
        }
        atat=stat/n;
        awt=swt/n;
        cout<<"\nProcess-ID\tArrival Time\tBurst Time\tWaiting Time\tTurn-A time\tExit Time\n";
        for(int i=0;i<n;i++)
        {
            cout<<processess[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<e[i]<<endl;

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