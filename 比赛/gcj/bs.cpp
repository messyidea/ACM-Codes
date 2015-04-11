/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/11 9:19:56
 |File Name: b.cpp
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
int x,l;
int ma[10005];
char s[10005];
int po[10005];
int ttto;
int main() {
	//freopen("C-small-attempt1.in","r",stdin); 
	//freopen("out2.out","w",stdout); 
    ma[11] = 1;
    ma[12] = 2;
    ma[13] = 3;
    ma[14] = 4;
    ma[21] = 2;
    ma[22] = -1;
    ma[23] = 4;
    ma[24] = -3;
    ma[31] = 3;
    ma[32] = -4;
    ma[33] = -1;
    ma[34] = 2;
    ma[41] = 4;
    ma[42] = 3;
    ma[43] = -2;
    ma[44] = -1;
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--) {
        printf("Case #%d: ",cas ++);
        scanf("%d %d",&l, &x);
        scanf("%s",s);
        rep(i,l) {
            if(s[i] == 'i') s[i] = 2;
            else if(s[i] == 'j') s[i] = 3;
            else s[i] = 4;
        }
        if(l * x < 3) {
            puts("NO");
            continue;
        }
        int now = 0,f = 0,tp,tot,tot2;
        ttto = 0;
        now = s[0];
        bool fg = false;
        if(now == 2) {
            fg = true;
            po[ttto++] = 0;
        }
        tp = x-1;
        tot = l;
        tot2 = l;
        while(tp -- > 0) {
            for(int i=0;i<tot2;++i) {
                s[tot ++] = s[i];
            }
        }
        //rep(i,tot) cout<<int(s[i])<<" ";cout<<endl;
        l = l * x;
        for(int i=1;i<l;++i) {
            now = ma[now*10+s[i]];
            tp = abs(now);
            if(now != tp) {
                now = tp;
                f ^= 1;
            }
            if(now == 2 && f == 0) {
                fg = true;
                po[ttto++] = i;
            }
        }
        //cout<<now<<"   "<<f<<endl;
        if(now != 1 || f != 1 || !fg) {
            puts("NO");
            continue;
        }
        now = s[l-1];
        f = 0;
        if(now == 4) {
            puts("YES");
            continue;
        }
        fg = false;
        for(int i=l-2;i>=0;--i) {
            now = ma[s[i]*10 + now];
            tp = abs(now);
            if(now != tp) {
                now = tp;
                f^= 1;
            }
            if(now == 4 && f == 0) {
                if(i > po[0]) {
                    fg = true;
                    break;
                } else {
                    fg = false;
                    break;
                }
            }
        }
        if(fg) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
	return 0;
}

