#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int cpu;
};

int waiting_time[1000],turnaround_time[1000];
int cpu_time[1000];

int main()
{
    int quantum;
    int n;
    int time=0;
    struct process p;

    cin>>n>>quantum;
    queue<process>q;

    for(int i=1; i<=n; i++)
    {
        cin>>p.pid>>p.cpu;
        cpu_time[p.pid]=p.cpu;
        q.push(p);
    }

    int temp=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.cpu>quantum)
        {
            time+=quantum;
            p.cpu-=quantum;
            q.push(p);
            cout<<temp<<"..."<<time<<"   Process "<<p.pid<<endl;
            temp=time;
        }
        else if(p.cpu<=quantum)
        {
            time+=p.cpu;
            waiting_time[p.pid]=time-cpu_time[p.pid];
            turnaround_time[p.pid]=waiting_time[p.pid]+cpu_time[p.pid];
            cout<<temp<<"..."<<time<<"   Process"<<p.pid<<endl;
            temp=time;
        }
    }
    double total_waiting_time=0,total_turnaround_time=0;
    for(int i=1; i<=n; i++)
    {
        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }
    for(int i=1; i<=n; i++)
    {
        cout<<"Process "<<i<<" Waiting Time: "<<waiting_time[i]<<endl;
    }
    cout<<"Avg Waiting Time: "<<total_waiting_time/n<<endl;
    cout<<"Avg Turn Around Time: "<<total_turnaround_time/n<<endl;
}
