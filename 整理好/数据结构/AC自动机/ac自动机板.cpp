/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/4 20:57:54
 |File Name: AC×Ô¶¯»ú°å 
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
#define maxnode 2000005
int total = 0;
class trie
{
public:
    int ch[maxnode][26];
    int val[maxnode];
    int f[maxnode];
    int last[maxnode];
    int sz;
    trie()
    {
        sz = 1;
        memset(ch[0],0,sizeof(ch[0]));
    }
    int idx(char c)
    {
        return c;
    }
    void insert(char *s,int v)
    {
        int u = 0,n = strlen(s);
        for (int i=0;i<n;++i)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    void getfail()
    {
        queue<int> q;
        f[0] = 0;
        for (int c = 0;c<26;++c)
        {
            int u = ch[0][c];
            if (u)
            {
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
        }
        while (!q.empty())
        {
            int r = q.front();
            q.pop();
            for (int c = 0;c < 26;++c)
            {
                int u = ch[r][c];
                if(!u) {ch[r][c] = ch[f[r]][c];continue;}
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
    void print(int j)
    {
        if (j)
        {
            printf(" %d",val[j]);
            print(last[j]);
        }
    }
    void find(char* t)
    {
        int n = strlen(t);
        int j = 0;
        for (int i=0;i<n;++i)
        {
            int c = idx(t[i]);
            //while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j]) print(j);
            else if (last[j]) print(last[j]);
        }
    }
};

char s[10005];
int main()
{
   // freopen("input.txt","r",stdin);
}