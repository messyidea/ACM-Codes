/***********************************************\
 |Author: YMC
 |Created Time: 2015/7/18 16:03:18
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
int ma[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int mb[20] = {9, 9 ,9 ,9, 1, 2, 3, 9};
char s[100];
int n, nn, t;
int yy, mm, dd;
int y , m, d, tp;
void callyy(int ttt) {
    int now = 0;
    for(int i=0;i<4;++i) now += ma[s[i] - '0'];
    for(int i = y + 1;i <= 2999; ++i) {
        int a1 = i / 1000;
        int a2 = i / 100 %10;
        int a3 = i / 10 % 10;
        int a4 = i % 10;
        int sum = 0;
        sum += ma[a1] + ma[a2] + ma[a3] + ma[a4];
        if(sum - now >= ttt) return i;
    }
    return -1;
}
void solve() {
    y = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0')*1;
    m = (s[4]-'0') * 10 + (s[5] - '0') * 1;
    d = (s[6]-'0') * 10 + (s[7] - '0') * 1;
    t = 0;
    for(int i=0;i<8;++i) t += ma[s[i] - '0'];
    nn = n - t;
    if(nn > 26) {
        tp = nn - 26;
        int ans = calyy(tp);
        if(ans < 0) {
            puts("-1");
            return ;
        } else {
            ans
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s);
        scanf("%d",&n);
        solve();
    }
	return 0;
}

