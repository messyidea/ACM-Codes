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
char st[10000];
int len,suma,sumb;
int lst;
int fun1(){
	int i,j;
	for(j=len-1;j>=0;j--)
	if(st[j]!='*') return j;
}
int main()
{
	int i,j,T;
	int res;
	
	scanf("%d",&T);
	while(T--){
	  scanf("%s",&st);
	  len=strlen(st);
  	  suma=0; sumb=0;
  	  for(i=0;i<len;i++) 
  	  if(st[i]=='*') sumb++;
  	  else           suma++;
  	  if(sumb==0) printf("0\n");
  	  else if(suma==0) printf("%d\n",sumb+1);
           else{
  	         if(sumb>=suma){
         	   res=suma=sumb-suma+1;	
  	         }
  	         else{
         	               res=0; suma=0; 	
        	  }
             sumb=0;
			 for(i=0;i<len;i++){
 			   if(st[i]=='*') sumb++;
			   else           suma++;
			   while(sumb>=suma){
                 lst=fun1();
                 if(lst>i){
   	               res++;
                   swap(st[i],st[lst]);
				   suma++; sumb--;	
                 }
                 else{
                   res++;	
                   suma++;
                 }
   			   }	
		     }
		     lst=fun1();
		     if(lst==len-1) res++;
		     printf("%d\n",res);
           }
	}
	return 0;
}

