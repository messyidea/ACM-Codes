
# include <iostream>
# include <cstring>
using namespace std;
#define LL long long
LL aa,bb;
int num[30];
LL dp[30][4000];
LL dfs(int cur,int mask,bool limit,int l){
	//cout<<mask<<endl;
	if(cur < 0) return mask == 2000;
	if(!limit && dp[cur][mask]!=-1) return dp[cur][mask];
	int up = limit?num[cur]:9;
	LL ret = 0;
	int tp;
	for(int i=0;i<=up;++i){
		tp=mask+i*(cur-l);
		ret += dfs(cur-1,tp,limit&&(up == i),l);
	}
	if(!limit) dp[cur][mask] = ret;
	return ret;	
}
LL cal(LL x)
{
	int len = 0;
	while(x){
		num[len++] = x%10;
		x/=10;
	}
	LL ret = 0;
	for(int i=0;i<len;++i){
		memset(dp,-1,sizeof(dp));
		ret += dfs(len-1,2000,true,i);
	}
	ret -= len-1;
	return ret;
}
int main()
{
	//for(int i=1;i<100;++i) cout<<cal(i)<<endl;
	//cout<<cal(11)<<endl;
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
		cin>>aa>>bb;
		cout<<cal(bb)-cal(aa-1)<<endl;
	}
	return 0;
}
