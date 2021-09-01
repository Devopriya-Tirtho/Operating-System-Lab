#include<bits/stdc++.h>
using namespace std;

struct process{

    int pid;
    int cpu_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;

    bool operator<(process x) const
    {
        return cpu_time > x.cpu_time;
    }

};

bool cmp(process a, process b)
{
    return a.arrival_time<b.arrival_time;
}


int main()
{
    int n;
    process temp;
    process ar[1000];

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>temp.pid>> temp.arrival_time>> temp.cpu_time;
        ar[i] = temp;
    }

    sort(ar, ar+n, cmp);

    priority_queue<process> pq;
    vector<process> vec;

    ar[0].waiting_time = 0;

    pq.push(ar[0]);
    //vec.push_back(ar[0]);

    bool first = true;
    int time = 0;
    int i = 1;
    int cnt = 1;

    while(!pq.empty())
    {
        process current = pq.top();
        pq.pop();
        if(first)
        {
            //printing for 1st process
            first = false;
            cout<<time<<"---P"<<current.pid<<"---";
        }
        else
        {
            cout<<current.pid<<"---";
        }

        time+=current.cpu_time;


        while(time>=ar[i].arrival_time && i<n)
        {
            pq.push(ar[i]);
            i++;
        }
        if(cnt<n)
            cout<<time<<"---P";
        else
            cout<<time<<endl<<endl;

        current.waiting_time = time - current.cpu_time - current.arrival_time;
        current.turnaround_time = current.cpu_time + current.waiting_time;

        vec.push_back(current);

        cnt++;
    }


    cout<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Process: "<<vec[i].pid<<" Waiting Time: "<<vec[i].waiting_time<<" Turnaround Time: "<<vec[i].turnaround_time<<endl;
    }

    return 0;
}

