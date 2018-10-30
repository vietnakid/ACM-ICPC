#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, k;

ll sum(ll x) {
    return x*(x+1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        if (sum(k) > n) {
            cout << -1 << endl;
            continue;
        }

        ll res = 0;

        ll left = 1, right = n;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll end = mid + k - 1;
            ll total = sum(end) - sum(mid-1);
            // cerr << mid << " " << end << " " << total << endl;
            if (total > n) {
                right = mid - 1;
            } else {
                res = mid;
                left = mid + 1;
            }
        }

        
        // FORE(i, 1, n) {
        //     ll start = i;
        //     ll end = i + k - 1;
        //     ll total = sum(end) - sum(start-1);
        //     if (total <= n) {
        //         res = i;
        //     } else {
        //         break;
        //     }
        // }
        
        ll start = res;
        ll end = start + k - 1;
        
        ll total = sum(end) - sum(start-1);
        ll remain = n - total;
        // cerr << start << " " << end << " " << remain << endl;
        ll id=max(end-remain+1,start);
        // cerr << id << endl;
        res = 1;
        FORE(i, start, end) {
            if (i == id) {
                ll tmp = i + remain;
                res = (res * ((tmp*tmp - tmp) % nMod)) % nMod;
                // cerr << (tmp*tmp - tmp) % nMod << endl;
            } else {
                res = (res * ((i*i - i) % nMod)) % nMod;
                // cerr << ((i*i - i) % nMod) << endl;
            }
        }
        
        cout << res << endl;
    }
    return 0;
}