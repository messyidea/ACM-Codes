/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-23 15:31:57
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
map<int,int> ma;
pair<int,int> pa[200005];
int que[200004];
int qq[200005];
int tot;
int n,m;
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.second >= b.second;
}
bool cmp2(int a,int b) {
    return a >= b;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--) {
        scanf("%d %d",&n,&m);
        ma.clear();
        tot = 0;
        rep(i,n) {
            scanf("%d %d",&pa[i].first,&pa[i].second);
            if(pa[i].first > pa[i].second) swap(pa[i].first,pa[i].second);
        }
        rep(i,m) {
            scanf("%d",&que[i]);
            qq[i] = que[i];
        }
        sort(qq,qq + m);
        sort(pa,pa + n);
        int to = 0;
        while(qq[to] < pa[0].first) to ++;
        for(int i=0;i<n;++i) {
            double mid = (pa[i].first + pa[i].second) * 1.0 / 2;
            int ff = pa[i].first;
            double tt = mid;
            while(qq[to] < pa[i].first) to ++;
            while(to < m && ff <= qq[to] && tt + eps >= qq[to]) {
                ma[qq[to]] = max(ma[qq[to]],qq[to] - ff);
                to ++;
            }
        }
        sort(pa,pa + n,cmp);
        sort(qq,qq + m,cmp2);
        to = 0;
        while(qq[to] > pa[0].second) to ++;
        for(int i=0;i<n;++i) {
            double mid = (pa[i].first + pa[i].second) * 1.0 / 2;
            int ff = pa[i].second;
            double tt = mid;
            while(qq[to] > pa[i].second) to ++;
            while(to < m && ff >= qq[to] && tt - eps <= qq[to]) {
                ma[qq[to]] = max(ma[qq[to]],ff - qq[to]);
                to ++;
            }
        }
        printf("Case %d:\n",cas ++);
        for(int i=0;i<m;++i) {
            printf("%d\n",ma[que[i]]);
        }
    }
	return 0;
}
