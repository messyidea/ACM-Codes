/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 13:39:02
 |File Name: f.cpp
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
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
char s[16][16];
int cc[16][16];
bool vis[16][16];
int tot = 0;
int da[16*16];
char c;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int count;
int now;
int sx,sy;
char sc;
int tt;
int tip;
void dfs(int i,int j)
{
    vis[i][j] = true;
    count ++;
    cc[i][j] = now;
    for (int k=0;k<4;++k)
    {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if (!vis[xx][yy] && s[xx][yy] == c)
        {
            dfs(xx,yy);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=10;i>0;--i) scanf("%s",s[i] + 1);
        for (int i=1;i<=10;++i)
        {
            for (int j=1;j<=15;++j)
            {
                printf("%c",s[i][j]);
            }
            now = 0;
            int mx = 0;
            tt = 1;
            int all = 150;
            int score = 0;
            while (true)
            {
                now = 0;
                mx = 0;
                for (int i=0;i<=16;++i)
                {
                    for (int j=0;j<=11;++j)
                    {
                        if (i == 0 || j == 0 || i == 16 || j == 11 || s[i][j] == 'A')
                        {
                            vis[i][j] = true;
                        }
                        else
                        {
                            vis[i][j] = false;
                        }
                    }
                }
                for (int i=1;i<=15;++i)         //寻找
                {
                    for (int j=1;j<=10;++j)
                    {
                        if (!vis[i][j])
                        {
                            c = s[i][j];
                            count = 0;
                            dfs(i,j);
                            if (count > mx)
                            {
                                mx = count;
                                sx = i;
                                sy = j;
                                sc = c;
                                tip = now;
                            }
                            now ++;
                        }
                    }
                }
                if (mx == 1)
                {
                    break;
                }
                int nowsco = (mx-2)*(mx-2)+(all == mx?1000:0);
                score += nowsco;
                printf("Move %d at (%d,%d): removed %d balls of color %c, got 90%d points.",tt ++,sy,sx,mx,sc,nowsco);
                int cou = 0;
                for (int i=1;i<=15;++i)         //下落
                {
                    cou = 0;
                    for (int j=10;j>=1;--j)
                    {
                        if (cc[i][j] == tip)
                        {
                            cou ++;
                            for (int k=j+1;k<=10;++k)
                            {
                                s[i][k-1] = s[i][k];
                            }
                        }
                    }
                    all -= cou;
                    for (int j=0;j<cou;++j)     //清空
                    {
                        s[i][10-j] = 'A';

                    }
                }

            }
            printf("Final score: %d, with %d balls remaining.",score,150-all);

        }
    }
    return 0;
}

