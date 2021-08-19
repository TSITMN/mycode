#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a ; i<=b ; ++i)
#define rerep(i,a,b) for(int i=b ; i>=a ; --i)
#define MEM(name,val) memset(name,val,sizeof(val));
template<typename T> void rd(vector<T> &a) {for (auto &ele : a) cin >> ele;}
template<typename T> void writeln(vector<T> &a) {for (auto &ele : a) cout << ele << ' '; cout << "\n" ;}

const int maxn = 5e5+5 ; //总字符个数

int tr[maxn][26] , fail[26*maxn] , vis[26*maxn] , cnt =0;

void insert(string);
void build();
int query(string);
void solve()
{
    MEM(tr,0);
    MEM(vis,0);
    cnt =0 ;
    //insert()
    //build()
    //query()
    
}

void insert(string s)
{
    int len = s.length();
    int rt = 0 ;
    rep(i,0,len-1)
    {   
        int id = s[i]-'a';
        if(!tr[rt][id]) tr[rt][id] = ++cnt;
        rt = tr[rt][id];
    }
    ++vis[rt];
}

void build()
{
    queue<int> Q;
    rep(i,0,25)
    {
        if(tr[0][i])
        {
            fail[tr[0][i]] = 0;
            Q.push(tr[0][i]);
        }
    }
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        rep(i,0,25)
        {
            if(tr[now][i])
            {
                fail[tr[now][i]] = tr[fail[now]][i];
                Q.push(tr[now][i]);
            }
            else tr[now][i] = tr[fail[now]][i];
        }
    }
}
int query(string s)
{
    int now =0 , ans =0 ,len = s.length();
    rep(i,0,len-1)
    {
        now = tr[now][s[i]-'a'];
        for(int j=now  ; j && vis[j]!=-1 ; j=fail[j])
        {
            ans += vis[j];
            if(vis[j]) vis[j] = -1;
        }
    }
    return ans;
}
