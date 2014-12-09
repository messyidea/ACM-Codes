/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/4 20:57:54
 |File Name: 病毒侵袭.cpp
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
int pos = 0;
int ans[1000005];
class trie
{
public:
    int ch[maxnode][128];
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
        for (int c = 0;c<128;++c)
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
            for (int c = 0;c < 128;++c)
            {
                int u = ch[r][c];
                if (!u) continue;
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
            //printf(" %d",val[j]);
            //total ++;
            ans[pos++] = val[j];
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
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j]) print(j);
            else if (last[j]) print(last[j]);
        }
    }
    /*bool canfind(char* t)
    {
        int n = strlen(t);
        int j = 0;
        for (int i=0;i<n;++i)
        {
            int c = idx(t[i]);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j]) return true;
            else if (last[j]) return true;
        }
        return false;
    }*/
};

char s[10005];
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
    	getchar();
        trie *t = new trie();
        for (int i=1;i<=n;++i)
        {
            //scanf("%s",s);
            gets(s);
            //cout<<s<<endl;
            t->insert(s,i);
        }
        t->getfail();
        int mm;
        scanf("%d",&mm);
        getchar();
        total = 0;
        for (int i=1;i<=mm;++i)
        {
            //scanf("%s",s);
            gets(s);
            pos = 0;
            t->find(s);
            if(pos!=0){
            	printf("web %d:",i);
            	sort(ans,ans+pos);
            	for(int i=0;i<pos;++i){
	            	printf(" %d",ans[i]);
	            }
	            printf("\n");
	            total++;
            }
        }
        printf("total: %d\n",total);
        delete t;

    }

    return 0;
}