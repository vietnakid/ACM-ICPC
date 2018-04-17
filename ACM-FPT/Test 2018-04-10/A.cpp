#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define FOR(i, a, b) \
for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vvi arr(m);
        FOR(i, 0, m) arr[i] = vi(n);
        FOR(i, 0, m)
        FOR(j, 0, n) cin >> arr[i][j];
        vii voted;
        map<int, int> ma;
        FOR(i, 0, m)
        ma[arr[i][0]]++;
        for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
            voted.push_back(make_pair(it->second, it->first));
        }
        sort(voted.begin(), voted.end());
        reverse(voted.begin(), voted.end());
        if (voted[0].first > m / 2) {
            cout << voted[0].second << " " << 1 << endl;
        } else {
            ma.clear();
            FOR(i, 0, m) {
                FOR(j, 0, n) {
                    if (arr[i][j] == voted[0].second || arr[i][j] == voted[1].second) {
                        ma[arr[i][j]]++;
                        break;
                    }
                }
            }
            voted.clear();
            for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
                voted.push_back(make_pair(it->second, it->first));
            }
            sort(voted.begin(), voted.end());
            reverse(voted.begin(), voted.end());
            cout << voted[0].second << " " << 2 << endl;
        }
    }
    return 0;
}
