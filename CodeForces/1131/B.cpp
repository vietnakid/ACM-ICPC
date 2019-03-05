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
    
    int n; cin >> n;
    vii arr(n+1);
    arr[0] = {0, 0};
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
        int _max = max(arr[i-1].first, arr[i-1].second);
        if (arr[i-1].first == arr[i-1].second) {
            _max++;
        }
        int _min = min(arr[i].first, arr[i].second);

        if (_min >= _max) {
            res += _min - _max + 1;
        }
    }
    cout << res << endl;
    return 0;
}