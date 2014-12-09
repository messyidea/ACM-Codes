/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/30 15:25:37
 |File Name: Palindrome.cpp
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
#define inf 1<<29
int n;
string s;
int dp[2][5005];
int minn;
int main() {
	//freopen("input.txt","r",stdin); 
    while(cin>>n){
        cin>>s;
        string s1 = s;
        reverse(s1.begin(),s1.end());
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i){
        	for(int j=1;j<=n;++j){
	        	if(s[i-1] == s1[j-1]){
	        		dp[i%2][j] = dp[(i+1)%2][j-1]+1;
	        	}
	        	else{
	        		dp[i%2][j]=max(dp[(i+1)%2][j],dp[i%2][j-1]);
	        	}
	        }
        }
        cout<<n - dp[(n)%2][n]<<endl;
    }
	return 0;
}

