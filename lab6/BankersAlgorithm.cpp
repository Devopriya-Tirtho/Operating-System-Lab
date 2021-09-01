#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,r;
    cin>>n>>r;
    int x;
    vector<int>allocation[n+1],maximum[n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=r; j++)
        {
            cin>>x;
            maximum[i].push_back(x);
        }
        for(int j=1; j<=r; j++)
        {
            cin>>x;
            allocation[i].push_back(x);
        }
    }
    for(int i=1; i<=r; i++)
    {
        cin>>x;
        maximum[0].push_back(x);
        allocation[0].push_back(0);
    }
    for(int i=0; i<r; i++)
    {
        for(int j=1; j<=n; j++)
        {
            allocation[0][i]+=allocation[j][i];
        }
    }
    for(int i=0; i<r; i++)
        allocation[0][i]=maximum[0][i]-allocation[0][i];
    int cnt,process=0;
    bool taken[n+1];
    memset(taken,false,sizeof(taken));
    while(process<n)
    {
        for(int i=1; i<=n; i++)
        {
            if(!taken[i])
            {
                cnt=0;
                for(int j=0; j<r; j++)
                {
                    if(allocation[0][j]>=(maximum[i][j]-allocation[i][j]))cnt++;
                }
                if(cnt==r)
                {
                    for(int j=0; j<r; j++)
                    {
                        allocation[0][j]+=allocation[i][j];
                        allocation[i][j]=0;
                    }
                    cout<<"p"<<i<<" ";
                    taken[i]=true;
                    process++;
                }
            }
        }
    }
}
/*
4
3
3
2
2
1
0
0
6
1
3
5
1
1
3
1
4
2
1
1
4
2
2
0
0
2
9
3
6

5
3
7 5 3
0 1 0
3 2 2
2 0 0
9 0 2
3 0 2
2 2 2
2 1 1
4 3 3
0 0 2
10 5 7
*/
