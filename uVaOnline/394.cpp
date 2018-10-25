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
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    vi b(n), s(n), d(n);
    vvi l(n), u(n), sizeEach(n);
    FOR(i, 0, n) {
        string name;
        cin >> name;
        mp[name] = i;
        cin >> b[i];
        cin >> s[i];
        cin >> d[i];
        FOR(j, 0, d[i]) {
            int x, y;
            cin >> x >> y;
            l[i].push_back(x);
            u[i].push_back(y);
            sizeEach[i].push_back(0);
        }
        sizeEach[i][d[i] - 1] = s[i];
        FORD(j, d[i]-2, 0) {
            sizeEach[i][j] = sizeEach[i][j+1]*(u[i][j+1] - l[i][j+1] + 1);
        }
    }
    // cerr << "///Debug\n";
    // cerr << b[2] << endl;
    // cerr << sizeEach[2][0] << endl;
    // cerr << "///Debug\n";
    FOR(i, 0, m) {
        string s;
        cin >> s;
        int index = mp[s];
        int res = b[index];
        vi arr(d[index]);
        FOR(j, 0, d[index]) {
            int x;
            cin >> x;
            arr[j] = x;
            res += (x - l[index][j]) * sizeEach[index][j];
        }
        cout << s << "[";
        FOR(j, 0, d[index]-1) {
            cout << arr[j] << ", ";
        }
        cout << arr[d[index]-1] << "] = ";
        cout << res << endl;
    }
    return 0;
}