#include<bits/stdc++.h>
using namespace std;

int process[1000], wait[1000];
int cpu[1000], rem_cpu[1000];
int turnaround[1000];
int n;
int quantum;


void findWaitingTime()
{
    for(int i=0; i<n; i++)
    {
        rem_cpu[i] = cpu[i];
    }

    int time=0;

    cout<<time;

    while(1)
    {
        bool done= true;
        for(int i=0; i< n; i++)
        {
            if(rem_cpu[i]>0)
            {
                done = false;
                if(rem_cpu[i]>quantum)
                {
                    rem_cpu[i] -= quantum;
                    time+=quantum;
                    cout<<"---"<<"p"<<i<<"---"<<time;
                }
                else
                {
                    time+= rem_cpu[i];
                    wait[i] = time - cpu[i];
                    rem_cpu[i] = 0;
                    cout<<"---"<<"p"<<i<<"---"<<time;
                }
            }
        }

        if(done == true)
            break;
    }
}

void findTurnaroundTime()
{
    for(int i=0 ; i<n ; i++)
    {
        turnaround[i] = wait[i] + cpu[i];
    }
}

int main()
{
    cin>>n>>quantum;

    for(int i=0; i<n; i++)
    {
        cin>>process[i]>>cpu[i];
    }


    findWaitingTime();
    findTurnaroundTime();

    cout<<endl<<endl;
    cout<<"Process\t"<<"Waiting Time\t"<<"Turnaround Time"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<process[i]<<"\t   "<<wait[i]<<"\t   \t"<<turnaround[i]<<endl;
    }

    return 0;

}

/*
4 3
0 5
1 7
2 9
3 9
*/
