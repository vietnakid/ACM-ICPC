#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 1000 + 7;
const int MOD = 998244353;

int dp[N][2 * N][4];

int add(int a, int b){
	return (a + b) % MOD;
}

bool full(int mask){
	return (mask == 0 || mask == 3);
}

int get(int mask, int nmask){
	int cnt = __builtin_popcount(mask ^ nmask);
	if (cnt == 0) return 0;
	if (cnt == 2) return (full(mask) ? 1 : 2);
	return (full(nmask) ? 0 : 1);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	int n, k;
	scanf("%d%d", &n, &k);
	// forn(i, 4)
	// 	dp[0][0][i] = 1;
    dp[1][1][0] = 1; dp[1][1][3] = 1;
    dp[1][2][1] = 1; dp[1][2][2] = 1;
	for (int i = 1; i < n; ++i){
		forn(j, k + 1){
			forn(mask, 4){
				forn(nmask, 4){
					dp[i + 1][j + get(mask, nmask)][nmask] = add(dp[i + 1][j + get(mask, nmask)][nmask], dp[i][j][mask]);
                    // cerr << j << " " << get(mask, nmask) << " " << mask << " " << nmask << " " << dp[i][j][mask] <<  "\n";
				}
			}
		}
	}
	int ans = 0;
    forn(mask, 4){
        ans = add(ans, dp[n][k][mask]);
        // cerr << mask << " " << dp[n][k][mask] << "\n";
    }
    cout << ans << "\n";
}       