
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
char ma[105][105];
bool vis[105][105];
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
inline void zheng(int &tt1,int &tt2,int time,int tar,int now) {
    int ci = time / p;
    tar = (tar + ci) % 4;
    int no = (ci + 1) * p - time;
    int tnow = now;
    tt1 = 0;
    if(tar == now) {
        tt1 = 1;
        tt2 = now;
        return ;
    }
    while(1) {
        tt1 ++;
        now = (now + 1) % 4;
        if(now == tar) {
            tt2 = (tnow + tt1) % 4;
            tt1 ++;
            return ;
        }

        no --;
        if(no == 0) {
            no = p;
            tar = (tar + 1) % 4;
        }
        if(now == tar) {
            tt2 = (tnow + tt1) % 4;
            tt1 ++;
            return ;
        }
        if(tt1 == 5) {
            tt1 = inf;
            return ;
        }
        
        
    }
}
inline void fan(int &tt1,int &tt2,int time,int tar,int now) {
    //转了几次，tar在哪边
    int ci = time / p;
    tar = (tar + ci) % 4;
    int no = (ci + 1) * p - time;   //xiayichang
    int tnow = now;
    tt1 = 0;
    if(tar == now) {
        tt1 = 1;
        tt2 = now;
        return ;
    }
    while(1) {
        tt1 ++;
        now = (now - 1 + 4) % 4;
        
        if(now == tar) {
            tt2 = ((tnow - tt1) % 4 + 4) % 4;
            tt1 ++;
            return ;
        }
        no --;
        if(no == 0) {
            no = p;
            tar = (tar + 1) % 4;
        }
        if(now == tar) {
            tt2 = ((tnow - tt1) % 4 + 4) % 4;
            tt1 ++;
            return ;
        }
        if(tt1 == 5) {
            tt1 = inf;
            return ;
        }
        
    }
}
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
    //cout<<sx<<"  "<<sy<<endl;
    pq.push(s);
    point tp;
    int tt1,tt2,tt3,tt4;
    while(!pq.empty()) {
        point nn = pq.top();
        //cout<<nn.d<<endl;
        //cout<<"         "<<nn.x<<"  "<<nn.y<<"  "<<nn.d<<"  "<<nn.n<<endl;
        if(nn.x == ex && nn.y == ey) return nn.d;
        pq.pop();
        for(int k=0;k<4;++k) {
            int xx = nn.x + dx[k];
            int yy = nn.y + dy[k];
            if(!isok(xx,yy)) continue;
            if(vis[xx][yy]) continue; 
            int ci = nn.d / p;
            //cout<<"k == "<<k<<endl;
            //正
            zheng(tt1,tt2,nn.d,k,nn.n);
            //反
            fan(tt3,tt4,nn.d,k,nn.n);
            //cout<<nn.d<<"  "<<k<<"  "<<nn.n<<endl;
            //cout<<"tt   "<<tt1<<"   "<<tt3<<endl;
            //deng(tt5,tt6,nn.d,k,nn,n);
            if(tt1 < tt3) {
                tp.x = xx;tp.y = yy;tp.d = nn.d + tt1;tp.n = tt2;
            } else {
                tp.x = xx;tp.y = yy; tp.d = nn.d + tt3;tp.n = tt4;
            }
            //cout<<tp.x<<"  "<<tp.y<<"  "<<tp.d<<"  "<<tp.n<<endl;
            vis[xx][yy] = true;
            pq.push(tp);
        }
    }
    return inf;
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
                //printf("%c",ma[i][j]);
                if(ma[i][j] == '@') {
                    sx = i; sy = j;
                } else if(ma[i][j] == '$') {
                    ex = i; ey = j;
                }
            }
        }
        now = 0;
        int ans = bfs();
        if(ans != inf) {
            printf("%d\n",ans);
        } else {
            puts("YouBadbad");
        }
    }
	return 0;
}
