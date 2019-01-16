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

ll n, m, r;
int f[2000005];
vector<pair<ii, int> > arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    memset(f, 0, sizeof(f));
    cin >> n >> m >> r;
    arr.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    f[0] = 0;
    int i = 0;
    for (int t = 1; t <= 2*n; t++) {
        f[t] = f[t-1];
        while (i < m && arr[i].first.first == t) {
            int start = arr[i].first.second - r;
            if (start < 0) start = 0;
            f[t] = max(f[t], f[start] + arr[i].second);
            i++;
        }
    }
    cout << f[n] << endl;
    return 0;
}