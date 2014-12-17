
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
int a[1010][110];
int main()
{
    int n,m,p;
    while(cin>>n>>m>>p)
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
        cout<<m*(m-1)/2<<endl;
        for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            if(p==1)
                cout<<j<<" "<<i<<endl;
            else
                cout<<i<<" "<<j<<endl;
    }
    return 0;
} 
/**************************************************************
    Problem: 1324
    User: 2014CHBY17
    Language: C++
    Result: Accepted
    Time:216 ms
    Memory:2108 kb
****************************************************************/
