
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef unsigned long long LL;
typedef pair<int, int> PII;

LL a;
const LL mx = 14000000000000000;

LL solve(LL r) {
    LL ret = 0;
    for (LL x = 1; x <= r; x *= 10) {
        int dig = (r / x) % 10;     //当前位数字
        LL le = (r / x) / 10;
        LL ri = r % x;
        int cur = 0;
        for (int i = 1; i < dig; ++i) cur += i;
        ret += cur * (le + 1) * x;
        ret += dig * (le * x + ri + 1);
        cur = 0;
        for (int i = dig + 1; i <= 9; ++i) cur += i;
        ret += cur * le * x;
    }
    return ret;
}

inline LL digSum(LL x) {
    LL ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    while(cin >> a)
    cout<<solve(a)<<endl; 
    return 0;
}
