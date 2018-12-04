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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

const int nMax = 10001;

int n, m;
int deg[nMax];
vii arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%d %d", &n, &m);
    
    memset(deg, 0, sizeof(deg));

    FOR(i, 0, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }

    if (n == 2) {
        if (deg[0] == 1) {
            cout << "0\n2 1\n0 1" << endl; 
        } else {
            cout << "2\n2 1\n0 1" << endl; 
        }
        return 0;
    }

    arr.resize(n);

    FOR(i, 0, n) {
        arr[i] = {deg[i] - 1, i};
    }

    sort(arr.begin(), arr.end());

    vi is1;
    vii diff1;

    int res = 0;
    int sum = 0;
    FOR(i, 0, n) {
        if (sum + arr[i].first > n-2) {
            deg[arr[i].second] = n-2 - sum + 1;
            sum = n-2;
        } else {
            deg[arr[i].second] = arr[i].first + 1;
            sum += arr[i].first;
            res++;
        }
        // cerr << arr[i].second << " " << deg[arr[i].second] << " " << arr[i].first << endl;
        if (deg[arr[i].second] == 1) {
            is1.push_back(arr[i].second);
        } else {
            diff1.push_back({arr[i].second, deg[arr[i].second]});
        }
    }

    memset(deg, 0, sizeof(deg));

    cout << n-res << endl;
    cout << n << " " << n - 1 << endl;

    FOR(i, 1, diff1.size()) {
        ii u = diff1[i-1];
        ii v = diff1[i];
        cout << u.first << " " << v.first << endl;
        diff1[i-1].second--;
        diff1[i].second--;
        // cerr << u.first << " " << u.second << endl;
        u = v;
    }

    int cnt = 0;
    FOR(i, 0, diff1.size()) {
        ii u = diff1[i];
        while (u.second > 0) {
            cout << u.first << " " << is1[cnt] << endl;
            cnt++;
            u.second--;
            // cerr << u.first << " " << u.second << endl;
        }
    }
    return 0;
}