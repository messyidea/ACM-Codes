
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
const LL inf = 1LL << 50;
struct Node {
    int x , id;
    double v;
    inline void input (int i) {
        id = i;
        scanf ("%d %lf" , &x , &v);
    }
    bool operator < (const Node &n) const {
        return x < n.x;
    }
}a[N];
int n , q , k , p[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &n , &q , &k);
        for (int i = 0 ; i < n ; i ++) {
            a[i].input (i);
        }
        sort (a , a + n);
        for (int i = 0 ; i < n ; i ++) {
            p[a[i].id] = i;
        }
        double ans = 0.0;
        while (q --) {
            int pos;scanf ("%d" , &pos);
            pos --;
            vector <int> v;
            int l = p[pos] - 1 , r = p[pos] + 1;
            for (int i = 0 ; i < k ; i ++) {
                LL d1 = inf , d2 = inf;
                if (l >= 0) d1 = abs (a[l].x - a[p[pos]].x);
                if (r < n) d2 = abs (a[r].x - a[p[pos]].x);
                // cout << d1 << " " << d2 << " " << i << endl;
                if (d1 < d2) {
                    v.push_back (l --);
                }
                else if (d1 > d2) v.push_back (r ++);
                else {
                    if (a[l].id < a[r].id) {
                        v.push_back (l --);
                    }
                    else v.push_back (r ++);
                }
            }
            // cout << v[0] << " " << v[1] << endl;
            double ret = 0.0;
            for (int i = 0 ; i < k ; i ++) {
                ret += a[v[i]].v;
            }
            ret = ret * 1.0 / k;
            a[p[pos]].v = ret;
            // for (int i = 0 ; i < k ; i ++) {
            //     a[v[i]].v = ret;
            // }
            // cout << ret << endl;
            ans += ret;
        }
        printf ("%.6f\n" , ans);
    }
    return 0;
}
