
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#define N 55
using namespace std;

struct point
{
	int x,y,id;
}a[N],b[N],c[N],t,o;
bool flag[N];
int num,n,m,ans[N],fst,tot;

double dis(point p,point q)
{
	return sqrt(double(pow(1.0*(p.x-q.x),2)+pow(1.0*(p.y-q.y),2)));
}
int cross(point p1,point o,point p2)
{
	return (p1.x-o.x)*(p2.y-o.y)-(p2.x-o.x)*(p1.y-o.y); 
}


void solve()
{
	o.x=0;
	o.id=-1;
	
	for (int cur=0;cur<n;cur++)
	{
		t.id=-1;
		for (int i=0;i<n;i++)
		{
			if (a[i].id==o.id || flag[i])continue;
			if (t.id==-1 || cross(a[i],o,t)>0 || cross(a[i],o,t)==0 && dis(a[i],o)<dis(t,o)) t=a[i];
		}
		
		o=t;
		ans[cur]=t.id;
		flag[t.id-1]=1;
	}
	
}

int main()
{
	int t0;
	
	scanf("%d",&t0);
	while (t0--)
	{
		scanf("%d",&n);
		o.y=101;
		for (int i=0;i<n;i++) 
		{
			scanf("%d%d%d",&a[i].id,&a[i].x,&a[i].y);
			o.y=min(o.y,a[i].y);
		}
		
		memset(flag,0,sizeof(flag));
		solve();
		
		printf("%d",n);
		for (int i=0;i<n;i++) printf(" %d",ans[i]);

		printf("\n");
	}
}
