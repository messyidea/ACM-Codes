/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/9 14:13:08
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
vector<int> ma[505];
int mm[505];
int a,b;
int n,s;
int pq[100005];
bool vis[505];
int bfs() {
    int front = 0,rear = 0;
    pq[rear ++] = s;
    int t;
    int rst = 0;
    int now = 0;
    vis[s] = true;
    while(front < rear) {
        t = pq[front ++];
        vis[t] = true;
        bool fg = false;
        for(int i=0;i<ma[t].size();++i) {
            if(vis[ma[t][i]]) continue;
            fg = true;
            now += mm[ma[t][i]];
            pq[rear ++] = ma[t][i];
        }
        if(fg)
            now --;
        if(now < 0) {
            rst -= now;
            now = 0;
        }
    }
    return rst;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&s);
        srep(i,n) ma[i].clear();
        rep(i,n-1) {
            scanf("%d %d",&a,&b);
            ma[a].push_back(b);
            ma[b].push_back(a);
        }
        int sum = 0;
        srep(i,n) {
            scanf("%d",&mm[i]);
            vis[i] = false;
            sum += mm[i];
        }
        int rst = bfs();
        int ans = rst + sum - mm[s];
        printf("Case #%d: %d\n",cas ++, ans/ma[s].size());
    }
	return 0;
}

