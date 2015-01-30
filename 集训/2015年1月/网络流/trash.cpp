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
#define maxn 205
int w[maxn][maxn],n;
int lx[maxn],ly[maxn];
int lef[maxn];
bool s[maxn],t[maxn];

bool match(int i){
    s[i] = true;
    srep(j,n){
        if(lx[i] + ly[j] == w[i][j] && !t[j]){
            t[j] = true;
            if(!lef[j] || match(lef[j])){
                lef[j] = i;
                return true;
            }
        }
    }
    return false;
}

void update(){
    int a = 1<<30;
    srep(i,n){
        if(s[i]){
            srep(j,n){
                if(!t[j]){
                    a = min(a,lx[i] + ly[j] - w[i][j]);
                }
            }
        }
    }
    srep(i,n){
        if(s[i]) lx[i] -= a;
        if(t[i]) ly[i] += a;
    }
}

void km(){
    srep(i,n){
        lef[i] = lx[i] = ly[i] = 0;
        srep(j,n){
            lx[i] = max(lx[i],w[i][j]);
        }
    }
    srep(i,n){
        for(;;){
            srep(j,n){
                s[j] = t[j] = 0;
            }
            if(match(i)) break;else update();
        }
    }
}
int ma[maxn][maxn];
int sum[maxn];

int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)){
    	memset(sum,0,sizeof(sum));
        srep(i,n){
            srep(j,n){
                scanf("%d",&ma[i][j]);
                sum[i] += ma[i][j];
            }
        }
        srep(i,n){
            srep(j,n){
                w[j][i] = -(sum[i]-ma[i][j]);
            }
        }
        km();
        int ans = 0;
        srep(i,n){
        	ans += sum[i] - ma[i][lef[i]];
		}
		cout<<ans<<endl;

    }
	return 0;
}

