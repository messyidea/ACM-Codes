#include<cstdio>  
#include<cstring>  
#include<vector>  
#include<algorithm>
#include <iostream>
  
using namespace std;  
  
const int N=50050;  
  
struct Interval{  
    int l,r,id;  
}in[N];  
  
struct Tree{  
    int l,r,Max;  
}tree[N<<2];  
  
int n,m;  
int a[N];  
int pre[N];  
int ans[N];  
vector<int> factor[N];  
  
  
void init(){  
    for(int i=1;i<N;i++)  
        for(int j=i;j<N;j+=i)  
            factor[j].push_back(i);  
}  
  
bool cmp(struct Interval a,struct Interval b){  
    return a.r<b.r;  
}  
  
void build(int l,int r,int id){  
    tree[id].l=l;  
    tree[id].r=r;  
    tree[id].Max=0;  
    if(l!=r){  
        int mid=(l+r)>>1;  
        build(l,mid,id<<1);  
        build(mid+1,r,id<<1|1);  
    }  
}  
  
void update(int pos,int val,int id){  
    tree[id].Max=max(tree[id].Max,val);  
    if(tree[id].l==tree[id].r) return ;  
    int mid=(tree[id].l+tree[id].r)>>1;  
    if(mid>=pos) update(pos,val,id<<1);  
    else update(pos,val,id<<1|1);  
}  
  
int query(int l,int r,int id){  
    if(tree[id].l==l && tree[id].r==r) return tree[id].Max;  
    int mid=(tree[id].l+tree[id].r)>>1;  
    if(mid>=r) return query(l,r,id<<1);  
    else if(mid<l) return query(l,r,id<<1|1);  
    else return max(query(l,mid,id<<1),query(mid+1,r,id<<1|1));  
}  
  
int main(){
    freopen("input.txt","r",stdin); 
    init();  
    int t,T;  
    int i,j,k;  
    scanf("%d",&T);  
    for(t=1;t<=T;t++){  
        scanf("%d",&n);  
        build(1,n,1);  
        for(i=1;i<=n;i++){  
            scanf("%d",&a[i]);  
        }  
        scanf("%d",&m);  
        for(i=0;i<m;i++){  
            scanf("%d %d",&in[i].l,&in[i].r);  
            in[i].id=i;  
        }  
        sort(in,in+m,cmp);  
        memset(pre,0,sizeof(pre));  
        for(i=1,j=0;i<=n && j<m;i++){  
            for(k=0;k<factor[a[i]].size();k++) { 
                //cout<<a[i]<<"      "<<factor[a[i]][k]<<endl; 
                int tem=factor[a[i]][k];    //因子
                if(pre[tem]!=0){  
                    update(pre[tem],tem,1);  
                }  
                pre[tem]=i; 
                //cout<<"    "<<pre[i]<<"  "<<endl;
            }  
            while(j<m && in[j].r==i){  
                ans[in[j].id]=query(in[j].l,in[j].r,1);  
                j++;  
            }  
        }  
        for(i=0;i<m;i++) printf("%d\n",ans[i]);  
    }  
    return 0;  
}  
