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

priority_queue< ll, vector<ll>, greater<ll> > heap;

vvi arr;
int n;
vi isFree;
vi inDeg;
vector<string> name;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc = 0;
    while (true) {
        tc++;
        n = 0;
        cin >> n;
        if (tc > 1) {
            cout << endl;
        }
        if (n == 0) break;
        map<string, int> order;
        int cnt = -1;
        arr = vvi(n+1);
        isFree = vi(n, true);
        inDeg = vi(n+1, 0);
        name.clear();

        FOR(i, 0, n) {
            string s;
            cin >> s;
            cnt++;
            order[s] = cnt;
            name.push_back(s);
        }

        int m;
        cin >> m;
        FOR(i, 0, m) {
            string s1, s2;
            cin >> s1 >> s2;
            arr[order[s1]].push_back(order[s2]);
            inDeg[order[s2]]++;
            // cout << order[s1] << " " << order[s2] << endl;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", tc);

        FOR(tt, 0, n) {
            FOR(i, 0, n) {
                if (isFree[i] && inDeg[i] == 0) {
                    cout << " " << name[i];
                    isFree[i] = false;
                    FOR(j, 0, arr[i].size()) {
                        inDeg[arr[i][j]]--;
                    }
                    break;
                }
            }
        }

        cout << "." << endl;
    }
    return 0;
}