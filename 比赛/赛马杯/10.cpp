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
int aa,bb,cc;
int da[1005];
int check(int l,int r) {
    int minn = inf;
    for(int i=l;i<=r;++i) minn = min(da[i],minn);
    return minn;
}
bool solve(int l,int r,int a) {
    int minn = check(l,r);
    if(minn == a) {
        return true;
    } else if(minn == 0) {
        for(int i=l;i<=r;++i) {
            if(da[i] != 0) {
                if(da[i] % a == 0) continue;
                else {
                    return false;
                }
            } else da[i] = a;
        }
    } else if(minn < a) {
        for(int i=l;i<=r;++i) {
            if(da[i] < a) {
                if()
            }
        }
    }

    return true;

}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        memset(da,0,sizeof(da));
        bool fg = true;
        while(m --) {
            scanf("%d %d %d",&aa,&bb,&cc);
            if(fg){
                cout<<"hehe"<<endl;
                fg = solve(aa,bb,cc);
            }
            else {
                continue;
            }
        }
        if(fg) {
            printf("%d",da[1]);
            for(int i=2;i<=n;++i)  {
                printf(" %d",da[i]);
            }
            puts("");
        } else {
            puts("Stupid BrotherK!");
        }
    }
	return 0;
}

