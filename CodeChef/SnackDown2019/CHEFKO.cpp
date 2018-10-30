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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, k;
vii arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        arr = vii(n);
        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            arr[i] = {x, y};
        }

        sort(arr.begin(), arr.end());
        int res = 0;
        if (k == 1) {
            FOR(i, 0, n) {
                res = max(res, arr[i].second - arr[i].first);
            }
            cout << res << endl;
            continue;
        }
        multiset<int> s;
        
        FOR(i, 0, n) {
            if (s.size() == k) {
                s.erase(s.begin());  
            }
            if (s.size() == k-1)
                res = max(res, min(*s.begin(), arr[i].second) - arr[i].first);
            s.insert(arr[i].second);
        }

        cout << res << endl;

    }
    return 0;
}