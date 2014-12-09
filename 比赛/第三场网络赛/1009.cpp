
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define MM(a,t) memset(a,t,sizeof(a))
#define rep(i,n) for(i=1;i<=n;i++)
#define INF 1e9
typedef long long ll;
#define mod 10000007
using namespace std;
int n,m,l;
ll a[120][120],xi[120];
struct matrix{
  ll a[120][120];    
};
matrix chu,die;
void setup(){
    int i,j;
    

    rep(i,n) a[i][0]=xi[i];
    for(i=2;i<=15;i++)
      for(j=1;j<=i-1;j++)
              a[j][i-j]=(a[j-1][i-j]+a[j][i-j-1])%mod;    
}
matrix mul(matrix a1,matrix a2,int i1,int i2){
    int i,j,k;
    matrix c;
    rep(i,i1)
      rep(j,i2){
          c.a[i][j]=0;
          rep(k,i2)
            c.a[i][j]=(c.a[i][j]+a1.a[i][k]*a2.a[k][j]%mod)%mod;
      }
      return c;
}
void qmi(int nn){
    while(nn){
      if(nn&1) chu=mul(chu,die,1,l);
      die=mul(die,die,l,l);
      nn=(nn>>1);
    }
}
int main(){
    
    int i,j;
    
    a[0][1]=233;
    for(i=2;i<=15;i++) a[0][i]=(a[0][i-1]*10+3)%mod;
    
    while(scanf("%d%d",&n,&m)!=EOF){
      rep(i,n) scanf("%I64d",&xi[i]);
      setup();
      if(m<=10) printf("%I64d\n",a[n][m]);
      else{
          l=n+2;
          chu.a[1][l]=1; chu.a[1][l-1]=a[0][n+1];
        for(i=n;i>=1;i--) chu.a[1][i]=a[n-i+1][i];
        MM(die.a,0);
        die.a[l][l]=1; die.a[l-1][l-1]=10; die.a[l][l-1]=3;
        rep(i,n) die.a[i][i]=die.a[i+1][i]=1;

        qmi(m-1);
        printf("%I64d\n",chu.a[1][1]);    
        }    
    }
    
    return 0;
}
