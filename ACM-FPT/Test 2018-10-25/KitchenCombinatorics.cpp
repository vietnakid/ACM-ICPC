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
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int r, s, m, d, n;
bool arr[76][76];
ll ingre[1001];
vvi as, am, ad;
ll res = 0;

ll mul(ll a, ll n, ll mod) {
    if (n == 0) return 0;
	if (n == 1) return a;
	ll b = mul(a, n >> 1, mod);
	ll res = (b + b);
    if (res > mod) {
        cout << "too many" << endl;
        exit(0);
    }
	if (n & 1) res = (res + a);
    if (res > mod) {
        cout << "too many" << endl;
        exit(0);
    }
	return res;
}

void input() {
    cin >> r >> s >> m >> d >> n;
    FORE(i, 1, r) {
        cin >> ingre[i];
    }
    FOR(i, 0, s) {
        int k;
        cin >> k;
        vi tmp;
        FOR(ii, 0, k) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        as.push_back(tmp);
    }
    FOR(i, 0, m) {
        int k;
        cin >> k;
        vi tmp;
        FOR(ii, 0, k) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        am.push_back(tmp);
    }
    FOR(i, 0, d) {
        int k;
        cin >> k;
        vi tmp;
        FOR(ii, 0, k) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        ad.push_back(tmp);
    }

    FOR(i, 0, n) {
        int u, v;
        cin >> u >> v;
        arr[u][v] = false;
        arr[v][u] = false;
    }
}

void solve() {
    FOR(i, 0, s) {
        int ins = i + 1;
        FOR(j, 0, m) {
            int inm = j + 1 + s;
            if (!arr[ins][inm]) 
                continue;
            FOR(k, 0, d) {
                int ind = k + 1 + s + m;
                // cerr << i << " " << j << " " << k << endl;
                if (!arr[ins][ind] || !arr[inm][ind]) 
                    continue;
                
                set<int> st;
                FOR(ii, 0, as[i].size()) {
                    st.insert(as[i][ii]);
                }
                FOR(ii, 0, am[j].size()) {
                    st.insert(am[j][ii]);
                }
                FOR(ii, 0, ad[k].size()) {
                    st.insert(ad[k][ii]);
                }
                ll s = 1;
                for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
                    s = mul(s, ingre[*it], INFLL);
                    // cerr << s << " " << ingre[*it] << endl;
                    if (s + res > INFLL) {
                        cout << "too many" << endl;
                        exit(0);
                    }
                }
                res += s;
                
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    memset(arr, true, sizeof(arr));

    input();
    solve();
    if (res > INFLL) {
        cout << "too many" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}