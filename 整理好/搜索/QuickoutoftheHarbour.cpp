/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/15 23:41:40
 |File Name: QuickoutoftheHarbour.cpp
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

using namespace std;
char ma[505][505];
bool vis[505][505];
int n,m,d;
struct point{
    int x,y,p;
    bool operator < (point a)const{
        return p>a.p;
    }
};
point s;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(){
    priority_queue<point> pq;
    //if(!pq.empty()) pq.pop();
    pq.push(s);
    vis[s.x][s.y] = true;
    while(!pq.empty()){
        point tp = pq.top();
        pq.pop();
        for(int i=0;i<4;++i){
            int xx = tp.x + dx[i];
            int yy = tp.y + dy[i];
            if(xx < 0||xx >= n ) return tp.p /*+ (ma[xx][yy]=='@'?d+1:1)*/;
            if(yy < 0||yy >= m ) return tp.p /*+ (ma[xx][yy]=='@'?d+1:1)*/;
            if(ma[xx][yy] != '#' && !vis[xx][yy]){
                point tt;
                tt.x = xx;
                tt.y = yy;
                tt.p = tp.p + 1;
                if(ma[xx][yy] == '@')   tt.p += d;
                vis[tt.x][tt.y] = true;
                pq.push(tt);
            }
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&d);
        memset(vis,false,sizeof(vis));
        getchar();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%c",&ma[i][j]);
                if(ma[i][j] == 'S'){
                    s.x = i,s.y = j,s.p = 0;
                }
            }
            getchar();
        }
        /*for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<ma[i][j];
            }
            cout<<endl;
        }*/
        printf("%d\n",bfs()+1);
    }
	return 0;
}

