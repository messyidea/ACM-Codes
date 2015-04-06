
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-6 9:12:55
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
pair<int,int> pp[105];
int cou[105];
pair<int,int> pa[105];
vector <int> ve[105];
int fc[105];
int n;
int cf = 0;
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.second > b.second;
}
int solve(int t) {
    int sum = 0;
    int c2 = cf;
    int tot = 0;
    rep(i,n) {
        if(pa[i].first == 1) continue;
        if(pa[i].second < t) {
            rep(j,ve[pa[i].first].size()) {
                fc[tot ++] = ve[pa[i].first][j];
            }
            continue;
        }
        int cc = pa[i].second - t + 1;
        rep(j,ve[pa[i].first].size()) {
            if(j < cc) {
                sum += ve[pa[i].first][j];
                c2 ++;
            } else {
                fc[tot ++] = ve[pa[i].first][j];
            }
        }
    }
    if(c2 >= t) return sum;
    else {
        sort(fc,fc + tot);
        int ttt = t - c2;
        rep(i,ttt) sum += fc[i];
        return sum;
    }
    
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        rep(i,n+1) ve[i].clear();
        
        rep(i,n-1) scanf("%d",&pp[i].first);
        rep(i,n-1) {
            scanf("%d",&pp[i].second);
            ve[pp[i].first].push_back(pp[i].second);
        }
        srep(i,n) sort(ve[i].begin(),ve[i].end());
        memset(cou, 0, sizeof(cou));
        rep(i,n-1) cou[pp[i].first] ++;
        srep(i,n) {
            pa[i].first = i;
            pa[i].second = cou[i];
        }
        pa[0].first = 0;
        pa[0].second = 0;
        cf = pa[1].second;
        sort(pa,pa+n+1,cmp);
        int ans = inf;
        for(int i=2;i<=n-1;++i) {
            ans = min(ans,solve(i));
        }
        printf("%d\n",ans);


    }
	return 0; 
}
