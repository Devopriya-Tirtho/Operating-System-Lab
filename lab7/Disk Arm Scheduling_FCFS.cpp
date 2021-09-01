#include<bits/stdc++.h>
using namespace std;

int n,head,total_movement=0;
int req[10000];

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
        total_movement+=abs(head-req[i]);
        head=req[i];
        cout<<" -> "<<req[i];
    }
    cout<<"\nTotal Cylinder movement: "<<total_movement<<'\n';
    return 0;
}
