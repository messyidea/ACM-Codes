
/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/29 19:26:15
File Name     :E:\2014ACM\Bestcoder\BC20\C.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct BIT{
    int c[2010];
    int n;
    void init(int _n){
        n = _n;
        for(int i = 1;i <= n;i++)c[i] = 0;
    }
    int lowbit(int x){
        return x&(-x);
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s = max(s,c[i]);
            i -= lowbit(i);
        }
        return s;
    }
    void add(int i,int val){
        while(i <= n){
            c[i] = max(c[i],val);
            i += lowbit(i);
        }
    }
}bt[1010];
int a[1010];
int b[1010];
int x[2010];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int cnt = 0;
        for(int i = 0;i < n;i++){
            scanf("%d%d",&a[i],&b[i]);
            x[++cnt] = a[i];
            x[++cnt] = b[i];
        }
        sort(x+1,x+cnt+1);
        cnt = unique(x+1,x+cnt+1)-x-1;
        for(int i = 0;i < n;i++){
            a[i] = lower_bound(x+1,x+cnt+1,a[i])-x;
            b[i] = lower_bound(x+1,x+cnt+1,b[i])-x;
        }
        int ans = 0;
        for(int i = 0;i <= m;i++)bt[i].init(cnt);
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= m;j++){
                int tmp = bt[j].sum(a[i]-1)+1;
                bt[j].add(a[i],tmp);
                ans = max(ans,tmp);
                if(j < m){
                    tmp = bt[j+1].sum(b[i]-1)+1;
                    bt[j].add(b[i],tmp);
                    ans = max(ans,tmp);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
