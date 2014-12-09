/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/16 16:26:02
 |File Name: Cleaning Robot.cpp
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
#define inf 1<<29
char ma[35][35];
bool vv[12];
bool vis[35][35];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
struct point{
    int x,y,p;
};
point s;
point dirty[12];
int dnum;
int sum;
bool check(int x,int y){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=m) return false;
    return true;
}
point pp[9000];
int dis[12][12];
int bfs(point a,point b){
	a.p = 0,b.p = 0;
    int front = 0,rear = 0;
    int total = 0;
    pp[rear ++] = a;
    vis[a.x][a.y] = true;
    while(front < rear){
        point tp = pp[front ++];
        if(tp.x == b.x && tp.y == b.y) return tp.p;
        for(int i=0;i<4;++i){
            int xx = tp.x + dx[i];
            int yy = tp.y + dy[i];
            if(check(xx,yy) && ma[xx][yy] != 'x' && !vis[xx][yy]){
                point tt;
                tt.x = xx;tt.y = yy;
                tt.p = tp.p+1;
                vis[xx][yy] = true;
                pp[rear++] = tt;
            }
        }
    }
    return -1;
}
void ddfs(int b,int l,int all){
	if(l == dnum){
		if(all < sum) sum = all;
		return ;
	}
	for(int i=0;i<dnum-1;++i){
		//if(i == b) continue;
		if(!vv[i]){
			if(all + dis[i][b] > sum) continue;
			vv[i] = true;
			ddfs(i,l+1,all+dis[i][b]);
			vv[i] = false;
		}
	}
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0) break;
        swap(n,m);
        getchar();
        dnum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%c",&ma[i][j]);
                if(ma[i][j] == 'o'){
                    s.x = i;s.y = j;s.p = 0;
                }
                else if(ma[i][j] == '*'){
                	dirty[dnum].x = i;dirty[dnum].y = j;dirty[dnum].p = 0;	
                	dnum ++;
                }
            }
            getchar();
        }
        memset(vis,false,sizeof(vis));
        dirty[dnum++] = s;
        bool flag = false;
        for(int i=0;i<dnum;++i){
        	for(int j=i+1;j<dnum;++j){
        		memset(vis,false,sizeof(vis));
	        	int dd = bfs(dirty[i],dirty[j]);
	        	if(dd == -1){
	        		//cout<<i<<" "<<j<<endl;
	        		flag = true;
	        		//break;
	        	}
	        	else{
	        		dis[i][j] = dd;
					dis[j][i] = dd;	
	        	}
	        }
	        //if(flag) break;
        }
        if(flag){
        	printf("-1\n");
        }
        else{
        	/*for(int i=0;i<dnum;++i){
	        	for(int j=0;j<dnum;++j){
	        		cout<<dis[i][j]<<" ";
	        	}
	        	cout<<endl;
	        }*/
        	sum = inf;
        	memset(vv,false,sizeof(vv));
        	vv[dnum-1] = true;
        	ddfs(dnum-1,1,0);
        	printf("%d\n",sum);
        }
    }
	return 0;
}

