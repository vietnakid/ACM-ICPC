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

int n;
string s1, s2;
vi a1[256], a2[256], r1, r2, h1, h2;
vii res;

void vietnakid() {
	cin >> n >> s1 >> s2;
    // cerr << s1 << "\n";
    // cerr << s2 << "\n";
    for (int i = 0; i < n; i++) {
        a1[s1[i]].push_back(i+1);
        a2[s2[i]].push_back(i+1);
    }
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < min(a1[i].size(), a2[i].size()); j++) {
            res.push_back({a1[i][j], a2[i][j]});
        }
        for (int j = min(a1[i].size(), a2[i].size()); j < a1[i].size(); j++) {
            r1.push_back(a1[i][j]);
        }
        for (int j = min(a1[i].size(), a2[i].size()); j < a2[i].size(); j++) {
            r2.push_back(a2[i][j]);
        }
    }
    for (int i = 0; i < min(a1['?'].size(), r2.size()); i++) {
        res.push_back({a1['?'][i], r2[i]});
    }
    for (int i = min(a1['?'].size(), r2.size()); i < a1['?'].size(); i++) {
        h1.push_back(a1['?'][i]);
    }
    for (int i = 0; i < min(a2['?'].size(), r1.size()); i++) {
        res
        .push_back({r1[i], a2['?'][i]});
    }
    for (int i = min(a2['?'].size(), r1.size()); i < a2['?'].size(); i++) {
        h2.push_back(a2['?'][i]);
    }
    for (int i = 0; i < min(h1.size(), h2.size()); i++) {
        res.push_back({h1[i], h2[i]});
    }
    cout << res.size() << "\n";
    for (auto x:res) {
        cout << x.first << " " << x.second << "\n";
    }
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