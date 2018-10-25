#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<ll> si;

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000000000000 // 2e18

const int nMAX = 1e6 + 1;

ll f[nMAX];
ll n, r, p;

ll solve(ll n) {
    if (n == 1) return 0;
    ll & sol = f[n];
    if (sol != INF) return sol;
    sol = r + (n-1)*p;
    REP(segment, 2, n) {
        ll worstCase = solve(ceil((long double)n / (long double)segment));
        sol = min(sol, r + (segment-1)*p + worstCase);
    }
    return sol;
}


int main()
{
    cin >> n >> r >> p;
    REP(i, 0, nMAX) f[i] = INF;

    f[1] = 0;
    cout << solve(n);
    return 0;
}
