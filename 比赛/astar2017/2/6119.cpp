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

int n,m;
int a,b;
int cc;
pair<int, int> mm[100005];
pair<int, int> mn[100005];
int gap[100005];
bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}
int main() {
	//freopen("input.txt","r",stdin); 
	
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &a, &b); 
			mm[i] = MP(a, b);
		}
		sort(mm, mm + n, cmp);
		cc = 0;
		mn[cc ++] = mm[0];
		for(int i = 1; i < n; ++i) {
			if(mm[i].second <= mn[cc - 1].second) continue;
			if(mm[i].first > mn[cc - 1].second) {
				mn[cc ++] = mm[i];
			} else {
				mn[cc - 1].second = mm[i].second;
			} 	
		} 
		//printf("cc == %d\n", cc);
		for(int i = 0; i < cc - 1; ++i) {
			gap[i] = mn[i+1].first - mn[i].second - 1; 
		}
		//printf("gap0 == %d\n", gap[0]);
		int left = 0;
		int ans = -1;
		int now = mn[0].second - mn[0].first + 1;
		int gapnow = 0;
		ans = max(ans, now + m);
		for(int i = 1; i < cc; ++i) {
			now += mn[i].second - mn[i].first + 1;
			gapnow += gap[i-1];
			if(m >= gapnow) {
				ans = max(ans, m + now);
			} else {
				while(gapnow > m) {
					gapnow -= gap[left];
					now -= mn[left].second - mn[left].first + 1;
					left ++;
				}
				ans = max(ans, m + now);
			}
		} 
		printf("%d\n", ans);
		
	}
	return 0;
}

