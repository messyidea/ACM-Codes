
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
char st[3000020];
int l,a[100];
char ch[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void prt16(int x){
  char ch1,ch2;
  ch1=ch[x/16]; ch2=ch[x%16];
  printf("%c%c",ch1,ch2);
}
void prtl(){
  int i,j,n;
  
  n=0; j=0;
  while(l>0){
    if(l%2==1) n+=(1<<j);
	j++; l/=2;
	if(l>0 && j==7) prt16(n+128),n=0,j=0;	
  }	
  prt16(n);
}
int main(){
  int i,j,T,l2;
  
  scanf("%d",&T);  	
  getchar();
  while(T--){
    gets(st);
	l=strlen(st); l2=l;
	prtl();
	rep(i,l2) prt16(int(st[i-1]));
	printf("\n");
  }
  
  
  
  return 0;	
}
