#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define maxn 110000
struct Node {
    int val;
    ll sum;
    ll add;
    Node* ch[2], *f;
    int size;
    void init() {
        f = ch[0] = ch[1] = NULL;
        size = 1;
        add = 0;
    }
    void rot(int c) {
        Node *y = f,*z = y->f;
        y->ch[!c] = ch[c]; if(ch[c]) ch[c]->f = y;
        f = z;
        if(z) if(z->ch[0] == y) z->ch[0] = this; else z->ch[1] = this;
        ch[c] = y; y->f = this;
        y->update();
    }
    void splay(Node* fa) {
        for(push_down();f != fa;){
            if(f->f == fa){
                if(f->ch[0] == this) rot(1);
                else rot(0);
            } else {
                Node* y=f, *z = y->f;
                if(y->ch[0] == this) {
                    if(z->ch[0] == y){
                        y->rot(1);rot(1);
                    } else {
                        rot(1);rot(0);
                    }
                } else {
                    if(z->ch[0] != y) {
                        y->rot(0);rot(0);
                    } else {
                        rot(0);rot(1);
                    }
                }
            }
        }
        update();
    }
    Node* find(int r){
        push_down();
        int L = 0; if(ch[0]) L += ch[0]->size;
        if(r <= L){
            return ch[0]->find(r);
        }
        if(r == L + 1){
            return this;
        }
        return ch[1]->find(r - L - 1);
    }
    void update() {
        size = 1;
        if(ch[0]) size += ch[0]->size;
        if(ch[1]) size += ch[1]->size;
        sum = val;
        if(ch[0]) sum += ch[0]->sum;
        if(ch[1]) sum += ch[1]->sum;
    }
    void push_down() {
        if(add){
            if(ch[0]) {
                ch[0]->add += add; ch[0]->val += add;
                ch[0]->sum += ch[0]->size * add;
            }
            if(ch[1]) {
                ch[1]->add += add; ch[1]->val += add;
                ch[1]->sum += ch[1]->size * add;
            }
        }
        add = 0;
    }
}dd[maxn];
int e;
inline Node* _alloc() {dd[e].init(); return &dd[e++];}
int d[maxn];
Node* _make(int l,int r) {
    if(l > r) return NULL;
    int mid = (l + r) / 2;
    Node* p = _alloc(); p->val = d[mid];
    p->ch[0] = _make(l,mid-1); if(p->ch[0]) p->ch[0]->f = p;
    p->ch[1] = _make(mid+1,r); if(p->ch[1]) p->ch[1]->f = p;
    p->update(); return p;
}
int main() {
    //freopen("input.txt","r",stdin);
    int n,m,Te = 1;
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;++i) scanf("%d",d+i);
        d[0] = d[n+1] = 0;
        e = 0;
        Node *root = _make(0,n+1),*tmp;
        printf("case #%d:\n",Te ++);
        for(int i=1;i<=m;++i) {
            char op;int a,b,val;
            scanf(" %c",&op);
            if(op == 'a') {
                scanf("%d %d %d",&a,&b,&val); a++; b++;
                tmp = root->find(a-1);
                tmp->splay(NULL);
                root = tmp;
                tmp = root->find(b+1);
                tmp->splay(root);
                tmp = tmp->ch[0];
                tmp->val += val;tmp->add += val;tmp->sum += tmp->size * (ll)val;
                tmp -> splay(NULL);
                root = tmp;
            } else {
                scanf("%d %d",&a,&b);
                a ++; b ++;
                tmp = root -> find(a - 1);
                tmp -> splay(NULL); root = tmp;
                tmp = root -> find(b + 1);
                tmp -> splay(root);
                tmp = tmp -> ch[0];
                printf("%I64d\n",tmp->sum);
            }
        }

    }
    return 0;
}
