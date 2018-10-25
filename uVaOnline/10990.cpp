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

const int nMax = 2e6 + 1;
vi phi(nMax, 0), DOP(nMax, 1), s(nMax, 0);

void init() {
    FOR(i, 1, nMax) {
        phi[i] = i;
    }
    FOR(i, 2, nMax) {
        if (phi[i] == i) {
            for (int j = i; j <= nMax; j += i) {
                phi[j] -= (phi[j] / i);
            }
        }
    }
    FOR(i, 2, nMax) {
        int p = phi[i];
        while (p != 1) {
            DOP[i]++;
            p = phi[p];
        }
    }
    DOP[0] = 0;
    FOR(i, 1, nMax) {
        s[i] = s[i-1] + DOP[i];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    init();
    int TC; cin >> TC;
    while (TC--) {
        int a, b;
        cin >> a >> b;
        cout << s[b] - s[a-1] << endl;
    }
    return 0;
}