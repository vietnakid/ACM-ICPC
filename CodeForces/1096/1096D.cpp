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

const ll nMax = 100005;

string s;
int n;
ll cost[nMax];

ll h[nMax], a[nMax], r[nMax], d[nMax], ha[nMax], har[nMax], hard[nMax];

void sovle() {
    for (int i = 1; i <= n; i++) {
        h[i] = h[i-1] + (s[i]=='h'?cost[i]:0);
        a[i] = min(a[i-1] + ((s[i]=='a' && h[i] > 0)?cost[i]:0), h[i]);
        r[i] = min(r[i-1] + ((s[i]=='r' && a[i] > 0)?cost[i]:0), a[i]);
        d[i] = min(d[i-1] + ((s[i]=='d' && r[i] > 0)?cost[i]:0), r[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') {
            ha[i] = min(a[i], h[i-1]);
        } else {
            ha[i] = ha[i-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'r') {
            har[i] = min(r[i], ha[i-1]);
        } else {
            har[i] = har[i-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'd') {
            hard[i] = min(d[i], har[i-1]);
        } else {
            hard[i] = hard[i-1];
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    cin >> s;
    s = '.' + s;
    for (int i = 1; i <= n ; i++) {
        cin >> cost[i];
    }
    sovle();
    cout << hard[n] << endl;
    // cerr << har[n-2] << endl;
    return 0;
}