#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,m;
vector<char>ar[1000];
vector<char>cycle_path;
int color[1000];
int par[1000];
bool cycle_found=false;
void DFS(char u)
{
    color[u]=GRAY;
    for(char v:ar[u])
    {
        if(color[v]==GRAY)
        {
            cycle_found=true;
            char temp =u;
            cycle_path.push_back(v);
            while(temp!=v)
            {
                cycle_path.push_back(temp);
                temp=par[temp];
            }
            return ;
        }
        if(color[v]==WHITE)
        {
            par[v]=u;
            DFS(v);
        }
    }
    color[u]=BLACK;
}


int main()
{
    cout<<"enter n ,m :";
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        char x,y;
        cin>>x>>y;
        int p=(int)(x-65);
        int q=(int)(y-65);
        ar[p].push_back(q);
    }
    for(int i=0; i<=n; i++)
    {
        if(color[i]==WHITE)
        {
            DFS(i);
        }
    }
    if (cycle_found)
    {
        cout << "Deadlock detected\n";
       /* for (int i = 0; i < cycle_path.size(); i++)
        {
            cout <<(char) (cycle_path[i]+65) << " ";
        }*/
        for (int i = cycle_path.size()-1; i >= 0; i--)
        {
            cout <<(char) (cycle_path[i]+65) << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "No deadlock detected\n";
    }
    return 0;
}




