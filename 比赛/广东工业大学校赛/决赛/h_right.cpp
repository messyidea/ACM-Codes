#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int T, n ,m ,k, nu, c;
#define maxn 100*6450
#define INF 999999
int num[maxn], sta[maxn], cost[maxn], dp[150];
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int co = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &m);
            scanf("%d", &nu);
            for(int i = 1; i <= m; i++){
                scanf("%d", &k);
                int temp;
                co++;
                num[co] = nu;
                sta[co] = 0;
                while(k--){
                    scanf("%d", &temp);
                    sta[co] |= (1<<temp); //1向左移动5位. 
                }
                scanf("%d", &c);
                cost[co] = c;
            } 
        }
        for(int i = 0; i < (1<<6) ;i++) dp[i] = INF; dp[0] = 0;
        
        for(int s = 0; s < (1<<6); s++){
            if(dp[s] == INF) continue;                 //这个状态还没有更新过 
            for(int i = 1; i <= co; i++){
                if((s& (1<<num[i])) != 0) continue; //已经有了这张牌,不需要了。
                if((s|sta[i]) != s) continue;       //如果当前卡不包含这个卡组，跳过
                dp[s|(1<<num[i])] = min(dp[s|(1<<num[i])], dp[s]+cost[i]); 
            }
        }
        if(dp[(1<<6)-1] == INF) printf("-1\n");
        else printf("%d\n", dp[ (1<<6)-1 ]);
    }
    return 0;
}
