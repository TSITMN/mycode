#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a ; i<=b ; ++i)
#define rerep(i,a,b) for(int i=b ; i>=a ; --i)
template<typename T> void rd(vector<T> &a) {for (auto &ele : a) cin >> ele;}
template<typename T> void writeln(vector<T> &a) {for (auto &ele : a) cout << ele << ' '; cout << "\n" ;}
const int maxn = 1e3+5;

int tr[32*maxn][2] , cnt , vis[32*maxn] , val[32*maxn];

void insert(int x , int p) // p == 1 插入 -1 删除
{   
    int root = 0;
    rerep(i,0,31)
    {
        int id = (x>>i)&1;
        if(!tr[root][id]) tr[root][id] = ++cnt;
        root = tr[root][id];
        vis[root] += p;
    }
    val[root] = x;
}

int find(int x)
{
    int root = 0;
    rerep(i,0,31)
    {
        int id = (x>>i)&1 ;
        if(tr[root][id^1] && vis[tr[root][id^1]]) root = tr[root][id^1];
        else root = tr[root][id]; 
    }
    return val[root];
}