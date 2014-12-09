/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/5 22:18:44
 |File Name: Fibonacci Tree.cpp
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
struct edge{
	int x,y,z;
}e[100005];
int fa[100005];
int find(int x){
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
bool cmp(edge a,edge b){
	return a.z > b.z;
}
bool cmp1(edge a,edge b){
	return a.z < b.z;
}
int n,m;
int fb[505];
int main() {
	//freopen("input.txt","r",stdin);
	fb[1] = 1;fb[2] = 2;
	for(int i=3;i<=25;++i){
		fb[i] = fb[i-1] + fb[i-2];
	} 
	int cas = 1;
	//for(int i=1;i<=25;++i) printf("%d ",fb[i]);printf("\n");
	//cout<<fb[25]<<endl;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		}
		sort(e,e+m,cmp);
		int n1 = 0;
		int n2 = 0;
		for(int i=0;i<=n;++i) fa[i] = i;
		for(int i=0;i<m;++i){
			//if(e[i].z == 0) break;
			int t1 = find(e[i].x);
			int t2 = find(e[i].y);
			if(t1 != t2){
				fa[t1] = t2;
				if(e[i].z == 1) n1 ++;
			}
		}
		sort(e,e+m,cmp1);
		for(int i=0;i<=n;++i) fa[i] = i;
		for(int i=0;i<m;++i){
			//if(e[i].z == 1) break;
			int t1 = find(e[i].x);
			int t2 = find(e[i].y);
			if(t1 != t2){
				fa[t1] = t2;
				if(e[i].z == 1) n2 ++;
			}
		}
		//cout<<n2<<" "<<n1<<endl;
		bool flag = false;
		for(int i=1;i<=25;++i){
			if(fb[i]>=n2 && fb[i] <= n1) flag = true;
		}
		for(int i=2;i<=n;++i) if(find(i)!=find(1)) {
			flag = false;
			break;
		}
		if(flag){
			printf("Case #%d: Yes\n",cas++);
		}
		else {
			printf("Case #%d: No\n",cas++);
		}
		//cout<<n1<<" "<<n2<<endl;
	}
	return 0;
}

