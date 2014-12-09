#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int N = 2005;

int a[N], b[N], A[N], B[N];
int n, m, f[N], g[N], tempf[N], tempg[N];
int c[N], tot;

int get(int x) {
    return lower_bound(c + 1, c + tot + 1, x) - c;
}

void add(int A[], int a, int b) {
    for (int i = a; i <= tot; i += (i & -i)) {
        A[i] = max(A[i], b);
    }
}

int ask(int A[], int a) {
    int ret = 0;
    for (int i = a; i; i -= (i & -i)) {
        ret = max(ret, A[i]);
    }
    
    return ret;
}

void work() {
    scanf("%d %d", &n, &m);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        c[++tot] = a[i], c[++tot] = b[i];
    }
    
    sort(c + 1, c + tot + 1);
    tot = unique(c + 1, c + tot + 1) - c - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = get(a[i]), b[i] = get(b[i]);
    }
    
    for (int i = 1; i <= tot; i++) {
        A[i] = 0;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = ask(A, a[i] - 1) + 1;
        g[i] = 0;
        ans = max(ans, f[i]);
        add(A, a[i], f[i]);
    }
    
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            tempf[i] = f[i], tempg[i] = g[i];
        }
        
        for (int i = 1; i <= tot; i++) {
            A[i] = B[i] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            f[i] = ask(A, a[i] - 1) + 1;
            g[i] = ask(B, b[i] - 1) + 1;
            add(A, a[i], max(tempf[i], f[i]));
            add(A, b[i], max(tempg[i], g[i]));
            add(B, a[i], tempf[i]);
            add(B, b[i], tempg[i]);
        }
        
        for (int i = 1; i <= n; i++) {
            ans = max(ans, f[i]);
            ans = max(ans, g[i]);
        }
    }
    
    printf("%d\n", ans);
}

int test;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &test);
    while (test--) {
        work();
    }
    
    return 0;
}
