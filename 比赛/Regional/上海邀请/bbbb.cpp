
#include<iostream>
#include <cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 30012
struct node
{
    int sum,maxsum;
    int left,right;
};
struct star
{
    long long x,y;
    int degree;
    int id;
};
node tree[MAXN*4];
star a[MAXN];
int home[MAXN];
int width,high;
int n;
void buildtree(int i)
{
    tree[i].sum=tree[i].maxsum=0;
    if(tree[i].left==tree[i].right)
    return ;
    int mid=(tree[i].left+tree[i].right)/2;
    tree[2*i].left=tree[i].left; tree[2*i].right=mid;
    tree[2*i+1].left=mid+1; tree[2*i+1].right=tree[i].right;
    buildtree(2*i); buildtree(2*i+1);
}
bool cmp1(const star &x,const star &y)
{
    if(x.y<y.y) return 1;
    if(x.y==y.y&&x.x<y.x) return 1;
    return 0;
} 
bool cmp2(const star &x,const star &y)
{
    return x.x<y.x;
}
void insert(int i,int x,int add)
{
    if(tree[i].left==tree[i].right)
    {
        tree[i].maxsum=tree[i].sum=tree[i].sum+add;
        return ;
    }
    int mid=(tree[i].left+tree[i].right)/2;
    if(x<=mid) insert(2*i,x,add);
    else insert(2*i+1,x,add);
    tree[i].sum+=add;
    tree[i].maxsum=max(tree[2*i].sum+tree[2*i+1].maxsum,tree[2*i].maxsum);
}
int main()
{   
    freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        scanf("%d%d",&width,&high);
        int i,j,k;
       
        int x,y,z;
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].x,&a[i].y);
            a[i].degree=1;
            a[i].x += 20005;
            a[i].y += 20005;
            a[i].id=i; a[i+n].id=i+n;
            a[i+n].x=a[i].x; a[i+n].y=a[i].y+high; a[i+n].degree=-a[i].degree;
        }
        n=2*n;
        sort(a+1,a+n+1,cmp1);
        j=0;
        a[j].x=-1; a[j].y=-1;
        for(i=1;i<=n;i++) 
        {
            if(a[i].y==a[j].y&&a[i].x==a[j].x)
            {
                a[j].degree+=a[i].degree;
            }
            else
            {
                j++; a[j].x=a[i].x; a[j].y=a[i].y; a[j].id=a[i].id; a[j].degree=a[i].degree;
                home[a[j].id]=j;
            }
        }
        n=j;
        tree[1].left=1; tree[1].right=n;
        buildtree(1);
        sort(a+1,a+n+1,cmp2);
        long long l1,l2;
        l1=a[1].x; l2=l1+width;
        i=1; j=0;
        int ans=0;
        while(j<n)
        {
            if(a[i].x-l1<a[j+1].x-l2)//必须是小于等于 左开右闭
            {
                l1=a[i].x;
                while(a[i].x==l1)//每次一定要把线上的所有点都处理了 
                {
                    insert(1,home[a[i].id],-a[i].degree); i++; 
                }               
                l2=l1+width;
            }         
            else
            {
                l2=a[j+1].x;
                while(a[j+1].x==l2)
                {
                    j++; insert(1,home[a[j].id],a[j].degree);
                }
                l1=l2-width;
            }
            if(tree[1].maxsum>ans) ans=tree[1].maxsum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
