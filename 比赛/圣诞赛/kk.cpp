/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 21:36:50
 |File Name: kk.cpp
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
int a,b,c;
int aa[1005];
int bb[1005];
int cc[1005];
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d%d%d",&a,&b,&c) != EOF) {
        for(int i=0;i<a;++i) {
            scanf("%d",&aa[i]);
        }
        for(int i=0;i<b;++i) {
            scanf("%d",&bb[i]);
        }
        for(int i=0;i<c;++i) {
            scanf("%d",&cc[i]);
        }
        sort(aa,aa + a);
        sort(bb,bb + b);
        sort(cc,cc + c);
        int tot;
        int p;
        int ans = 0;
        for(int i=0;i<a;++i) {
            tot = 0;
            p = 0;
            for(int j=0;j<b;++j) {
                if(j > 0 && bb[j] == bb[j-1]) {
                    ans += p;
                    continue;
                }
                p = 0;
                int tt = aa[i] + bb[j];
                while(tot < c && cc[tot] < tt) tot ++;
                while(tot < c && cc[tot] == tt) {
                    p ++;
                    tot ++;
                }
                ans += p;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
