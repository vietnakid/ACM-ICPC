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

vi split(ll n) {
    vi res;
    while (n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}


ll construct(vi a) {
    ll res = 0;
    FOR(i, 0, a.size()) {
        res = res*10 + a[i];
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll n;
    while (cin >> n) {
        vi a = split(n);
        vi arr = a;
        sort(a.begin(), a.end());
        vi b;
        FOR(i, 0, a.size()) {
            if (a[i] != 0) {
                b.push_back(a[i]);
                a.erase(a.begin() + i);
                cerr << a[i] << endl;
                break;
            }
        }
        b.insert(b.begin()+1, a.begin(), a.end());
        ll mi = construct(b);
        sort(arr.rbegin(), arr.rend());
        ll ma = construct(arr);
        printf("%lld - %lld = %lld = 9 * %lld\n", ma, mi, ma-mi, (ma-mi)/9);
    }
    return 0;
}