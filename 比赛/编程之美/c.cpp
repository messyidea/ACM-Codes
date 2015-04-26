/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/26 14:16:21
 |File Name: c.cpp
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
struct edge{
    int v;
    int z;
    int s;
};
edge et;
vector<edge> ma[100005];
struct PP {
    ll l;   //bu tong
    ll r;   //xiang tong
    int m;
}pp[100005];
ll ans;
int n,m,q;
int que;
int aa,bb,cc,dd;
int main() {
//	freopen("input.txt","r",stdin); 
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        printf("Case #%d:\n", cas ++);
        ans = 0;
        scanf("%d %d %d",&n,&m,&q);
        srep(i,n) {
            pp[i].l = 0;
            pp[i].r = 0;
            ma[i].clear();
            scanf("%d",&pp[i].m);
        }
        rep(i,m) {
            scanf("%d %d %d",&aa,&bb,&cc);
            et.v = bb; et.z = cc; et.s = ma[bb].size();
            ma[aa].push_back(et);
            et.v = aa;et.s = ma[aa].size()-1;
            ma[bb].push_back(et);
            if(pp[aa].m != pp[bb].m) {
                ans += cc;
                pp[aa].l += cc;
                pp[bb].l += cc;
            } else {
                pp[aa].r += cc;
                pp[bb].r += cc;
            }
        }
        while(q --) {
            scanf("%d",&que);
            if(que == 1) {
                scanf("%d",&aa);
                ans -= pp[aa].l;
                ans += pp[aa].r;
                swap(pp[aa].l,pp[aa].r);
                for(int i=0;i<ma[aa].size();++i) {
                    if(pp[ma[aa][i].v].m != pp[aa].m) {
                        pp[ma[aa][i].v].l -= ma[aa][i].z;
                        pp[ma[aa][i].v].r += ma[aa][i].z;
                    } else {
                        pp[ma[aa][i].v].l += ma[aa][i].z;
                        pp[ma[aa][i].v].r -= ma[aa][i].z;
                    }
                }
                pp[aa].m ^= 1;
            } else if(que == 3) {
                printf("%lld\n",ans);
            } else if(que == 2) {
                scanf("%d %d %d",&aa,&bb,&cc);
                //cout<<aa<<"  "<<bb<<"  "<<cc<<endl;
                
                if(ma[aa].size() > ma[bb].size()) swap(aa,bb);
                bool fg = false;
                rep(i,ma[aa].size()) {
                    if(ma[aa][i].v == bb) {
                        fg = true;
                        if(pp[aa].m != pp[bb].m) {
                            int ttt = cc - ma[aa][i].z;
                            ans += cc - ma[aa][i].z;
                            ma[aa][i].z = cc;
                            ma[bb][ma[aa][i].s].z = cc;
                            pp[aa].l += ttt;
                            pp[bb].l += ttt;
                        } else {
                            int ttt = cc - ma[aa][i].z;
                            pp[aa].r += ttt;
                            pp[bb].r += ttt;
                            ma[aa][i].z = cc;
                            ma[bb][ma[aa][i].s].z = cc;    
                        }
                        
                    }
                }
                if(!fg) {
                    et.v = bb; et.z = cc; et.s = ma[bb].size();
                    ma[aa].push_back(et);
                    et.v = aa; et.s = ma[aa].size() - 1;
                    ma[bb].push_back(et);
                    if(pp[aa].m != pp[bb].m) {
                        pp[aa].l += cc;
                        pp[bb].l += cc;
                        ans += cc;
                    } else {
                        pp[aa].r += cc;
                        pp[bb].r += cc;
                    }
                }
            } 
        }

    }
	return 0;
}

