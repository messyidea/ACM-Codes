
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 55555;

struct Node *nill;

struct Node {
        Node *ch[2],*fa;
        int sum,val,sz;
        void setc(Node *o,int c) {
                ch[c] = o;
                o->fa = this;
                up();
        }
        void up() {
                if (this==nill) return ;
                sum = ch[0]->sum + ch[1]->sum + val;
                sz = ch[0]->sz + ch[1]->sz + 1;
        }
        bool d() {
                return fa->ch[1]==this;
        }
}memo[N],*bat,*idx[N];
void newNode(Node *&o,int val = 0) {
        o = bat++;
        o->ch[0] = o->ch[1] = o->fa = nill;
        o->sum = o->val = val;
        o->sz = 1;
}
void init() {
        bat = memo;
        newNode(nill); nill->sz = 0;
}
void rot(Node *o) {
        int c = o->d();
        Node *tmp = o->fa;
        tmp->setc(o->ch[c^1],c);
        tmp->fa->setc(o,tmp->d());
        o->setc(tmp,c^1);
}
void splay(Node *o,Node *p) {
        while (o->fa!=p) {
                if (o->fa->fa==p) {
                        rot(o);
                } else {
                        o->d()==o->fa->d() ? (rot(o->fa),rot(o)) : (rot(o),rot(o));
                }
        }
}
Node *findK(Node *o,int K) {
        while (true) {
                if (o->sz==K) return o;
                if (o->ch[0]->sz >= K) {
                        o = o->ch[0];
                } else {
                        K -= o->ch[0]->sz - 1;
                        o = o->ch[1];
                }
        }
}
void modify(int p,int dt) {
        splay(idx[p-1],nill);
        splay(idx[p+1],idx[p-1]);
        idx[p+1]->ch[0]->val += dt;
        idx[p+1]->ch[0]->up();
}
int query(int l,int r) {
        splay(idx[l-1],nill);
        splay(idx[r+1],idx[l-1]);
        return idx[r+1]->ch[0]->sum;
}
void show(Node *o) {
        if (o==nill) return ;
        show(o->ch[0]);
        printf("%d ",o->val);
        show(o->ch[1]);
}
int main() {
        int cas,ca = 0,n;
        scanf("%d",&cas);
        while (cas--) {
                printf("Case %d:\n",++ca);
                init();
                scanf("%d",&n);
                newNode(idx[0]);
                for (int i = 1; i <= n; i ++) {
                        int x;
                        scanf("%d",&x);
                        newNode(idx[i],x);
                        idx[i]->setc(idx[i-1],0);
                }
                newNode(idx[n+1]);
                idx[n+1]->setc(idx[n],0);
                char s[13];
                int a,b;
                while (scanf("%s",s)==1) {
                        if (s[0]=='E') break;
                        scanf("%d%d",&a,&b);
                        if (s[0]=='A') {
                                modify(a,b);
                        } else if (s[0]=='S') {
                                modify(a,-b);
                        } else {
                                printf("%d\n",query(a,b));
                        }
                }
        }
        return 0;
}
