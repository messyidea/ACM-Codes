/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/14 22:37:03
 |File Name: DungeonMaster.cpp
 |Description: 要把访问语句放在里面，不然6倍 
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
bool vis[105][105][105];
int n,m,l;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
char c;
struct point{
    int x,y,z;
    int pos;
};
int len;
point s,t;
bool check(int x,int y,int z){
    //if(x>=0 && x< l && y >=0 && y<n && z>=0 && z<m) return true;
    if(x<0 || x>=l) return false;
    if(y<0 || y>=n) return false;
    if(z<0 || z>=m) return false;
    return true;
}
bool bfs(){
    //int front = 0,rear = 0;
    //pp[rear++] = s;
    queue<point> pp;
    pp.push(s);
    vis[s.x][s.y][s.z] = true;
    while(!pp.empty()){
        //point tp = pp[front++];
        point tp = pp.front();
        pp.pop();
        int x = tp.x;
		int y = tp.y;
		int z = tp.z;
		int p = tp.pos;
        if(x == t.x && y == t.y && z == t.z){
            len = p;
            return true;
        }
        //vis[x][y][z] = true;
        for(int i=0;i<6;++i){
            int xx = x+dx[i];
            int yy = y+dy[i];
            int zz = z+dz[i];
            if(check(xx,yy,zz) && !vis[xx][yy][zz]){
                point tt;
                tt.x = xx;
                tt.y = yy;
                tt.z = zz;
                tt.pos = p+1;
                vis[tt.x][tt.y][tt.z] = true;
                pp.push(tt);
            }
        }
    }
    return false;
}
int main() {
	//freopen("input.txt","r",stdin); 
    //ios_base::sync_with_stdio(0);cin.tie(0);
    while(scanf("%d%d%d",&l,&n,&m)){
        if(l == 0 && n == 0 && m == 0){
            break;
        }
        getchar();
        //memset(vis,false,sizeof(vis));
        for(int i=0;i<l;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<m;++k){
                    //cin>>c;
                    scanf("%c",&c);
                    if(c == 'S'){
                        s.x = i;s.y = j;s.z = k;
                        vis[i][j][k] = true;
                        s.pos = 0;
                    }
                    else if(c == 'E'){
                        t.x = i;t.y = j;t.z = k;
                        t.pos = 0;
                        vis[i][j][k] = false;
                    }
                    else if(c == '.'){
                    	vis[i][j][k] = false;
                    }
                    else vis[i][j][k] = true;
                }
                getchar();
                
            }
            getchar();
        }
        if(bfs()){
            printf("Escaped in %d minute(s).\n",len);
        }
        else{
            printf("Trapped!\n");
        }
    }
	return 0;
}