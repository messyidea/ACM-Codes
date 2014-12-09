
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))
const int maxl= 100005;
const int inf=0x7fffffff;

int sa[maxl], rank[maxl], hei[maxl];

char s[maxl];
int slen;
int n;

int x1[maxl], x2[maxl], c[maxl];
int nxt2[maxl];
void BuildSA() {
	memset(c, 0, sizeof(c));
	for (int i=0; i<slen; ++i) c[s[i]]++;
	for (int i=1; i<maxl; ++i) c[i]+=c[i-1];
	for (int i=slen-1; i>=0; --i) {
		--c[s[i]];
		sa[c[s[i]]]=i; rank[i]=c[s[i]];
	}

	int sigm=0;
	for (int i=0; i<slen; ++i) {
		x1[sa[i]]=(0==i || s[sa[i]]==s[sa[i-1]])?sigm:++sigm;
	}
	if (sigm == slen-1) return; 

	int *cur=x1, *nxt=x2;
	for (int k=1; k<slen; k<<=1) {
		int rk=0;
		for (int i=slen-k; i<slen; ++i) nxt[rk++]=i;
		for (int i=0; i<slen; ++i) if (sa[i]>=k) nxt[rk++]=sa[i]-k;

		memset(c, 0, sizeof(c));
		for (int i=0; i<slen; ++i) c[cur[i]]++;
		for (int i=1; i<=sigm; ++i) c[i]+=c[i-1];
		for (int i=slen-1; i>=0; --i) {
			--c[cur[nxt[i]]];
			sa[c[cur[nxt[i]]]]=nxt[i];
			rank[nxt[i]]=c[cur[nxt[i]]];
		}

		for (int i=0; i<slen-k; ++i) nxt2[i]=cur[i+k];
		for (int i=slen-k; i<slen; ++i) nxt2[i]= -1;

		sigm=0;
		for (int i=0; i<slen; ++i) {
			nxt[sa[i]] = (0==i || cur[sa[i]]==cur[sa[i-1]]
				&& nxt2[sa[i]]==nxt2[sa[i-1]])?sigm:++sigm;
		}

		if (sigm == slen-1) return;
		
		swap(cur, nxt);
	}
}

void CalHei() {
	int cur=0;
	for (int i=0; i<slen; ++i) {
		if (0==rank[i]) { hei[i]=0; cur=0; continue; }
		for (int j=cur; i+j<slen && sa[rank[i]-1]+j<slen; ++j) {
			if (s[i+j] == s[sa[rank[i]-1]+j]) ++cur;
			else break;
		}
		hei[rank[i]]=cur;

		cur=(cur<=0)?0:cur-1;
	}
}

int dp[maxl][20];
void BuildST() {
	for (int i=0; i<slen; ++i) dp[i][0]=hei[i];
	for (int j=1,k=2; k<slen; ++j,(k<<=1)) {
		for (int i=0; i+k<=slen; ++i) {
			dp[i][j]=Min(dp[i][j-1], dp[i+(k>>1)][j-1]);
		}
	}
}

int RMQ(int l, int r) {
	int len=r-l+1, j=(double)log((double)len)/(double)log(2.0);
	return Min(dp[l][j], dp[r+1-(1<<j)][j]);
}

int main() {
    //freopen("input.txt","r",stdin);
	while (scanf(" %s", s)!=EOF) {
		slen = strlen(s);
		BuildSA();
		CalHei();
		BuildST();

		int  curL, curR, preL, preR;
        long long inlen = 0,outlen = 0;
		scanf("%d", &n);
		scanf("%d%d", &preL, &preR);
		inlen += preR-preL+1;
		outlen += 3+preR-preL;
		while (--n) {
			scanf("%d%d", &curL, &curR);
			inlen += curR-curL+1;

			int l=rank[preL], r=rank[curL];
			if (l>r) swap(l,r);

			int curNum=(l==r)?inf:RMQ(l+1,r), reNum;
			curNum=Min(Min(curNum,curR-curL),preR-preL);

			reNum=curR-curL-curNum;
			outlen += ((0==curNum)?1:(1+log10((double)curNum))) + 2 + reNum;

			preL=curL; preR=curR;
		}
		printf("%I64d %I64d\n", inlen, outlen);
	}
	return 0;
}
