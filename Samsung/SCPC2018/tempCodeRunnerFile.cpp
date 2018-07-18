#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m, l;
vii arr;

bool canLight(ll basex, ll basey) {
    double y = (double)basex / (double)basey;
    int cnt = 0, index = 0;
    double now = 0;
    for(; index < m-1; index += 2) {
        // cerr << "WTF " << arr[index+1].second << " " << y << endl;
        if (arr[index+1].second <= y) {
            cnt++;
            now = arr[index+2].first;
            if (now >= n) {
                return cnt <= l;
            }
        } else {
            double x = (y - (double)(arr[index].second)) + (double)(arr[index].first);
            double left = x - y;
            // cout << " x, y " << x << " " << y << " " << now << endl;
            if (left <= now) {
                now = x + y;
            } else {
                return false;
            }
            cnt++;
            if (now >= (double)(arr[index+2].first)) {
                continue;
            }
            x = (double)(arr[index+2].first) - (y - (double)(arr[index+2].second));
            left = x - y;
            // cout << " x, y " << x << " " << y << " " << now << endl;
            if (left <= now) {
                now = x + y;
            } else {
                return false;
            }
            cnt++;
        }
    }
    // cerr << y << " " << cnt << endl;
    if (now < n) {
        return false;
    }
    
    return cnt <= l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << endl;
        cin >> n >> m >> l;
        ll basex = 0, basey = 1; 
        ll minx = 0, miny = 1;
        arr = vii();
        FORE(i, 0, m) {
            int u, v;
            cin >> u >> v;
            basex = max(basex, (ll)v);
            arr.push_back({u, v});
            if (i > 1) {
                int y1 = arr[i-1].second - arr[i-2].second;
                int y2 = arr[i].second - arr[i-1].second;
                if ((y1 >0 && y2 >0) || (y1 < 0 && y2 < 0)) {
                    arr[i-1] = arr[i];
                    arr.pop_back();
                }
            }
        }
        int y1 = arr[1].second - arr[0].second;
        if (y1 < 0) {
            arr.insert(arr.begin(), {0, arr[0].second - arr[0].first});
        }
        m = arr.size();
        // cerr << m << " " << basex << endl;
        if (m % 2 == 0) {
            ii u = arr[arr.size() - 1];
            arr.push_back({u.first + u.second ,0});
        }
        ii res = {0, 0};
        FOR(tt, 0, 1000) {
            ll midx, midy;
            midx = (basex + minx);
            midy = (basey + miny);
            ll gcd = GCD(midx, midy);
            midx /= gcd;
            midy /= gcd;
            if (canLight(midx, midy)) {
                res = {midx, midy};
                basex = midx;
                basey = midy;
            } else {
                minx = midx;
                miny = midy;
            }
        }
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}