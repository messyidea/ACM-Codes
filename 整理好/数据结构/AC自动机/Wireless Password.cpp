/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/7 22:55:00
 |File Name: Wireless Password.cpp
 |Description: 单词可以覆盖，可以把不存在的失配边补上。动归还是不太写的来。。 
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
#define maxnode 105
#define mod 20090717
int num[1500];
int nn,mm,kk;
int dp[30][105][1<<10];
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
        memset(val,0,sizeof(val));
        memset(f,-1,sizeof(f));
    }
    int idx(char c)
    {
        return c-'a';
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
        val[u] = 1<<v;
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
            val[r] |= val[f[r]];
            for (int c = 0;c < 26;++c)
            {	
                int u = ch[r][c];
                if(!u) {ch[r][c] = ch[f[r]][c];continue;}
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                val[u]|=val[ch[v][c]];
                last[u] = val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
    int solve(){
    	for(int i=0;i<=nn;++i){
	    	for(int j=0;j<sz;++j){
	    		for(int k=0;k<(1<<mm);++k){
		    		dp[i][j][k] = 0;
		    	}
	    	}
	    }
	    dp[0][0][0] = 1;
	    int tp = 0;
	    for(int i=0;i<nn;++i){
    		for(int j=0;j<sz;++j){
		    	for(int k=0;k<(1<<mm);++k){
	    			if(dp[i][j][k]){
			    		for(int x = 0;x<26;++x){
		    				dp[i+1][ch[j][x]][k|val[ch[j][x]]]+=dp[i][j][k];
		    				dp[i+1][ch[j][x]][k|val[ch[j][x]]] %= mod;
		    			}
			    	}
	    		}
		    }
    	}
    	int sum = 0;
    	for(int i=0;i<(1<<mm);++i){
	    	if(num[i] >= kk){
	    		for(int j=0;j<sz;++j){
		    		sum += dp[nn][j][i];
		    		sum %= mod;
		    	}
	    	}
	    }
    	return sum;
    }
};
char s[100];
int main() {	
	//freopen("input.txt","r",stdin); 
	int n,m,k;
	for(int i=0;i<(1<<10);++i){
		num[i] = 0;
		for(int j=0;j<10;++j){
			if(i & (1<<j)){
				num[i]++;
			}
		}
	}
	while(scanf("%d%d%d",&nn,&mm,&kk)!=EOF){
		if(nn == 0 && mm == 0 && kk == 0) break;
		//memset(dp,0,sizeof(dp));
		trie *t = new trie();
		for(int i=0;i<mm;++i){
			scanf("%s",s);
			//cout<<s<<endl;
			t->insert(s,i);
		}
		t->getfail();
		printf("%d\n",t->solve());
		delete t;
	}
	return 0;
}

