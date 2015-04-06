
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-6 12:53:20
 |File Name: f.cpp
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
#define srep(i,n) for(int int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n,m,k;
int ma[150][150];
int a,b;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m,&k);
        memset(ma,0,sizeof(ma));
        rep(i,m) {
            scanf("%d %d",&a,&b);
            ma[a][b] = 1;
            ma[b][a] = 1;
        }
        
        int ans = 0;
        if(k == 0) {
            ans = n * (n-1) / 2 - m;
            printf("%d\n",ans);
            continue;
        }
        bool fg2;
        while(true) {
            fg2 = false;
            for(int i=0;i<n;++i) {
                for(int j=i+1;j<n;++j) {
                    if(ma[i][j] == 0) {
                        bool fg = false;
                        int count = 0;
                        for(int a=0;a<n;++a) {
                            if(a == i || a == j) continue;
                            if(ma[i][a]==1 && ma[j][a]==1) {
                                count++;
                                if(count >= k) {
                                    fg = true;
                                    break;
                                }
                            }
                            
                        }
                        if(fg) {
                            fg2 = true;
                            ma[i][j] = 1;
                            ma[j][i] = 1;
                            ans ++;
                        }
                    }
                }
            }
            if(!fg2) break;
        }
        printf("%d\n",ans);
    }
	return 0;
}
