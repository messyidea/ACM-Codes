/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/2 12:39:24
 |File Name: d.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
char ma[100][100];
int hang[100][100];
int lie[100][100];
#define len 2505
int l,r,u,d;
int n,m;
int nn,mm;
int map[len][len];
int used[len];
int lin[len];
int dfs(int a)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!used[i]&&map[a][i])
        {
            used[i]=1;
            if(lin[i]==-1||dfs(lin[i]))
            {
                lin[i]=a;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&nn,&mm);
        rep(i,nn) scanf("%s",ma[i]);
        int ans = 0;
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        int id = 1;
        int t1,t2;
        rep(i,nn) {
            rep(j,mm) {
                if(ma[i][j] != '#') hang[i][j] = id;
                else id ++;
            }
            id ++;
        }
        t1 = id;
        id = 1;
        
        rep(i,mm) {
            rep(j,nn) {
                if(ma[j][i] != '#') lie[j][i] = id;
                else id ++;
            }
            id ++;
        }
        t2 = id;
        n = max(t1,t2);
        memset(map,0,sizeof(map));
        memset(lin,-1,sizeof(used));
        rep(i,nn) {
            rep(j,mm) {
                if(ma[i][j] == '*') {
                    map[hang[i][j]][lie[i][j]] = 1;
                }
            }
        }
        
        int sum = 0;
        for(int i=1;i<=n;++i) {
            memset(used,0,sizeof(used));
            if(dfs(i)) sum++;
        }
        printf("%d\n",sum);
    }
	return 0;
}

