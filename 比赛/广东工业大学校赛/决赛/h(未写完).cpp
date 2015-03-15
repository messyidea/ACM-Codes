/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/15 16:14:08
 |File Name: h.cpp
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
int n,a,b,c,d,m;
int tot;
struct Ca{
    int k;
    int y;
    int c;
    int y2;
}ca[1000005];
bool cmp(Ca a,Ca b) {
    return a.y < b.y;
}
int da[1000000];
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        tot = 0;
        rep(i,n) {
            scanf("%d",&a);
            scanf("%d",&b);
            while(a -- ){
                scanf("%d",&c);
                ca[tot].k = b;
                ca[tot].y = 0;
                rep(i,c) {
                    scanf("%d",&d);
                    ca[tot].y += (1<<d);
                }
                ca[tot].y2 = ca[tot].y + (1 << b);
                scanf("%d",&ca[tot].c);
                tot++;
            }   
        }
        sort(ca,ca + tot,cmp);
        //for(int i=0;i<tot;++i) cout<<ca[i].y<<"  "<<ca[i].k<<"   "<<ca[i].y2<<endl;
        for(int i=0;i<=64;++i) da[i] = inf;
        da[0] = 0;
        for(int i=0;i<64;++i) {
            for(int j=0;j<tot;++j) {
                if(i >> ca[i].k & 1) continue;
                //cout<<i<<"  "<<ca[j].k<<endl;
                bool fg = true;
                int yy = ca[j].y;
                for(int k=0;k<6;++k){
                    if(!(ca[j].y >> k & 1)) continue;
                    if(!(i >> k & 1)) {
                        fg = false;
                        break;
                    }
                }
                if(fg) {
                    //cout<<11<<endl;
                    da[i + (1<<ca[i].k)] = min(da[i + (1<<ca[i].k)], da[i] + ca[i].c);
                    cout<<i + (1<<ca[i].k)<<"    "<<da[i + (1<<ca[i].k)]<<endl;
                }
            }
        }
        cout<<da[63]<<"  "<<da[64]<<endl;
        if(da[63] >= inf) {
            puts("-1");
        } else {
            printf("%d\n",da[63]);
        }
    }
	return 0;
}

