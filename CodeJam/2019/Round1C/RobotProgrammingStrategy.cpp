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

const int P = 0;
const int S = 1;
const int R = 2;

int num[256];

void vietnakid() {
    num['P'] = 0; num['S'] = 1; num['R'] = 2;
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int n; cin >> n;
        set<string> st;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            string tmp = s;
            while (s.size() < 600) {
                s.insert(s.end(), tmp.begin(), tmp.end());
            }
            st.insert(s);
        }
        string res = "";
        for (int i = 0; i < 600 && !st.empty(); i++) {
            vector<string> e;
            vi cnt(3, 0);
            for (auto x : st) {
                cnt[num[x[i]]] = 1;
            }
            if (cnt[P] && cnt[R] && cnt[S]) {
                res = "IMPOSSIBLE";
                break;
            } else if (cnt[P] && cnt[S]) {
                res.push_back('S');
                
                for (auto x : st) {
                    if (num[x[i]] == P)
                        e.push_back(x);
                }
            } else if (cnt[R] && cnt[S]) {
                res.push_back('R');
                
                for (auto x : st) {
                    if (num[x[i]] == S)
                        e.push_back(x);
                }
            } else if (cnt[P] && cnt[R]) {
                res.push_back('P');
                
                for (auto x : st) {
                    if (num[x[i]] == R)
                        e.push_back(x);
                }
            } else if (cnt[P]) {
                res.push_back('S');
                
                for (auto x : st) {
                    if (num[x[i]] == P)
                        e.push_back(x);
                }
            } else if (cnt[S]) {
                res.push_back('R');
                
                for (auto x : st) {
                    if (num[x[i]] == S)
                        e.push_back(x);
                }
            } else if (cnt[R]) {
                res.push_back('P');
                
                for (auto x : st) {
                    if (num[x[i]] == R)
                        e.push_back(x);
                }
            } else {
                assert(false);
            }

            for (auto x : e) {
                st.erase(x);
            }
        }
        if (res.size() > 500) {
            res = "IMPOSSIBLE";
        }
        cout << "Case #" << tc << ": " << res << "\n";
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