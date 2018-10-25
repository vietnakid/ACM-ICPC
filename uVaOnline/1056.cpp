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

map<string, int> mp;
vector<string> names;
int cnt;

int findIndex(string a) {
    if (mp.find(a) == mp.end()) {
        mp[a] = cnt;
        names.push_back(a);
        cnt++;
    } 
    return mp[a];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc = 0;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        cnt = 0;
        mp.clear();
        names.clear();
        vvi arr(n, vi(n, INF));
        FOR(i, 0, n) {
            arr[i][i] = 0;
        }
        FOR(i, 0, m) {
            string a, b;
            cin >> a >> b;
            int ia = findIndex(a);
            int ib = findIndex(b);
            arr[ia][ib] = 1;
            arr[ib][ia] = 1;
        }
        FOR(k, 0, n) {
            FOR(i, 0, n) {
                FOR(j, 0, n) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
        int res = 0;
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                res = max(res, arr[i][j]);
            }
        }
        tc++;
        cout << "Network " << tc<< ": ";
        if (res == INF) {
            cout << "DISCONNECTED" << endl;
        } else {
            cout << res << endl;
        }
        cout << endl;
    }
    return 0;
}