/*
每一次能改变从左上角开始扩散出的一块颜色相同的格子的颜色，然后问最少多少不能让所有的格子变成同一个颜色。
思路：我们可以把格子分为两类的，一部分是还没访问过的，一部分是访问过的。访问过的就是相同颜色的，目标是去访问未访问的格子。但是每一次只能往周围的一种颜色扩散。我们用IDA*做，估价函数是剩下的未访问的格子中有多少种数字，因为有多少种数字，最少要改变这么多次的颜色，所以这个估价函数是合理的。但是估价函数其实不用每一次都重新算的。我们一开始就用一个cnt记录剩下的格子中对应的数字还有多少个，当一个数字的数量变为0的时候我们就减小h。当h为0时，就完成整个过程了。
下次要大胆的用IDA*写。。。一开始竟然用宽搜。。。慢的一塌糊涂。
*/

#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<string.h>
using namespace std;
int n , h;
int q[20*10] , front , rear;

inline int getx(int r,int c) { return r*n + c; }
inline int row(int x) { return x/n; }
inline int col(int x) { return x%n; }
inline bool inRange(int r,int c) { return 0<=r&&r<n&&0<=c&&c<n; }
const int Move[2][4] = { {-1,0,1,0} , {0,1,0,-1} };
bool ok;

struct State
{
	State() { 
		memset(A,0,sizeof(A)); memset(cnt,0,sizeof(cnt)); 
		memset(vis,false,sizeof(vis)); g = h = 0; 
	}
	int A[9][9];
	int cnt[6];
	int g , h;
	bool vis[9][9];

	void bfs(int z) {
		++g;
		front = rear = 0;
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j) if (vis[i][j])
				q[rear++] = getx(i,j);
		ok = false;
		while (front<rear) {
			int x = q[front++];
			int r = row(x) , c = col(x);
			for (int i = 0 ; i < 4 ; ++i) {
				int rr = r+Move[0][i];
				int cc = c+Move[1][i];
				if (!inRange(rr,cc) || vis[rr][cc] || A[rr][cc]!=z) continue;
				vis[rr][cc] = true;
				ok = true;
				if (--cnt[A[rr][cc]]==0) --h;
				q[rear++] = getx(rr,cc);
			}
		}
	}
}start;

bool dfs(const State & st,int maxdep) 
{
	if (st.h==0) return true;
	for (int i = 0 ; i < 6 ; ++i) {
		State now = st;
		now.bfs(i);
		if (!ok || now.g+now.h > maxdep) continue;
		if (dfs(now,maxdep)) return true;
	}
	return false;
}

void input()
{
	start = State();
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int x; scanf("%d",&x);
			start.A[i][j] = x;
			if (++start.cnt[x]==1)
				++start.h;
		}
	}
	start.vis[0][0] = true; 
	--start.g;
	if (--start.cnt[start.A[0][0]]==0)
		--start.h;
	start.bfs(start.A[0][0]);
}

void solve() 
{
	int maxdep;
	for (maxdep = 0 ; ; ++maxdep)
		if (dfs(start,maxdep)) break;
	printf("%d\n",maxdep);
}

int main()
{
	while (scanf("%d",&n)==1)
	{
		if (n==0) return 0;
		input();
		solve();
	}
	return 0;
}
