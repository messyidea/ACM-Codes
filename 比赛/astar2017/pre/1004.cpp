#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int aa[200][2000];
int bb[200][2000];
int pre[200][2000];
int cc[200][2];
int n, m, t;
int T = 1;
int now[200];
int ttt = 0;
int ttt2 = 0;
void dfs(int t1, int t2)
{
    //now[ttt ++] = bb[t1][t2] + 1;
    if(bb[t1][t2] <= 0)
    {
        return;
    }
    now[ttt ++] = bb[t1][t2];
    //printf("%d\n", bb[t1][t2]);
    t = cc[bb[t1][t2]][1];
    ttt2 += cc[bb[t1][t2]][1];
    if(t2 - t >= 0)
    {
        dfs(pre[t1][t2], t2 - t);
    }
}

void solve()
{
    //puts("solve");
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    memset(pre, 0, sizeof(pre));
    memset(now, 0, sizeof(now));
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            aa[i][j] = aa[i-1][j];
            bb[i][j] = bb[i-1][j];
            pre[i][j] = pre[i-1][j];
            if(j >= cc[i][1])
            {
                t = aa[i - 1][j - cc[i][1]] + cc[i][0];
                if(t > aa[i - 1][j])
                {
                    aa[i][j] = t;
                    bb[i][j] = i;
                    pre[i][j] = i-1;

                }
            }
        }
    }
    //printf("%d\n", aa[m][n]);
    if (aa[m][n] == 0)
    {
        printf("Case #%d:\n", T++);
        printf("%d %d\n", 0, 0);
        return;
    }
    ttt = 0;
    ttt2 = 0;
    dfs(m, n);

    printf("Case #%d:\n", T++);
    printf("%d %d\n", aa[m][n], ttt2);
    ttt --;
    printf("%d", now[ttt]);
    for (int i = ttt-1; i >=0; --i)
    {
        printf(" %d", now[i]);
    }
    puts("");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int TTT;
    scanf("%d", &TTT);
    while(TTT --)
    {

        scanf("%d", &n);

        scanf("%d", &m);
        //printf("%d %d\n", n, m);

        for(int i = 1; i <= m; ++i)
        {
            scanf("%d %d", &cc[i][0], &cc[i][1]);
        }
        solve();

    }
    return 0;
}