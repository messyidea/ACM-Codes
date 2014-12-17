//记录。。CF#277  E
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')
#define inputFile "input.txt"
#define outputFile "output.txt"

typedef long long int lld;
typedef pair<int, int> PII;
typedef pair<int, lld> PIL;
typedef pair<lld, int> PLI;
typedef pair<lld, lld> PLL;

const int INF = (1LL << 31) - 1;
const lld LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int MOD = (int)(1e9) + 7;

const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;

int N, best;
int V[NMAX];
int T[NMAX];
int F1[NMAX];
int F2[NMAX];
int F[NMAX];
int sol[NMAX];

int main() {
    int i, j;

    freopen(inputFile, "r", stdin);

    scanf("%d", &N);

    for(i = 1; i <= N; i++)
        scanf("%d", &V[i]);
    //F1[i].第i位结尾的最长上升子序列长度
    for(i = 1; i <= N; i++) {
        T[i] = INF;
        j = lower_bound(T + 1, T + i + 1, V[i]) - T;
        T[j] = V[i];
        F1[i] = j;
        best = max(best, j);
    }
    //F2[i].第i位开头的最长上升子序列长度
    for(i = N; i >= 1; i--) {
        T[N - i + 1] = INF;
        j = lower_bound(T + 1, T + N - i + 2, -V[i]) - T;
        T[j] = -V[i];
        F2[i] = j;
    }

    for(i = 1; i <= N; i++)
        if(F1[i] + F2[i] - 1 != best)
            sol[i] = 1;
        else {
            sol[i] = 2;
            F[F1[i]]++; //记录次数。
        }

    for(i = 1; i <= N; i++)
        if(sol[i] == 2 && F[F1[i]] == 1)    //次数为1则唯一。
            sol[i] = 3;

    for(i = 1; i <= N; i++)
        printf("%d", sol[i]);

    return 0;
}
