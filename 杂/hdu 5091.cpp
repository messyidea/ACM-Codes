#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

#define eps 1e-8
typedef long long LL;

struct node
{
    node* left,*right;
    int l,r;
    int value;
    int wait;
} tree[800010];

double line[801000];
int num=0;
int n;
double W,H;
int count1=0;
void buildtree(node* p,int l,int r)
{
    p->l=l,p->r=r;
    p->value=0,p->wait=0;
    if(l==r)return ;
    int middle=(l+r)/2;
    count1++;
    p->left=tree+count1;
    buildtree(tree+count1,l,middle);
    count1++;
    p->right=tree+count1;
    buildtree(tree+count1,middle+1,r);
}
void update(node* p,int l,int r,int c)
{
    if(l<=p->l&&r>=p->r)
    {
        p->value+=c;
        p->wait+=c;
        return ;
    }
    int middle=(p->l+p->r)/2;
    if(r<=middle)
        update(p->left,l,r,c);
    else if(l>middle)
        update(p->right,l,r,c);
    else
    {
        update(p->left,l,middle,c);
        update(p->right,middle+1,r,c);
    }
    p->value=max(p->left->value,p->right->value)+p->wait;
}
struct point
{
    double x;
    double up,down;
    int cost;
} points[800010];
bool operator<(point a,point b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    return b.cost>0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        scanf("%lf%lf",&W,&H);
        W+=0.01;
        H+=0.01;
        memset(tree,0,sizeof tree);
        num=0;
        count1=0;
        int t=0;
        for(int i=0; i<n; i++)
        {
            int x,y,cost;
            scanf("%d%d",&x,&y);
            points[t].x=x-W/2;
            points[t].up=y+H/2;
            points[t].down=y-H/2;
            points[t++].cost=1;

            points[t].x=x+W/2;
            points[t].up=y+H/2;
            points[t].down=y-H/2;;
            points[t++].cost=-1;

             line[num++]=y+H/2;
            line[num++]=y-H/2;
        }
        sort(points,points+t);
        sort(line,line+num);
        num=unique(line,line+num)-line;
        buildtree(tree,0,num-2);
        int ans=0;
        for(int i=0; i<t; i++)
        {
            int l=lower_bound(line,line+num,points[i].down)-line;
            int r=lower_bound(line,line+num,points[i].up)-line;
            update(tree,l,r,points[i].cost);
            ans=max(ans,tree->value);
        }
        printf("%d\n",ans);
    }
    return 0;
}
