#include <iostream>
#pragma once
using namespace std;

class schedule
{
    protected:
    int processess[5],bt[5],wt[5],at[5],pr[5],n=5;
    public:
    schedule()
    {
        for(int i=0;i<5;i++)
        {
            at[i]=0;
        }
    }

    void findWaitingTime(int processess[],int n,int bt[],int wt[],int at[]);
    void findTurnAroundTime(int processess[],int n,int bt[],int wt[],int tat[]);
    void findavgTime(int processess[],int n,int bt[],int at[]);

    void computeSJF(int processess[],int at[],int n,int bt[]);

    void computePri(int processess[],int bt[],int n,int pr[]);

   


};