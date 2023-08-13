#include <iostream>
#include "schedule.h"
#include "fcfs.h"
#include "priority.h"
#include "sjf.h"
using namespace std;
int main()
{
    int arrival_time[5],burst_time[5],pri[5];
    int choice;
    do
    {
        cout<<"\nCPU Scheduling Algorithms Implementation";
        cout<<"\n1.Reading Data\n2.Displaying Scheduling Parameters\n3.Exit";
        cout<<"\nEnter your Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
        

        int a;
        for(int i=0;i<5;i++)
        {
            try
            {
                cout<<"Enter Burst Time for process no "<<i+1<<": ";
                cin>>a;
                if(a<0)
                {
                    throw a;
                }    
                else
                    burst_time[i]=a;




                
            }
            catch(int k)
            {
                cout<<"\nBurst Time can never be negative"<<k<<endl;

                cout<<"\nEnter Burst Time again";
                i=i-1;

            }
        }

        for(int i=0;i<5;i++)
        {

            try
            {
                cout<<"\nEnter arrival time for process number"<<i+1<<": ";
                cin>>a;
                if(a<0)
                {
                    throw a;

                }
                else
                arrival_time[i]=a;

                
            }
            catch(int k)
            {
                cout<<"\nArrival Time can never be negative"<<k;
                cout<<"\nEnter Arrival Time again";
                i=i-1;

                
            }
            

        }

        for(int i=0;i<5;i++)
        {
            cout<<"\nEnter Priority for process number "<<i+1<<": ";
            cin>>pri[i];
        }
            
            break;
        }    

        case 2:
        {
            int processes[]={1,2,3,4,5};
            int n=5;
            fcfs f;
            f.findavgTime(processes,n,burst_time,arrival_time);
            cout<<endl;
            cout<<endl;
 
            sjf s;
            s.computeSJF(processes,arrival_time,n,burst_time);
            cout<<endl;
            cout<<endl;

            priority p;
            p.computePri(processes,burst_time,n,pri);
            cout<<endl;
            cout<<endl;


         break;   
        }

        

        case 3:
        exit(1);
        break;    
        
        default:
            break;
        }
    }while(1);
    
}