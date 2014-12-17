
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef __int64 LL;
const int mod=1000007;
int A[1105][45],maxm;
void swap(int &a,int &b){int t=a;a=b;b=t;}
int max(int a,int b){return a>b?a:b;}

void build_matrix(int n)
{
    memset(A,0,sizeof(A));
    maxm=-1;
    for(int i=0;i<n;i++)
    {
        __int64 temp;
        scanf("%I64d",&temp);
        for(int j=0;;j++)
        {
            if(!temp) break;
            A[j][i]=temp%2;temp/=2;
            maxm=max(maxm,j);
        }
    }
}

int gauss(int n,int m)
{
    int i=0,j=0,k,r,u;
    while(i<n&&j<m)
    {
        r=i;
        for(k=i;k<n;k++)
            if(A[k][j]){r=k;break;}
        if(A[r][j])
        {
            if(r!=i) for(k=0;k<=m;k++) swap(A[r][k],A[i][k]);
            for(u=i+1;u<n;u++) if(A[u][j])
            for(k=i;k<=m;k++) A[u][k]^=A[i][k];
                i++;
        }
        j++;
    }
    return i;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        build_matrix(n);
        int ans=gauss(maxm+1,n);
        if( ans == n ) {
            puts( "No" ) ;
        }else{
            puts( "Yes" ) ;
        }
    }
    return 0;
}
