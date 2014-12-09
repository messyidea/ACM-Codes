#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <algorithm>  
#include <map>  
using namespace std;  
#define BigInteger long long  
const int Max = 200005;  
const int Maxn =Max<<1;  
struct node1  
{  
    BigInteger x,y,w;  
} Point[Max*2];  
struct node2  
{  
    BigInteger maxsum,lsum,rsum,sumval;  
} light[Maxn<<2];  
BigInteger num[Maxn<<1];  
BigInteger max(BigInteger a, BigInteger b)  
{  
    if(a<b)a=b;  
    return a;  
}  
int cmp1(const void *a,const void *b)  
{  
    struct node1 *aa=(struct node1 *)a;  
    struct node1 *bb=(struct node1 *)b;  
    return aa->x-bb->x;  
}  
void PushUp(int tr ,BigInteger val)  
{  
    light[tr].sumval+=val;  
    light[tr].lsum=max(light[tr<<1].lsum,light[tr<<1].sumval+light[tr<<1|1].lsum);  
    light[tr].rsum=max(light[tr<<1|1].rsum,light[tr<<1|1].sumval+light[tr<<1].rsum);  
    light[tr].maxsum=max(max(light[tr<<1].maxsum,light[tr<<1|1].maxsum),light[tr<<1].rsum+light[tr<<1|1].lsum);  
  
}  
void update(int p,BigInteger add,int l,int r,int tr)  
{  
    if(l==r)  
    {  
        light[tr].sumval+=add;  
        light[tr].lsum=light[tr].sumval;  
        light[tr].rsum=light[tr].sumval;  
        light[tr].maxsum=light[tr].sumval;  
        return ;  
    }  
    int m=(l+r)>>1;  
    if(p<=m)update(p,add,l,m,tr<<1);  
    else update(p,add,m+1,r,tr<<1|1);  
    PushUp(tr,add);  
}  
void build(int l,int r,int tr)  
{  
  
    light[tr].sumval=0;  
    light[tr].lsum=-(1LL<<60);  
    light[tr].rsum=-(1LL<<60);  
    light[tr].maxsum=-(1LL<<60);  
    if(l==r)  
    {  
        return ;  
    }  
    int m=(l+r)>>1;  
    build(l,m,tr<<1);  
    build(m+1,r,tr<<1|1);  
}  
int Bserch(int l,int r,BigInteger key)  
{  
    while(l<=r)  
    {  
        int m=(l+r)>>1;  
        if(num[m]<key)l=m+1;  
        else if(num[m]>key)r=m;  
        else return m;  
    }  
}  
int main()  
{  
    freopen("input.txt","r",stdin);
    int w,h,n;  
    while(scanf("%d%d%d",&n)!=EOF)  
    {  
        if(n == -1) break;
        scanf("%d %d",&w,&h);
        for(int i=1; i<=n; i++)  
        {  
            Point[i].w = 1;
            scanf("%I64d%I64d",&Point[i].x,&Point[i].y); 
           Point[i].x += 20005; 
           Point[i].y += 20005;
            num[i]=Point[i].y;  
            num[i+n]=Point[i].y+h;  
        }  
        qsort(Point+1,n,sizeof(Point[0]),cmp1);  
        sort(num+1,num+1+n+n);  
        int cnt=2;  
        for(int i=2; i<=2*n; i++)  
        {  
            if(num[i]!=num[i-1])  
            {  
                num[cnt++]=num[i];  
            }  
        }  
        cnt--;  
        build(1,cnt,1);  
        BigInteger ans=0;  
        int j=1,tl;  
        for(int i=1; i<=n; i++)  
        {  
             while(j<i&&Point[j].x+w<=Point[i].x)  
            {  
                tl=Bserch(1,cnt,Point[j].y);  
                update (tl,-Point[j].w,1,cnt,1);  
                tl=Bserch(1,cnt,Point[j].y+h);  
                update (tl,Point[j].w,1,cnt,1);  
                j++;  
            }  
            tl=Bserch(1,cnt,Point[i].y+h);  
            update (tl,-Point[i].w,1,cnt,1);  
            tl=Bserch(1,cnt,Point[i].y);  
            update (tl,Point[i].w,1,cnt,1);  
            ans=max(ans,light[1].maxsum);  
        }  
        printf("%I64d\n",ans);  
    }  
    return 0;  
}  

