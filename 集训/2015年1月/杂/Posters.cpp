/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-25 14:32:41
 |File Name: Posters.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
//#include <cmath>
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
typedef long long ll;

using namespace std;
const int N = 50005;
struct Line {
    int x,y1,y2,c;
}line[N << 3];
int tot;
int n;
int x1,x2,y1,y2,x3,y3,x4,y4;
bool cmp(Line a,Line b) {
    if(a.x != b.x)
        return a.x < b.x;
    else return a.c < b.c;
}
struct Tree {
    int l,r,c,x;
}tree[N << 2];
ll sum;
void build(int l,int r,int rt) {
    tree[rt].l = l; tree[rt].r = r;
    tree[rt].c = 0; tree[rt].x = 0; 
    if(l + 1 == r) return ;
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid,r,R(rt));
}
void fun(int rt) {
    if(tree[rt].c) {
        //cout<<tree[rt].r<<"   "<<tree[rt].l<<endl;
        tree[rt].x = tree[rt].r - tree[rt].l;
    } else if(tree[rt].l + 1 == tree[rt].r) {
        tree[rt].x = 0;
    } else {
        tree[rt].x = tree[L(rt)].x + tree[R(rt)].x;
    }

}
void update(int y1,int y2,int c,int rt) {
    if(tree[rt].l >= y2 || tree[rt].r <= y1) return ;
    if(tree[rt].l >= y1 && y2 >= tree[rt].r) {
        tree[rt].c += c;
        fun(rt);
        return ;
    }
    update(y1,y2,c,L(rt));
    update(y1,y2,c,R(rt));
    fun(rt);
}
int main() {
	freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) && n) {
        tot = 0;
        rep(i,n) {
            scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
            line[tot].x = x1;line[tot].y1 = y1;line[tot].y2 = y2; line[tot].c = 1; tot ++;
            line[tot].x = x3;line[tot].y1 = y1;line[tot].y2 = y2; line[tot].c = -1;tot ++;
            line[tot].x = x3;line[tot].y1 = y4;line[tot].y2 = y2; line[tot].c = 1; tot ++;
            line[tot].x = x4;line[tot].y1 = y4;line[tot].y2 = y2; line[tot].c = -1;tot ++;
            line[tot].x = x3;line[tot].y1 = y1;line[tot].y2 = y3; line[tot].c = 1; tot ++;
            line[tot].x = x4;line[tot].y1 = y1;line[tot].y2 = y3; line[tot].c = -1;tot ++;
            line[tot].x = x4;line[tot].y1 = y1;line[tot].y2 = y2; line[tot].c = 1; tot ++;
            line[tot].x = x2;line[tot].y1 = y1;line[tot].y2 = y2; line[tot].c = -1;tot ++;
        }
        sort(line,line + tot,cmp);
        build(0,50001,1);
        sum = 0;
        //rep(i,tot) cout<<line[i].x<<"    "<<line[i].y1<<"   "<<line[i].y2<<endl;
        for(int i=0;i<tot-1;++i) {
            update(line[i].y1,line[i].y2,line[i].c,1);
            sum += (long long)tree[1].x * (long long)(line[i+1].x - line[i].x);
            cout<<tree[1].x<<endl;
        }
        printf("%I64d\n",sum);
    }
	return 0;
}

