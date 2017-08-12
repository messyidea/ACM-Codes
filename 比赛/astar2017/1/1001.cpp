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
#include <cmath>
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


int main() {
	//freopen("input.txt","r",stdin); 
	//puts("hello world");
	int T;
	int n;
	int ans = 0;
	while(scanf("%d\n", &T) != EOF) {
		while(T--) {
			scanf("%d", &n);
			ans = 0;
			n--;
			for(int i = 1;i * i <= n; ++i) {
				if(n % i == 0) {
					ans ++;
					if(i * i != n) {
						ans ++;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

