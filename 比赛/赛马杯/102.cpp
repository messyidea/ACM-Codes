/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/2 13:00:02
 |File Name: 10.cpp
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
int n,m;
int da[1005];
int aa[1005],bb[1005],cc[1005];
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a%b);
}
int check(int a,int b,int c) {
    int t = da[a];
    for(int i=a+1;i<=b;++i) {
        t = gcd(t,da[i]);
    }
    if(t == c) return true;
    else return false;
}
int main() {
	//freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        memset(da,0,sizeof(da));
        rep(i,m) {
            scanf("%d %d %d",&aa[i],&bb[i],&cc[i]);
            for(int j=aa[i];j<=bb[i];++j) {
                if(da[j] == 0){
                    da[j] = cc[i];
                    continue;
                }
                int gc = gcd(da[j],cc[i]);
                
                da[j] = (da[j]/gc) * cc[i];
            }
        }
        srep(i,n) if(da[i] == 0) da[i] = 1;
        //srep(i,n) cout<<da[i]<<" ";cout<<endl;
        bool fg = true;
        rep(i,m) {
            if(!check(aa[i],bb[i],cc[i])) {
                fg = false;
                break;
            }
        }
        if(fg) {
            printf("%d",da[1]);
            for(int i=2;i<=n;++i) {
                printf(" %d",da[i]);
            }
            puts("");
        } else {
            puts("Stupid BrotherK!");
        }
    }
	return 0;
}

