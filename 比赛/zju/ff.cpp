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
int p;
int sx,sy,ex,ey;
int now;
char ma[55][55];
bool vis[15][15][4][55];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
struct point{
    int x,y;
    int d,n;
    bool operator < (const point b) const {
        return d > b.d;
    }
};
priority_queue<point> pq;
bool isok(int xx,int yy) {
    if(xx <= 0 || xx > n) return false;
    if(yy <= 0 || yy > m) return false;
    if(ma[xx][yy] == '*') return false;
    return true; 
}
int bfs() {
    while(!pq.empty()) pq.pop();
    memset(vis,false,sizeof(vis));
    point s;
    s.x = sx, s.y = sy, s.d = 0; s.n = 0;
    pq.push(s);
    vis[sx][sy][0][0] = true;
    point tp;
    int nt, xx, yy, time;
    while(!pq.empty()) {
        point nn = pq.top();
        pq.pop();
        if(ma[nn.x][nn.y] == '$') return nn.d;
        //rest
        time = nn.d;
        nt = nn.n;
        time ++;
        if(time % p == 0) nt = (nt + 3) % 4;
        if(!vis[nn.x][nn.y][nt][time%p]) {
            vis[nn.x][nn.y][nt][time%p] = true;
            tp.x = nn.x; tp.y = nn.y; tp.d = time; tp.n = nt;
            pq.push(tp);
        }
        //an xia an jian
        time = nn.d;
        xx = nn.x + dx[nn.n];
        yy = nn.y + dy[nn.n];
        time ++;
        nt = nn.n;
        if(time % p == 0) nt = (nt + 3) % 4;
        if(isok(xx,yy) && !vis[xx][yy][nt][time%p]) {
            vis[xx][yy][nt][time%p] = true;
            tp.x = xx; tp.y = yy; tp.d = time; tp.n = nt;
            pq.push(tp);
        }
        //left
        time = nn.d;
        nt = (nn.n + 3) % 4;
        time ++;
        if(time % p == 0) nt = (nt + 3) % 4;
        if(!vis[nn.x][nn.y][nt][time%p]) {
            vis[nn.x][nn.y][nt][time%p] = true;
            tp.x = nn.x; tp.y = nn.y; tp.d = time; tp.n = nt;
            pq.push(tp);
        }
        //right
        time = nn.d;
        nt = (nn.n + 1) % 4;
        time ++;
        if(time % p == 0) nt = (nt + 3) % 4;
        if(!vis[nn.x][nn.y][nt][time%p]) {
            vis[nn.x][nn.y][nt][time%p] = true;
            tp.x = nn.x; tp.y = nn.y; tp.d = time; tp.n = nt;
            pq.push(tp);
        }
    }
    return -1;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m,&p);
        srep(i,n) {
           scanf("%s",ma[i] + 1); 
        }
        srep(i,n) {
            srep(j,m) {
                if(ma[i][j] == '@') {
                    sx = i; sy = j;
                }
            }
        }
        now = 0;
        int ans = bfs();
        if(ans != -1) {
            printf("%d\n",ans);
        } else {
            puts("YouBadbad");
        }
    }
	return 0;
}
