#include <iostream>
#include <cstdio>
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
typedef long long ll;

using namespace std;

int ma[105][105];
bool mb[105][105]; 
char ss[105];
int tt[2];
int n, m;
bool ffff;
bool check(int a, int b) {
	if(!(a >= 0 && a < n)) return false;
	if(!(b >=0 && b < m)) return  false;
	return true;
}
void dfs(int a, int b) {
	
	if(check(a-1, b)) {
		if(ma[a-1][b] == ma[a][b] && !mb[a-1][b]) {
			mb[a-1][b] = 1;
			dfs(a-1, b);
		}
	} else {
		ffff = true;
	} 
	if(check(a+1, b)) {
		//printf("%d %d\n", ma[a+1][b]);
		if(ma[a+1][b] == ma[a][b] && !mb[a+1][b]) {
			mb[a+1][b] = 1;
			dfs(a+1, b);
		}
	} else {
		ffff = true;
	}
	if(check(a, b-1)) {
		if(ma[a][b-1] == ma[a][b] && !mb[a][b-1]) {
			mb[a][b-1] = 1;
			dfs(a, b-1);
		}
	}  else {
		ffff = true;
	}
	if(check(a, b+1)) {
		if(ma[a][b+1] == ma[a][b] && !mb[a][b+1]) {
			mb[a][b+1] = 1;
			dfs(a, b+1);
		}
	}  else {
		ffff = true;
	}
	
}

bool checkm(int val) {
	for(int i = 0; i < m; ++i) {
		if(ma[0][i] == val) return false;
		if(ma[n-1][i] == val) return false;
	}
	for(int i = 0; i < n ;++i)   {
		if(ma[i][0] == val) return false;
		if(ma[i][m-1] == val) return false;
	}
	return true;
}
int main() {
	//freopen("input.txt","r",stdin); 
	//puts("hello world");
	int count;
	int ha;
	while(scanf("%d %d", &n, &m) != EOF) {
		//printf("%d %d\n", n, m);
		count = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%s", &ss);
			for(int j = 0; j < m; ++j) {
				if(ss[j] == '0') {
					ma[i][j] = 0;
				} else {
					ma[i][j] = 1;
				}
			}
		} 
		memset(mb, 0, sizeof(mb));
		memset(tt, 0, sizeof(tt));
		ha = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(!mb[i][j]) {
					tt[ma[i][j]] ++;
					mb[i][j] = true;
					count ++;
					ffff = false;
					dfs(i, j);
					if(ffff == false && ma[i][j] == 0) {
						ha ++;
					}
				}
			}
		}
		if(tt[1] == 1 && ha == 1) {
			puts("0");
		} else if(tt[1] == 1 && ha == 0) {
			puts("1");
		} else {
			puts("-1");
		}
	}
	return 0;
}

