#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAX_V=100;
struct NODE
{
    int from , to , val;
    bool operator<(const NODE&b)
    {
        return b.val<val;
    }
}node[MAX_V];

int fa[MAX_V] , vertex;
void inti(int n)
{
    for(int i=1 ; i<=n  ;++i)
    {
        fa[i] = i;
    }
}
int find_fa(int x)
{
    if(x!=fa[x]) fa[x] = find_fa(fa[x]);
    return fa[x];
}
void merge(int a , int b)
{
    int pa=find_fa(a) , pb = find_fa(b);
    if(pa==pb) return;
    fa[pa] = pb;
    return;
}
bool same(int a , int b)
{
    return find_fa(a)==find_fa(b);
}

int solve()
{   
    int ans =0;
    priority_queue<NODE>Q;
    inti(vertex);
    for(int i=1 ; i<=vertex ; ++i)
    {
        Q.push(node[i]);
    }
    for(int i=1 ; i<=vertex ; ++i)
    {   
        NODE tmp = Q.top();
        Q.pop();
        if(!same(tmp.from , tmp.to))
        {
            ans += tmp.val;
            merge(tmp.from , tmp.to);
        }
    }
    return ans;
}