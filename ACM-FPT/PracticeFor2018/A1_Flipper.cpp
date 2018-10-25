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

#define INF 1e9+7
#define INFLL 1e18+7
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
    int tc = 0;
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        tc++;
        string s; cin >> s;
        vector<vii > arr(n);
        FOR(i, 0, n) {
            int x = s[i] == 'U' ? 1 : 0;
            arr[i].push_back({i+1, x});
        }
        cin >> s;
        int left = 0, right = n-1;
        for(char q : s) {
            if (q == 'L') {
                left++;
                FORD(i, arr[left-1].size() - 1, 0) {
                    ii x = arr[left-1][i];
                    x.second = 1 - x.second;
                    arr[left].push_back(x);
                }
            } else {
                right--;
                FORD(i, arr[right+1].size() - 1, 0) {
                    ii x = arr[right+1][i];
                    x.second = 1 - x.second;
                    arr[right].push_back(x);
                }
            }
        }
        vii res = arr[left];
        reverse(res.begin(), res.end());

        cout << "Pile " << tc << endl;

        int m; cin >> m;
        FOR(k, 0, m) {
            int q; cin >> q;
            q--;
            cout << "Card " << q+1 << " is a face " << (res[q].second == 1 ? "up " : "down ") << res[q].first << "." << endl;
            // cout << res[q].second << " " << res[q].first << endl;
        }
    }
    return 0;
}