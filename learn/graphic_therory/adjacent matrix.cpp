#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
struct Matrix
{
    int r ,  c;
    int v[MAXN][MAXN];
    Matrix(int rr , int cc)
    {
        r = rr , c = cc;
        memset(v,0,sizeof(v));
    }
    int *operator[](int n)
    {
        return v[n];
    }
    Matrix operator*(Matrix& others)
    {
        Matrix ans(r,others.c);
        for(int i=1 ; i<=r ; ++i)
        {
            for(int j=1 ; j<=c ; ++j)
            {
                for(int k=1 ; k<=others.c ; ++k)
                {
                    ans[i][k] = ans[i][k] + v[i][j] * others[j][k];
                }
            }
        }
        return ans;
    }
};