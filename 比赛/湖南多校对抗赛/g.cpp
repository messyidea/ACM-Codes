
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
char ch[28]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
             'P','Q','R','S','T','U','V','W','X','Y','Z','_','.'};
int main()
{
	int i,j,n,m,l;
    char st[100];

    while(scanf("%d",&n)!=EOF){
      if(n==0) break; m=n;
	  getchar();
	  scanf("%s",&st);
	  l=strlen(st);
	  while(m--){
  	    rep(i,l){
    	  if(st[i-1]=='_'){
	    	 st[i-1]='.';
	    	 continue;
  	      }
  	      if(st[i-1]=='.'){
      	    st[i-1]='A';
			continue;	
      	  }
		  int ind=int(st[i-1]-'A');
		  st[i-1]=ch[ind+1]; 	
	    }	
  	  }	
  	    rep(i,l) cout<<st[l-i]; cout<<endl;	
    }

	
	return 0;
}
