/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/22 13:35:55
 |File Name: b.cpp
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
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int que[5005];
map<int,int> ma;
map<int,int> mb;
int tot;
int n,u;
int top;
char ch[20];
void pa(int u,int ca){
    if(ma[u] > 0) {
        printf("Operation #%d: same priority.\n",ca);
        return ;
    }
    ma[u] = tot;
    que[tot ++] = u;
    printf("Operation #%d: success.\n",ca);
    return ;
}
void pcl(int u,int ca) {
    if(ma[u] == 0) {
        printf("Operation #%d: invalid priority.\n",ca);
        return ;
    }
    printf("Operation #%d: close %d with %d.\n",ca,u,mb[u]);
    int pos = ma[u];
    ma[u] = 0;
    mb[u] = 0;
    for(int i=pos + 1;i < tot;++i) {
        que[i-1] = que[i];
        ma[que[i-1]] = i-1;
    }
    tot --;
    if(top == u) top = -1;
    return ;
}

void pcha(int u,int ca) {
    if(top != -1) {
        mb[top] += u;
        printf("Operation #%d: success.\n",ca);
        return ;
    }
    if(tot == 1) {
        printf("Operation #%d: empty.\n",ca);
        return ;
    }
    mb[que[1]] += u;
    printf("Operation #%d: success.\n",ca);
    return ;
}
void pr(int u,int ca) {     //u是位置
    if(u < 1 ||u >= tot) {
        printf("Operation #%d: out of range.\n",ca);
        return ;
    }
    int t = que[u];
    for(int i=u;i > 1;--i) {
        que[i] = que[i-1];
        ma[que[i]] = i;
    }
    que[1] = t;
    ma[que[1]] = 1;
    printf("Operation #%d: success.\n",ca);
    return ;
}
void pp(int ca) {
    if(tot == 1) {
        printf("Operation #%d: empty.\n",ca);
        return ;
    }
    int p = -1,u = -1;
    for(int i=1;i<tot;++i) {
        if(que[i] > u){
            u = que[i];
            p = i;
        }
    }
    if(p == 1) {
        printf("Operation #%d: success.\n",ca);
        return ;
    }
    int t = que[p];
    for(int i=p;i>1;--i) {
        que[i] = que[i-1];
        ma[que[i]] = i;
    }
    que[1] = t;
    ma[que[1]] = 1;
    printf("Operation #%d: success.\n",ca);
    return ;
}
void pcho(int u,int ca) {
    if(ma[u] == 0) {
        printf("Operation #%d: invalid priority.\n",ca);
        return ;
    }
    int t = u;
    int p = ma[u];
    for(int i=p;i>1;--i) {
        que[i] = que[i-1];
        ma[que[i]] = i;
    }
    que[1] = t;
    ma[que[1]] = 1;
    printf("Operation #%d: success.\n",ca);
    return ;
}

void pt(int u,int ca) {
    if(ma[u] == 0) {
        printf("Operation #%d: invalid priority.\n",ca);
        return ;
    }
    top = u;
    printf("Operation #%d: success.\n",ca);
    return ;
}

void pu(int ca) {
    if(top == -1) {
        printf("Operation #%d: no such person.\n",ca);
        return ;
    }
    top = -1;
    printf("Operation #%d: success.\n",ca);
}

int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        tot = 1;
        top = -1;
        ma.clear();
        mb.clear();
        srep(i,n) {
            scanf("%s",ch);
            if(ch[0] == 'U') {
                pu(i);
            } else if(ch[0] == 'P') {
                pp(i);
            } else {
                scanf("%d",&u);
                if(ch[0] == 'T') {
                    pt(u,i);
                } else if(ch[0] == 'C') {
                    if(ch[1] == 'h') {
                        if(ch[2] == 'a') {
                            pcha(u,i);
                        } else {
                            pcho(u,i);
                        }
                    } else {
                        pcl(u,i);
                    }
                } else if(ch[0] == 'A'){
                    pa(u,i);
                } else if(ch[0] == 'R') {
                    pr(u,i);
                }
            }
            
        }
        if(top != -1) {
            if(mb[top] > 0)printf("Bye %d: %d\n",top,mb[top]);
            for(int i=1;i<tot;++i) {
                if(que[i] == top || mb[que[i]] == 0) continue;
                printf("Bye %d: %d\n",que[i],mb[que[i]]);
            }
        } else {
            for(int i=1;i<tot;++i) {
                if(mb[que[i]] == 0) continue;
                printf("Bye %d: %d\n",que[i],mb[que[i]]);
            }
        }
    }

	return 0;
}

