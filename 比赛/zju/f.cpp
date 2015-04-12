
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define mst(a,t) memset(a,t,sizeof(a))
#define rep(i, n)	for(int i = 0; i < n; i ++)
using namespace std;
const int N = 55;
struct Node {
	int x, y, p, time;
	Node(int x=0, int y=0, int p=0, int time=0):
		x(x), y(y), p(p), time(time) {
		}
};
int d[11][11][4][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
bool In(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
char field[N][N];
int Gao(int x, int y, int P) {
	int time;
	queue<Node> Q;
	memset(d, -1, sizeof d);
	Q.push(Node(x,y,0,0));
	d[x][y][0][0] = 0;
	while(!Q.empty()) {
		Node u = Q.front();
		Q.pop();
		x = u.x;
		y = u.y;
		time = u.time;
		int p = u.p, now = d[x][y][p][time];
		if(field[x][y] == '$')	return now;
		
		int nxt_time, nx, ny, np;
		np = p;
		nxt_time = time + 1;
		nxt_time %= P;
		if(nxt_time == 0) {
			np = (np + 3)%4;
		}
		if(d[x][y][np][nxt_time] == -1) {
			d[x][y][np][nxt_time] = now + 1;
			Q.push(Node(x,y,np,nxt_time));
		}
		nx = x + dx[p];
		ny = y + dy[p];
		if(In(nx, ny) && field[nx][ny] != '*') {
			if(d[nx][ny][np][nxt_time] == -1) {
				d[nx][ny][np][nxt_time] = now + 1;
				Q.push(Node(nx,ny,np,nxt_time));
			}
		}
		np = (p+1)%4;
		nxt_time = time + 1;
		nxt_time %= P;
		if(nxt_time == 0) {
			np = (np + 3)%4;
		}
		if(d[x][y][np][nxt_time] == -1) {
			d[x][y][np][nxt_time] = now + 1;
			Q.push(Node(x,y,np,nxt_time));
		}
		np = (p+3)%4;
		nxt_time = time + 1;
		nxt_time %= P;
		if(nxt_time == 0) {
			np = (np + 3)%4;
		}
		if(d[x][y][np][nxt_time] == -1) {
			d[x][y][np][nxt_time] = now + 1;
			Q.push(Node(x,y,np,nxt_time));
		}
	}
	return -1;
}
int main()
{
	int T, P;
//	freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d%d", &n, &m, &P);
		int x, y;
		rep(i, n) {
			scanf("%s", field[i]);
			rep(j, m) if(field[i][j] == '@') {
				x = i, y = j;
			}
		}
		int res = Gao(x, y, P);
		if(res == -1) {
			puts("YouBadbad");
		} else
			printf("%d\n", res);	
	}
	return 0;
}
