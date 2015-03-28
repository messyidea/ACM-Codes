/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/25 21:34:19
 |File Name: hdu1166.cpp
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
#define maxn 110000
struct Node {
    int val;
    int sum;
    int add;
    Node* ch[2], *f;
    int size;
    void init() {
        f = ch[0] = ch[1] = NULL; size = 1;
        add = 0;    //延迟标记
    }
    void rot(int c) {
        Node *y = f, *z = y->f;
        //y->push_down(); push_down();
        y->ch[!c] = ch[c];  if(ch[c]) ch[c]->f = y;
        f = z;
        if(z) {
            if(y == z->ch[0])   z->ch[0] = this;
            else z->ch[1] = this;
        }
        ch[c] = y;  y->f = this;
        y->update();    //自己暂时不更新,y是原来的fa,在自己下面
    }
    void splay(Node *fa) {
        for(pushdown(); f != fa; ) {    //每次自己要旋转,则需要把标记传递下去,子标记不受影响。
            if(f->f == fa) {
                if(f->ch[0] == this) rot(1);
                else rot(0);
            } else {
                Node *y = f, *z = y->f;
                if(y->ch[0] == this) {
                    if(z->ch[0] == y) {
                        y->rot(1); rot(1);
                    } else {
                        rot(1); rot(0);
                    }
                } else {
                    if(z->ch[0] != y) {
                        y->rot(0); rot(0);
                    } else {
                        rot(0); rot(1);
                    }
                }
            }
        }
        update();   //本节点最后更新
    }
    void pushdown() {
        if(add) {
            if(ch[0]) {
                ch[0]->add += add;
                ch[0]->val += add;
                ch[0]->sum += ch[0]->size * add;
            }
            if(ch[1]) {
                ch[1]->add += add;
                ch[1]->val += add;
                ch[1]->sum += ch[1]->size * add;
            }
            add = 0;
        }
    }

    void update() {
        size = 1;
        if(ch[0]) size += ch[0]->size;
        if(ch[1]) size += ch[1]->size;
        sum = val;
        if(ch[0]) sum += ch[0]->sum;
        if(ch[1]) sum += ch[1]->sum;
    }
    Node* find(int r) {
        pushdown();     //找的时候要维护一些信息。不然找到的节点的信息错误
        int L = 0; if(ch[0]) L += ch[0]->size;
        if(r <= L) return ch[0]->find(r);
        if(r == L+1) return this;
        return ch[1]->find(r-L-1);
    }

}node[maxn];
int e;
inline Node* _alloc() {
    node[e].init(); return &node[e++];
}
int da[maxn];
Node* _make(int l, int r) {
    if(l > r) return NULL;
    int mid = l + r >> 1;   //从中间开始建，树的深度最小
    Node *p = _alloc(); p->val = da[mid];
    p->ch[0] = _make(l, mid-1); if(p->ch[0]) p->ch[0]->f = p;
    p->ch[1] = _make(mid+1, r); if(p->ch[1]) p->ch[1]->f = p;
    p->update();    //子节点更新好之后再更新自己。
    return p;
}
char op[10];
int a, b, c, n;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--) {
        printf("Case %d:\n", ++cas);
        scanf("%d",&n);
        srep(i,n) scanf("%d",&da[i]);
        da[0] = da[n+1] = 0;
        e = 0;
        Node *root = _make(0, n+1), *tp;
        while(scanf("%s",op) != EOF) {
            if(op[0] == 'Q') {
                scanf("%d %d",&a,&b); a++; b++;
                tp = root->find(a - 1);
                tp->splay(NULL); root = tp;
                tp = root->find(b + 1);
                tp->splay(root);
                tp = tp->ch[0];
                printf("%d\n",tp->sum);
            } else if(op[0] == 'A') {
                scanf("%d %d",&a,&b); a++;
                tp = root->find(a-1);
                tp->splay(NULL);    root = tp;
                tp = root->find(a+1);
                tp->splay(root);
                tp = tp->ch[0];
                tp->sum += b;
            } else if(op[0] == 'S') {
                scanf("%d %d",&a,&b); a++;
                tp = root->find(a-1);
                tp->splay(NULL);    root = tp;
                tp = root->find(a+1);
                tp->splay(root);
                tp = tp->ch[0];
                tp->sum -= b;
            } else break;
        }
    }
	return 0;
}

