/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/29 23:00:42
 |File Name: MAXAverageProblem.cpp
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

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int n,k;
int ma[100005];
double sum[100005];
int so[100005];
int cnt = 0;
int head,tail;
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d%d",&n,&k)!=EOF){
        sum[0] = 0;
        for(int i=1;i<=n;++i){
            scanf("%d",&ma[i]);
            sum[i] = sum[i-1]+ma[i];
        }
        //memset(so,0,sizeof(so));
        so[0] = 0;
        head = tail = 0;
        double maxn = 0;
        for(int i=k;i<=n;++i){
            int now = i-k;
            while(head < tail){
                double k1 = (sum[so[tail]] - sum[so[tail-1]])/(so[tail]-so[tail-1]);
                double k2 = (sum[now]-sum[so[tail]])/(now-so[tail]);
                if(k1>=k2) tail--;
                else break;
            }
            tail++;
            so[tail] = now;
            while(head < tail){
                double k1 = (sum[so[head]]-sum[i])/(so[head]-i);
                double k2 = (sum[so[head+1]]-sum[i])/(so[head+1]-i);
                if(k1<=k2) head++;
                else break;
            }
            double t = (sum[so[head]]-sum[i])/(so[head]-i);
            if(t > maxn) maxn = t;
        }
        printf("%.2lf\n",maxn);


    }
	return 0;
}

