#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

const int nMAX = 1001;

ll C[nMAX][nMAX];
ll mod = 1e9+7;

void init() {
	C[0][0] = 1;
    REP(i,1,nMAX){
        C[i][0] = C[i][i] = 1;
        REP(j,1,i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    init();
    ll n, r = 0, res = 1;
    cin >> n;
    REP(i, 0, n) {
        int x;
        cin >> x;
        r += x;
        // cout << r -1 << " " << x-1 << " " << C[r-1][x-1] << endl;
        res = (res * C[r-1][x-1]) % mod;
    }
    cout << res << endl;
    return 0;
}