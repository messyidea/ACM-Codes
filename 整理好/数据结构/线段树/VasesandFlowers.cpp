/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/1 21:26:18
 |File Name: VasesandFlowers.cpp
 |Description: 线段树太渣了。。写不好啊。。模仿的。按照自己的通常的写法重写了一遍。 
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
using namespace std;
const int N = 50005;
struct Tree{
    int l,r,sum,cover;
}tree[N<<2];
int n,m;
void build(int l,int r,int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = 0;
    tree[rt].cover = -1;
    if(l == r) return;
    int mid = (l+r)>>1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}
void pushdown(int rt){
    tree[L(rt)].sum = tree[rt].cover * (tree[L(rt)].r - tree[L(rt)].l + 1);
    tree[L(rt)].cover = tree[rt].cover;
    tree[R(rt)].sum = tree[rt].cover * (tree[R(rt)].r - tree[R(rt)].l + 1);
    tree[R(rt)].cover = tree[rt].cover;
    tree[rt].cover = -1;
}
int query(int l,int r,int rt){
    if(l == tree[rt].l && r == tree[rt].r){
        return tree[rt].sum;
    }
    if(tree[rt].cover >= 0){
        pushdown(rt);
    }
    int ans = 0;
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(r <= mid) ans += query(l,r,L(rt));
    else if(l >= mid + 1) ans += query(l,r,R(rt));
    else{
        ans += query(l,mid,L(rt));
        ans += query(mid+1,r,R(rt));
    }
    return ans;
}
void pushup(int rt){
    tree[rt].sum = tree[L(rt)].sum + tree[R(rt)].sum;
}
void update(int l,int r,int d,int rt){
    if(l == tree[rt].l && r == tree[rt].r){
        tree[rt].cover = d;
        tree[rt].sum = (r-l+1)*d;
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r )>>1;
    if(r <= mid) update(l,r,d,L(rt));
    else if(l >= mid + 1) update(l,r,d,R(rt));
    else{
        update(l,mid,d,L(rt));
        update(mid+1,r,d,R(rt));
    }
    pushup(rt);
}
int search(int l,int r,int want){
    int mid;
    int a = l;		//l会变化 
    while(l < r){
        mid = (l+r)>>1;
        int tp = query(a,mid,1);
        if(mid - a + 1 >= want + tp) r = mid;
        else l = mid+1;
    }
    return l;
}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        n--;
        build(0,n,1);
        int a,b,c;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            if(a == 1){
                int rsum = query(b,n,1);
                if(rsum == n-b+1) printf("Can not put any one.\n");
                else{
                	int lsum;
                	if(b == 0) lsum = 0;
                	else lsum = query(0,b-1,1);
                    int pos = search(0,n,b-lsum+1);
                    int pos2 = search(b,n,min(n-b+1-rsum,c));
                    printf("%d %d\n",pos,pos2);
                    update(pos,pos2,1,1);
                }
            }
            else{
                printf("%d\n",query(b,c,1));
                update(b,c,0,1);
            }
        }
        printf("\n");
    }
	return 0;
}

