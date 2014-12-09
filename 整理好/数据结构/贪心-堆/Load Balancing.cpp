/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/6 21:36:44
 |File Name: Load Balancing.cpp
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
struct node{
    int t,i;
    bool operator < (const node a)const{
        return t > a.t; 
    }
}nn[1000005];
int ans[1000005];
bool cmp(node a,node b){
	return a.t > b.t;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d",&nn[i].t);
            nn[i].i = i;
        }
        sort(nn,nn+n,cmp);
        priority_queue<node> pq;
        for(int i=0;i<m;++i){
        	node no;
        	no.t = nn[i].t;
        	no.i = i;
            pq.push(no);
            ans[nn[i].i] = i;
        }
        for(int i=m;i<n;++i){
            node no = pq.top();
            //cout<<no.t<<endl;
            pq.pop();
            no.t += nn[i].t;
            ans[nn[i].i] = no.i;
            pq.push(no);
        }
        printf("%d\n%d",n,ans[0]);
        for(int i=1;i<n;++i){
            printf(" %d",ans[i]);
        }
        printf("\n");
        
    }
	return 0;
}

