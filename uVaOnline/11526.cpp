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

long long H(int n){
    long long res = 0;
    for( int i = 1; i <= n; i=i+1 ){
        res = (res + n/i);
        cerr << i << " " << n/i << endl;
    }
    return res;
}

long long h(ll n) {
    long long res = 0;
    for(ll i = 1; i*i <= n; i=i+1 ){
        res = (res + n/i);
        res += (n/i - n/(i+1)) * (i);
    }
    int l = sqrt(n);
    if (l != 0 && n/l == l) {
        res -= l;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
        ll n; cin >> n;
        cout << h(n) << endl;
    }
    return 0;
}