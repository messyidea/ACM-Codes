/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-26 12:20:21
 |File Name: Robbers.cpp
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
int da[1005];
double db[1005];
int ans[1005];
int st[1005];
int tot = 0;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int n,m,y;
    while(~scanf("%d",&T)) {
        while(T--) {
            tot = 0;
            scanf("%d %d %d",&n,&m,&y);
            srep(i,n) scanf("%d",&da[i]);
            srep(i,n) db[i] = da[i] * 1.0 / y *1.0 * m;
            srep(i,n) ans[i] = db[i] + 0.5;
            srep(i,n) if(fabs(db[i] - int(db[i]) - 0.5) < eps) {
                st[tot ++] = i;
            }
            for(int i=0;i<tot;i+=2) ans[st[i]] --;
            printf("%d",ans[1]);
            for(int i=2;i<=n;++i) printf(" %d",ans[i]);
            puts("");

        }
    }
	return 0;
}

