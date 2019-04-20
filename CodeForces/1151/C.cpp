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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll a, b;

ll sumEven(ll pos) {
    return (pos % nMod) * ((pos + 1) % nMod) % nMod;
}

ll sumOdd(ll pos) {
    return (pos % nMod) * (pos % nMod) % nMod;
}

ll cal(ll pos) {
    if (pos == 0) return 0;
    int p = log2(pos);
    if (p % 2 == 0) {
        ll cnt = 0;
        for (int i = 1; i < p; i+=2) {
            cnt += ((ll)1 << i);
        }
        return (sumOdd(pos-cnt) + sumEven(cnt)) % nMod;
    } else {
        ll cnt = 0;
        for (int i = 0; i < p; i+=2) {
            cnt += ((ll)1 << i);
        }
        return (sumEven(pos-cnt) + sumOdd(cnt)) % nMod;
    }
}

void vietnakid() {
    cin >> a >> b;
    ll res = (cal(b) - cal(a-1) + nMod) % nMod;
    cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}