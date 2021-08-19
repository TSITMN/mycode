#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX_V = 100;
int vertex ;
int cost[MAX_V][MAX_V];
bool used[MAX_V];
int prever[MAX_V];
int d[MAX_V];

void Dijkastra(int s)
{
    memset(d , 0x3f , sizeof(d));
    memset(used , 0 , sizeof(used));
    memset(prever , -1 , sizeof(prever));
    d[s] = 0;
    while(1)
    {
        int v=-1;
        for(int i=1 ; i<=vertex ; ++i)
        {
            if(!used[i] && (v==-1 || d[i]< d[v]))v=i;
        }
        if(v==-1) break;
        used[v] = 1;
        for(int i=1 ; i<=vertex ; ++i)
        {
            if(d[i] < d[v] + cost[v][i])
            {
                d[i] = d[v] + cost[v][i];
                prever[i] = v;
            }
        }
    }
}
vector<int> get_path(int t)
{
    vector<int> path;
    for(;t!=-1;t=prever[t]) path.push_back(t);
    reverse(path.begin() , path.end());
    return path;
}