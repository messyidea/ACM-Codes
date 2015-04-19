
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-19 12:15:59
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
int n,m;
char s[22][22];
int sx,sy;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dnow;
int nx,ny;
int cas = 1;
void solve() {
    nx = sx; ny = sy;
    while(s[nx][ny] != 'x') {
        nx += dx[dnow];
        ny += dy[dnow];
        if(s[nx][ny] == '/') {
            if(dnow == 0) dnow =3;
            else if(dnow == 1) dnow = 2;
            else if(dnow == 2) dnow = 1;
            else dnow = 0;
        } else if(s[nx][ny] == '\\') {
            if(dnow == 0) dnow = 1;
            else if(dnow == 1) dnow = 0;
            else if(dnow == 2) dnow = 3;
            else dnow = 2;
        }
    }
    s[nx][ny] = '&';
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        if(n == 0 && m == 0) break;
        rep(i,m) {
            scanf("%s",s[i]);
            rep(j,n) {
                if(s[i][j] == '*') {
                    sx = i;sy = j;
                }
            }
        }
        if(sx == 0) dnow = 0;
        else if(sx == m-1) dnow = 2;
        if(sy == 0) dnow = 1;
        else if(sy == n-1) dnow = 3;
        solve();
        printf("HOUSE %d\n",cas ++);
        rep(i,m) {
            printf("%s\n",s[i]);
        }
    }
	return 0;
}
