#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a ; i<=b ; ++i)
#define rerep(i,a,b) for(int i=b ; i>=a ; --i)
template<typename T> void rd(vector<T> &a) {for (auto &ele : a) cin >> ele;}
template<typename T> void writeln(vector<T> &a) {for (auto &ele : a) cout << ele << ' '; cout << "\n" ;}

const int maxn = 1e5+10;

int tr[maxn][30] , cnt ;
bool vis[maxn];

void insert(char *str)
{
    int len = strlen(str);
    int root = 0;
    rep(i,0,len-1)
    {
        int id = str[i] - 'a';
        if(!tr[root][id]) tr[root][id] = ++cnt;
        root = tr[root][id];
    }
    vis[root] = 1;
}

bool find(char *str)
{
    int len = strlen(str);
    int root = 0;
    rep(i,0,len-1)
    {
        int id = str[i] - 'a';
        if(!tr[root][id]) return 0;
        root = tr[root][id];
    }
    return vis[root];
}