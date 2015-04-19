
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-19 13:49:57
 |File Name: a.cpp
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
char s[100][100];
int n,m;
int w1[15],w2[15],w3[15];
int tot1,tot2,tot3;
int tp;
int righ, down;
void solve() {
    tot1 = 0; tot2 = 0; tot3 = 0;
    tp = n;
    while(tp > 0) {
        w1[tot1 ++] = tp % 10;
        tp /= 10;
    }
    tp = m;
    while(tp > 0) {
        w2[tot2 ++] = tp % 10;
        tp /= 10;
    }
    tp = n*m;
    while(tp > 0) {
        w3[tot3 ++] = tp % 10;
        tp /= 10;
    }
    righ = 2+4*tot1+2;
    down = 4 + tot2 * 4;
    s[0][0] = '+'; s[down][0] = '+';
    s[0][righ] = '+'; s[down][righ] = '+';
    srep(i,righ-1) {
        s[0][i] = '-';
        s[down][i] = '-';
    }
    srep(i,down-1) {
        s[i][0] = '|';
        s[i][righ] = '|';
    }
    rep(i,tot1) {
        s[1][4+i*4] = w1[tot1 - i - 1] + '0';
    }
    rep(i,tot2) {
        s[4 + i*4][righ - 1] = w2[tot2 - i - 1] + '0';
    }
    for(int i=2;i<down;i+=4) {
        for(int j=2;j<righ;j+=4) s[i][j] = '+';
    }
    for(int i=2;i<down;i+=4) {
        for(int j=2;j<=2+tot1*4;++j) {
            if(s[i][j] != '+') s[i][j] = '-';
        }
    }
    for(int i=2;i<righ;i+=4) {
        for(int j=2;j<=2+tot2*4;++j) {
            if(s[j][i] != '+') s[j][i] = '|';
        }
    }
    int t1 = tot1-1,t2 = tot2-1;
    for(int i=3;i<down-2;i+=4) {
        for(int j=3;j<righ-2;j+=4) {
            int tt = w1[t1 --] * w2[t2];
            int shi = tt / 10 + '0';
            int ge = tt % 10 + '0';
            s[i][j] = shi;
            s[i+2][j+2] = ge; 
        }
        t2 --;
        t1 = tot1 - 1;
    }
    for(int i=3;i<down-2;i+=4) {
        for(int j=5;j<righ;j+=4) {
            s[i][j] = '/';
            s[i+1][j-1] = '/';
            s[i+2][j-2] = '/';
        }
    }
    int ttt = tot3 - 1;
    int now = 1 + 4 * (tot1 - 1);
    while(ttt -- > 0) {
        s[down-1][now] = '/';
        now -= 4;
        if(now <= 0) break;
    }
    now = 3 + 4 * (tot2 - 1);
    while(ttt-- > 0) {
        s[now][1] = '/';
        now -= 4;
    }
    //rep(i,tot3) cout<<w3[i]<<" ";cout<<endl;
    ttt = tot3;
    tot3 --;
    now = 3 + 4 * (tot1 - 1);
    int tnow = 0;
    while(ttt -- > 0) {
        s[down-1][now] = w3[tnow++] + '0';
        now -= 4;
        if(now <= 0) break;
    }
    now = 5 + 4 * (tot2 - 1);
    while(ttt-- > 0) {
        s[now][1] = w3[tnow++] + '0';
        now -= 4;
    }



    //print
    rep(i,down+1) {
        rep(j,righ+1) {
            printf("%c",s[i][j]);
        }
        puts("");
    }



}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        if(n == 0 && m == 0) break;
        //clear
        rep(i,50) rep(j,50) s[i][j] = ' ';
        solve();

    }
	return 0;
}
