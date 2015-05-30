/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/30 23:03:36
 |File Name: B.cpp
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
const double eps=1e-6 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
struct tt{
    double x,v;
};
tt t[105];
int n;
int m;
double x,v;
bool cmp(tt a,tt b) {
    return a.x < b.x;
}
int eq[105];
int eqtot;
int low[105];
int high[105];
int ltot;
int htot;
double cal(int a,int b) {
    double xx = x, vv = v;
    double vv1,xx1,vv2,xx2;
    xx1 = t[a].x; xx2 = t[b].x;
    vv1 = (vv*xx - vv*xx2)/(xx1-xx2);
    vv2 = vv - vv1;
    vv1 = vv1 / t[a].v;
    vv2 = vv2 / t[b].v;
    double ans1 = min(vv1,vv2);
    double ans = max(vv1,vv2);
    //cout<<"ans == "<<ans<<endl;
    if(ans1 < 0) return inf*1.0;
    else return ans;
}
int main() {
	freopen("B-small-attempt5.in","r",stdin); 
    //freopen("input.txt","r",stdin); 
	//freopen("out1.txt","w",stdout); 
	freopen("out6.txt","w",stdout); 
    int T;
    int cas = 1;
    cin>>T;
    while(T--) {
        printf("Case #%d: ",cas ++);
        eqtot = 0;
        ltot = 0;
        htot = 0;
        cin>>n>>v>>x;
        //cout<<v<<" "<<x<<endl;
        rep(i,n) {
            cin>>t[i].v>>t[i].x;
            //cout<<"      "<<t[i].v<<" "<<t[i].x<<endl;
        }
        /*if(n == 2) {
            tt tf;
            tf.v = t[0].v + t[1].v;
            tf.x = (t[0].v*t[0].x + t[1].v*t[1].x) / (t[0].v + t[1].v);
            t[n ++] = tf;
        }*/
        sort(t,t+n,cmp);
        if(t[0].x - x > eps) {
            puts("IMPOSSIBLE");
            continue;
        }
        int pos = -1;
        int eqtot = 0;
        for(int i=0;i<n;++i) {
            if(fabs(t[i].x - x) < eps) {
                eq[eqtot++] = i;
                continue;
            }
            if(t[i].x > x) {
                high[htot++] = i;
            } else {
                low[ltot++] = i;
            }
        }
        /*if(((htot == 0 || ltot == 0) && eqtot == 0)) {
            puts("IMPOSSIBLE");
            continue;
        }*/
        double ans = inf;
        /*for(int i=0;i<ltot;++i) {
            for(int j=0;j<htot;++j) {
                ans = min(ans,cal(low[i],high[j]));
            }
        }*/
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                double tp = cal(i,j);
                if(fabs(tp - inf) < eps) continue;
                else ans = min(ans,tp);
            }
        }
        for(int i=0;i<eqtot;++i) {
            ans = min(ans,v / t[eq[i]].v);
        }
        if(fabs(ans - inf) < eps || ans - inf*1.0 > 1) {
            puts("IMPOSSIBLE");
            continue;
        }
        printf("%.9lf\n",ans);

    }
	return 0;
}

