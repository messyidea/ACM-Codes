#include<algorithm>
#include<cstdio>
#include<cassert>
using namespace std;
const int N = 100005;
int n,splsize;
struct node{
    int flag,sz,ch[2],p;
} tree[N];
struct sample{
    int id,v;
    bool operator < (sample A) const{
        return A.v == v ? id < A.id : v < A.v;
    }
}num[N];
// splay
inline void upt(int x){
    tree[x].sz = tree[tree[x].ch[0]].sz + tree[tree[x].ch[1]].sz+1;
}
inline void setchd(int y,int x,int p){
    tree[y].ch[p] = x; tree[x].p = y;
}
void rot(int x){
    int y = tree[x].p;
    int chd = tree[y].ch[1] == x;
    setchd(tree[y].p,x,tree[tree[y].p].ch[1] == y);
    setchd(y,tree[x].ch[chd^1],chd);
    setchd(x,y,chd^1);
    upt(y);  upt(x);
}
void pushup(int x){
    if(tree[x].flag) {
        tree[x].flag=0;
        swap(tree[x].ch[0],tree[x].ch[1]);
        tree[tree[x].ch[0]].flag ^= 1;
        tree[tree[x].ch[1]].flag ^= 1;
    }
}
void dfs(int x){
    if(!x) return ;
    dfs(tree[x].p);
    pushup(x);
}
void splay(int x,int rt){
    dfs(x);
    while(tree[x].p!=rt){
        int y = tree[x].p;
        int flag = tree[y].ch[1] == x;
        if(tree[tree[x].p].p !=rt && flag == (tree[tree[y].p].ch[1] == y)) rot(y);
        rot(x);
    }
}
// function
void ins(int x){
    setchd(x-1,x,1);
    tree[x].ch[0] = tree[x].ch[1] = tree[x].flag= 0;
    splay(x,0);
}
int cal(int x){
    splay(x,0);
    int ans = tree[tree[x].ch[0]].sz +1;
    tree[tree[x].ch[0]].flag ^=1;
    int u = tree[x].ch[0];
    int v = tree[x].ch[1];
    if(u==0) setchd(0,v,1);
    else if(v==0) setchd(0,u,1);
    else {
        pushup(u); pushup(v);
        while(tree[u].ch[1]){ u = tree[u].ch[1]; pushup(u);}
        while(tree[v].ch[0]){ v = tree[v].ch[0]; pushup(v);}
        splay(u,0);     splay(v,u); 
        assert(tree[v].ch[0] == x);
        tree[v].ch[0] = 0;
    }
    return ans;
}
// main
int main(){
    tree[0].ch[0] = tree[0].ch[1] = tree[0].p = 0;
    while(~scanf("%d",&n) && n){
        for(int i=0; i<n; i++){
            scanf("%d",&num[i].v);
            ins(i+1);
            num[i].id = i;
        }
        sort(num,num+n);
        for(int i=0; i<n; i++){
            int pos = num[i].id + 1;
            int ans = cal(pos) + i;
            if(i) printf(" ");
            printf("%d",ans);
        }
        puts("");
    }
}

