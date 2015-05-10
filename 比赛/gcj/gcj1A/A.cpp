/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/18 9:45:31
 |File Name: A.cpp
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
int da[1005];
int ans1,ans2;
int mtp = 0,tp;
int main() {
	freopen("A-large.in","r",stdin); 
	freopen("out.txt","w",stdout); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--) {
        ans1 = 0; ans2 = 0;
        scanf("%d",&n);
        rep(i,n) scanf("%d",&da[i]);
        mtp = 0;
        for(int i=1;i<n;++i) {
            tp = da[i-1] - da[i];
            if(tp > 0) {
                mtp = max(mtp,tp);
                ans1 += tp;
            }
        }
        for(int i=0;i<n-1;++i) {
            if(da[i] > mtp) ans2 += mtp;
            else ans2 += da[i];
        }
        printf("Case #%d: %d %d\n",cas++,ans1,ans2);
    }
	return 0;
}

