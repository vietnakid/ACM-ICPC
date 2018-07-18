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

ll l, r, k;
vi arr;
int res;
const ll m = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC = 0;
    while (true) {
        
        cin >> l >> r >> k;
        if (l == 0 && r == 0 && k == 0) {
            break;
        }
        TC++;
        cout << "Case " << TC << ": ";
        res = INF;
        arr = vi(k);
        FOR(i, 0, k) {
            cin >> arr[i];
        }
        
        vi check(m, false);
        queue<int> q;
        q.push(l);
        check[l] = true;
        res = 0;
        while (true) {
            queue<int> q2;
            res++;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                FOR(i, 0, k) {
                    int x = (u + arr[i]) % m;
                    if (!check[x]) {
                        check[x] = true;
                        q2.push(x);
                        // cout << x << endl;
                    }
                }
            }
            q = q2;
            if (check[r] || q.size() == 0) {
                break;
            }
        }
        
        if (check[r]) {
            cout << res << endl;
        } else {
            cout << "Permanently Locked\n";
        }
    }
    return 0;
}