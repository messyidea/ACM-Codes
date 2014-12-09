/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/4 7:46:38
 |File Name: Period.cpp
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
char s[1000005];
int f[1000005];
void getfail(char* s){
	memset(f,0,sizeof(f));
	int m = strlen(s);
	f[0] = 0;f[1] = 0;
	for(int i=1;i<m;++i){
		int j = f[i];
		while(j && s[i]!=s[j]) {
			j = f[j];
		}
		f[i+1] = s[i] == s[j]?j+1:0;
	}
}
int main() {
	freopen("input.txt","r",stdin);
	int n; 
	int cas = 0;
	while(scanf("%d",&n)!=EOF && n){
		printf("Test case #%d\n",++cas);
		scanf("%s",s);
		getfail(s);
		//for(int i=0;i<=n;++i) cout<<f[i]<<" ";cout<<endl;
		for(int i=2;i<=n;++i){
			if(i%(i-f[i]) == 0 && i/(i-f[i])!=1){
				printf("%d %d\n",i,i/(i-f[i]));
			}
		}
		printf("\n");
	}
	return 0;
}

