
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

#define MAXN 102000
#define MOD 51061

int sz;
int ch[MAXN][2],f[MAXN];
int rev[MAXN],w[MAXN];
unsigned int sum[MAXN],mul[MAXN],add[MAXN],node[MAXN];


void newnode(int keys)
{
    int p=++sz;
    sum[p]=node[p]=keys;
    rev[p]=ch[p][0]=ch[p][1]=f[p]=0;
    mul[p]=1;
    add[p]=0;
    w[p]=1;
}

 bool isroot(int x)
{
    return (!f[x]||ch[f[x]][0]!=x&&ch[f[x]][1]!=x);
}

void update(int rt,int m,int a)
{
    if(!rt) return;
    node[rt]=(node[rt]*m+a)%MOD;
    sum[rt]=(sum[rt]*m+a*w[rt])%MOD;
    mul[rt]=(mul[rt]*m)%MOD;
    add[rt]=(add[rt]*m+a)%MOD;
}

void push_up(int rt)
{
    if(!rt) return ;
    int l=ch[rt][0];
    int r=ch[rt][1];
    sum[rt]=node[rt];
    w[rt]=1;
    if(l) sum[rt]=(sum[rt]+sum[l])%MOD,w[rt]+=w[l];
    if(r) sum[rt]=(sum[rt]+sum[r])%MOD,w[rt]+=w[r];
}

void push_down(int rt)
{
    if(!rt) return;
    int l=ch[rt][0];
    int r=ch[rt][1];
    if(rev[rt])
    {
        swap(ch[rt][0],ch[rt][1]);
        rev[l]^=1;rev[r]^=1;
        rev[rt]=0;
    }
    if(mul[rt]!=1 || add[rt]!=0)
    {
        update(l,mul[rt],add[rt]);
        update(r,mul[rt],add[rt]);
        mul[rt]=1;
        add[rt]=0;
    }
}

void rotate(int x,int c)
{
    if(isroot(x)) return;
    int y=f[x],z=f[y];
    ch[y][!c]=ch[x][c];
    if(ch[x][c]) f[ch[x][c]]=y;
    ch[x][c]=y;
    if(f[y])
    {
        if(ch[f[y]][0]==y)
            ch[f[y]][0]=x;
        if(ch[f[y]][1]==y)
            ch[f[y]][1]=x;
    }
    f[y]=x;f[x]=z;
    push_up(y);
}

void splay(int x)
{
    int y,z;
    push_down(x);
    while(!isroot(x))
    {
        y=f[x],z=f[y];
        if(isroot(y))
        {
            push_down(y);push_down(x);
            if(ch[y][0]==x)
                rotate(x,1);
            else
                rotate(x,0);
        }
        else
        {
            push_down(z);push_down(y);push_down(x);
            if(ch[z][0]==y)
            {
                if(ch[y][0]==x)
                    rotate(y,1),rotate(x,1);
                else
                    rotate(x,0),rotate(x,1);
            }
            else
            {
                if(ch[y][1]==x)
                    rotate(y,0),rotate(x,0);
                else
                    rotate(x,1),rotate(x,0);
            }
        }
    }
    push_up(x);
}

int Access(int u)
{
    int v=0;
    for(;u;u=f[u])
    {
        splay(u);
        ch[u][1]=v;
        push_up(v=u);
    }
    return v;
}

void makeRoot(int u)
{
    int p=Access(u);
    rev[p]^=1;
    splay(u);
}

int findRoot(int x) {
    for (x = Access(x); push_down(x),ch[x][0]!=0 ; x = ch[x][0]);
    splay(x);
    return x;
}
bool link(int u,int v)
{
	if(findRoot(u)==findRoot(v)) return false;
	makeRoot(u);
	f[u]=v;
	Access(u);
	return true;
}

bool cut(int u,int v)
{
	if(u==v||findRoot(u)!=findRoot(v)) return false;
	makeRoot(u);
	Access(v);
	splay(v);
	f[ch[v][0]]=0;
	ch[v][0]=0;
	push_up(v);
	return true;
}

bool modify(int u,int v,int m,int a) {
    if (findRoot(u)!=findRoot(v)) return false;
    makeRoot(u);
    Access(v);
    splay(v);
    update(v,m,a);
    return true;
}

bool query(int u,int v,int &ans) {
    if (findRoot(u)!=findRoot(v)) return false;
    makeRoot(u);
    Access(v);
    splay(v);
    ans=sum[v];
    return true;
}

int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        sz=0;
        int u,v,w;
        char str[3];
        for(int i=0;i<n;i++)
            newnode(1);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            link(u,v);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%s",str);
            if(str[0]=='*')
            {
                scanf("%d%d%d",&u,&v,&w);
                modify(u,v,w,0);
            }
            else if(str[0]=='+')
            {
                scanf("%d%d%d",&u,&v,&w);
                modify(u,v,1,w);
            }
            else if(str[0]=='-')
            {
                scanf("%d%d",&u,&v);
                cut(u,v);
                scanf("%d%d",&u,&v);
                link(u,v);
            }
            else if(str[0]=='/')
            {
                long long ans;
                scanf("%d%d",&u,&v);
                query(u,v,w);
                printf("%d\n",w);
            }
        }
    }
    return 0;
}

