
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#define EPS 1e-7
#define N 100005
#define M 1005
using namespace std;

struct stick
{
	double x,y,p,q;
}a[N];
int b[N],c[N],tot,n,t;
bool del[N];

double cross(double x,double y,double ox,double oy,double p,double q)
{
	return (x-ox)*(q-oy)-(y-oy)*(p-ox);
}

bool ok(stick a,stick b)	//注意共线 
{
	if (min(a.x,a.p)>max(b.x,b.p) || max(a.x,a.p)<min(b.x,b.p)) return 1;
	if (min(a.y,a.q)>max(b.y,b.q) || max(a.y,a.q)<min(b.y,b.q)) return 1;
	if (cross(a.x,a.y,a.p,a.q,b.x,b.y)*cross(a.x,a.y,a.p,a.q,b.p,b.q)<=0 
			&& cross(b.x,b.y,b.p,b.q,a.x,a.y)*cross(b.x,b.y,b.p,b.q,a.p,a.q)<=0) return 0;
	return 1;
}

int main()
{
	while (~scanf("%d",&n) && n)
	{
		tot=0;
		for (int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].p,&a[i].q);
		}
		
		for (int i=0;i<n;i++)
		{
			t=0;
			for (int j=0;j<tot;j++)
				if (ok(a[i],a[b[j]])) c[t++]=b[j];
		
			c[t++]=i;
			
			tot=0;
			for (int j=0;j<t;j++) b[tot++]=c[j];
		}
		
		printf("Top sticks: ");
		for (int i=0;i<tot;i++)
		{
			if (i) printf(", ");
			printf("%d",b[i]+1);
		}
		printf(".\n");
	}
}
