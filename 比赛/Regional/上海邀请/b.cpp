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
using namespace std;  
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int MAXN = 50005;  
  
int c[MAXN],n;  
  
int lowbit(int x){return x & (-x);}  
  
int sum(int n){  
    int sum = 0;
    while(n > 0){  
        sum += c[n];  
        n -= lowbit(n);  
    }  
    return sum;  
}  
 
void add(int x){  
    while(x <= MAXN){  
        ++c[x];  
        x += lowbit(x);  
    }  
} 
struct po{
    int x,y;
    bool f;
};
po pp[40005];
//int ma[20005][20005];
map<pair<int,int>,int> ma;
int tot;
bool cmp(po a,po b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.f > b.f;
}
int main(){ 
    freopen("input.txt","r",stdin); 
    int n,x,y,w,h;  
    while(~scanf("%d",&n)){  
        if(n == -1) {
            break;
        }
        //memset(ma,0,sizeof(ma));
        ma.clear();
        scanf("%d%d",&w,&h);
        tot = 0;
        rep(i,n) {
            scanf("%d %d",&x,&y);
            x += 20005;
            y += 20005;
            pp[tot].x = x;
            pp[tot].y = y;
            pp[tot++].f = true;
            pp[tot].x = max(x - w,1);
            pp[tot].y = max(y - h,1);
            pp[tot ++].f = false;
            pp[tot].x = x;
            pp[tot].y = max(y - h,1);
            pp[tot ++].f = false;
            pp[tot].x = min(x + w,40006);
            pp[tot].y = min(y + h,40006);
            pp[tot ++].f = false;
            pp[tot].x = x;
            pp[tot].y = min(y + h,40006);
            pp[tot ++].f = false;
        }
        sort(pp,pp+tot,cmp);
        int ans = 0;
        int tp = 0;
        bool z;
        rep(i,tot) {
            tp = 0;
            x = pp[i].x;
            y = pp[i].y;
            z = pp[i].f;
            if(!z) {
                ma[MP(x,y)] = sum(x);
                tp = ma[MP(x,y)];
                tp -= sum(max(x - w,1));
                tp -= ma[MP(x,y-h)];
                tp += ma[MP(x-w,y-h)];
                if(tp > ans) ans = tp;
                continue;
            }
            add(x);
            tp += sum(x);
            ma[MP(x,y)] = tp;
            tp -= sum(max(x - w,1));
            tp -= ma[MP(x,y-h)];
            tp += ma[MP(x-w,y-h)];
            if(tp > ans) ans = tp;
        }
        printf("%d\n",ans);
    }  
    return 0;  
}  

