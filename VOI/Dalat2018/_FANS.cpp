#include <bits/stdc++.h>
using namespace std;

long long n,mod,F[1000005][5][5][5];
bool Free[1000005][5][5][5];
char s[1000005];

inline long long f(int i,int j,int mi,int ma)
{
	if(Free[i][j][mi][ma]==true)
		return F[i][j][mi][ma];
	Free[i][j][mi][ma]=true;
	if(ma-mi>2)
		return F[i][j][mi][ma]=0;
	if(i==n+1)
		return F[i][j][mi][ma]=1;
	if(j>0)
		F[i][j][mi][ma]=(F[i][j][mi][ma]+f(i+1,j-1,min(mi,j-1),ma))%mod;
	if(j<4)
		F[i][j][mi][ma]=(F[i][j][mi][ma]+f(i+1,j+1,mi,max(ma,j+1)))%mod;
	return F[i][j][mi][ma];
}

int main()
{
	cin>>n>>mod>>s+1;
	long long res=1,sum=2,minn=2,maxn=2;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='M')
			sum--;
		else
			sum++;
		if(s[i]=='V'&&sum>=2)
			res=(res+f(i+1,sum-2,min(minn,sum-2),maxn))%mod;
		minn=min(minn,sum);
		maxn=max(maxn,sum);
	}
	cout<<res;
}
