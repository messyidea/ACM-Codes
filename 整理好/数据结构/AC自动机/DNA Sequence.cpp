/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/5 13:27:07
 |File Name: DNA Sequence.cpp
 |Description: ¡£¡£ 
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
#define maxnode 110
#define mod 100000
int total = 0;
int n,m;
//int ma[maxnode][maxnode];
class trie
{
public:
    int ch[maxnode][4];
    int val[maxnode];
    int f[maxnode];
    int last[maxnode];
    //int matrix[maxnode][maxnode];
    int sz;
    trie()
    {
        sz = 1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    int idx(char c)
    {
        if(c == 'A') return 0;
        if(c == 'T') return 1;
        if(c == 'C') return 2;
        if(c == 'G') return 3;
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
        for (int c = 0;c<4;++c)
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
            for (int c = 0;c < 4;++c)
            {
                int u = ch[r][c];
                if(!u) {ch[r][c] = ch[f[r]][c];continue;}
                //if(!u) {continue;}
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]]?f[u]:last[f[u]];
                if(val[f[u]] == 1) val[u] = 1;
            }
        }
    }
};
struct ma{
	long long m[maxnode][maxnode];
	void clear(){
		memset(m,0,sizeof(m));
	}
};
ma ss,tt;
char s[15];
ma operator *(ma a,ma b){
	ma newma;
	newma.clear();
	for(int i=0;i<total;++i){
		for(int j=0;j<total;++j){
			for(int k=0;k<total;++k){
				newma.m[i][j]+=a.m[i][k]*b.m[k][j];
				newma.m[i][j]%=mod;
			}
		}
	}
	return newma;
}
ma poww(ma a,long long n){
	ma b;
	b.clear();
	for(int i=0;i<total;++i) b.m[i][i] = 1;
	while(n > 0){
		if(n & 1) b = b*a;
		a = a*a;
		n>>=1;
	}
	return b;
}
int main() {
	//freopen("input.txt","r",stdin); 
	while(scanf("%d%d",&n,&m)!=EOF){
		ss.clear();
		tt.clear();
		trie *t = new trie();
		for(int i=1;i<=n;++i){
			scanf("%s",s);
			t->insert(s,1);
		}
		total = t->sz;
		t->getfail();
		//for(int i=0;i<total;++i) cout<<t->val[i]<<" ";cout<<endl;
		//for(int i=0;i<total;++i) cout<<t->last[i]<<" ";cout<<endl;
		for(int i=0;i<t->sz;++i){
			for(int j=0;j<4;++j){
				if(t->val[i] == 0 && t->val[t->ch[i][j]] == 0){
					ss.m[i][t->ch[i][j]]++;
				}
			}
		}
		/*for(int i=0;i<total;++i){
			for(int j=0;j<total;++j){
				cout<<ss.m[i][j]<<" ";
			}
			cout<<endl;
		}*/
		tt = poww(ss,m);
		long long sum = 0;
		//for(int i=0;i<total;++i) cout<<tt.m[0][i]<<" ";cout<<endl; 
		for(int i=0;i<total;++i){
			sum += tt.m[0][i];
			sum %= mod;
		}
		printf("%lld\n",sum);
		delete t;
	}
	return 0;
}

