#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

bitset<33767> state;
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
queue<ll> q;
ll res = 0;
vii query(51);

ll cal(ll n, ll x, ll y) {
    return LCM(GCD(n, x), y);
}

ll toState(ll n) {
    ll res = 0;
    ll k = 1;
    for (int i = 0; i < 15; i++) {
        if (n % primes[i] == 0) {
            res += k;
        }
        k = k * 2;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    ll n, qq; cin >> n >> qq;
    for (int i = 0; i < qq; i++) {
        cin >> query[i].first >> query[i].second;
    }
    state.reset();

    q.push(n);
    state[toState(n)] = true;

    while(!q.empty()) {
        ll n = q.front(); q.pop();
        res = max(res, n);
        for (int i = 0; i < qq; i++) {
            ll m = cal(n, query[i].first, query[i].second);
            if (!state[toState(m)]) {
                q.push(m);
                state[toState(m)] = true;
            }
        }
    }
    cout << res << endl;
    return 0;
}