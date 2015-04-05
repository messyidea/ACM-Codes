/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/5 20:15:01
 |File Name: Paint_the_Grid_Again.cpp
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
char s[45][45];
int d[45][45];
bool vis[45][45];
bool vi[1606];
int now;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int tot;
set<int> se;
vector <int> ma[1606];
bool isok(int i,int j) {
    if(i <= 0 || i > n) return false;
    if(j <= 0 || j > m) return false;
    return true;
}
void dfs(int i,int j) {
    vis[i][j] = true;
    d[i][j] = now;
    rep(k,4) {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if(isok(xx,yy) && !vis[xx][yy] && s[i][j] == s[xx][yy]) {
            dfs(xx,yy);
        }
    }
}
void dfs2(int i,int j) {
    vis[i][j] = true;
    rep(k,4) {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if(isok(xx,yy)) {
            if(!vis[xx][yy]) {
                if(d[i][j] == d[xx][yy]) {
                    dfs2(xx,yy);
                } else {
                    //cout<<"     "<<d[xx][yy]<<endl;
                    se.insert(d[xx][yy]);
                    vis[xx][yy] = true;
                }
            }
        }
    }
}
pair<int,int> pp[1606];
int bfs(int ss) {
    memset(vi,false,sizeof(vi));
    int front = 0,rear = 0;
    pp[rear ++] = MP(ss,1);
    vi[ss] = true;
    pair<int,int> tp;
    int maxx = 1;
    while(front < rear) {
        tp = pp[front ++];
        //if(vi[tp.first]) continue;
        int tk = tp.first;
        for(int i=0;i<ma[tk].size(); ++i) {
            if(!vi[ma[tk][i]]) {
                vi[ma[tk][i]] = true;
                pp[rear ++] = MP(ma[tk][i], tp.second + 1);
                maxx = max(maxx,tp.second + 1);
            }
        }
    }
    return maxx;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        srep(i,n) {
            scanf("%s",s[i]+1);
        }
        memset(vis,false,sizeof(vis));
        now = 1;
        srep(i,n) {
            srep(j,m) {
                if(!vis[i][j]) {
                    dfs(i,j);
                    now ++;
                }
            }
        }
        now --;
        int tnow = 1;
        set<int>::iterator it;
        /*srep(i,n) {
            srep(j,n) {
                cout<<d[i][j]<<" ";
            }
            puts("");
        }*/
        srep(i,n) {
            srep(j,m) {
                if(d[i][j] == tnow) {
                    se.clear();
                    memset(vis,false,sizeof(vis));
                    dfs2(i,j);
                    it = se.begin();
                    ma[tnow].clear();
                    while(it != se.end()) {
                        ma[tnow].push_back(*it);
                        //cout<<tnow<<"  "<<(*it)<<endl;
                        it ++;
                    }
                    tnow ++;
                }
            }
        }
        //cout<<"now == "<<now<<endl;
        int ans = inf;
        srep(i,now) {
            ans = min(ans,bfs(i));
        }
        printf("%d\n",ans - 1);

        
        

    }
	return 0;
}

