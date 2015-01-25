/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-25 14:10:53
 |File Name: a_simple.cpp
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
int n;
int da[404];
int ls[404],rs[404];
int t1,t2;
bool cmp(int a,int b) {
    return a > b;
}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        t1 = 0;t2 = 0;
        srep(i,n) {
            scanf("%d",&da[i]);
            if(da[i] < 0) ls[t1 ++] = da[i];
            else if(da[i] > 0) rs[t2 ++] = da[i];
        }
        sort(ls,ls + t1,cmp);
        sort(rs,rs + t2);
        int p = 0;
        int tt1,tt2;
        tt1 = 0; tt2 = 0;
        int now = 0;
        int sum = 0;
        while(tt1 < t1 || tt2 < t2) {
            if(tt1 < t1 && tt2 < t2) {
                if(abs(p - ls[tt1]) * ((t2 - tt2) )  < abs(p - rs[tt2]) * ((t1 - tt1) )) {
                    now += abs(p - ls[tt1]);
                    p = ls[tt1];
                    sum += now;
                    tt1 ++;
                } else {
                    now += abs(p - rs[tt2]);
                    p = rs[tt2];
                    sum += now;
                    tt2 ++;
                }
            } else if(tt1 < t1) {
                for(int i=tt1;i<t1;++i) {
                    now += abs(ls[tt1] - p);
                    sum += now;
                    p = ls[tt1];
                    tt1 ++;
                }
                break;
            } else {
                for(int i=tt2;i<t2;++i) {
                    now += abs(rs[tt2] - p);
                    sum += now;
                    p = rs[tt2];
                    tt2 ++;
                }
                break;
            }
        }
        printf("%d\n",sum);
    }
	return 0;
}

