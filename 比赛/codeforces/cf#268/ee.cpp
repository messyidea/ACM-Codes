
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
#include<time.h>
using namespace std;
long long dp1[2][18],dp2[2][18],ans[2][10],p[2],aa,bb;
long long k[2],a[2][18],ANS,n,l,r,mid,now;
int f___(long long x)
{
    int now=0;
    while (x!=0)
    {
        now+=x%10;
        x/=10;
    }
    return now;
}
long long fu__(long long a,long long b)
{
    long long temp=1;
    for (long long i=1; i<=b; ++i)
        temp*=a;
    if (!b)
        return 1;
    return temp;
}
void fu_k(long long x)
{
    long long i,j;
    long long temp;
    for (int i=0; i<10; ++i)
    {
        for (int j=1; j<=k[x]; ++j)
        {
            if (i==0&&j==k[x])
                break;
            if (a[x][j]==i)
            {
                ans[x][i]+=dp1[x][j-1]+1;
                temp=dp2[x][j+1];
                if (i==0)
                    temp--;
                ans[x][i]+=temp*fu__(10,j-1);
            }
            else if (a[x][j]>i)
            {
                temp=dp2[x][j+1]+1;
                if (i==0) temp--;
                ans[x][i]+=temp*fu__(10,j-1);
            }
            else if (a[x][j]<i)
            {
                temp=dp2[x][j+1];
                if (i==0) temp--;
                ans[x][i]+=temp*fu__(10,j-1);
            }
        }
    }
}
void f_ck(long long aa,long long bb)
{
    aa--;
    memset(a,0,sizeof(a));
    memset(dp2,0,sizeof(dp2));
    memset(dp1,0,sizeof(dp1));
    p[0]=p[1]=1,k[0]=k[1]=0;
    while (aa>0)
    {
        a[0][++k[0]]=aa%10;
        aa=aa/10;
        dp1[0][k[0]]=dp1[0][k[0]-1]+a[0][k[0]]*p[0];
        p[0]*=10;
    }
    p[1]=1;
    while (bb>0)
    {
        a[1][++k[1]]=bb%10;
        bb/=10;
        dp1[1][k[1]]=dp1[1][k[1]-1]+a[1][k[1]]*p[1];
        p[1]*=10;
    }
    for (int i=k[0]; i>0; --i)
        dp2[0][i]=dp2[0][i+1]*10+a[0][i];
    for (int i=k[1]; i>0; --i) dp2[1][i]=dp2[1][i+1]*10+a[1][i];
    for (int i=0; i<2; ++i)
        fu_k(i);
    ANS=0;
    for (int i=1; i<10; ++i)
        ANS+=i*(ans[1][i]-ans[0][i]);
}
int main()
{

    cin>>n;
    l=0,r=20000000000000000LL;
    mid=l+r>>1;
    while (l<=r)
    {
        for (int i=1; i<10; ++i)
            ans[0][i]=ans[1][i]=0;
        f_ck(1,mid);
        if (ANS<=n)
        {
            l=mid+1;
            mid=l+r>>1;
        }
        else
        {
            r=mid-1;
            mid=l+r>>1;
        }
    }
    for (int i=1; i<10; ++i)
        ans[0][i]=ans[1][i]=0;
    f_ck(1,r);
    now=ANS,l=1;
    while (now!=n)
    {
        if (now>n)
        {
            now-=f___(l);
            l++;
        }
        if (now<n)
        {
            now+=f___(r+1);
            r++;
        }
    }
    printf("%I64d %I64d\n",l,r);
    return 0;
}
