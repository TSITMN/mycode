#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX_V = 100;
int d[MAX_V][MAX_V];
int vertex;

void floyd_warshall()
{
    for(int i=1 ; i<=vertex ; ++i)
    {
        for(int j=1 ; j<=vertex ; ++j)
        {
            for(int k=1 ; j<=vertex ; ++k)
            {
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
            }
        }
    }
}