/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/30 16:02:34
 |File Name: Max Sum of Max-K-sub-sequence.cpp
 |Description: 单调队列 
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
#define N 100005
#define inf 1<<29
int n,m;
int A[N*2];
int que[N*4];
int sum[N*2];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        sum[0] = 0;
        for(int i=1;i<=n;++i) {
            scanf("%d",&A[i]);
            sum[i] = sum[i-1]+A[i];
        }
        for(int i=n+1;i<=n+m;++i){
            sum[i] = sum[i-1] + A[i-n];
        }
        int tail = 1,head = 1;
        int tsum = -inf,tp1=0,tp2=0;
        que[0] = 0;
        for(int i=1;i<n+m;++i){
            while((head!=tail) && sum[que[head-1]]>sum[i-1]){
                head--;
            }
            while((head!=tail) && que[tail] < i-m){		//这边也要符合。 
                tail++;
            }
            que[head++] = i-1;
            if(sum[i] - sum[que[tail]] > tsum){
                tsum = sum[i] - sum[que[tail]];
                tp1 = que[tail]+1;
                tp2 = i;
            }
        }
        printf("%d %d %d\n",tsum,tp1,tp2>n?tp2%n:tp2);
    }
	return 0;
}

