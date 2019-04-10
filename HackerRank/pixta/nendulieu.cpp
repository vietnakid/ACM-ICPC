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

int n;
int arr[105];
vii seg;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int start = arr[0], end = 0;
    arr[n] = INF;
    for (int i = 1; i <= n; i++) {
        if (arr[i] - arr[i-1] != 1) {
            end = arr[i-1];
            seg.push_back({start, end});
            start = arr[i];
        }
    }
    ll res = 0;
    for (auto a : seg) {
        // cerr << a.first << " " << a.second << "\n";
        if (a.second > a.first)
            res += a.second - a.first - 1;
    }
    if (seg[0].first == 1 && seg[0].second != 1) {
        res++;
    }
    if (seg[seg.size() - 1].first != 1000 && seg[seg.size() - 1].second == 1000) {
        res++;
    }
    cout << res << "\n";
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}