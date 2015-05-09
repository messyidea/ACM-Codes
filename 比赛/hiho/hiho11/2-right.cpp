
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

vector<int> fac[MaxN];
int id = 0;
int have(int x, int y) {
	int ret = 0;
	while (x % y == 0) {
		++ret; x /= y;
	}
	return ret;
}

int vis[MaxN];
int calc(int x, int y) {
	int ret = 1;
	++id;
	for (auto &i : fac[x]) {
		vis[i] = id;
		ret *= (have(x, i) + have(y, i)) + 1;	
	}
	for (auto &i : fac[y]) if (vis[i] != id) {
		ret *= (have(x, i) + have(y, i)) + 1;	
	}
	return ret;
}

int n, A[MaxN];
pair<int,int> p[MaxN];
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	For(i,2,100000) {
		if (fac[i].empty()) {
			for (int j = i; j <= 100000; j += i) {
				fac[j].push_back(i);
			}
		}
	}
	cin >> n;
	For(i,1,n) scanf("%d", &A[i]);
	For(i,1,n) p[i] = {calc(A[i], 1), A[i]};
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	/*int ans = 0;
	For(i,1,n) For(j,1,n) {
		ans = max(ans, calc(A[i], A[j]));
	}*/
	int ans1 = 0;
	For(i,1,1000) For(j,1,1000) ans1 = max(ans1, calc(p[i].second, p[j].second));
	cout << ans1 << endl;
	return 0;
}
