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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vvi arr;

bool cmp(vi a, vi b) {
    return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    arr.resize(m+1);
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
    }

    sort(arr.rbegin(), arr.rend(), cmp);

    FOR(i, 0, m+1) {
        sort(arr[i].rbegin(), arr[i].rend());
    }

    FOR(i, 0, arr.size()) {
        FOR(j, 1, arr[i].size()) {
            arr[i][j] += arr[i][j-1];
        }
    }

    // FOR(i, 0, arr.size()) {
    //     FOR(j, 0, arr[i].size()) {
    //         cerr << arr[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    ll res = 0;
    FOR(choose, 0, arr[0].size()) {
        ll cnt = 0;
        FOR(i, 0, m) {
            if (arr[i].size() < choose+1) {
                break;
            } 

            if (arr[i][choose] > 0) {
                cnt += arr[i][choose];
            }
        }
        res = max(res, cnt);
        // cerr << cnt << " " << choose << endl;
    }
    cout << res << endl;
    return 0;
}