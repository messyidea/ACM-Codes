/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/6 20:33:29
 |File Name: b.cpp
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
int da[200005];
bool vis[1000005];
int pre[1000005];
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    scanf("%d",&n);
    rep(i,n) {
        scanf("%d",&da[i]);
    }
    memset(vis,false,sizeof(vis));
    sort(da,da+n);
    int nn = unique(da,da+n) - da;
    rep(i,nn) vis[da[i]] = true;
    int pr = 0;
    for(int i=1;i<=1000005;++i) {
        if(vis[i]) {
            pre[i] = pr;
            pr = i;
        } else {
            pre[i] = pr;
        }
    }
    int maxx = 0;
    int t = 0;
    int mm = pre[1000005] * 2 + 1;
    for(int i=0;i<nn;++i) {
        for(int j=2*da[i];j <= 1000005 && j <= mm;j += da[i]) {
            t = pre[j] % da[i];
            if(t > maxx) maxx = t;
        }
        maxx = max(maxx,pre[1000005] % da[i]);
    }
    printf("%d\n",maxx);
	return 0;
}

