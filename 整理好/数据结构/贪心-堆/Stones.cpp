/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/6 22:16:55
 |File Name: Stones.cpp
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
struct stone{
    int x,l;
    bool operator < (const stone a)const{
        if(x == a.x) return l > a.l;
        else return x > a.x;
    }
};
//priority_queue <stone> pq;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int a,b;
    //int start;
    int n;
    while(T--){
        priority_queue <stone> pq;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&a,&b);
            stone st;
            st.x = a;
            st.l = b;
            pq.push(st);
            //if(i == 0) start = a;
        }
        int pos = 0;
        int maxn = -1;
        while(!pq.empty()){
            if(pos % 2 == 0){
                stone tp = pq.top();
                //cout<<tp.x<<endl;
                pq.pop();
                tp.x += tp.l;
                maxn = tp.x;
                pq.push(tp);
                pos ++;
            }
            else{
                pos ++;
                stone tp = pq.top();
                pq.pop();
                maxn = tp.x;
                
            }

        }
        //cout<<maxn<<endl;
        printf("%d\n",maxn);
    }
	return 0;
}

