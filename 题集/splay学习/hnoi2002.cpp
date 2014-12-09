#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define maxn 110000
#define inf 0x3f3f3f3f
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
Node* root;
int e;
inline Node* _alloc() {dd[e].init(); return &dd[e++];}
int d[maxn];
int ins(int u){
    Node* r = root;
    Node* tp;
    while(true){
        if(r->val == u){
            r->splay(NULL);
            root = r;
            return 0;
        }
        tp = r->ch[r->val < u];
        //r = r->ch[r->value < u];
        if(tp == NULL){
           Node* tp = _alloc();
           tp->f = r;
           r->ch[r->val < u] = tp;
           tp->ch[0] = tp->ch[1] = NULL;
           tp->val = u;
           tp->splay(NULL);
           root = tp;
           return 1; 
        }
        r = tp;
    }
}
int finds(int tp){
    Node* r = root->ch[0];
    if(r == NULL) return inf;
    while(r->ch[1]!=NULL) r = r->ch[1];
    return tp - r->val;
}
int findt(int tp){
    Node* r = root->ch[1];
    if(r == NULL) return inf;
    while(r->ch[0]!=NULL) r = r->ch[0];
    return r->val - tp;
}
int main() {
    int n;
    int tp;
    while(~scanf("%d",&n)) {
        root = NULL;
        ll sum = 0;
        scanf("%d",&tp);
        sum += tp;
        root = _alloc();
        root->ch[0] = root->ch[1] = NULL;
        root ->val = tp;
        for(int i=0;i<n-1;++i){
            scanf("%d",&tp);
            if(ins(tp) == 0) continue;
            int s = finds(tp);
            int t = findt(tp);
            sum += min(s,t);
        }
        cout<<sum<<endl;
    }
    return 0;
}
