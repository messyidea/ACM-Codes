/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/30 15:53:15
 |File Name: 重温世界杯.cpp
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

using namespace std;
const int N = 100005;
int so[N*2];
int n;
int a,b;
bool cmp(int a,int b){
    return a>b;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i){
            scanf("%d%d",&a,&b);
            so[i] = a-b;
        }
        for(int i=n;i<2*n;++i){
        	so[i] = so[i-n];
        }
        int sum = 0;
        int tsum = 0;
        int tmax = 0;
        int maxn = 0;
        int p1 = 0;
        int p2 = -1;
        for(int i=0;i<2*n;++i){
        	tsum += so[i];
        	if(tsum >= 0){
	        	p2++;
	        	if(p2 - p1 + 1 >= n){
	        		maxn = n;
	        		break;
	        	}
	        	else if(p2 - p1 + 1 > maxn){
	        		maxn = p2 - p1 + 1;
	        	}
	        }
	        if(tsum < 0){
        		tsum = 0;
        		p1 = i+1;
        		p2 = i;
        	}
        }
        printf("%d\n",maxn);

    }
	return 0;
}

