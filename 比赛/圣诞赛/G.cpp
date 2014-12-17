/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 12:49:59
 |File Name: e.cpp
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
int me[105];
int n,m;
char c;
char cc[105];
int tot;
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        tot = 1;
        memset(me,0,sizeof(me));
        me[m+1] = inf;
        rep(ii,n) {
            scanf("%s",&cc);
            c = cc[0];
            //cout<<c<<endl;
            int cou = 0;
            int tt;
            int pre = -1;
            if(c == 'A') {
                scanf("%d",&tt);
                bool fg = false;
                for(int i=1;i<=m+1;++i) {
                    if(me[i] != 0) {
                        if(cou >= tt) {
                            printf("%d\n",tot);
                            for(int j = pre;j < pre + tt;++j) {
                                me[j] = tot;
                            }
                            tot ++;
                            fg = true;
                            break;
                        } else {
                            cou = 0;
                            pre = -1;
                        }
                    }
                    if(me[i] == 0) {
                        if(pre == -1) pre = i;
                        cou ++;
                        continue;
                    }
                }
                if(!fg) {
                    puts("NULL");
                } 
            }else if(c == 'D') {
                bool fg = false;
                int pre = -1;
                int p = -1;
                int cou = 0;
                for(int i=1;i<=m;++i) {
                    if(me[i] == 0) {
                        fg = true;
                        if(pre == -1) pre = i;
                    } else if(fg){
                        p = me[i];
                        
                        for(int j=i;j<=m;++j) {
                            if(me[j] == p) cou++;
                            else break;
                        }
                        for(int j=i;j<=m;++j) {
                            if(me[j] == p) me[j] = 0;
                            else break;
                        }
                        for(int j=pre;j<pre + cou;++j) {
                            me[j] = p;
                        }
                        i = pre + cou - 1;
                        pre = -1;
                        fg = false;
                        cou = 0;
                    }
                }
            } else if(c == 'E'){
                bool fg = false;
                scanf("%d",&tt);
                if(tt == 0) {
                    puts("ILLEGAL OPERATION");
                    continue;
                }
                for(int i=1;i<=m;++i) {
                    if(me[i] == tt) {
                        me[i] = 0;
                        fg = true;
                    }
                }
                if(!fg) {
                    puts("ILLEGAL OPERATION");
                }
            }
            //srep(i,m) cout<<me[i]<<" ";cout<<endl;
        }
    }
	return 0;
}

