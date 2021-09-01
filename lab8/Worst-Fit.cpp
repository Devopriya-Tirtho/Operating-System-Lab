#include<bits/stdc++.h>
using namespace std;

int memory_partition[1000];
int req[1000];

int main()
{
    int n,R;
    cout<<"Enter the Number of Partitions: ";
    cin>>n;
    cout<<"Memory Holes : ";
    for(int i=0; i<n; i++)
        cin>>memory_partition[i];
    cout<<"Enter the Number of Requests: ";
    cin>>R;
    cout<<"Memory Requests: ";
    for(int i=0; i<R; i++)
        cin>>req[i];
    cout<<"Worst Fit\nStep by step memory allocation situation in Worst Fit\n";
    for(int r=0; r<R; r++)
    {
        int maximum=INT_MIN;
        int mi=-1;
        cout << req[r] << "\t->\t";
        for(int p=0; p<n; p++)
        {
            if(memory_partition[p]>maximum)
            {
                maximum=memory_partition[p];
                mi=p;
            }
        }
        if(memory_partition[mi]>=req[r])
        {
            memory_partition[mi]-=req[r];
            for(int i=0; i<n; i++)
                cout<<memory_partition[i]<<"\t";
            cout<<'\n';
        }
        else
        {
            cout<<"CAN'T BE ALLOCATED\n";
            int sum=0;
            for(int i=0; i<n; i++)
                sum+=memory_partition[i];
            cout<<"External Fragmentation: "<<sum+req[r-1]<<'\n';
            break;
        }
    }
    return 0;
}

