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
#define x first
#define y second

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
string s;
vii sum;
ii dst;

void vietnakid() {
	cin >> n;
    cin >> s;
    cin >> dst.x >> dst.y;

    if (abs(dst.x) + abs(dst.y) > n || ((abs(dst.x) + abs(dst.y)) - n) % 2 != 0) {
        cout << "-1\n";
        return;
    }
    sum.push_back({0, 0});
    map<char, ii> state;
    state['U'] = {0, 1};
    state['D'] = {0, -1};
    state['L'] = {-1, 0};
    state['R'] = {1, 0};
    for (int i = 0; i < n ; i++) {
        int xx = sum[i].x + state[s[i]].x;
        int yy = sum[i].y + state[s[i]].y;
        sum.push_back({xx, yy});
    }
    int res = INF;
    for (int i = 0; i <= n; i++) {
        int rx = dst.x - (sum[n].x - sum[i].x);
        int ry = dst.y - (sum[n].y - sum[i].y);
        int l = 0, r = i;
        while (l <= r) {
            int m = (l+r) / 2;
            int leng = i - m;
            int rrx = rx - sum[m].x;
            int rry = ry - sum[m].y;
            // cerr << m << " -> " << i << " || " << rx << " " << ry << " ||| " << rrx << " " << rry << " . " << leng << "\n";
            if (leng >= abs(rrx) + abs(rry)) {
                res = min(res, leng);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // for (int m = 0; m <= i; m++) {
        //     int leng = i - m;
        //     int rrx = rx - sum[m].x;
        //     int rry = ry - sum[m].x;
        //     cerr << m << " -> " << i << " || " << rx << " " << ry << " ||| " << rrx << " " << rry << "\n";
        //     if (leng >= abs(rrx) + abs(rry)) {
        //         res = min(res, leng);
        //     }
        // }
    }
    cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}