/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-25 12:29:11
 |File Name: A_Very_Simple_Problem.cpp
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
int da[505];
int aa[505];
int bb[505];
int t1,t2;
bool cmp(int a,int b) {
    return a > b;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int ls,rs;
    int lc,rc;
    int n;
    while(T--) {
        scanf("%d",&n);
        ls = 0;
        rs = 0;
        lc = 0; rc = 0;
        t1 = 0; t2 = 0;
        rep(i,n) {
            scanf("%d",&da[i]);
            if(da[i] < 0) {
                ls -= da[i];
                lc ++;
                aa[t1 ++] = da[i];
                
            }
            else {
                rs += da[i];
                rc ++;
                bb[t2 ++] = da[i];
            }
        }
        sort(da,da + n);
        int ans = 0;
        if(da[0] < 0 && da[n-1] > 0)
            //printf("%d\n",min(ls + (-da[0] * 2) * rc + rs, rs + da[n-1] * 2 * lc + ls));
            ans = min(ls + (-da[0] * 2) * rc + rs, rs + da[n-1] * 2 * lc + ls);
        else if(da[0] >= 0) {
            //printf("%d\n",rs);
            ans = rs;
        } else {
            //printf("%d\n",ls);
            ans = ls;
        }
        int ans2 = 0;
        int p = 0;
        int tt1 = 0,tt2 = 0;
        int now = 0;
        sort(aa,aa + t1,cmp);
        sort(bb,bb + t2);
        while(tt1 < t1 || tt2 < t2) {
            if(tt1 < t1 && tt2 < t2) {
            if(abs(aa[tt1] - p) < abs(bb[tt2] - p)) {
                now += abs(aa[tt1] - p);
                p = aa[tt1];
                tt1 ++;
                ans2 += now;
            } else {
                now += abs(bb[tt2] - p);
                p = bb[tt2];
                tt2 ++;
                ans2 += now;
            }
            } else if(tt1 < t1) {
                for(int i=tt1;i<t1;++i) {
                    now += abs(aa[tt1] - p);
                    ans2 += now;
                    p = aa[tt1];
                    tt1 ++;
                }
                break;
            } else {
                for(int i=tt2;i<t2;++i) {
                    now += abs(bb[tt2] - p);
                    ans2 += now;
                    p = bb[tt2];
                    tt2 ++;
                }
                break;
            }
        }
        ans = min(ans,ans2);
        printf("%d\n",ans);
    }
	return 0;
}

