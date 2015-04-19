
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
#include<map>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define MM(a,t) memset(a,t,sizeof(a))
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
char st[20],ans[20];
int ind[20];
int n;
ll m;
int ch[30];
ll jie[20];
bool mp[30];
void setup(){
  int i,j;
  
  jie[0]=1;
  rep(i,17) jie[i]=jie[i-1]*i;	
}
ll cal(){
  int i,j;
  ll res=1,di=1;
  int t=0;
  MM(ch,0);
  
  for(i=0;i<n;i++){
    if(ind[i]!=0) continue;
	ch[st[i]-'A']++;	
  }
  for(i=0;i<26;i++)
  if(ch[i]!=0){
    di*=jie[ch[i]];
	t+=ch[i];	
  }	
  res=jie[t]/di;
  return (ll)res;
}
void DFS(int ii,ll m){
  int i,j,pr=-1;
  
  MM(mp,0);
  if(m==1){
    for(i=0;i<n;i++) if(ind[i]==0) ind[i]=ii++;
	return;	
  }
  if(ii==n+1) return;
  for(i=0;i<n;i++){
    if(ind[i]!=0) continue;
	if(mp[int(st[i]-'A')]!=0) continue;
	mp[int(st[i]-'A')]=1;	
    ind[i]=ii;	  
	if(pr!=-1) ind[pr]=0;
    pr=i;	
    ll tmp=cal();
    //cout<<ii<<' '<<st[i]<<' '<<tmp<<endl;
	if(m>tmp){
	  m-=tmp;
	}
	else {
	  ind[i]=0; ind[pr]=ii;
	  DFS(ii+1,m);
	  return;
	}
  }	
}
void PRT(){
  int i,j;
  
  
  rep(i,n) ans[ind[i-1]]=st[i-1];
  rep(i,n) printf("%c",ans[i]); printf("\n");	
}
int main(){
	int i,j;
	
	setup();
	while(scanf("%s%lld",&st,&m)!=EOF){
	   if(m==0) break;
	   n=strlen(st);
	   MM(ind,0); sort(st,st+n);
	   //printf("%lld\n",cal());
	   DFS(1,m);
	   PRT();	
	}
	
	return 0;
}
