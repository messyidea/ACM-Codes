/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/3 23:31:20
 |File Name: Power Strings.cpp
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
	int m = strlen(s);
	/*f[0] = 0;f[1] = 0;
	for(int i=1;i<m;++i){
		int j = f[i];
		while(j && s[i]!=s[j]) j = f[i];
		f[i+1] = s[i] == s[j]?j+1:0;
	}*/
	int i=0,j=-1;
	f[0] = -1;
	while(s[i]){
		if(j == -1 || s[i] == s[j]){
			j++;
			i++;
			f[i] = j;
		}
		else{
			j = f[j];
		}
	}
}
int main() {
	//freopen("input.txt","r",stdin); 
	while(scanf("%s",s)!=EOF){
		if(s[0] == '.') break;
		getfail(s);
		int n = strlen(s);
		/*for(int i=0;i<=n;++i){
			cout<<f[i]<<endl;
		}*/
		if(n%(n - f[n]) == 0){
			printf("%d\n",n/(n - f[n]));
		}
		else printf("1\n");
	}
	return 0;
}

