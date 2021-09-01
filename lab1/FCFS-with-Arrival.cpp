#include<bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int arr_time;
    int cpu_time;
    int wait_time;
    int turn_around;
} arr[1000];
bool cmp(process A, process B)
{
    if(A.arr_time==B.arr_time)
        return A.pid<B.pid;
    else
        return A.arr_time<B.arr_time;
}
int main()
{
    int n;
    cout<<"Enter the Number of Process: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,y;
        arr[i].pid=i+1;
        cout<<"Enter Arrival Time and CPU Time for Process "<<arr[i].pid<<": ";
        cin>>x>>y;
        arr[i].arr_time=x;
        arr[i].cpu_time=y;
    }
    sort(arr, arr+n, cmp);
    int total=0,total_wait=0,total_turn=0;
    for(int i=0;i<n;i++)
    {
        arr[i].wait_time=total-arr[i].arr_time;
        arr[i].turn_around=arr[i].wait_time+arr[i].cpu_time;
        total=total+arr[i].cpu_time;
    }
    cout<<"Process\tArrival Time\tCPU Time\tWaiting Time\tTurn Around Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].pid<<'\t'<<arr[i].arr_time<<'\t'<<'\t'<<arr[i].cpu_time<<'\t'<<'\t'<<arr[i].wait_time<<'\t'<<'\t'<<arr[i].turn_around<<'\n';
        total_wait+=arr[i].wait_time;
        total_turn+=arr[i].turn_around;
    }
    cout<<"Average Waiting Time: "<<(float)total_wait/(float)n<<'\n';
    cout<<"Average Turn Around Time: "<<(float)total_turn/(float)n<<'\n';
    return 0;
}
