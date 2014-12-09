
#include<iostream>
#include<string>
#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int n,m;
int v[5010][5010],h[5010],l[5010],r[5010];
int x[5010],y[5010],lenx,leny;
int a[5010],b[5010];

int findx(int c)
{
    int l=0,r=lenx-1;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(x[mid]==c)
            return mid;
        if(x[mid]>c)
            r=mid-1;
        else
            l=mid+1;
    }
}

int findy(int c)
{
    int l=0,r=leny-1;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(y[mid]==c)
            return mid;
        if(y[mid]>c)
            r=mid-1;
        else
            l=mid+1;
    }
}

int main()
{
    int i,j,p,aa,bb;
    //freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        scanf("%d",&p);
        lenx=leny=0;
        for(i=0;i<p;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            x[lenx++]=a[i];
            y[leny++]=b[i];
        }
        //******************************//离散化
        x[lenx++]=0;y[leny++]=0;
        x[lenx++]=n;y[leny++]=m;
        sort(x,x+lenx);
        sort(y,y+leny);
        for(j=1,i=1;i<lenx;i++)
        {
            if(x[i]!=x[i-1])
                x[j++]=x[i];
        }
        lenx=j;
        for(j=1,i=1;i<leny;i++)
        {
            if(y[i]!=y[i-1])
                y[j++]=y[i];
        }
        leny=j;
        //*******************************//
        memset(v,0,sizeof(v));
        for(i=0;i<p;i++)
        {
            aa=findx(a[i]);
            bb=findy(b[i]);
            v[aa][bb]=1; //标记障碍点
        }
        int lm,rm,ans=0,temp;
        for(i=0;i<leny;i++)
        {
            l[i]=0;r[i]=m;h[i]=0;
        }
        for(i=1;i<lenx;i++)
        {
            lm=0;
            for(j=0;j<leny;j++)
            {
                if(!v[i-1][j]) //如果上一个不是障碍点
                {
                    h[j]=h[j]+x[i]-x[i-1]; //高度累加
                    if(lm>l[j]) //l[i][j]=max(l[i-1][j] , (i-1,j)左边第一个障碍点的位置)
                        l[j]=lm;
                }
                else //如果上一个点是障碍点
                {
                    h[j]=x[i]-x[i-1]; //高度重新计算
                    l[j]=0;
                    r[j]=m;
                    lm=y[j]; //更新(i-1,j)左边第一个障碍点的位置
                }
            }
            rm=m;
            for(j=leny-1;j>=0;j--)
            {
                if(r[j]>rm) //r[i][j]=min(r[i-1][j] , (i-1,j)右边第一个障碍点的位置)
                    r[j]=rm;
                temp=h[j]*(r[j]-l[j]);
                if(temp>ans) //计算最优解
                    ans=temp;
                if(v[i-1][j]) //如果该点是障碍点，更新(i-1,j)右边第一个障碍点的位置
                    rm=y[j];
            }
        }
        for(i=1;i<lenx;i++) //计算相邻y坐标之间的面积
        {
            temp=m*(x[i]-x[i-1]);
            if(temp>ans)
                ans=temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
