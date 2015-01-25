
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;

#define MAXN 200005

struct Seg{
    int y,x1,x2;
    int flag;
    bool operator<(const Seg& seg) const{
        return y<seg.y;
    }
} seg[MAXN<<1];

struct Node{
    LL sum,l,r;
    int cover;
    void init(int ll,int rr){
        l = ll,r = rr;
        sum = cover = 0;
    }
} nd[MAXN<<4];

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int x[MAXN<<1];

class SegTree{
public:
    int ql,qr,flag;
    SegTree(int n){
        build(1,n,1);
    }

    void build(int l,int r,int rt){
        nd[rt].init(x[l-1],x[r]);
        if(l==r) return;
        else{
            int mid = (l+r)>>1;
            build(lson);
            build(rson);
            nd[rt].sum = nd[rt<<1].sum+nd[rt<<1|1].sum;
        }
    }

    long long query(int l,int r,int rt){
        return nd[1].sum;
    }

    void push_Up(int l,int r,int rt){
        if(nd[rt].cover) nd[rt].sum = nd[rt].r-nd[rt].l;
        else nd[rt].sum = nd[rt<<1].sum+nd[rt<<1|1].sum;
    }

    void update(int l,int r,int rt){
        if(ql<=l&&r<=qr){
            nd[rt].cover+=flag;
            push_Up(l,r,rt);
        }else{
            int mid = (l+r)>>1;
            if(ql<=mid) update(lson);
            if(mid<qr) update(rson);
            push_Up(l,r,rt);
        }
    }
};

void add_seg(int x1,int y1,int x2,int y2,int &seg_cnt,int &x_cnt){
    x[x_cnt++] = x1;
    x[x_cnt++] = x2;
    if(x1>=x2||y1>=y2) return;
    seg[seg_cnt++] = (Seg){y1,x1,x2,1};
    seg[seg_cnt++] = (Seg){y2,x1,x2,-1};
}

int main(void)
{
    //freopen("data.txt","r",stdin);
    int n;
    while(scanf("%d",&n),n){
        int seg_cnt = 0;
        int x_cnt = 0;
        for(int i = 0;i<n;i++){
            int x1,y1,x2,y2,x3,y3,x4,y4;
            scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
            add_seg(x1,y1,x3,y2,seg_cnt,x_cnt);
            add_seg(x1,y1,x2,y3,seg_cnt,x_cnt);
            add_seg(x1,y4,x2,y2,seg_cnt,x_cnt);
            add_seg(x4,y1,x2,y2,seg_cnt,x_cnt);
        }
        sort(x,x+x_cnt);
        sort(seg,seg+seg_cnt);
        x_cnt = unique(x,x+x_cnt)-x;
        SegTree segtree(x_cnt-1);
        LL ans = 0;
        for(int i = 0;i<seg_cnt-1;i++){
            segtree.ql = lower_bound(x,x+x_cnt,seg[i].x1)-x+1;
            segtree.qr = lower_bound(x,x+x_cnt,seg[i].x2)-x;
          //  cout<<seg[i].x1<<" "<<seg[i].x2<<endl;
            segtree.flag = seg[i].flag;
            segtree.update(1,x_cnt-1,1);
            ans+=segtree.query(1,x_cnt-1,1)*(seg[i+1].y-seg[i].y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
