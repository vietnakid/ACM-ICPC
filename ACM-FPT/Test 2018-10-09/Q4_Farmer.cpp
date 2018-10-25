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
    int n;
    cin >> n;
    vector< pair< vi, vi > > res(n);
    FOR(i, 0, n) {
        string s1, s2;
        cin >> s1 >> s2;
        res[i].first = vi(26, 0);
        res[i].second = vi(26, 0);
        FOR(j, 0, s1.size()) {
            res[i].first[s1[j] - 'a']++;
        }
        FOR(j, 0, s2.size()) {
            res[i].second[s2[j] - 'a']++;
        }
    }
    FOR(c, 0, 26) {
        int r = 0;
        FOR(i, 0, n) {
            int m = max(res[i].first[c], res[i].second[c]);
            r += m;
        }
        cout << r << endl;
    }
    return 0;
}