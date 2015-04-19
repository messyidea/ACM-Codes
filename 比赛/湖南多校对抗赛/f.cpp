
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-19 12:45:23
 |File Name: F.cpp
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
#define srep(i,n) for(int int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char s[55][55];
int n,m;
pair<pair<int,int>,int> start[10];
int tot = 0;
int m2n[155];
int vis[55][55];
bool flag,flag2;
bool getstart() {
    tot = 0;
    rep(i,m) {
        if((m2n[s[0][i]] & 8) == 0) {
            start[tot ++] = MP(MP(0,i),0);
            if(tot >= 3) return false;
        }
        if((m2n[s[n-1][i]] & 2) == 0) {
            start[tot ++] = MP(MP(n-1,i),2);
            if(tot >= 3) return false;
        }
    }
    rep(i,n) {
        if((m2n[s[i][0]] & 1) == 0) {
            start[tot ++] = MP(MP(i,0),1);
            if(tot >= 3) return false;
        }
        if((m2n[s[i][m-1]] & 4) == 0) {
            start[tot ++] = MP(MP(i,m-1),3);
            if(tot >= 3) return false;
        }
    }
    if(tot != 2) return false;
    return true;
}
bool isok(int x,int y) {
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    return true;
}
void dfs(int x,int y,int d) {
    //if(!flag) return ;
    vis[x][y] = d;
    int t = m2n[s[x][y]];
    if((t & 1) == 0) {
        int xx = x;
        int yy = y - 1;
        if(isok(xx,yy)) {
            if(vis[xx][yy] != 0 && abs(d - vis[xx][yy]) > 1) {
                flag = false;
            }
            if(!vis[xx][yy]) {
                dfs(xx,yy,d+1);
            }
        }
    }
    if((t & 2) == 0) {
        int xx = x + 1;
        int yy = y;
        if(isok(xx,yy)) {
            if(vis[xx][yy] != 0 && abs(d - vis[xx][yy]) > 1) {
                flag = false;
            }
            if(!vis[xx][yy]) {
                dfs(xx,yy,d+1);
            }
        }
    }
    if((t & 4) == 0) {
        int xx = x;
        int yy = y + 1;
        if(isok(xx,yy)) {
            if(vis[xx][yy] != 0 && abs(d - vis[xx][yy]) > 1) {
                flag = false;
            }
            if(!vis[xx][yy]) {
                dfs(xx,yy,d+1);
            }
        }
    }
    if((t & 8) == 0) {
        int xx = x-1;
        int yy = y;
        if(isok(xx,yy)) {
            if(vis[xx][yy] != 0 && abs(d - vis[xx][yy]) > 1) {
                flag = false;
            }
            if(!vis[xx][yy]) {
                dfs(xx,yy,d+1);
            }
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    m2n['0'] = 0; m2n['1'] = 1; m2n['2'] = 2;
    m2n['3'] = 3; m2n['4'] = 4; m2n['5'] = 5;
    m2n['6'] = 6; m2n['7'] = 7; m2n['8'] = 8;
    m2n['9'] = 9; m2n['A'] = 10; m2n['B'] = 11;
    m2n['C'] = 12; m2n['D'] = 13; m2n['E'] = 14;
    m2n['F'] = 15;
    bool fg;
    while(scanf("%d %d",&n,&m) != EOF) {
        if(n == 0 && m == 0) break;
        flag = true;
        rep(i,n) {
            scanf("%s",s[i]);
        }
        fg = getstart();
        if(!fg) {
            puts("NO SOLUTION");
            continue;
        }
        memset(vis,0,sizeof(vis));
        int sx = start[0].first.first;
        int sy = start[0].first.second;
        dfs(sx,sy,1);
        int ssx = start[1].first.first;
        int ssy = start[1].first.second;
        if(vis[ssx][ssy] == 0) {
            puts("NO SOLUTION");
            continue;
        }
        flag2 = true;
        rep(i,n) {
            rep(j,m) {
                //cout<<vis[i][j]<<"  ";
                if(vis[i][j] == 0) flag2 = false;
            }
            //cout<<endl;
        }
        if(!flag2) {
            puts("UNREACHABLE CELL");
            continue;
        }

        if(!flag) {
            puts("MULTIPLE PATHS");
            continue;
        }

        puts("MAZE OK");
         
    }
	return 0;
}
