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

int whatday(int y, int m, int d) {
	int ans;
	if( m == 1 || m == 2) {
		m += 12;
		y --;
	}
	if((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3)) {
		ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y/4 + 5) %7;
	}  else {
		ans = (d + 2 *m + 3*(m+1) / 5 + y + y/4 -y/100 + y/400) %7;
	}
	return ans;
	
}


      
bool check_rui(int y, int m, int d) {
	if(y % 400 == 0) return true;
	if(y % 4 == 0 && y % 100 != 0) return true;
	return false;
}

int main() {
	//freopen("input.txt","r",stdin); 
	int T, tp, a, b, c;
	while(scanf("%d", &T) != EOF) {
		while(T--) {
			scanf("%d-%d-%d", &a, &b, &c);
			tp = whatday(a,b,c);
			if(b == 2 && c == 29) {
				while(1) {
					a ++;
					if(check_rui(a, b, c)) {
						if(whatday(a, b, c) == tp) {
							printf("%d\n", a);
							break;
						}
					}
				}
			} else {
			while(1) {
				a++;
				if(whatday(a, b, c) == tp) {
					printf("%d\n", a);
					break;
				}
			}
			}
		}
	}
	return 0;
}

