#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX_V = 100;
int cost[MAX_V][MAX_V];
typedef pair<int , int> P;
int d[MAX_V];
bool used[MAX_V];
int vertex;

void Dijkstra(int a)
{   
    priority_queue< P , vector<P> , greater<P>> Q;
    memset(used , 0 ,sizeof(used));
    d[a] = 0;
    Q.push(P(0,1));
    while(!Q.empty())
    {   
        P tmp = Q.top();
        Q.pop();
        int v = tmp.second;
        if(d[v] < tmp.first) continue;
        for(int i=1 ; i<=vertex ; ++i)
        {
            if(d[i] > d[v] + cost[v][i])
            {   
                d[i] = d[v] + cost[v][i];
                Q.push(P(d[i], i));
            }
        }
    }
}