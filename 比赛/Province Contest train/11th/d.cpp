
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<queue>
#include<stack> 
#include<vector>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define MM(a,t) memset(a,t,sizeof(a))
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
int n,m;
bool p[520][520];
int a[520],b[520];
int main(){
	int i,j,T;
	
	scanf("%d",&T);
	while(T--){
	  scanf("%d%d",&n,&m);
	  MM(p,0); j=0;
	  rep(i,m) scanf("%d",&a[i]);
	  rep(i,m) scanf("%d",&b[i]);
	  rep(i,m){
	  	int s=a[i],e=b[i];
  	    if(!p[s][e]){
    	  j++; p[s][e]=p[e][s]=1;  	
 	    }	
  	  }
	  printf("%.3lf\n",j*1.0/n);
	}
	
	
	return 0;
}
