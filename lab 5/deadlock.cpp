#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_PROCESS 1000
int n,m;
vector<int> arr[MAX_PROCESS];
vector<int> cycle_path;
int parent[MAX_PROCESS];
int color[MAX_PROCESS];
bool found=false;
void DFS(int u)
{
    color[u]=GRAY;
    for(int v: arr[u])
    {
        if(color[v]==GRAY)
        {
            found=true;
            int temp=u;
            cycle_path.push_back(v);
            while(temp!=v)
            {
                cycle_path.push_back(temp);
                temp=parent[temp];
            }
            return;
        }
        if(color[v]==WHITE)
        {
            parent[v]=u;
            DFS(v);
        }
    }
    color[u]=BLACK;
}
int main()
{
    cout<<"Number of nodes : ";
    cin>>n;
    cout<<'\n';
    m=n;
    cout<<"Edges:\n";
    for(int i=0; i<m; i++)
    {
        char x,y;
        cin>>x>>y;
        arr[(char)y].push_back((char)x);
    }
    for(int i=0; i<MAX_PROCESS; i++)
    {
        if(color[i]==WHITE)
            DFS(i);
    }
    if(found)
    {
        cout<<"Deadlock Detected Among nodes: ";
        for(int i=0; i<cycle_path.size(); ++i)
            cout<<(char)cycle_path[i]<<" ";
        cout<<'\n';
    }
    else
        cout<<"No Deadlock Detected\n";
    return 0;
}
