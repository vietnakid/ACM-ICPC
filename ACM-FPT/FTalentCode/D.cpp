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

ll f[18][700][100];

const int zero = 350;
ll n, m;

int sumDigit(ll n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll cal(int index, int diff, int state) {
    // cout << index << " " << diff - zero << " " << state << endl;
    if (index == n) {
        return diff == zero;
    }
    if (f[index][diff][state] != -1) {
        return f[index][diff][state];
    }
    ll res = 0;
    FOR(d, 0, 10) {
        int ndiff = sumDigit(d*m + state) - sumDigit(state) - d + diff;
        int nstate;
        if (m < 10) {
            nstate = (state + d*m) / 10;
        } else {
            nstate = ((state + d*m) - ((state + d*m)%10)) / 10;
        }
        res += cal(index+1, ndiff, nstate);
    }
    f[index][diff][state] = res;
    return res;
}

ll cal2() {
    ll res = 0;
    int N = (ll)pow(10, n);
    FOR(i, 0, N) {
        if (sumDigit(i) == sumDigit(i*m)) {
            // cerr << i << endl;
            res++;
        }
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout); 
    while (cin >> n >> m) {
        if (m == 1 || m == 10 || m == 100) {
            cout << (ll)pow(10, n) << endl;
            continue;
        }
        
        memset(f, -1, sizeof(f));
        cout << cal(0, 0 + zero, 0) << endl;
        // cout << cal(0, 0 + zero, 0) << " " << cal2() << endl;
    }

    return 0;
}