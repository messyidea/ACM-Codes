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
//#include <algorithm>
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
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int tttt = 0;
    while (T--)
    {
        if(tttt ++ != 0) puts("");
        printf("Game %d:\n\n",tttt);
        for (int i=10;i>0;--i) scanf("%s",s[i] + 1);
        /*for (int i=1;i<=10;++i)
        {
            for (int j=1;j<=15;++j)
            {
                printf("%c",s[i][j]);
            }
            puts("");
            

        }*/
        now = 0;
        int mx = 0;
        tt = 1;
        int all = 150;
        int score = 0;
        while (true)
        {
            now = 1;
            mx = 0;
            for (int i=0;i<=16;++i)
            {
                for (int j=0;j<=11;++j)
                {
                    if (i == 0 || j == 0 || i == 16 || j == 11 || s[j][i] == 'A')
                    {
                        vis[j][i] = true;
                        cc[j][i] = 0;
                    }
                    else
                    {
                        vis[j][i] = false;
                        cc[j][i] = 0;
                    }
                }
            }
            for (int i=1;i<=15;++i)         //寻找
            {
                for (int j=1;j<=10;++j)
                {
                    if (!vis[j][i])
                    {
                        //cout<<i<<"     "<<j<<"      "<<s[i][j]<<endl;
                        c = s[j][i];
                        count = 0;
                        dfs(j,i);
                        if (count > mx)
                        {
                            mx = count;
                            sx = j;
                            sy = i;
                            sc = c;
                            tip = now;
                        }
                        now ++;
                    }
                }
            }
            if (mx == 0 || mx == 1)
            {
                break;
            }
            int nowsco = (mx-2)*(mx-2);
            score += nowsco;
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",tt ++,sx,sy,mx,sc,nowsco);
            int cou = 0;
            //cout<<"tip == "<<tip<<endl;
            for (int i=1;i<=15;++i)         //下落
            {
                cou = 0;
                for (int j=10;j>=1;--j)
                {
                    if (cc[j][i] == tip)
                    {
                        cou ++;
                        for (int k=j+1;k<=10;++k)
                        {
                            s[k-1][i] = s[k][i];
                        }
                    }
                }
                all -= cou;
                for (int j=0;j<cou;++j)     //清空
                {
                    s[10-j][i] = 'A';

                }
            }
            for(int i=15;i>0;--i) {
                bool fg = true;
                for(int j=1;j<=10;++j) {
                    if(s[j][i] != 'A')  {
                        fg = false;
                        break;
                    }
                }
                if(fg) {
                    for(int k=i;k<=14;++k) {
                        for(int j=1;j<=10;++j) {
                            s[j][k] = s[j][k+1];
                        }
                    }
                    for(int j=1;j<=10;++j) {
                        s[j][15] = 'A';
                    }
                }
            }
            /*for (int i=1;i<=10;++i)
        {
            for (int j=1;j<=15;++j)
            {
                printf("%c",s[i][j]);
            }
            puts("");
            

        }*/

        }
        if(all == 0) score += 1000;
        printf("Final score: %d, with %d balls remaining.\n",score,all);
    }
    return 0;
}

