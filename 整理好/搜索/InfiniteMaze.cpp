/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/17 9:04:23
 |File Name: InfiniteMaze.cpp
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
char ma[1505][1505];
bool vis[1505][1505];
int mx[1505][1505];
int my[1505][1505];
int n,m;
int sx,sy;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool flag;
void dfs(int x,int y){
	if(flag) return ;
    for(int i=0;i<4;++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        int tx = (xx%n+n)%n;
        int ty = (yy%m+m)%m;
        if(ma[tx][ty]!='#'){
       		if(!vis[tx][ty]){
	        	vis[tx][ty] = true;
	        	mx[tx][ty] = xx;
	        	my[tx][ty] = yy;
	        	dfs(xx,yy);
	        }
	        else{
				if(mx[tx][ty]!=xx ||my[tx][ty]!=yy){
					flag = true;
					return ;
				}
	        }
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%c",&ma[i][j]);
            if(ma[i][j] == 'S'){
                sx = i,sy = j;
            }
        }
        getchar();
    }
    memset(vis,0,sizeof(vis));
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    vis[sx][sy] = true;
    mx[sx][sy] = sx;
    my[sx][sy] = sy;
    flag = false;
    dfs(sx,sy);
    if(flag){
    	printf("Yes\n");
    }
    else printf("No\n");
	return 0;
}

