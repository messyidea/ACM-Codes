// File Name: 2104.cpp
// Author: Zlbing
// Created Time: 2013年10月06日 星期日 18时04分39秒

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=1e5+100;
int ls[MAXN*20],rs[MAXN*20];
int sum[MAXN*20];
int root[MAXN];
//root表示N颗线段树的根结点
int tot;
void build(int l,int r,int& rt)
{
    rt=++tot;
    sum[rt]=0;
    if(l==r)return;
    int m=(l+r)>>1;
    build(l,m,ls[rt]);
    build(m+1,r,rs[rt]);
}
void update(int last,int p,int l,int r,int &rt)
{
    rt=++tot;
    ls[rt]=ls[last];
    rs[rt]=rs[last];
    sum[rt]=sum[last]+1;
    if(l==r)return;
    int m=(l+r)>>1;
    if(p<=m)update(ls[last],p,l,m,ls[rt]);
    else update(rs[last],p,m+1,r,rs[rt]);
}
int query(int ss,int tt,int l,int r,int k)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    int cnt=sum[ls[tt]]-sum[ls[ss]];
    if(k<=cnt)
        return query(ls[ss],ls[tt],l,m,k);
    else
        return query(rs[ss],rs[tt],m+1,r,k-cnt);
}
int num[MAXN],hash[MAXN];
int main()
{
    int n,m;
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        REP(i,1,n)
        {
            scanf("%d",&num[i]);
            hash[i]=num[i];
        }
        tot=0;
        sort(hash+1,hash+n+1);
        int cnt=unique(hash+1,hash+n+1)-hash-1;
        build(1,cnt,root[0]);
        REP(i,1,n)
        {
            num[i]=lower_bound(hash+1,hash+cnt+1,num[i])-hash;      //离散化
        }
        REP(i,1,n)
        {
            update(root[i-1],num[i],1,cnt,root[i]);     //在第i颗书中插入第i个节点
        }
        int a,b,c;
        REP(i,1,m)
        {
            scanf("%d%d%d",&a,&b,&c);
            int ans=query(root[a-1],root[b],1,cnt,c);
            printf("%d\n",hash[ans]);
        }
    }
    return 0;
}
