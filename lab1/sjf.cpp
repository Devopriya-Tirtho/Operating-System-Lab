#include<bits/stdc++.h>
using namespace std;
struct process{
int pid;
int cpuTime;
};

bool com(process a,process b)
{
    return a.cpuTime<b.cpuTime;
}
int wt[100],tat[100];
int main(){
int n=4;
struct process ar[4]={{1,6},{2,8},{3,7},{4,3}};
sort(ar,ar+n,com);

 wt[0]=0;
for(int i=1;i<n;i++)
{
    wt[i]=wt[i-1]+ar[i-1].cpuTime;
}
for(int i=0;i<n;i++)
{
tat[i]=ar[i].cpuTime+wt[i];
}
cout<<"\t wt tat \n ";
double t_wt=0.0,t_tat=0.0;
for(int i=0;i<n;i++)
{
    t_wt=t_wt+wt[i];
    t_tat=t_tat+tat[i];
    cout<<"Process "<<i+1<<"  "<<wt[i]<< " "<<tat[i]<<endl;
}
cout<<"0";
for(int i=0;i<n;i++)
{
cout<<"-----";
cout<<tat[i];

}
cout<<endl;
for(int i=1;i<=n;i++)
{

cout<<"  p"<<i<<"  ";
}

return 0;
}
