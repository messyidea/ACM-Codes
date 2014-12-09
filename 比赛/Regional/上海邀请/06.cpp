
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
int n;
int a[12];
char st[10]={'p','q','r','u','v','w','x','y','z','j'};
int main()
{
    int i,j,T;
    bool ff,ff2;

    scanf("%d",&T);
    while(T--){
         n=10;
      ff=true; ff2=false;
      rep(i,n){
        scanf("%d",&a[i]);
        if(a[i]!=0) ff=false;    
      }
      if(ff){
        printf("0\n");
        continue;    
      }
      rep(i,n-1){
        if(a[i]==0) continue;
        if(!ff2){
          if(abs(a[i])==1){
              if(a[i]<0) printf("-");    
            }
            else printf("%d",a[i]);
          printf("%c",st[i-1]);  
          ff2=true;    
        }
        else{
          if(abs(a[i])==1){
              if(a[i]<0) printf("-");    
              else       printf("+");
            }
            else{
            if(a[i]<0) printf("%d",a[i]);    
              else       printf("+%d",a[i]);    
            }
          printf("%c",st[i-1]); 
        }    
      }
      if(a[n]!=0){
          if(!ff2){
          printf("%d",a[i]);
          ff2=true;      
        }
        else{
          if(a[i]>0)      printf("+%d",a[i]);     
          else           printf("%d",a[i]);     
        }
      }
      cout<<"\n";
    }
    
    return 0;
}
