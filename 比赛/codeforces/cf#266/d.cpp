
#include <iostream>

using namespace std;

const int MAXN = 2010;
const int MOD = 1000000007;
int dp[MAXN], a[MAXN];
inline long long add(long long a, long long b)
{
	return (a + b) % MOD;
}
inline long long mul(long long a, long long b)
{
	return (a * b) % MOD;
}
int get(int i, int j)
{
	if (j >= a[i] - 1 && j <= a[i])
		return dp[i];
	else
		return 0;
}
int main()
{
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > h)
		{
			cout << 0 << endl;
			return 0;
		}
		a[i] = h - a[i];
	}
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i] = add(get(i + 1, a[i]), mul(a[i], get(i + 1, a[i] - 1)));
		//cerr << i << " " << dp[i] << " " << a[i] << endl;
	}
	if (a[0] <= 1)
		cout << dp[0] << endl;
	else
		cout << 0 << endl;
}
