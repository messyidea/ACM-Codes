
/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/12 21:59:07
 |File Name: d5.cpp
 |Description:
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;
#define CH 26
#define maxn 100010
int *yy[maxn];
struct DD
{
    int num;
    int kind[2];
    int p;
    DD *fail,*x[CH];
    void init()
    {
        num = 0;
        p = -1;
        kind[0] = kind[1] = 0;
        memset(x,NULL,sizeof(x));
    }
}dd[maxn*4];

int e;
DD* root;
DD *_alloc()
{
    dd[e].init();
    return &dd[e++];
}
void init()
{
    e = 0;
    root = _alloc();
}
void insert(char* ch,int v,int i)
{
    DD *p = root;
    int len = strlen(ch);
    for (int i=0,d;ch[i];i++)
    {
        d = ch[i]-'a';
        if (p->x[d] == NULL) p->x[d] = _alloc();
        p = p->x[d];
    }
    p->num = len;
    yy[i] = &p->kind[v];
}
void fail_pointer()
{
    queue<DD*> que;
    root->fail = root;
    DD*p ;
    for (int i=0;i<CH;++i)
    {
        if (root->x[i])
        {
            root->x[i]->fail = root;
            que.push(root->x[i]);
        }
        else
            root->x[i] = root;
    }
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        for (int i=0;i<CH;++i)
        {
            if (p->x[i])
            {
                p->x[i]->fail = p->fail->x[i];
                que.push(p->x[i]);
            }
            else
                p->x[i] = p->fail->x[i];
        }
    }
}
int work(DD*root,char*s)
{
    int len = strlen(s);
    DD* h = root;
    for (int i=0,d;i<len;++i)
    {
        d = s[i]-'a';
        while (h->x[d]==NULL && h != root) h = h->fail;
        h = h->x[d]== NULL?root:h->x[d];
        DD* tp = h;
        while (tp!=root)
        {
            if (tp->num > 0)
            {
                tp->kind[0]++;
                if (tp->p == -1 || i-tp->p >= tp->num)
                {
                    tp->kind[1]++;
                    tp->p = i;
                }
            }
            tp = tp->fail;
        }
    }
}
char s[maxn];
char ch[10];
int main()
{
    //freopen("input.txt","r",stdin);
    int ccnt = 0;
    int n,v;
    while (scanf("%s",s)!=EOF)
    {
        scanf("%d",&n);
        init();
        for (int i=1;i<=n;++i)
        {
            scanf("%d%s",&v,ch);
            insert(ch,v,i);
        }
        fail_pointer();
        work(root,s);
        printf("Case %d\n",++ccnt);
        for (int i=1;i<=n;++i)
        {
            printf("%d\n",*yy[i]);
        }
        printf("\n");

    }

    return 0;
}
