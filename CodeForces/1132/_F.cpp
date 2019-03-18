#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN=500;
int n, dp1[mxN][mxN+1][26], dp2[mxN][mxN+1];
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	cin >> n >> s;
	for(int i=n-1; ~i; --i) {
		for(int j=i+1; j<=n; ++j) {
			for(int k=0; k<26; ++k) {
				dp1[i][j][k]=1e9;
				if(s[j-1]-'a'==k) {
					dp1[i][j][k]=dp1[i][j-1][k];
				}
				for(int l=i+1; l<j; ++l)
					dp1[i][j][k]=min(dp1[i][j][k], dp1[i][l][k]+dp2[l][j]);
			}
			dp2[i][j]=1e9;
			for(int k=0; k<26; ++k)
				dp2[i][j]=min(dp1[i][j][k]+1, dp2[i][j]);
		}
	}
	cout << dp2[0][n];
	return 0;
}