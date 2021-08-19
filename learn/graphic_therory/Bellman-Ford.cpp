#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 0x3f3f3f3f;
struct edge
{
    int from , to ,cost;
}ed[MAX_E];
int V,E; 
int dis[MAX_V];

void shortest_path(int s)
{
    for(int i=1 ; i<=V ; ++i) dis[i] =INF;
    dis[s] = 0;
    while(1)
    {
        bool update = 0;
        for(int i=1 ; i<=E ; ++i)
        {
            edge e = ed[i];
            if(dis[e.from] !=INF && dis[e.to] > dis[e.from] + e.cost)
            {
                dis[e.to] = dis[e.from] + e.cost;
                update = 1;
            }
        }
        if(!update) break;
    }
}
bool find_negative_loop()
{
    memset(dis,0,sizeof(dis));
    for(int i=0 ; i<=V ; ++i)
    {
        for(int j=1 ; j<=E ; ++j)
        {
            edge e = ed[j];
            if(dis[e.to] > dis[e.from] + e.cost)
            {
                dis[e.to] = dis[e.from] + e.cost;
                if(i==V) return 1;
            }
        }
    }
    return 0;
}
  