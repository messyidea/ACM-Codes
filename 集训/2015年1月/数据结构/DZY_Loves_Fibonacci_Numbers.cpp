#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300005
#define MOD 1000000009
#define ll long long
#define len (r-l+1)
#define lenl (mid-l+1)
#define lenr (r-mid)
#define lo (o<<1)
#define ro (lo|1)
#define mid ((l+r)>>1)
using namespace std;

ll F[N],num[N],a[4*N],b[4*N],ka[N],kb[N],suma[N],sumb[N],sum[N],s[4*N];
int n,m,lx,rx;

void pre()
{
	ka[0]=0;
	ka[1]=1; 
	ka[2]=0;
	suma[0]=0;
	for (int i=1;i<N;i++)
	{
		if (i>2) ka[i]=(ka[i-1]+ka[i-2])%MOD;
		suma[i]=(suma[i-1]+ka[i])%MOD;
	}
	
	kb[0]=0;
	kb[1]=0;
	kb[2]=1;
	sumb[0]=0;
	for (int i=1;i<N;i++)
	{
		 if (i>2) kb[i]=(kb[i-1]+kb[i-2])%MOD;
		 sumb[i]=(sumb[i-1]+kb[i])%MOD;
	}
	
	F[0]=0;
	F[1]=F[2]=1;
	for (int i=3;i<N;i++) F[i]=(F[i-1]+F[i-2])%MOD;
}

void down(int o,int l,int r)
{
	a[lo]=(a[lo]+a[o])%MOD;
	if (lenl>1) b[lo]=(b[lo]+b[o])%MOD;
	a[ro]=(a[ro]+ka[lenl+1]*a[o]%MOD + kb[lenl+1]*b[o]%MOD)%MOD;
	if (lenr>1) b[ro]=(b[ro]+ka[lenl+2]*a[o]%MOD + kb[lenl+2]*b[o]%MOD)%MOD;
	a[o]=b[o]=0;
}

ll getS(ll a,ll b,int k)
{
	return (a*suma[k]%MOD+b*sumb[k]%MOD)%MOD;
}

void up(int o,int l,int r)
{
	s[o]=(s[lo]+s[ro])%MOD;
	s[o]=(s[o]+getS(a[lo],b[lo],lenl))%MOD;
	s[o]=(s[o]+getS(a[ro],b[ro],lenr))%MOD;
}

void add(int o,int l,int r)
{
	ll ta,tb;
	
	if (lx<=l && r<=rx)
	{
		a[o]=(a[o]+F[l-lx+1])%MOD;
		if (l<r) b[o]=(b[o]+F[l+1-lx+1])%MOD;
		return;
	}
	down(o,l,r);
	if (lx<=mid) add(lo,l,mid);
	if (rx>mid) add(ro,mid+1,r);
	up(o,l,r);  
}

ll ask(int o,int l,int r)
{
	ll ret=0;
	if (lx<=l && r<=rx) return (s[o]+getS(a[o],b[o],len))%MOD;
	down(o,l,r);
	if (lx<=mid) ret=(ret+ask(lo,l,mid))%MOD;
	if (rx>mid) ret=(ret+ask(ro,mid+1,r))%MOD;
	up(o,l,r);
	return ret;
}

int main()
{
	int t;
	
	pre();
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(s,0,sizeof(s));
	scanf("%d%d",&n,&m);
	
	sum[0]=0;
	for (int i=1;i<=n;i++) 
	{
		scanf("%I64d",num+i);
		sum[i]=(sum[i-1]+(ll)num[i])%MOD;
	}
	
	while (m--)
	{
		scanf("%d%d%d",&t,&lx,&rx);
		if (t==1) add(1,1,n);
		else printf("%I64d\n",(sum[rx]-sum[lx-1]+MOD+ask(1,1,n))%MOD);
	}
	
	return 0;
}