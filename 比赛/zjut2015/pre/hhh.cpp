#include <stdlib.h>
#include<stdio.h>
#include<cstring>
#define MAXN 60
#define MAXM 60
int a[MAXN][MAXM+1];
int n,m;
void swap(int& a,int& b)
{
    a^=b;
    b^=a;
    a^=b;
}
inline int fab(int x)
{
    return x>0?x:-x;
}
int gauss()
{
    int i=0,j=0,k,l,index;
    while (i<n&&j<m+1)
    {
        index=i;
        for (k=i+1;k<n;k++)
        {
            if (fab(a[k][j])>fab(a[index][j]))
                index=k;
        }
        if (a[index][j]!=0)
        {
            if (index!=i)
                for (k=j;k<m+1;k++)
                    swap(a[i][k],a[index][k]);
            for (k=0;k<n;k++)
                if (k!=i&&a[k][j]!=0)
                    for (l=j;l<m+1;l++)
                        a[k][l]^=a[i][l];
            i++;
        }
        j++;
    }
    for (j=i;j<n;j++)
        if (a[j][m]!=0)
            return -1;
}
char sss[100];
int aa[100];
int main()
{
    freopen("input.txt","r",stdin);
    int t,i,j,k,var;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        n=60;
        m=60;
        memset(a,0,sizeof(a));
        /*for (j=0;j<5*6;j++)
        {
            scanf("%d",&var);
            if (var==1)
                a[j][m]=1;
        }*/
        int ttt = 0;
        for(int i=0;i<15;++i) {
            scanf("%s",sss);
            int len = strlen(sss);
            for(int j=0;j<len;++j) {
                a[ttt++][m] = sss[j] - '0';
                //a[ttt-1][m] = 1 - a[ttt-1][m];
            }
        }
        //puts("111");
        for(int i=0;i<60;++i) {
            a[i][i] = 1;
            aa[0] = i + 12;
            aa[1] = i + 1;
            aa[2] = i - 1;
            aa[3] = i + 4;
            aa[4] = i - 4;
            aa[5] = i - 12;
            for(int kk=0;kk<=6;++kk) {
                if(aa[kk] >= 0 && aa[kk] < 60) {
                    a[i][aa[kk]] = 1;
                    a[aa[kk]][i] = 1;
                }
            }
        }
        int ret = gauss();
        if(ret == -1) {
            puts("Oh,my Boring!");
            continue;
        }
        for (j=0;j<n;j++)
        {
            if ((j+1)%4!=0)
                printf("%d ",a[j][m]);
            else printf("%d\n",a[j][m]);
        }
    }
    return 0;
}

