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

#define x first.first
#define y first.second
#define pos second

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vector<pair<ii, int> > arr;
int origin[100005];

void solve() {
    int yMax = arr[0].y;
    int res = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i].x > yMax) {
            res = i;
            break;
        }
        yMax = max(yMax, arr[i].y);
    }
    // cerr << res << " " << yMax << endl;
    if (res == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < res; i++) {
            origin[arr[i].pos] = 1;
        }
        for (int i = res; i < n; i++) {
            origin[arr[i].pos] = 2;
        }
        for (int i = 0; i < n; i++) {
            cout << origin[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i].x >> arr[i].y;
            arr[i].pos = i;
        }
        sort(arr.begin(), arr.end());
        solve();
    }
    return 0;
}