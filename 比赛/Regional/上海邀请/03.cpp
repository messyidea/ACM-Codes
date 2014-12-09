
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[105][105];
int pre[105][105];
int a[105][105];

int ans[105];

int main(){
    int T,n,m;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=m;i++)
            dp[1][i]=a[1][i];
        if(m==1){
            printf("Case %d\n",cas);
            for(int i=1;i<=n;i++){
                if(i==1) printf("1");
                else printf(" 1");
            }
            printf("\n");
            continue;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                if(j==1) {
                    if(dp[i-1][j]<dp[i-1][j+1]){
                        pre[i][j]=j;
                        dp[i][j]=a[i][j]+dp[i-1][j];
                    }else{
                        pre[i][j]=j+1;
                        dp[i][j]=a[i][j]+dp[i-1][j+1];
                    }
                }
                else if(j==m){
                    if(dp[i-1][j]<dp[i-1][j-1]){
                        pre[i][j]=j;
                        dp[i][j]=a[i][j]+dp[i-1][j];
                    }else{
                        pre[i][j]=j-1;
                        dp[i][j]=a[i][j]+dp[i-1][j-1];
                    }
                }
                else {
                    int tr,tpr;
                    if(dp[i-1][j]<dp[i-1][j+1]){
                        tr=j;
                        tpr=dp[i-1][j];
                    }else{
                        tr=j+1;
                        tpr=dp[i-1][j+1];
                    }
                    if(dp[i-1][j-1]<tpr){
                        tr=j-1;
                        tpr=dp[i-1][j-1];
                    }
                    pre[i][j]=tr;
                    dp[i][j]=a[i][j]+tpr;
                }
                //cout<<pre[i][j]<<" ";
            }
            //cout<<"\n";
        }
        int line=1,maxdp=dp[n][1];
        for(int i=2;i<=m;i++){
            if(maxdp>=dp[n][i]) {
                line=i;
                maxdp=dp[n][i];
            }
        }
        printf("Case %d\n",cas);
        ans[1]=line;
        int tt=2;
        for(int i=n;i>=2;i--)
        {
            ans[tt++]=pre[i][line];
            line=pre[i][line];
        }
        for(int i=n;i>=1;i--)
        {
            if(i==n) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
