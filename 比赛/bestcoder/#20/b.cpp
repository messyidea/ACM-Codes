/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/29 19:06:40
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
int num[200005];
pair<int,int> pp[100005];
int tot;
int t2;
int n,a,b;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        tot = 0;
        t2 = 0;
        rep(i,n) {
            scanf("%d %d",&a,&b);
            num[tot ++] = a;
            num[tot ++] = b;
            pp[i] = make_pair(a,b); 
        }
        sort(num,num + tot);
        tot = unique(num,num+tot) - num;
        memset(da,0,sizeof(da));
        rep(i,n) {
            int l = lower_bound(num,num + tot,pp[i].first) - num;
            int r = lower_bound(num,num + tot,pp[i].second) - num;
            da[l] += 1;
            da[r + 1] -= 1;
        }
        int sum = 0;
        int maxn = 0;
        for(int i=0;i<=tot+1;++i) {
            sum += da[i];
            if(sum > maxn) maxn = sum;
        }
        printf("%d\n",maxn);
    }
	return 0;
}

