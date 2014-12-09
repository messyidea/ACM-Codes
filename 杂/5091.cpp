#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
#define lson i*2,l,m
#define rson i*2+1,m+1,r
const int MAXN=20000+5;//因为点有1W个,所以扫描线2W个,不同的Y坐标最多有2W个
int cnt[MAXN*4],sum[MAXN*4];
double Y[MAXN];
struct seg
{
    double l,r,h;
    int d;
    seg(){}
    seg(double a,double b,double c,int d):l(a),r(b),h(c),d(d){}
    bool operator <(const seg&b)const
    {
        if(h == b.h) return d>b.d;
        return h<b.h;
    }
}ss[MAXN];
void PushUp(int i)
{
    sum[i]=max(sum[i*2],sum[i*2+1]) + cnt[i];
}
void update(int ql,int qr,int v,int i,int l,int r)
{
    if(ql<=l && r<=qr)
    {
        cnt[i]+=v;
        sum[i]+=v;
        return ;
    }
    int m=(l+r)>>1;
    if(ql<=m) update(ql,qr,v,lson);
    if(m<qr) update(ql,qr,v,rson);
    PushUp(i);
}
int main()
{
    int n;
    double w,h;
    while(~RD(n))
    {
        if(n == -1)
            break;
        scanf("%lf%lf",&w,&h);
        w+=0.5,h+=0.5;
        double x,y;
        int val;
        int cnt_y=0,cnt_ss=0;//记录有多少个Y值和扫描线
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&x,&y);
            //x+=20000,y+=20000;
            ss[cnt_ss++] = seg(y-h/2,y+h/2,x-w/2,1);
            ss[cnt_ss++] = seg(y-h/2,y+h/2,x+w/2,-1);
            Y[cnt_y++] = y-h/2;
            Y[cnt_y++] = y+h/2;
        }
        sort(ss,ss+cnt_ss);
        sort(Y,Y+cnt_y);
        cnt_y = unique(Y,Y+cnt_y)-Y;
        int ans=0;
        clr0(cnt),clr0(sum);
        for(int i=0;i<cnt_ss-1;i++)
        {
            int ql=lower_bound(Y,Y+cnt_y,ss[i].l)-Y;
            int qr=lower_bound(Y,Y+cnt_y,ss[i].r)-Y-1;  
            if(ql<=qr) update(ql,qr,ss[i].d,1,0,cnt_y-1);
            ans=max(ans,sum[1]);
        }
        printf("%d\n",ans);
    }
}
