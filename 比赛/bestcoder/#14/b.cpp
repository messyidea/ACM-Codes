/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/18 19:36:59
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
int ma[105][105];
pair<int,int> mm[100];
int tot;
struct tt{
    int p;
    int t;
    int n;
    bool operator < (tt b) const {
        return t > b.t;
    }
};
int bfs() {
    int ans = inf;
    priority_queue<tt> pq;
    tt tp;
    tp.p = 1;tp.t = 0;tp.n = 0;
    pq.push(tp);
    while(!pq.empty()) {
        tp = pq.top();
        pq.pop();
        if(tp.t > ans) return ans;
        if(tp.p	 == (1<<tot) - 1){
            //cout<<22<<"  "<<tp.t<<endl;
            int now =tp.t +  mm[tp.n].first + mm[tp.n].second;
            ans = min(ans,now);
            continue;
        } 
        for(int i=1;i<tot;++i) {
            if(tp.p & (1<<i)) continue;
            tt te;
            te.t = tp.t + abs(mm[i].first - mm[tp.n].first) + abs(mm[tp.n].second - mm[i].second);
            te.p = tp.p + (1<<i);
            te.n = i;
            pq.push(te);
        }
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int n,m;
    while(~scanf("%d %d",&n,&m)) {
        tot = 0;
        mm[tot ++] = make_pair(0,0);
        rep(i,n) {
            rep(j,m) {
                scanf("%d",&ma[i][j]);
                if(ma[i][j] > 0) {
                    if(i == 0 && j == 0) continue;
                    mm[tot ++] = make_pair(i,j);
                    //cout<<i<<" "<<j<<" "<<tot<<endl;
                }
            }
        }
        int rst = bfs();
        cout<<rst<<endl;
    }
    
	return 0;
}

