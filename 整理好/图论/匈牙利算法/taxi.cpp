
/***********************************************\
 |Author: YMC
 |Created Time: 2014-7-11 16:28:38
 |File Name: cdc.cpp
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
#define rep(i,n) for(int i=0;i<n;++i)
#define mset(l,n) memset(l,n,sizeof(l))

using namespace std;
int n,m;
double v;
#define maxn 105
struct point{
    double x,y;
}pa[maxn],pb[maxn];
double dis[maxn][maxn];
#define inf 0x7fffffff
int maxx,minx;
int cnt = 0;
double mm[maxn*maxn];
double now;
bool vis[maxn];
int from[maxn];
bool match(int x){
    for(int i=0;i<m;++i){
        if(!vis[i] && dis[x][i] <= now){
            vis[i] = true;
            if(from[i] == -1 || match(from[i])){
                from[i] = x;
                return true;
            }
        }
    }
    return false;
}
bool hungry(){
    memset(from,-1,sizeof(from));
    rep(i,n){
        memset(vis,false,sizeof(vis));
        if(!match(i)) return false;
    }
    return true;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d%d",&n,&m)!=EOF){
        rep(i,n){
            scanf("%lf%lf",&pa[i].x,&pa[i].y);
        }
        rep(i,m){
            scanf("%lf%lf",&pb[i].x,&pb[i].y);
        }
        scanf("%lf",&v);
        cnt = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dis[i][j] = sqrt((pa[i].x - pb[j].x)*(pa[i].x - pb[j].x)+(pa[i].y - pb[j].y)*(pa[i].y - pb[j].y))/v;
                mm[cnt ++] = dis[i][j];
            }
        }
        sort(mm,mm+cnt);
        int l = 0,r = cnt-1,mid;
        double ans;
        while(l<=r){
            mid = (l+r)/2;
            now = mm[mid];
            if(hungry()){
                r = mid-1;
                ans = now;
            }
            else l = mid+1;
        }
        printf("%.2lf\n",ans);

    }
	return 0;
}
