#include<bits/stdc++.h>
using namespace std;
int resource_number,process_number;
int allocation[100][100],max_need[100][100],need[100][100];
int available[100],resources[100];
bool visited[100];
int cnt=0;
vector<int> safe_sequence;
bool process_run()
{
    int curr=0;
    for(int i=1; i<=process_number; i++)
    {
        bool all=true;
        if(visited[i]==true)
            continue;
        for(int j=1; j<=resource_number; j++)
        {
            if(need[i][j]>available[j])
                all=false;
        }
        if(all)
        {
            curr=i;
            visited[i]=true;
            safe_sequence.push_back(i);
            for(int k=1; k<=resource_number; k++)
                available[k]+=allocation[curr][k];
            return true;
        }
    }
    return false;
}
int main()
{
    cout<<"Enter Process Number: ";
    cin>>process_number;
    cout<<"Enter Resource Number: ";
    cin>>resource_number;
    cout<<"Resources: ";
    for(int i=1; i<=resource_number; i++)
        cin>>resources[i];
    cout<<"\n\tAllocation\t\Max\n\n";
    for(int i=1; i<=process_number; i++)
    {
        cout<<"P"<<i<<"\t";
        for(int j=1; j<=resource_number; j++)
        {
           cin>>allocation[i][j];
        }
        for(int j=1;j<=resource_number;j++)
        {
            cin>>max_need[i][j];
        }
        cout<<'\n';
    }
    cout<<"\nAvailable: ";
    for(int i=1; i<=resource_number; i++)
    {
        int sum=0;
        for(int j=1; j<=process_number; j++)
            sum+=allocation[j][i];
        available[i]=resources[i]-sum;
        cout<<available[i]<<" ";
    }
    cout<<"\n\nNeed\n";
    for(int i=1; i<=process_number; i++)
    {
        for(int j=1; j<=resource_number; j++)
        {
            need[i][j]=max_need[i][j]-allocation[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<'\n';
    }
    while(cnt<process_number)
    {
        if(process_run())
            cnt++;
        else
        {
            cout<<"The System is not in Safe Sequence\n";
            return 0;
        }
    }
    cout<<"\n< ";
    for(int i=0; i<safe_sequence.size(); i++)
    {
        cout<<"P"<<safe_sequence[i]<<" ";
    }
    cout<<"> is\nthe safe sequence.";
    return 0;
}
