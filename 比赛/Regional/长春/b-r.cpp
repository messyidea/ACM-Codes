
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
typedef unsigned long long ull;
using namespace std;
const int MAXN = 100010;
const ull base = 31;

ull nbase[MAXN],hash[MAXN];
int n,len,ans,slen;
char str[MAXN];
map<ull, int> mp;

int main() {
    freopen("input.txt","r",stdin);
	ull tmp;
	nbase[0] = 1;
	for (int i = 1; i <= MAXN; i++)
		nbase[i] = nbase[i-1] * base;
	while (scanf("%d%d", &n, &len) != EOF) {
		scanf("%s", str);
		slen = strlen(str);
		hash[slen] = 0;
		for (int i = slen-1; i >= 0; i--) 
			hash[i] = hash[i+1]*base+str[i]-'a'+1;
		ans = 0;
		for (int i = 0; i < len && i+n*len <= slen; i++) {
			mp.clear();
			for (int j = i; j < i+n*len; j += len) {
				tmp = hash[j] - hash[j+len]*nbase[len];
				mp[tmp]++;
			}
			if (mp.size() == n)
				ans++;
			for (int j = i+n*len; j+len <= slen; j += len) {
				tmp = hash[j-n*len] - hash[j-(n-1)*len]*nbase[len];
				mp[tmp]--;
				if (mp[tmp] == 0)
					mp.erase(tmp);
				tmp = hash[j] - hash[j+len]*nbase[len];
				mp[tmp]++;
				if (mp.size() == n)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
