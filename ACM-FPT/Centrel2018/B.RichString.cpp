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

string s;
int n;
int res = 0;
string rr = "";
vii rii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> s;
    n = s.size();
    FOR(i, 0, n) {
        int cnt = 0;
        vi a(26, 0);
        vi b(26, true);
        FOR(j, i, n) {
            a[s[j] - 'A']++;
            if (a[s[j] - 'A'] == 1) {
                cnt++;
            } else if(b[s[j] - 'A']) {
                b[s[j] - 'A'] = false;
                cnt--;
            }

            if (cnt > res) {
                rii.clear();
                rii.push_back({i, j});
                res = cnt;
                string tmp = "";
                FORE(ii, i, j) {
                    tmp.push_back(s[ii]);
                }
                rr = tmp;
            } else  if (cnt == res) {
                rii.push_back({i, j});
            }
        }
    }

    FOR(i, 0, rii.size()) {
        ii x = rii[i];
        
        // cout << x.first << " " << x.second << endl;
        int left = x.first, right = x.second;
        if (i != 0 && rii[i].first == rii[i-1].first) {
            continue;
        }
        
        string tmp = "";
        FORE(ii, left, right) {
            tmp.push_back(s[ii]);
        }
        if (tmp < rr) {
            rr = tmp;
        }
        // cout << tmp << " " << rr << endl;
    }

    // cout << res << endl;
    cout << rr << '\n';
    return 0;
}