/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/14 19:34:09
 |File Name: K-Nice.cpp
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
#include <map>
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
int da[20][20];
int vis[20][20];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m,k;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m,&k);
        memset(vis,0,sizeof(vis));
        memset(da,0,sizeof(da));
        for(int i=2;i<=n-1;++i) {
            for(int j=2;j<=m-1;++j) {
                if(k == 0) goto fin;
                vis[i][j] = 2;
                k--;
            }
        }
fin:
        /*srep(i,n) {
            srep(j,m) cout<<vis[i][j]<<" ";cout<<endl;
        }*/
        for(int i=2;i<=n-1;++i) {
            for(int j=2;j<=m-1;++j) {
                if(vis[i][j] == 2) {
                    rep(k,4) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if(vis[xx][yy] == 0) {
                            vis[xx][yy] = 1;
                        }
                    }
                }
            }
        }
        int tot = 1;
        srep(i,n) {
            srep(j,m) {
                if(vis[i][j] == 0) {
                    da[i][j] = tot++;
                }
            }
        }
        srep(i,n) {
            if(vis[i][1] == 0) {
                printf("%d",da[i][1]);
            } else printf("%d",0);
            for(int j=2;j<=m;++j) {
                if(vis[i][j] == 0) {
                    printf(" %d",da[i][j]);
                } else printf(" %d",0);
            }
            puts("");
        }

    }
	return 0;
}

