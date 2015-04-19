
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-19 14:57:47
 |File Name: i.cpp
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
int n,m;
int T,L,W;
int ma[1005][1005];
pair<int,int> start[105];
int tot;
int a,b;
int a1,a2,b1,b2;
struct PP {
    int x,y,d;
};
PP pp[1000005];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool isok(int x,int y) {
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    if(ma[x][y] == -1) return false;
    if(ma[x][y] == 0) return true;
    return false;
}
void bfs() {
    int front = 0,rear = 0;
    PP tp,tt;
    rep(i,tot) {
        tp.x = start[i].first;
        tp.y = start[i].second;
        //cout<<tp.x<<"  "<<tp.y<<endl;
        tp.d = 1;
        pp[rear ++] = tp;
    }
    while(front < rear) {
        tp = pp[front ++];
        if(tp.d >= T) continue;
        rep(i,4) {
            int xx = tp.x + dx[i];
            int yy = tp.y + dy[i];
            if(isok(xx,yy)) {
                tt.x = xx; tt.y = yy; tt.d = tp.d + 1;
                ma[xx][yy] = tt.d;
                pp[rear ++] = tt;
            }
        }
    }
    int ans = 0;
    rep(i,n) {
        rep(j,m) {
            //cout<<ma[i][j]<<" ";
            if(ma[i][j] != -1 && ma[i][j] != 0) ans ++;
        }
        //cout<<endl;
    }
    printf("%d\n",ans);

}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) != EOF) {
        if(n == -1) break;
        scanf("%d %d %d %d",&m,&T,&L,&W);
        tot = 0;
        rep(i,n) rep(j,m) ma[i][j] = 0;
        rep(i,L) {
            scanf("%d %d",&a,&b);
            a --; b --;
            start[tot ++] = MP(a,b);
            ma[a][b] = 1;
        }
        rep(i,W) {
            scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
            a1 --; a2 --; b1 --; b2 --;
            if(a1 > a2) {
                swap(a1,a2); swap(b1,b2);
            }
            if(a1 == a2) {
                if(b1 >= b2) swap(b1,b2);
                for(int j=b1;j<=b2;++j) ma[a1][j] = -1;
            } else if(b1 == b2) {
                for(int j=a1;j<=a2;++j) ma[j][b1] = -1;
            } else {
                if(b1 <= b2) {
                    int ttt = b1;
                    for(int i=a1;i<=a2;++i) {
                        ma[i][ttt ++] = -1;
                    }
                } else {
                    int ttt = b1;
                    for(int i=a1;i<=a2;++i) {
                        ma[i][ttt --] = -1;
                    }
                }
            }
        }
        bfs();

    }
	return 0;
}
