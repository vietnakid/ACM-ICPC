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

int n, q;
vvi arr;
vi l;
ll _lcm = 1;
ll nextVertex[51];

int walk(int u, ll t) {
    for (int i = 0; i < t; i++) {
        u = arr[u][i % l[u]];
    }
    return u;
}

void findNextVertex() {
    for (int i = 1; i <= n; i++) {
        nextVertex[i] = walk(i, _lcm);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> q;
    arr.resize(n+1);
    l.resize(n+1);
    for (int i = 1; i <=n; i++) {
        cin >> l[i];
        _lcm = LCM(_lcm, l[i]);
        for (int j = 0; j < l[i]; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    while (_lcm < 200000) {
        _lcm *= 2;
    }
    findNextVertex();
    for (int i = 0; i < q; i++) {
        ll t;
        cin >> t;
        t--;
        int u = 1;
        ll h = t / _lcm;
        for (int j = 0; j < h; j++) {
            u = nextVertex[u];
        }
        cout << walk(u, t%_lcm) << endl;
    }

    return 0;
}