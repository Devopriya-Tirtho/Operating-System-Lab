#include<bits/stdc++.h>
using namespace std;

int n,head,total_movement=0;
int req[10000];
bool visited[10000];
int min_index()
{
    int minimum=INT_MAX;
    int mi=-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true)
            continue;
        if(abs(head-req[i])<minimum)
        {
            minimum=abs(head-req[i]);
            mi=i;
        }
    }
    visited[mi]=true;
    return mi;
}
int main()
{
    cout<<"Enter The Number of Requests: ";
    cin>>n;
    cout<<"Enter The Requests: ";
    for(int i=0;i<n;i++)
        cin>>req[i];
    cout<<"Enter The Head Position: ";
    cin>>head;
    cout<<"Cylinder Serving Order: "<<head;
    for(int i=0;i<n;i++)
    {
        int temp=min_index();
        total_movement+=abs(head-req[temp]);
        head=req[temp];
        cout<<" -> "<<head;
    }
    cout<<"\nTotal Cylinder movement: "<<total_movement<<'\n';
    return 0;
}
