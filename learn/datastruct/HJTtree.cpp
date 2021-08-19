/*https://www.bilibili.com/video/BV1C4411u7rK?p=2*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int maxn = 1e5+10;
vector<int> v;
int a[maxn] , cnt , rt[maxn];
struct NODE
{
    int l , r , sum;
}tr[maxn<<5];
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}

void insert(int l , int r , int pre , int &now , int pos)
{
    tr[++cnt] = tr[pre];
    now = cnt;
    ++tr[now].sum;
    if(l==r) return;
    int mid = (l+r)>>1;
    if(pos<=mid) insert(l , mid , tr[pre].l , tr[now].l , pos);
    else insert( mid+1 , r ,tr[pre].r , tr[now].r , pos);
}

int query(int l , int r , int L , int R , int k)
{
    if(l==r) return l;
    int mid = ( l + r ) >> 1;
    int d = tr[tr[R].l].sum - tr[tr[L].l].sum;
    if(k <= d) return query(l , mid , tr[L].l , tr[R].l , k );
    else return query(mid+1 , r , tr[L].r , tr[R].r , k-d);
}

void solve()
{
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; ++i)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort ( v.begin() , v.end() );
    v.erase( unique( v.begin() , v.end() ) , v.end() );
    for(int i=1 ; i<=n ; ++i)
    {
        insert( 1 , n , rt[i-1] , rt[i] , getid(a[i]) );
    }
    while(m--)
    {
        int l ,r , k;
        cin >> l >> r >> k;
        cout << v[ query( 1 , n , rt[l-1] , rt[r] , k) - 1 ] << "\n";
    }
}

int main()
{

}
