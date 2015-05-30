/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/30 22:00:17
 |File Name: A.cpp
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
char ss[105][105];
int n,m;
char s[4] = {'^','>','v','<'};
int la[4] = {2,3,0,1};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool vis[105][105];
bool check(int x,int y) {
    if(x<0 || x>=n) return false;
    if(y<0 || y>=m) return false;
    return true;
}
int tra(int x,int y) {
    memset(vis,false,sizeof(vis));
    int d;
    for(int i=0;i<4;++i) {
        if(ss[x][y] == s[i]) d=i;
    }
    vis[x][y] = true;
    bool flag = false;
    pair<int,int> last = MP(x,y);
    int lastd = la[d];
    bool one = true;
    while(1) {
        x += dx[d];
        y += dy[d];
        if(check(x,y)) {
            if(vis[x][y] == true) {
                flag = true;
                one = false;
                break;
            }
            if(ss[x][y] != '.') {
                last=MP(x,y);
                lastd = la[d];
                for(int i=0;i<4;++i) {
                    if(ss[x][y] == s[i]) d = i;
                }
            }
            vis[x][y] = true;
        } else {
            break;
        }
    }
    if(flag) return 0;
    else {
        if(one) {
            x = last.first,y = last.second;
            bool ff = false;
            for(int i=0;i<x;++i) {
                if(ss[i][y] != '.') {
                    ff = true;
                    break;
                }
            }
            if(ff) {
                ss[x][y] = '^';
                return 1+tra(x,y);
            } 
            for(int i=x+1;i<n;++i) {
                 if(ss[i][y] != '.') {
                    ff = true;
                    break;
                }
            }
            if(ff) {
                ss[x][y] = 'v';
                return 1+tra(x,y);
            } 
             for(int i=0;i<y;++i) {
                 if(ss[x][i] != '.') {
                    ff = true;
                    break;
                }
            }
            if(ff) {
                ss[x][y] = '<';
                return 1+tra(x,y);
            } 
             for(int i=y+1;i<m;++i) {
                 if(ss[x][i] != '.') {
                    ff = true;
                    break;
                }
            }
            if(ff) {
                ss[x][y] = '>';
                return 1+tra(x,y);
            } 




        } else {
            ss[last.first][last.second] = s[lastd];
            return 1;
        }
    }
}
bool solve() {
    bool flag = true;
    for(int i=0;i<n;++i) {
        rep(j,m) {
            if(ss[i][j] == '.') continue;
            bool fg = false;
            rep(ii,n) {
                if(ii == i) continue;
                if(ss[ii][j] != '.') {
                    fg = true;
                    break;
                }
            }
            if(fg) break;
            rep(jj,m) {
                if(jj == j) continue;
                if(ss[i][jj] != '.') {
                    fg = true;
                    break;
                }
            }
            if(fg) break;
            else return false;
        }
    }
    int count = 0;
    rep(i,n) {
        rep(j,m) {
            if(ss[i][j] == '.') continue;
            count += tra(i,j);
        }
    }
    printf("%d\n",count);
    return true;
}
int main() {
	freopen("A-large.in","r",stdin); 
	//freopen("input.txt","r",stdin); 
	freopen("out2.txt","w",stdout); 
    int cas = 1;
    int T;
    scanf("%d",&T);
    while(T--) {
        printf("Case #%d: ",cas ++);
        scanf("%d %d",&n,&m);
        rep(i,n) {
            scanf("%s",ss[i]);
        }

        /*puts("");
        rep(i,n) {
            puts(ss[i]);
        }
        puts("");*/

        if(!solve()) {
            puts("IMPOSSIBLE");
        }
        /*puts("");
        rep(i,n) {
            puts(ss[i]);
        }
        puts("");*/
    }
	return 0;
}

