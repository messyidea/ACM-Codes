/***********************************************\
 |Author: YMC
 |Created Time: 2015/1/18 20:56:55
 |File Name: a.cpp
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
int n,d,tp;
int mm;
int da[30004];
int sum[30004];
int maxsum;
void dfs(int now,int d,int nows) {
    if(now > mm) {
        if(nows > maxsum) maxsum = nows;
        return ;
    }
    if(d <= 2) {
        if(nows + sum[now] > maxsum) maxsum = nows;
        return ;
    }
    if(nows + sum[now] <= maxsum) return ;
    dfs(now + d,d,nows + da[now]);
    dfs(now + d + 1, d + 1, nows + da[now]);
    dfs(now + d - 1, d - 1, nows + da[now]);
}
int main() {
	freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&d) != EOF) {
        memset(da,0,sizeof(da));
        memset(sum,0,sizeof(sum));
        srep(i,n) {
            scanf("%d",&tp);
            if(mm < tp) mm = tp;
            da[tp] ++;
        }
        for(int i=mm;i>=0;--i) sum[i] = da[i] + sum[i+1];
        maxsum = 0;
        dfs(d,d,da[0]);
        printf("%d\n",maxsum);
    }
	return 0;
}

