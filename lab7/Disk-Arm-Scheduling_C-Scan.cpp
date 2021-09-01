#include<bits/stdc++.h>
using namespace std;

int L,R,n,head,curr_dir,read_dir,cnt=0,total_movement=0;
int req[10000];
bool visited[10000];
vector<int> sequence;

bool find_request()
{
    for(int i=0; i<n; i++)
    {
        if(visited[i]==true)
            continue;
        if(head==req[i])
        {
            sequence.push_back(req[i]);
            visited[i]=true;
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<"Number of total Cylinders: ";
    cin>>R;
    L=0;
    R--;
    cout<<"Number of requests: ";
    cin>>n;
    cout<<"Cylinder requests: ";
    for(int i=0; i<n; i++)
        cin>>req[i];
    cout<<"Enter head position: ";
    cin>>head;
    cout<<"Current head facing side: ";
    cin>>curr_dir;
    cout<<"Read head facing side";
    cin>>read_dir;
    cout<<"Cylinder Serving Order: "<<head;
    while(cnt<n)
    {
        if(curr_dir==read_dir)
        {
            if(find_request())
                cnt++;
        }
        if(curr_dir==1)
            head++;
        else
            head--;
        if(head==R)
            curr_dir=0;
        if(head==L)
            curr_dir=1;
        total_movement++;
    }
    for(int i=0; i<sequence.size(); i++)
        cout<<" -> "<<sequence[i];
    cout<<"\nTotal Cylinder movement: "<<total_movement<<'\n';
    return 0;
}
