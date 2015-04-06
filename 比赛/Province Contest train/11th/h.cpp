
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
int a,b,c,res1,res2;
void cal(){
  int i,j,co;
  
  res1=0; res2=0;
  
  co=0;
  while(co<a){
    res1+=300*(co*2+1);
	co++;	
  }
  while(co<a+b){
    res1+=100*(co*2+1);
	co++;	
  }
  while(co<a+b+c){
    res1+=50*(co*2+1);
	co++;	
  }
  co=0;
  while(co<c){
    res2+=50*(co*2+1);
	co++;	
  }
  while(co<c+b){
    res2+=100*(co*2+1);
	co++;	
  }
  while(co<c+b+a){
    res2+=300*(co*2+1);
	co++;	
  }

}
int main(){
	int i,j,T;
	
	scanf("%d",&T);
	while(T--){
	  scanf("%d%d%d",&a,&b,&c);
	  cal();
	  printf("%d %d\n",res1,res2);	
	}
	
	
	return 0;
}
