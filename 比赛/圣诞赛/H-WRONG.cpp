/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 22:19:29
 |File Name: fin.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
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
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n,m;
int da[100];
int sum;
int tget(int q) {
    int t = sum * 2 ;
    if(t % m != 0) return -1;
    t /= m;
    t -= (m-1) * q;
    if(t % 2 != 0) return -1;
    return t / 2;
}
int tmp[100];
int ttt[100];
bool dfs(int left) {
    if(left == 0) return true;
    for(int i=0;i<n;++i) {
        if(ttt[i] == 0) continue;
        if(left < ttt[i]) return false;
        if(left >= ttt[i]) {
            ttt[i] = 0;
            if(dfs(left - ttt[i])){
                left -= ttt[i];
                return true;
            }
            ttt[i] = da[i];
        }
    }
    return false;
}
bool judge(int a) {
    int s;
    if(a == 0) {
        if(sum % m == 0) s = sum / m;
        else return false;
    } 
    else s = tget(a);
    //cout<<"   "<<s<<endl;
    if(s < 0) return false;
    int tt = 0;
    for(int i=0;i<m;++i) {
        int t = s + i * a;
        tmp[i] = t;
    }
    //rep(i,m) cout<<tmp[i]<<" ";cout<<endl;
    for(int j=0;j<n;++j) ttt[j] = da[j];
    for(int i=0;i<m;++i) {
        //cout<<i<<"             "<<tmp[i]<<endl;
        if(dfs(tmp[i])) return false;
    }
    return true;

}
bool cmp(int a,int b) {
    return a > b;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        sum = 0;
        rep(i,n) {
            scanf("%d",&da[i]);
            sum += da[i];
        }
        if(m <= 0) {
            puts("Impossible");
            continue;
        }
        if(m == 1) {
            printf("%d\n",sum);
            continue;
        }
        sort(da,da+n);
        int ans = -1;
        for(int i=0;i<=200005;++i) {
            //cout<<i<<endl;
            if(judge(i)) {
                ans = i;
                break;
            }
        }
        if(ans == -1) puts("Impossible");
        else 
        printf("%d\n",ans);
    }
	return 0;
}

