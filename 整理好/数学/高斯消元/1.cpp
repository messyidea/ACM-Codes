#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100
double g[2][N][N];
int pre, cur, n;

void mul() {
    int i, j;
    for (i = 0; i <= n + 2; i++)
        for (j = 0; j <= n + 2; j++)
            g[cur][i][j] = 0;
    for (i = 1; i <= n + 2; i++) {
        g[cur][1][i] = g[pre][1][i], g[cur][n + 2][i] = g[pre][n + 2][i];
        g[cur][i][1] = g[pre][i][1], g[cur][i][n + 2] = g[pre][i][n + 2];
    }
    for (i = 2; i <= n + 1; i++) {
        for (j = 2; j <= n + 1; j++) {
            g[cur][i - 1][j] += g[pre][i][j] / 4.0;
            g[cur][i + 1][j] += g[pre][i][j] / 4.0;
            g[cur][i][j - 1] += g[pre][i][j] / 4.0;
            g[cur][i][j + 1] += g[pre][i][j] / 4.0;
        }
    }

}
vector<double> list;
vector<double> ans[35];
int main() {
    int i, j;
    freopen("out.txt", "w", stdout);
    for (n = 1; n <= 33; n+=2) {
        memset(g, 0, sizeof(g));
        pre = 0, cur = 1;
        g[pre][n / 2 + 2][n / 2 + 2] = 100;
        for (i = 0; i < 20*n*n; i++) {
            mul();
            pre = !pre, cur = !cur;
        }
        list.clear();
        for (i = 2; i <= n + 1; i++) {
            list.push_back(g[cur][i][1]);
            list.push_back(g[cur][i][n+2]);
            list.push_back(g[cur][1][i]);
            list.push_back(g[cur][n+2][i]);
        }
        sort(list.begin(), list.end());
        double sum = 0;
   for(i = list.size()-1, j = 0; i >=0; i--, j++)
        {
            printf("ta[%d][%d]=%.6lf", n,j,list[i]);
            if(i)
                printf(",");
            ans[n].push_back(list[i]);
            sum += list[i];
        }
        printf(";\n");
        //printf("%.3lf\n", sum);
    }
    return 0;
}

