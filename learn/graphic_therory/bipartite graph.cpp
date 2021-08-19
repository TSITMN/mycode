#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX_V = 100;
vector<int> G[MAX_V];

void build(int n)
{
    for(int i=1 ; i<=n ; ++i)
    {
        int v,w;
        cin>>v>>w;
        G[v].push_back(w);
    }
}

int color[MAX_V];
bool dfs(int v , int c)
{
    color[v] = c;
    for(auto i :G[v])
    {
        if(color[i]==c) return 0;
        if(color[i] == 0 && !dfs(i,-c)) return 0;
    }
    return 1;
}
