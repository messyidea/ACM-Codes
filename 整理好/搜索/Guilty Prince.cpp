/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/14 22:21:38
 |File Name: Guilty Prince.cpp
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
int n,m;
int sum;
char ma[35][35];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
#define inf 1<<29
bool check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}
int dfs(int ii,int jj){
    if(ma[ii][jj] == '.'){
        ma[ii][jj] = '#';
        sum++;
    } 
    for(int i=0;i<4;++i){
        int x = ii+dx[i];
        int y = jj+dy[i];
        if(check(x,y) && ma[x][y]!='#'){
            dfs(x,y);
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        scanf("%d%d",&n,&m);
        swap(n,m);
        //cout<<n<<m<<endl;
        getchar();
        int ii = 0,jj = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%c",&ma[i][j]);
                if(ma[i][j] == '@'){
                    ii = i,jj = j;
                }
            }
            getchar();
        }
        sum = 1;
        ma[ii][jj] = '@';
        dfs(ii,jj);
        printf("Case %d: %d\n",cas++,sum);
    }
	return 0;
}

