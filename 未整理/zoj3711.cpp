#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define srep(i,n) for(int i=1;i<=n;++i)
int T, N, M, K;
int da[115];
double dp[115][5][115][115];   //次数 位置 警告后呆的时间 剩余手
int main() {
    int _T;
    scanf("%d",&_T);
    while(_T--) {
        scanf("%d %d %d %d",&T, &N, &M, &K);    //time door hands students
        srep(i,N) {
            scanf("%d",&da[i]);
        }
        for(int i=0;i<=N;++i) {
            for(int j=0;j<=3;++j) {
                for(int k=0;k<=T;++k) {
                    for(int l=0;l<=M;++l) {
                        dp[i][j][k][l] = 0.0;
                    }
                }
            }
        }
        dp[0][0][0][M] = 1.0;
        da[0] = 0;
        srep(i,N) {
            int tt = da[i] - da[i-1];
            //0 a out b out
            //1 a out b in
            //2 a in b out
            //3 a in b in
            for(int j=0;j<=M;++j) {
                dp[i][0][0][j] += dp[i-1][0][0][j] * (K-2)/K;
                dp[i][1][0][j] += dp[i-1][0][0][j] / K;
                dp[i][2][0][j] += dp[i-1][0][0][j] / K;
            }

            for(int j=0;j<=M;++j) {
                dp[i][0][0][j] += dp[i-1][1][0][j] / K;
                dp[i][1][0][j] += dp[i-1][1][0][j]*(K-2) / K;
                dp[i][3][0][j] += dp[i-1][1][0][j] / K;
            }

            for(int k=0;k<=T;++k) {
                for(int j=0;j<=M;++j) {
                    dp[i][3][(k+tt)>=T?0:(k+tt)][max(0,j-(k+tt>=T))] += dp[i-1][2][k][j]/K;
                    dp[i][0][0][j] += dp[i-1][2][k][j]/K;
                    dp[i][2][min(T,k+tt)][j] += dp[i-1][2][k][j]*(K-2)/K;
                }
            }

            for(int k=0;k<=T;k++)
            {
                for(int j=0;j<=M;j++)
                {
                    int a,b;
                    a=(k+tt)%T,b=max(0,j-(k+tt)/T);
                    dp[i][3][a][b]+=dp[i-1][3][k][j]*(K-2)/K;
                    dp[i][2][a][b]+=dp[i-1][3][k][j]*1/K;
                    dp[i][1][0][b]+=dp[i-1][3][k][j]*1/K;
                }
            }



        }
        int last = 1440 - da[N]; //sheng yu
        double ans = 0;
        for(int i=0;i<=T;++i) {
            for(int j=0;j<=2;++j) {
                for(int k=0;k<=M;++k) {
                    ans += dp[N][j][i][k] * k;
                }
            }
        }

        for(int i=0;i<=T;++i) {
            for(int k=0;k<=M;++k) {
                ans += dp[N][3][i][k] * (max(0,k-((i+last)/T)));

            }
        }

        printf("%.6lf\n",ans);

    }
    return 0;
}
