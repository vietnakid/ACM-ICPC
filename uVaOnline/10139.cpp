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
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vii analysis(ll m) {
    vii res;
    for(ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            int cnt = 0;
            while (m % i == 0) {
                cnt++;
                m /= i;
            }
            res.push_back({i, cnt});
        }
    }
    if (m > 1) {
        res.push_back({m, 1});
    }
    return res;
}

int cal(ll x, ll a) {
    int res = 0;
    while (x % a == 0) {
        res++;
        x /= a;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll m, n;
    while (cin >> n >> m) {
        vii divisor = analysis(m);
        bool check = true;
        for (int i = 0; i < divisor.size() && check; i++) {
            int x = divisor[i].first;
            int t = divisor[i].second;
            int cnt = 0;
            for(int k = 1; x * k <= n && cnt < t; k++) {
                cnt += cal(x*k, x);
            }
            if (cnt < t) {
                check = false;
            }
        }
        if (check) {
            printf("%d divides %d!\n", m, n);
        } else {
            printf("%d does not divide %d!\n", m, n);
        }
    }
    return 0;
}