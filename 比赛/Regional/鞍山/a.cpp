/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/22 12:29:13
 |File Name: a.cpp
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
int n,k,m;
double da[50005];
double da2[50005];
double suma[50005];
double suma2[50005];
double sum,msum,cen,sum2;
double ans,minn;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&k);
        m = n - k;  //剩下的星
        srep(i,n) {
            scanf("%lf",&da[i]);
        }
        if(n == k || n == k+1){
            printf("%.10lf\n",0);
            continue;
        }
        sort(da+1,da+1+n);
        srep(i,n) da2[i] = da[i] * da[i];
        suma[0] = 0;
        suma2[0] = 0;
        for(int i=1;i<=n;++i) {
            suma[i] = suma[i-1] + da[i];
            suma2[i] = suma2[i-1] + da2[i];
        }

        /*srep(i,n) cout<<da[i]<<" ";cout<<endl;
        srep(i,n) cout<<da2[i]<<" ";cout<<endl;
        srep(i,n) cout<<suma[i]<<" ";cout<<endl;
        srep(i,n) cout<<suma2[i]<<" ";cout<<endl;*/
        
        minn = 10000000000000000000000000.0;
        for(int i=m;i <= n ;++i) {
            sum = suma[i] - suma[i-m];
            sum2 = suma2[i] - suma2[i-m];
            cen = sum * 1.0 / double(m);
            ans = 0;
            ans += sum2;
            ans += cen * cen * m;
            ans -= 2 * cen * sum;
            //cout<<ans<<endl;
            if(ans < minn) minn = ans;
        }
        printf("%.10lf\n",minn);
    }
	return 0;
}

