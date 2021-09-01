#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int rem_cpu;
    int arrival;
    int cpu;
    int waiting_time;
    int turnaround_time;
};

bool cmp(process a, process b)
{
    return a.arrival<b.arrival;
}
bool cmp_print(process a, process b)
{
    return a.pid<b.pid;
}
//nt waiting_time[1000], turnaround_time[1000];

int main()
{
    int n;
    cin>>n;

    struct process p;
    process ar[n];
    int total_time=0;

    for(int i=0; i<n; i++)
    {
        cin>>p.pid>>p.arrival>>p.cpu;
        p.rem_cpu=p.cpu;
        ar[i]=p;

        total_time+=p.cpu;
    }

    sort(ar,ar+n,cmp);

    int time;
    double total_waiting_time=0,total_turnaround_time=0;

    for(time=0; time<=total_time; time++)
    {
        int remaining=INT_MAX;
        int id;

        for(int i=0; i<n; i++)
        {
            if(ar[i].arrival<=time&&ar[i].rem_cpu<remaining&&ar[i].rem_cpu>0)
            {
                remaining=ar[i].rem_cpu;
                id=i;  //*********
            }
        }

        ar[id].rem_cpu--;

        if(ar[id].rem_cpu==0)
        {
            int Waiting_Time=time-ar[id].cpu-ar[id].arrival+1;
            int TurnAround_Time=Waiting_Time+ar[id].cpu;

            ar[id].waiting_time = Waiting_Time;
            ar[id].turnaround_time = TurnAround_Time;
             // cout<<"Process "<<ar[id].pid<<" Waiting Time: "<<Waiting_Time<<" Turn Around Time:"<<TurnAround_Time<<endl;

            total_waiting_time+=Waiting_Time;
            total_turnaround_time+=TurnAround_Time;
        }


    }

    sort(ar,ar+n,cmp_print);

    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<ar[i].pid<<" Waiting Time: "<<ar[i].waiting_time<<" Turn Around Time:"<<ar[i].turnaround_time<<endl;
    }


    cout<<"Avg Waiting Time: "<<total_waiting_time/n<<endl;
    cout<<"Avg Turn Around Time: "<<total_turnaround_time/n<<endl;
}
