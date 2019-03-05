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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vii arr(n);
    ll X = 0, Y = 0, x = 0, y = 0;
    ll nx = abs(x2 - x1), ny = abs(y2 - y1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            if (y2 - y1 >= 0) {
                arr[i].second = 1;
            } else {
                arr[i].second = -1;
            }
        } else if (s[i] == 'D') {
            if (y2 - y1 < 0) {
                arr[i].second = 1;
            } else {
                arr[i].second = -1;
            }
        } else if (s[i] == 'R') {
            if (x2 - x1 >= 0) {
                arr[i].first = 1;
            } else {
                arr[i].first = -1;
            }
        } else if (s[i] == 'L') {
            if (x2 - x1 < 0) {
                arr[i].first = 1;
            } else {
                arr[i].first = -1;
            }
        }
        // cerr << arr[i].first << " " << arr[i].second << endl;
        X += arr[i].first;
        Y += arr[i].second;
    }
    // cerr << X << " " << Y << " - " << nx << " " << ny << endl;
    ll res = INFLL;
    for (int i = 0; i < n; i++) {
        x += arr[i].first;
        y += arr[i].second;

        ll left = 0, right = INF;
        for (int j = 0; j < 100; j++) {
            if (left > right) break;
            ll m = (left + right) / 2;
            ll t1 = nx - m*X - x;
            ll t2 = ny - m*Y - y;
            // cerr << m << " " << t1 << " " << t2 << " " << m*n + i + 1 << endl;
            if (abs(t1) + abs(t2) <= m*n + i + 1) {
                right = m - 1;
                res = min(res, m*n + i+1);
            } else {
                left = m + 1;
            }
        }
        // cerr << res << endl << '\n';
    }
    if (res == INFLL) {
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}