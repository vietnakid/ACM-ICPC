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
    int n, m;
    ll sum = 0;
    cin >> n;
    vi arr(n);
    for (auto & x : arr) {
        cin >> x;
        sum += x;
    }
    sort(arr.rbegin(), arr.rend());
    cin >> m;
    vii q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(q.begin(), q.end());
    ll s = 0;
    int index = 0;
    vl res(m);
    for (int i = 0; i < n; i++) {
        s += arr[i];
        if (index < m && i+1 == q[index].first) {
            ll cost = s - arr[i] + (sum - s);
            res[q[index].second] = cost;
            index++;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}