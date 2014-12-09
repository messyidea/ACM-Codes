
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
int n,l;
char st1[20],st2[20];
int pan(int l,int r){
    int i,j;
    
    for(i=l;i<=r;i++){
        if(st1[i]<st2[i]) return -1;    
        if(st1[i]>st2[i]) return  1;
    }

    return 0;
}
int main()
{
    int i,j,T;
    char ch1,ch2;
    
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
      n=6;
      scanf("%s%s",&st1,&st2);
      if(st1[0]==st2[0]) ch1='=';
      else if(st1[0]>st2[0]) ch1='>';
           else              ch1='<';
      if(st1[1]==st2[1]){
          int tmp=pan(2,5);
        if(tmp==0) ch2='=';
        else if(tmp==1) ch2='>';
             else       ch2='<';      
      }
      else{
         int tmp=pan(2,4);
        if(tmp==0) ch2='=';
        else if(tmp==1) ch2='>';
             else       ch2='<';          
      } 
      printf("Case %d: %c %c\n",t,ch1,ch2);
          
    }

    
    return 0;
}
