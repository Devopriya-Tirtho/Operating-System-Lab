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
    cout<<"Best Fit\nStep by step memory allocation situation in Best Fit\n";
    for(int r=0; r<R; r++)
    {
        int minimum=INT_MAX;
        int mi=-1;
        cout << req[r] << "\t->\t";
        for(int p=0; p<n; p++)
        {
            if(memory_partition[p]>=req[r] && (memory_partition[p]-req[r]<=minimum))
            {
                minimum=memory_partition[p]-req[r];
                mi=p;
            }
        }
        if(mi==-1)
        {
            cout<<"CAN'T BE ALLOCATED\n";
            int sum=0;
            for(int i=0; i<n; i++)
                sum+=memory_partition[i];
            cout << "External Fragmentation: " << sum << '\n';
            break;
        }
        else{
            memory_partition[mi]-=req[r];
            for(int i=0;i<n;i++)
                cout<<memory_partition[i]<<"\t";
            cout<<'\n';
        }
    }
    return 0;
}

