#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

#define ls rt<<1
#define rs rt<<1|1
const int MAXN =100;
struct NODE
{
    int val , lazy , l ,r;
}tr[MAXN<<2];
int input[MAXN];
void push_up(int rt)
{
    tr[rt].val = tr[ls].val + tr[rs].val;
}

void push_down(int rt)
{   
    if(!tr[rt].lazy) return;
    tr[ls].val += tr[rt].lazy*(tr[ls].r - tr[ls].r -1);
    tr[rs].val += tr[rt].lazy*(tr[rs].r - tr[rs].r -1);
    
    tr[ls].lazy += tr[rt].lazy;
    tr[rs].lazy += tr[rt].lazy;

    tr[rt].lazy = 0;
}

void Build(int rt , int l , int r)
{
    tr[rt].l = l , tr[rt].r = r;
    if(l==r)
    {
        tr[rt].val = input[l];
        return;
    }
    int mid = (l+r)>>1;
    Build(ls,l,mid);
    Build(rs,mid+1,r);
    push_up(rt);
}

void Segment_add(int rt , int l , int r , int x)
{
    if(tr[rt].l >=l && tr[rt].r <=r)
    {
        tr[rt].lazy += x;
        return;
    }
    int mid = (tr[rt].l + tr[rt].r) >>1;
    if(mid>=r) Segment_add(ls,l,r,x);
    else if(mid<l) Segment_add(rs,l,r,x);
    else 
    {
        Segment_add(ls,l,mid,x);
        Segment_add(rs,mid+1,r,x);
    }
    push_up(rt);
}

int Segment_Query(int rt, int l ,int r)
{
    if(tr[rt].l >=l && tr[rt].r <=r)
    {   
        return tr[rt].val;
    }
    int mid = (tr[rt].l + tr[rt].r)>>1;
    if(mid>=r) return Segment_Query(ls,l,r);
    else if(mid<l) return Segment_Query(rs,l,r);
    else return Segment_Query(ls,l,mid)+Segment_Query(rs,mid+1,r);
}
